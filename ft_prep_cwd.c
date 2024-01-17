/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_cwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:30:54 by riael             #+#    #+#             */
/*   Updated: 2024/01/16 17:36:41 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ft_go_back(t_minidat *minidat);

char	*ft_prep_cwd(t_minidat *minidat, char *str)
{
	char	*ret;
	char	*back;

	if (str == (void *)0)
		return ((void *)0);
	if (ft_strcmp(str, "..") == 0)
	{
		return (ft_go_back(minidat));
	}
	if (ft_strcmp(str, ".") == 0)
		return (ft_strdup(minidat->cwd));
	if (ft_strcmp(str, "/") == 0)
		return (ft_strdup("/"));
	if (str[0] == '/')
		return (str);
	back = (void *)0;
	ret = (void *)0;
	back = ft_strjoin(minidat->cwd, "/");
	ret = ft_strjoin(back, str);
	free(back);
	return (ret);
}

char	*ft_go_back(t_minidat *minidat)
{
	int		i;
	char	*ret;

	if (ft_strcmp(minidat->cwd, "/") == 0)
		return ((void *)0);
	if (ft_strcmp(minidat->cwd, "/home") == 0)
		return (ft_strdup("/"));
	i = ft_strlen(minidat->cwd);
	ret = ft_strdup(minidat->cwd);
	if (ret == (void *)0)
		return ((void *)0);
	while (ret[i] != '/')
	{
		ret[i] = '\0';
		i -= 1;
	}
	ret[i] = '\0';
	return (ret);
}
