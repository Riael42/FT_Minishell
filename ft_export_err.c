/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:41:01 by riael             #+#    #+#             */
/*   Updated: 2023/12/22 18:52:56 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_export_err(t_minidat *minidat)
{
	minidat->err = 1;
	minidat->last_exit = -42;
	ft_putstr_fd("There was an error exporting! \n", 2);
	return (1);
}
