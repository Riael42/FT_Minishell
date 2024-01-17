/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:34:37 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/19 17:35:03 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_strs	*set_arg(t_strs **args, t_pipecommand **pipe)
{
	t_strs	*arg;

	if (*args == NULL)
	{
		*args = malloc(sizeof(t_strs));
		if (*args == NULL)
			(*pipe)->malloc_err = 1;
		(*args)->next = NULL;
		return (*args);
	}
	arg = *args;
	while (arg->next != NULL)
		arg = arg->next;
	arg->next = malloc(sizeof(t_strs));
	if (arg->next == NULL)
		(*pipe)->malloc_err = 1;
	arg->next->next = NULL;
	return (arg->next);
}

void	get_arg(char *s, int *i, t_strs **args, t_pipecommand **pipe)
{
	int		start;
	int		end;
	char	*file;
	t_strs	*arg;

	arg = set_arg(args, pipe);
	set_start_end(s, i, &start, &end);
	file = get_name(s, start, end, pipe);
	arg->s = file;
}
