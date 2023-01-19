/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:55:52 by jose              #+#    #+#             */
/*   Updated: 2023/01/19 04:17:12 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ptr)
{
	static int				count = 0;
	static unsigned char	a = 0;

	(void)ptr;
	if (sig == SIGUSR2)
		a = a | (1 << (7 - count));
	count++;
	if (count == 8)
	{
		write (1, &a, 1);
		a = 0;
		count = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("PID %d\n", getpid());
	while (1)
		pause();
}
