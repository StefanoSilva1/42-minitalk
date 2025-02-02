/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:39:31 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/01 16:45:58 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

extern volatile sig_atomic_t	g_ack_received;

void	handle_signal(int sig, siginfo_t *info, void *context);
void	send_char(int pid, char c);
void	acknowledge(int sig);

#endif
