/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:39:31 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/05 11:42:36 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft.h"

typedef struct s_msg
{
	int		bit;
	char	character;
	char	*buffer;
	char	*temp;
}	t_msg;

void	handle_signal(int sig, siginfo_t *info, void *context);
void	send_char(int pid, char c);
void	acknowledge(int sig);
void	append_char(t_msg *msg, char c);

#endif
