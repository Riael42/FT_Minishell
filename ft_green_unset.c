/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_green_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't give up | #42gether>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:54:34 by riael             #+#    #+#             */
/*   Updated: 2024/01/09 20:44:52 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_del_var(t_minidat *minidat, int i);
int	ft_green_if(t_minidat *minidat, t_pipecommand *pcmd, int i, int j);

int	ft_green_unset(t_minidat *minidat, t_pipecommand *pcmd)
{
	int	i;
	int	j;

	if (pcmd->args[1] == (void *)0)
		return (-42);
	j = 0;
	while (pcmd->args[++j] != (void *)0)
	{
		i = -1;
		while (minidat->envp[++i] != (void *)0)
		{
			if (ft_green_if(minidat, pcmd, i, j))
			{
				if (minidat->envp[i + 1] == (void *)0)
				{
					free(minidat->envp[i]);
					minidat->envp[i] = (void *)0;
				}
				else
					ft_del_var(minidat, i);
			}
		}
	}
	return (0);
}

int	ft_green_if(t_minidat *minidat, t_pipecommand *pcmd, int i, int j)
{
	if (ft_strncmp(minidat->envp[i], pcmd->args[j], \
					ft_strlen(pcmd->args[j])) == 0 && \
		minidat->envp[i][ft_strlen(pcmd->args[j])] == '=')
		return (1);
	return (0);
}

int	ft_del_var(t_minidat *minidat, int i)
{
	char	**ret;
	int		j;
	int		k;

	minidat->envlines -= 1;
	ret = (char **)malloc(sizeof(char *) * (minidat->envlines + 1));
	if (ret == (void *)0)
		return (ft_malloc_err_int(minidat)); 
	j = 0;
	k = 0;
	while (minidat->envp[j] != (void *)0)
	{
		if (j == i)
		{
			free(minidat->envp[j]);
			j += 1;
			k = 1;
		}
		ret[j - k] = ft_strdup(minidat->envp[j]);
		free(minidat->envp[j++]);
	}
	ret[j - k] = (void *)0;
	free(minidat->envp);
	minidat->envp = ret;
	return (0);
}
