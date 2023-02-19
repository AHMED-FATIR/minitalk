/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:32:56 by afatir            #+#    #+#             */
/*   Updated: 2023/01/29 16:02:14 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
unsigned char	x = 0;
int counter = 0;
int wahed = 128;

void handler(int sig)
{

	if (sig == SIGUSR1)
		x = x | wahed;	
	wahed = wahed >> 1;
	counter++;
	if (counter == 8)
	{
		write(1, &x, 1);
		counter = 0;
		x = 0;
		wahed = 128;
	}
}

int main (int ac, char **av)
{
	pid_t pid;

	pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
		;
	return (0);
}