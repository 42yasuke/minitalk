/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:59:25 by jralph            #+#    #+#             */
/*   Updated: 2023/01/10 16:55:40 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	handler(int sig)
{
	if (sig == SIGINT)
		write (1, "I won't die!\n", 13);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		printf("ton PID est %d\n", getpid());
		sleep(1);
	}
	return (0);
}
