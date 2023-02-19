/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:26:47 by mbelouar          #+#    #+#             */
/*   Updated: 2023/02/19 16:05:12 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_pow2(int base, int puiss)
{
	int	pow;
	int	i;

	pow = 1;
	i = 0;
	while (i < puiss)
	{
		pow *= base;
		i++;
	}
	return (pow);
}

void	print_char(int *tab, siginfo_t *info)
{
	char		c;
	int			i;

	i = 8;
	c = 0;
	while (i)
	{
		if (tab[i - 1] == 1)
			c += ft_pow2(2, 8 - i);
		i--;
	}
	if (!c)
		kill(info->si_pid, SIGUSR1);
	else
		write (1, &c, 1);
}

void	handle_sig(int sig, siginfo_t *info, void *message)
{
	static int		stock_bits[32];
	static int		i;
	static int		len;
	static pid_t	clientpid;

	(void) message;
	if (clientpid != info->si_pid)
	{
		clientpid = info->si_pid;
		i = 0;
	}
	if (len == 0)
		len = 1;
	stock_bits[i++] = (sig == SIGUSR1);
	while (i == 4 && stock_bits[0] == 1 && stock_bits[len] == 1)
		len++;
	if (i == 8 * len)
	{
		i = -1;
		while (++i < len)
			print_char(&stock_bits[i * 8], info);
		i = 0;
		len = 1;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sigact;

	(void) av;
	sigact.sa_sigaction = &handle_sig;
	sigact.sa_flags = SA_SIGINFO;
	if (ac != 1)
	{
		ft_printf("There's something wrong with the number of arguments\n");
		return (EXIT_FAILURE);
	}
	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
}
