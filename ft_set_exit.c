/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:51:14 by riael             #+#    #+#             */
/*   Updated: 2023/12/22 18:44:04 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_set_exit(t_minidat *minidat, int status, t_pipecommand *utor)
{
	if (WIFEXITED(status))
		minidat->last_exit = WEXITSTATUS(status);
	else
		minidat->last_exit = 1;
	utor->type = 8;
	utor = utor->next;
}
