/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:13:04 by mbelouar          #+#    #+#             */
/*   Updated: 2023/02/14 23:33:50 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     MINITALK_H
# define    MINITALK_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define	EXIT_SUCCESS	0
# define	EXIT_FAILED		1

int     ft_atoi(const char *str);
int     ft_pow2(int base, int puiss);
void    handle_sig(int sig, siginfo_t *info, void *message);

#endif
