/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:10:00 by seukim            #+#    #+#             */
/*   Updated: 2026/07/19 20:17:48 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static int	g_ack = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
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
		while (!g_ack)
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

static void	send_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "Error: usage is ./client <pid> <message>\n", 41);
		return (1);
	}
	pid = parse_pid(argv[1]);
	if (pid == -1 || kill(pid, 0) == -1)
	{
		write(1, "Error: invalid pid or server not found\n", 39);
		return (1);
	}
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_string(pid, argv[2]);
	return (0);
}
