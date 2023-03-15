/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:02:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/03/15 12:19:49 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	output;

	(void) context;
	if (signal == SIGUSR1)
		output |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (output == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", output);
		output = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	int					pid;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("Errore numero parametri in ingresso");
		exit (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	act.sa_sigaction = ft_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
