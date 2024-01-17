/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_green_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:25:42 by riael             #+#    #+#             */
/*   Updated: 2024/01/16 17:21:22 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_green_isdigit(char *str);

int	ft_green_exit(t_minidat *minidat, t_pipecommand *spcmd)
{
	int	i;

	if (spcmd->args[1] != (void *)0)
	{
		i = ft_green_isdigit(spcmd->args[1]);
		if (i == 0)
		{
			ft_putstr_fd("exit\nminishell: exit: ", 1);
			ft_putstr_fd(spcmd->args[1], 1);
			ft_putstr_fd(": numeric argument required\n", 1);
			minidat->exit = 1;
			return (2);
		}
		else
		{
			ft_putstr_fd("exit", 1);
			minidat->last_exit = ft_atoi(spcmd->args[1]);
			minidat->exit = 1;
			if (minidat->last_exit >= 0 && minidat->last_exit <= 255)
				return (minidat->last_exit);
		}
	}
	minidat->exit = 1;
	return (42);
}

int	ft_green_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] <= '0' || str[i] >= '9')
			return (0);
		i += 1;
	}
	return (1);
}
