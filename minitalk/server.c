/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:01:25 by seukim            #+#    #+#             */
/*   Updated: 2026/07/19 20:17:47 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

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
	static unsigned char	current_char = 0;
	static int				bits_received = 0;
	int						new_bit;

	(void)context;
	if (sig == SIGUSR1)
		new_bit = 0;
	else
		new_bit = 1;
	current_char = current_char << 1;
	current_char = current_char | new_bit;
	bits_received++;
	if (bits_received == 8)
	{
		if (current_char != '\0')
			write(1, &current_char, 1);
		bits_received = 0;
		current_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "Server PID: ", 12);
	put_nbr(getpid());
	write(1, "\n", 1);
	while (1)
		usleep(50);
	return (0);
}

/*
** main 흐름:
** struct sigaction sa;              -> 설정 구조체 선언
** sa.sa_sigaction = sig_handler;    -> 핸들러 지정
** sa.sa_flags = SA_SIGINFO;         -> 3인자 모드(발신자 PID 수신)
** sigemptyset(&sa.sa_mask);         -> 마스크 초기화
** sigaction(SIGUSR1, &sa, NULL);    -> SIGUSR1 등록
** sigaction(SIGUSR2, &sa, NULL);    -> SIGUSR2 등록
** write + put_nbr + write           -> 서버 PID 출력
** while (1) pause();                -> 신호 대기 무한루프
*/