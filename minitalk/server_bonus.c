/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:01:25 by seukim            #+#    #+#             */
/*   Updated: 2026/08/09 20:58:52 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

typedef struct s_state
{
	unsigned char	c;
	int				bits;
	int				pid;
}	t_state;

static t_state	g_state;

static void	put_nbr(int n)
{
	char	c;

	if (n >= 10)
		put_nbr(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	int	client;

	(void)context;
	client = info->si_pid;
	if (client <= 0)
		return ;
	if (client != g_state.pid)
	{
		g_state.pid = client;
		g_state.c = 0;
		g_state.bits = 0;
	}
	g_state.c = g_state.c << 1;
	if (sig == SIGUSR2)
		g_state.c = g_state.c | 1;
	g_state.bits++;
	if (g_state.bits < 8)
		return (kill(client, SIGUSR1), (void)0);
	g_state.bits = 0;
	if (g_state.c == '\0')
		return (g_state.pid = 0, kill(client, SIGUSR2), (void)0);
	write(1, &g_state.c, 1);
	g_state.c = 0;
	kill(client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	write(1, "Server PID: ", 12);
	put_nbr(getpid());
	write(1, "\n", 1);
	while (1)
		usleep(100);
	return (0);
}
