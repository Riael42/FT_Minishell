/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:52:25 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/19 17:52:29 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	jump_to_next_fu(char *s, char c, int *i)
{
	(*i)++;
	while (s[*i] && s[*i] != c)
		(*i)++;
}

static char	*split(int start, int end, char *s, t_pipecommand **pipe)
{
	char	*ret;
	int		i;
	int		size;

	ret = malloc(sizeof(char) * (end - start + 2));
	if (ret == NULL)
		(*pipe)->malloc_err = 1;
	i = 0;
	size = end - start;
	while (i < size)
		ret[i++] = s[start++];
	ret[i] = 0;
	return (ret);
}

static void	jumps(char *s, int *i)
{
	if (s[*i] == '\'')
		jump_to_next_fu(s, '\'', i);
	else if (s[*i] == '"')
		jump_to_next_fu(s, '"', i);
}

void	malloc_next(t_strs **tmp, t_pipecommand **pipe)
{
	(*tmp)->next = malloc(sizeof(t_strs));
	if ((*tmp)->next == NULL)
		(*pipe)->malloc_err = 1;
	*tmp = (*tmp)->next;
}

t_strs	*split_by(char *s, char c, t_pipecommand **pipe)
{
	int		i;
	int		start;
	t_strs	*strs;
	t_strs	*tmp;

	tmp = init_vars(&i, &start, &strs, pipe);
	while (s[i])
	{
		jumps(s, &i);
		if (s[i] == c || s[i + 1] == 0)
		{
			if (s[i + 1] != 0)
			{
				tmp->s = split(start, i, s, pipe);
				start = i + 1;
				malloc_next(&tmp, pipe);
			}
			else
				tmp->s = split(start, i + 1, s, pipe);
			tmp->next = NULL;
		}
		if (s[i] != 0)
			i++;
	}
	return (strs);
}
