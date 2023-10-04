/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:33:06 by afatir            #+#    #+#             */
/*   Updated: 2023/01/29 16:06:30 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_request(int sg)
{
	if (sg == SIGUSR2)
		ft_putstr_fd("\nmessage sended :)\n", 1);
	exit (0);
}

static void	last_message(pid_t pid)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
		usleep(900);
	}
	while (1)
	{	
		signal(SIGUSR2, &ft_request);
		pause();
	}
}

static void	ft_send_message(int c, pid_t pid)
{
	int	b;
	int	i;

	b = 1;
	i = 8;
	while (i--)
	{
		if (c & b)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(900);
		b = b << 1;
	}
}

int	main(int ac, char **av)
{
	pid_t				pid;
	int					i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr_fd("Number of Arguments is invalid :(\n", 2);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 0)
		return (write(2, "PID not exit :(\n", 12));
	while (av[2][i])
	{
		ft_send_message(av[2][i], pid);
		i++;
	}
	last_message(pid);
	return (0);
}
