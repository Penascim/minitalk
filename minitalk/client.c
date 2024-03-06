/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penascim <penascim@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:38:51 by penascim          #+#    #+#             */
/*   Updated: 2024/03/06 19:30:57 by penascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			pid = ft_atoi(av[1]);
			send_bits(av[2][i], pid);
			i++;
		}
	}
}
/*
	((c >> 8) & 1)
	00110001 -> 0 = 1
	00011000 -> 1 = 0
	00001100 -> 2 = 0
	00000110 -> 3 = 0
	00000011 -> 4 = 1
	00000001 -> 5 = 1
	00000000 -> 6 = 0
	00000000 -> 7 = 0
*/
