/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_green_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't give up | #42gether>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:43:01 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 19:21:05 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_replace_pwd(t_minidat *minidat);
int	ft_replace_owd(t_minidat *minidat);
int	ft_complex_cd(t_minidat *minidat, char **list, t_pipecommand *incmd);

int	ft_green_cd(t_minidat *minidat, t_pipecommand *incmd)
{
	char	**list;
	int		i;
	int		j;

	list = ft_prep_cd(minidat, incmd);
	j = ft_complex_cd(minidat, list, incmd);
	i = 0;
	while (j != -1 && list[i] != (void *)0)
	{
		free(list[i]);
		i += 1;
	}
	if (j != -1)
		free(list);
	ft_replace_pwd(minidat);
	ft_replace_owd(minidat);
	return (j);
}

int	ft_complex_cd(t_minidat *minidat, char **list, t_pipecommand *incmd)
{
	int		i;
	int		err;
	char	*s;

	i = -1;
	err = 0;
	while (list[++i] != (void *)0)
	{
		err = 0;
		s = ft_prep_cwd(minidat, list[i]);
		if (s != (void *)0)
		{
			err = chdir(s);
			if (err == -1)
				return (ft_cd_err(minidat, incmd));
			free(minidat->owd);
			minidat->owd = ft_strdup(minidat->cwd);
			free(minidat->cwd);
			minidat->cwd = ft_strdup(s);
			free(s);
		}
		else
			return (-1);
	}
	return (0);
}

int	ft_replace_owd(t_minidat *minidat)
{
	int	i;

	i = 0;
	while (minidat->envp[i] != (void *)0)
	{
		if (ft_strncmp(minidat->envp[i], "OLDPWD=", 7) == 0)
		{
			free(minidat->envp[i]);
			minidat->envp[i] = ft_strjoin("OLDPWD=", minidat->owd);
			if (minidat->envp[i] == ((void *)0))
			{
				ft_malloc_err(minidat);
				return (-99);
			}
			else
				return (0);
		}
		i += 1;
	}
	return (0);
}

int	ft_replace_pwd(t_minidat *minidat)
{
	int	i;

	i = 0;
	while (minidat->envp[i] != (void *)0)
	{
		if (ft_strncmp(minidat->envp[i], "PWD=", 4) == 0)
		{
			free(minidat->envp[i]);
			minidat->envp[i] = (void *)0;
			minidat->envp[i] = ft_strjoin("PWD=", minidat->cwd);
			if (minidat->envp[i] == (void *)0)
			{
				ft_malloc_err(minidat);
				return (-99);
			}
			else
				return (0);
		}
		i += 1;
	}
	return (0);
}
