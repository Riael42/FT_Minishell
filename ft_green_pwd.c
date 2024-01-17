/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_green_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:21:40 by riael             #+#    #+#             */
/*   Updated: 2024/01/05 16:22:44 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_green_pwd(t_minidat *minidat)
{
	char	*pwd;

	pwd = (void *)0;
	pwd = (char *)malloc(sizeof(char) * 101);
	if (pwd == (void *)0)
	{
		ft_malloc_err(minidat);
		return (1);
	}
	pwd = getcwd(pwd, 100);
	write(1, pwd, ft_strlen(pwd));
	write(1, "\n", 1);
	minidat->last_exit = 0;
	free(pwd);
	return (0);
}
