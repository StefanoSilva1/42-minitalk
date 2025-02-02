/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:31:43 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/01 16:56:08 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ack_received = 0;

void	acknowledge(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_byte(int pid, unsigned char byte)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack_received = 0;
		if ((byte >> (7 - bit)) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		while (!g_ack_received)
			pause();
	}
}

void	send_string(int pid, char *str)
{
	int				i;
	unsigned char	*bytes;

	i = 0;
	bytes = (unsigned char *)str;
	while (bytes[i])
		send_byte(pid, bytes[i++]);
	send_byte(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

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
	send_string(pid, argv[2]);
	return (0);
}

