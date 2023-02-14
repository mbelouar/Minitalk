/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:01:03 by mbelouar          #+#    #+#             */
/*   Updated: 2023/02/14 23:32:30 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

int	ft_pow2(int base, int puiss)
{
	int pow;
	int i;

	pow = 1;
	i = 0;
	while (i < puiss)
	{
		pow *= base;
		i++;
	}
	return (pow);
}

void	handle_sig(int sig, siginfo_t *info, void *message)
{
	static int	stock_bits[8];
	static int	i;
	pid_t		clientpid;
	int sum;

	if (clientpid != info->si_pid)
	{
		clientpid = info->si_pid;
		i = 0;
	}
	if (sig == SIGUSR1)
		stock_bits[i++] = 1;
	else if (sig == SIGUSR2)
		stock_bits[i++] = 0;
	if (i == 8)
	{
		sum = 0;
		while (i)
		{
			if (stock_bits[i - 1] == 1)
				sum += ft_pow2(2, 8 - i);
			i--;
		}
		write (1, &sum, 1);
		i = 0;
	}
}

int main(int ac, char **av)
{
	int	pid;
	struct sigaction	sigact;

	sigact.sa_sigaction = &handle_sig;
	sigact.sa_flags = SA_SIGINFO;
	if (ac != 1)
	{
		ft_printf("There's something wrong with the number of arguments\n");
		return (EXIT_FAILED);
	}
	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
}