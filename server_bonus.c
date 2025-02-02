/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:32:16 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/01 20:39:50 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t g_ack_received = 0;

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	character = 0;

	(void)context;
	if (sig == SIGUSR2)
		character |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write(1, &character, 1);
		if (character == '\0')
			write(1, "\n", 1);
		bit = 0;
		character = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		write(2, "Error: Failed to send acknowledgment\n", 37);
	else
		g_ack_received = 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
	{
		if (g_ack_received)
		{
			g_ack_received = 0;
		}
		pause();
	}
	return (0);
}
