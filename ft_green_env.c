/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_green_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:23:21 by riael             #+#    #+#             */
/*   Updated: 2023/12/21 20:47:09 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_green_env(t_minidat *minidat)
{
	int	i;

	i = 0;
	while (minidat->envp[i] != (void *)0)
	{
		ft_putstr_fd(minidat->envp[i], 1);
		ft_putchar_fd('\n', 1);
		i += 1;
	}
	minidat->last_exit = 0;
	return (0);
}
