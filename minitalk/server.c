/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:01:25 by seukim            #+#    #+#             */
/*   Updated: 2026/08/09 21:02:41 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_state	g_state;

static void	put_nbr(int n)
{
	char	c;

	if (n >= 10)
		put_nbr(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
}

static void	reset_state(int pid)
{
	g_state.pid = pid;
	g_state.c = 0;
	g_state.bits = 0;
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	int	client;

	(void)context;
	client = info->si_pid;
	if (client <= 0)
		return ;
	if (client != g_state.pid)
		reset_state(client);
	g_state.c = g_state.c << 1;
	if (sig == SIGUSR2)
		g_state.c = g_state.c | 1;
	g_state.bits++;
	if (g_state.bits == 8 && g_state.c == '\0')
	{
		write(1, "\n", 1);
		reset_state(0);
	}
	else if (g_state.bits == 8)
	{
		write(1, &g_state.c, 1);
		reset_state(client);
	}
	kill(client, SIGUSR1);
}

static int	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (0);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (0);
	return (1);
}

int	main(void)
{
	if (!setup_signals())
		return (1);
	write(1, "Server PID: ", 12);
	put_nbr(getpid());
	write(1, "\n", 1);
	while (1)
		usleep(100);
	return (0);
}
