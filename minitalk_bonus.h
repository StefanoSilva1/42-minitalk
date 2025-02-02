/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:39:31 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/01 16:54:06 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft.h"


extern volatile sig_atomic_t	g_ack_received;

void	handle_signal(int sig, siginfo_t *info, void *context);
void	acknowledge(int sig);
void	send_byte(int pid, unsigned char byte);
void	send_string(int pid, char *str);

#endif

