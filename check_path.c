/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:01:49 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/20 14:01:53 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	expand_path(char **path, char *pathvar, t_pipecommand **pipe)
{
	*path = strjoin_se(*path, pathvar, 0, ft_strlen(pathvar));
	if (*path == NULL)
		(*pipe)->malloc_err = 1;
	*path = strjoin_se(*path, "/", 0, 1);
	if (*path == NULL)
		(*pipe)->malloc_err = 1;
	*path = strjoin_se(*path, (*pipe)->args[0], 0, ft_strlen((*pipe)->args[0]));
	if (*path == NULL)
		(*pipe)->malloc_err = 1;
}

char	*new_str(char *s)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (i < ft_strlen(s))
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	check_access(t_pipecommand **pipe)
{
	struct stat	sb;

	if (stat((*pipe)->args[0], &sb) == 0 && S_ISDIR(sb.st_mode))
		return ((*pipe)->type = -1, 1);
	if (access((*pipe)->args[0], X_OK) != -1)
	{
		(*pipe)->command = new_str((*pipe)->args[0]);
		return (1);
	}
	else if (access((*pipe)->args[0], F_OK) == 0 && 
		access((*pipe)->args[0], X_OK) == -1)
	{
		(*pipe)->type = -2;
		return (1);
	}
	return (0);
}

static int	inner_while(char *path, char **paths, t_pipecommand **pipe, int i)
{
	expand_path(&path, paths[i], pipe);
	if (access(path, X_OK) != -1)
	{
		(*pipe)->command = path;
		free_arr(paths);
		return (1);
	}
	else if (access(path, F_OK) == 0 && access(path, X_OK) == -1)
	{
		free(path);
		(*pipe)->type = -2;
		free_arr(paths);
		return (1);
	}
	free(path);
	path = NULL;
	return (0);
}

void	check_path(t_pipecommand **pipe, t_minidat *dat)
{
	char	*path;
	char	**paths;
	int		i;

	i = -1;
	path = NULL;
	if (check_access(pipe) == 1)
		return ;
	paths = get_paths(dat, pipe);
	while (paths != NULL && paths[++i] != NULL)
	{
		if (inner_while(path, paths, pipe, i))
			return ;
	}
	(*pipe)->type = -1;
	free_arr(paths);
}
