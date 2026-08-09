/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:19:25 by seukim            #+#    #+#             */
/*   Updated: 2026/08/09 21:03:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static volatile sig_atomic_t	g_ack = 0;

static void	ack_handler(int sig)
{
	g_ack = sig;
}

static void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack = 0;
		if (((c >> i) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_ack == 0)
			usleep(50);
		i--;
	}
}

static int	parse_pid(char *s)
{
	long	pid;
	int		i;

	pid = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		pid = pid * 10 + (s[i] - '0');
		if (pid > 2147483647)
			return (-1);
		i++;
	}
	if (pid <= 0)
		return (-1);
	return ((int)pid);
}

static int	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (0);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		write(2, "Error: usage is ./client <pid> <message>\n", 40);
		return (1);
	}
	pid = parse_pid(argv[1]);
	if (pid == -1 || kill(pid, 0) == -1)
	{
		write(2, "Error: invalid pid or server not found\n", 38);
		return (1);
	}
	if (!setup_signals())
		return (1);
	i = 0;
	while (argv[2][i])
		send_char(pid, (unsigned char)argv[2][i++]);
	send_char(pid, '\0');
	if (g_ack == SIGUSR2)
		write(1, "Message received by server\n", 27);
	return (0);
}
