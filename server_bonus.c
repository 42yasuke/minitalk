/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:09:06 by jralph            #+#    #+#             */
/*   Updated: 2023/01/19 17:54:47 by jralph           ###   ########.fr       */
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
