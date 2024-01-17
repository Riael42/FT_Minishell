/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:00:07 by dwilke            #+#    #+#             */
/*   Updated: 2024/01/16 15:00:12 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*get_value(char *name, t_minidat *dat)
{
	int	i;

	i = 0;
	while (dat->envp[i])
	{
		if (ft_strncmp(dat->envp[i], name, ft_strlen(name)) == 0 
			&& dat->envp[i][ft_strlen(name)] == '=')
			return (&(dat->envp[i][ft_strlen(name) + 1]));
		i++;
	}
	return (NULL);
}

char	**get_paths(t_minidat *dat, t_pipecommand **pipe)
{
	char	*value;
	t_strs	*tmp_strs;
	char	**val_arr;

	value = get_value("PATH", dat);
	if (value == NULL)
		return (NULL);
	tmp_strs = split_by(value, ':', pipe);
	val_arr = convert(tmp_strs, pipe);
	return (val_arr);
}

void	free_arr(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}
