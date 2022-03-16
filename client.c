/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:35:33 by egun              #+#    #+#             */
/*   Updated: 2022/03/06 21:24:24 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_convert(char x, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((x >> i) & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
	}
}

int	main(int argc, char **argv)
{
	char	*msg;
	int		i;

	i = 0;
	if (argc == 3)
	{
		msg = argv[2];
		while (msg[i])
		{
			ft_convert(msg[i], ft_atoi(argv[1]));
			i++;
		}
		if (*msg)
			ft_convert('\n', ft_atoi(argv[1]));
	}
	else
		ft_printf(BRED "Yanlış mesaj ahbap tekrar dene\n" RST);
	return (0);
}
