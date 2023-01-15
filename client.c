/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:55:20 by jose              #+#    #+#             */
/*   Updated: 2023/01/15 14:56:00 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(int error)
{
	if (error == BAD_PARAMETERS)
		write (1, "BAD_PARAMETERS\n", ft_strlent("BAD_PARAMETERS\n"));
	if (error == BAD_PID)
		write (1, "BAD_PID\n", ft_strlent("BAD_PID\n"));
	exit (1);
}

void	handler(int sig)
{
	if (sig == SIGINT)
		write (1, "I won't die!\n", 13);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		ft_error(BAD_PARAMETERS);
	
	/*struct sigaction	sa;

	sa.sa_handler = &handler;
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		printf("ton PID est %d\n", getpid());
		sleep(1);
	}*/
	return (0);
}
