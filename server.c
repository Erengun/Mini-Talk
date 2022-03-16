/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:35:36 by egun              #+#    #+#             */
/*   Updated: 2022/03/16 18:35:25 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	askim_fatih(int sig)
{
	static int	i = 7;
	static char	c = 0;

	c += sig << i;
	if (i == 0)
	{
		i = 7;
		ft_printf("%c", c);
		c = 0;
	}
	else
		i--;
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		askim_fatih(1);
	}
	else if (signal == SIGUSR2)
	{
		askim_fatih(0);
	}
	else if (signal == SIGINT)
	{
		ft_printf(RED "\nMaking exit. Goodbyee..\n" RST);
		exit(1);
	}
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGINT, signal_handler);
	pid = getpid();
	ft_printf(BLU "Your pid is :"WHT" %d\n" RST, pid);
	while (42)
		pause();
}
