/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:35:43 by afatir            #+#    #+#             */
/*   Updated: 2023/01/13 00:10:26 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_init(int sig)
{
	int		b;

	if (sig == SIGUSR1)
		b = 1;
	else
		b = 0;
	return (b);
}

static void	final_message(int pid)
{
	usleep(5000);
	if (kill(pid, SIGUSR2) == -1)
		exit(1);
}

static void	the_handler(int sig, siginfo_t *info, void *data)
{
	static int	pid;
	static int	c;
	static int	i;
	int			b;

	(void)data;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0;
		i = 0;
	}
	b = ft_init(sig);
	c += (b << i);
	i ++;
	if (i == 8)
	{
		if (c == 0)
			final_message(pid);
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_a;

	s_a.sa_sigaction = the_handler;
	s_a.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr_fd("PID of the server is : ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &s_a, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &s_a, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
