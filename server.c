/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:45:01 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/05 11:58:13 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg	g_msg = {0};

void	append_char(t_msg *msg, char c)
{
	if (!msg->buffer)
		msg->buffer = ft_strdup((char []){c, '\0'});
	else
	{
		msg->temp = ft_strjoin(msg->buffer, (char []){c, '\0'});
		free(msg->buffer);
		msg->buffer = msg->temp;
	}
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR2)
		g_msg.character |= (1 << (7 - g_msg.bit));
	g_msg.bit++;
	if (g_msg.bit == 8)
	{
		if (g_msg.character == '\0')
		{
			if (g_msg.buffer)
				ft_printf("%s\n", g_msg.buffer);
			else
				ft_printf("%s\n", "");
			free(g_msg.buffer);
			g_msg.buffer = NULL;
		}
		else
			append_char(&g_msg, g_msg.character);
		g_msg.bit = 0;
		g_msg.character = 0;
	}
	(kill(info->si_pid, SIGUSR1));
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
