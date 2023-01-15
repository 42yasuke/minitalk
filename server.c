/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:55:52 by jose              #+#    #+#             */
/*   Updated: 2023/01/15 22:50:57 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int				count = 0;
	static unsigned char	a = 0;

	if (sig == SIGUSR2)
		a = a | (1 << (7 - count));
	count++;
	if (count == 8)
	{
		if (a != 0)
		{
			write (1, &a, 1);
			a = 0;
			count = 0;
		}
		else
		{
			write (1, "Server has been closed !\n", 25);
			exit (0);
		}
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sa.sa_flags = 0;
	(void)ac;
	(void)av;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("PID %d\n", getpid());
	while (1)
		pause();
}
