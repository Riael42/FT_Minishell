/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:00:26 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 20:09:02 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static char	*get_env_name(t_ex_data *ex_d, int start);
static char	*get_env_value(char *name, t_ex_data *ex_d);
int			ft_is_onechar(char c);
int			check_jump(t_ex_data *ex_d);

void	replace_env_new(t_ex_data *ex_d)
{
	char	*env_name;
	char	*env_value;
	int		start;

	ex_d->new_line = strjoin_se(ex_d->new_line, ex_d->line, 
			ex_d->start, ex_d->i);
	ex_d->i = ex_d->i + 1;
	start = ex_d->i;
	if (ex_d->line[ex_d->i] && ft_is_onechar(ex_d->line[ex_d->i]) == 1)
		ex_d->i = ex_d->i + 1;
	else
	{
		while (check_jump(ex_d))
			ex_d->i = ex_d->i + 1;
	}
	env_name = get_env_name(ex_d, start);
	env_value = get_env_value(env_name, ex_d);
	if (env_value != NULL)
		ex_d->new_line = strjoin_se(ex_d->new_line, env_value, 0,
				ft_strlen(env_value));
	if (ft_strcmp(env_name, "?") == 0)
		free(env_value);
	free(env_name);
	ex_d->start = ex_d->i;
}

static char	*get_env_name(t_ex_data *ex_d, int start)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * (ex_d->i - start + 1));
	while (start < ex_d->i)
		ret[i++] = ex_d->line[start++];
	ret[i] = 0;
	return (ret);
}

static char	*get_env_value(char *name, t_ex_data *ex_d)
{
	int	i;

	i = 0;
	if (ft_strcmp(name, "?") == 0)
	{
		if (ex_d->data->last_exit == 131)
			return (ft_itoa(130));
		return (ft_itoa(ex_d->data->last_exit));
	}
	while (ex_d->data->envp[i])
	{
		if (ft_strncmp(ex_d->data->envp[i], name, ft_strlen(name)) == 0 
			&& ex_d->data->envp[i][ft_strlen(name)] == '=')
			return (&(ex_d->data->envp[i][ft_strlen(name) + 1]));
		i++;
	}
	return (NULL);
}

int	ft_is_onechar(char c)
{
	if (c == '?')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


int	check_jump(t_ex_data *ex_d)
{
	if (ex_d->line[ex_d->i] && ex_d->line[ex_d->i] >= '0' && ex_d->line[ex_d->i] <= '9')
		return(1);
	else if (ex_d->line[ex_d->i] && ex_d->line[ex_d->i] >= 'a' && ex_d->line[ex_d->i] <= 'z')
		return (1);
	else if (ex_d->line[ex_d->i] && ex_d->line[ex_d->i] >= 'A' && ex_d->line[ex_d->i] <= 'Z')
		return (1);
	else
		return (0);
	// if (ex_d->line[ex_d->i] && ex_d->line[ex_d->i] != ' ' && 
	// 	ex_d->line[ex_d->i] != '"' && ex_d->line[ex_d->i] != '\'' && 
	// 	ex_d->line[ex_d->i] != '$' && ex_d->line[ex_d->i] != '|')
	// 	return (1);
	// return (0);
}
