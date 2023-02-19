/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:28:44 by afatir            #+#    #+#             */
/*   Updated: 2023/02/11 17:05:49 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	the_handler(int sig, siginfo_t *info, void *data)
{
	static int	pid;
	static int	i;
	int			b;
	static int	c;

	(void)data;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0;
		i = 0;
	}
	if (sig == SIGUSR1)
		b = 1;
	else
		b = 0;
	c += (b << i);
	i ++;
	if (i == 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = the_handler;
	sa.sa_flags = 0;
	pid = getpid();
	ft_putstr_fd("PID of the server is : ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL)
	sigaction(SIGUSR2, &sa, NULL)
	while (1)
		pause();
	return (0);
}
