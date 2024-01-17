/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:16:29 by riael             #+#    #+#             */
/*   Updated: 2023/12/21 15:03:22 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_unset_noargs(t_minidat *minidat)
{
	ft_putstr_fd("unset: not enough arguments\n", 2);
	minidat->err = 1;
	minidat->last_exit = 1;
	return (-42);
}
