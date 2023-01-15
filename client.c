/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:55:20 by jose              #+#    #+#             */
/*   Updated: 2023/01/15 22:50:04 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(int error)
{
	if (error == BAD_PARAMETERS)
		write (1, "BAD_PARAMETERS\n", 15);
	if (error == BAD_PID)
		write (1, "BAD_PID\n", 8);
	exit (1);
}

void	ft_send_char(int pid, unsigned char str)
{
	int	i;
	int	ret;

	i = 7;
	ret = BAD_PID;
	while (i > -1)
	{
		if (str & (1 << i))
			ret = kill (pid, SIGUSR2);
		else
			ret = kill (pid, SIGUSR1);
		if (ret == BAD_PID)
			ft_error(BAD_PID);
		i--;
		usleep(500);
	}
}

void	ft_send_chaine(int pid, char *str)
{
	int	already_sent;

	already_sent = 0;
	while (str && *str)
	{
		ft_send_char(pid, *str);
		str++;
		already_sent = 1;
	}
	if (already_sent)
		ft_send_char(pid, '\n');
	if (!*str && !already_sent)
		ft_send_char(pid, *str);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		ft_error(BAD_PARAMETERS);
	ft_send_chaine(ft_atoi(av[1]), av[2]);
	write (1, "Message sent with sucess !\n", 27);
	return (0);
}
