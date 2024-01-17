/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_green_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't give up | #42gether>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:20:29 by riael             #+#    #+#             */
/*   Updated: 2024/01/16 18:36:31 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int		ft_check_var(char *var);
int		ft_add_var(t_minidat *minidat, t_pipecommand *pipecmd, int num);
void	ft_freenvp(t_minidat *minidat);
int		ft_set_var(t_minidat *minidat, t_pipecommand *pipecmd, int num, int i);

int	ft_green_export(t_minidat *minidat, t_pipecommand *pipecmd)
{
	int	i;
	int	code;

	code = 0;
	if (pipecmd->args[1] == (void *)0 || pipecmd->args[1][0] == '\0')
		ft_green_env(minidat);
	else
	{
		i = 1;
		while (pipecmd->args[i] != (void *)0)
		{
			if (ft_check_var(pipecmd->args[i]) == 1)
			{
				if (code != 1)
					code = ft_add_var(minidat, pipecmd, i);
				else
					ft_add_var(minidat, pipecmd, i);
			}
			else
				code = ft_export_err(minidat);
			i += 1;
		}
	}
	return (code);
}

int	ft_set_var(t_minidat *minidat, t_pipecommand *pipecmd, int num, int i)
{
	int		j;

	j = 0;
	if (minidat->envp[i] == (void *)0)
	{
		minidat->newvp[i] = ft_strdup(pipecmd->args[num]);
		return (1);
	}
	while (pipecmd->args[num][j] != '=')
		j += 1;
	j = ft_strncmp(pipecmd->args[num], minidat->envp[i], j + 1);
	if (j != 0)
	{
		minidat->newvp[i] = ft_strdup(minidat->envp[i]);
		return (0);
	}
	minidat->newvp[i] = ft_strdup(pipecmd->args[num]);
	return (1);
}

void	ft_freenvp(t_minidat *minidat)
{
	int	i;

	i = 0;
	while (minidat->envp[i] != (void *)0)
	{
		free(minidat->envp[i]);
		i += 1;
	}
	free(minidat->envp);
}

int	ft_add_var(t_minidat *minidat, t_pipecommand *pipecmd, int num)
{
	int		i;
	int		check;
	char	**ret;

	check = 0;
	ret = (char **)malloc(sizeof (char *) * (minidat->envlines + 2));
	if (ret == (void *)0)
		return (ft_export_err(minidat));
	minidat->newvp = ret;
	i = -1;
	while (minidat->envp[++i] != (void *)0)
	{
		check += ft_set_var(minidat, pipecmd, num, i);
		if (minidat->newvp[i] == (void *)0)
			return (ft_frexport_err(minidat));
	}
	if (check == 0)
	{
		ft_set_var(minidat, pipecmd, num, i++);
		minidat->envlines += 1;
	}
	minidat->newvp[i] = (void *)0;
	ft_freenvp(minidat);
	minidat->envp = minidat->newvp;
	return (0);
}

int	ft_check_var(char *var)
{
	if (var == (void *)0)
		return (0);
	if (ft_strchr(var, '$') != (void *)0)
		return (0);
	if (ft_isdigit(var[0]) || ft_strchr(var, '=') == (void *)0 || \
		var[0] == '=')
		return (0);
	return (1);
}
