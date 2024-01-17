/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clonenvp_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:47:37 by riael             #+#    #+#             */
/*   Updated: 2023/12/22 16:48:59 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**ft_clonenvp_err(t_minidat *minidat)
{
	minidat->last_exit = -1;
	ft_putstr_fd("There was an error cloning envp\n", 2);
	return ((void *)0);
}
