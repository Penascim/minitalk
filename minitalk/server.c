/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penascim <penascim@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:38:57 by penascim          #+#    #+#             */
/*   Updated: 2024/03/06 19:01:26 by penascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk.h"

void	signs(int sig)
{
	static char	c = 0;
	static int	bit = 0;

	if (sig == SIGUSR2)
		c = c << 1;
	else
		c = c << 1 | 1;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}
/*	
	00000000 }
		&	 } 00000000
	00000110 }
\\\\\\\\\\\\\\\\\\\\\\\\\\
	00000000 }
		|	 } 00000001
	00000011 }
*/

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, signs);
		signal(SIGUSR2, signs);
	}
	return (0);
}
