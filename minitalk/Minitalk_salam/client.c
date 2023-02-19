/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:32:52 by afatir            #+#    #+#             */
/*   Updated: 2023/01/29 16:03:49 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	pid_t			pid;
	unsigned char	x;
	int i = 0;
	int j = 0;

	if (ac != 3)
		return (printf("error!!"), 1);
	pid = atoi(av[1]);
	while (av[2][j])
	{
		x = 0b10000000;
		i = 0;
		while (i < 8)
		{
			if (x & av[2][j])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			x = x >> 1;
			i++;
			usleep(900);
		}
	j++;
	}	
	return (0);
}