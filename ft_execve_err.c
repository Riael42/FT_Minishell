/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:31:41 by riael             #+#    #+#             */
/*   Updated: 2023/12/21 20:31:42 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_execve_err(t_minidat *minidat)
{
	ft_putstr_fd("There was an execve error!\n", 2);
	minidat->last_exit = 1;
	minidat->err = 1;
}
