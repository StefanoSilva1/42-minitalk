/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:45:05 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/03/31 08:53:40 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ack_received = 0;

void	acknowledge(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack_received = 0;
		if ((c >> (7 - bit)) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack_received)
			;
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;
	int					i;

	if (argc != 3)
	{
		write(2, "Invalid number of arguments\n", 28);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "Invalid PID\n", 12);
		return (1);
	}
	sa.sa_handler = acknowledge;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (argv[2][i])
		send_char(pid, argv[2][i++]);
	send_char(pid, '\0');
	return (0);
}
