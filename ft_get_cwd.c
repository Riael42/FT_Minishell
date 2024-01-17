/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:26:58 by riael             #+#    #+#             */
/*   Updated: 2024/01/05 16:14:50 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ft_get_cwd(t_minidat *minidat)
{
	char	*pwd;

	pwd = (void *)0;
	pwd = (char *)malloc(sizeof(char) * 101);
	if (pwd == (void *)0)
	{
		ft_malloc_err(minidat);
		return ((void *)0);
	}
	pwd = getcwd(pwd, 100);
	minidat->last_exit = 0;
	return (pwd);
}
