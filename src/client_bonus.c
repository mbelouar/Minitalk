/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:49:14 by mbelouar          #+#    #+#             */
/*   Updated: 2023/02/19 15:56:22 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_confirmation_message(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("\nMESSAGE SENT ! please check the server\n");
}

int	main(int ac, char **av)
{
	int	i;
	int	bit;

	i = -1;
	if (ac == 3 && ft_atoi(av[1]) > 0)
	{
		signal(SIGUSR1, ft_confirmation_message);
		while (++i < ft_strlen(av[2]) + 1)
		{
			bit = 8;
			while (--bit >= 0)
			{
				if ((av[2][i] >> bit) & 1)
					kill(ft_atoi(av[1]), SIGUSR1);
				else
					kill(ft_atoi(av[1]), SIGUSR2);
				usleep(250);
			}
		}
	}
	else
	{
		ft_printf("There's something wrong with the arguments\n");
		return (EXIT_FAILURE);
	}
}
