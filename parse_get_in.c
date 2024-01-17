/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:53:37 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/19 17:53:42 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	get_in(char *s, int *i, t_pipecommand **pipe)
{
	int		flag;
	int		start;
	int		end;
	char	*file;

	flag = 1;
	(*i)++;
	if (s[*i] == '<' && (*i)++)
		flag = 2;
	jump_spaces(s, i);
	set_start_end(s, i, &start, &end);
	file = get_name(s, start, end, pipe);
	if (flag == 1)
	{
		if ((*pipe)->in_op != NULL)
			free((*pipe)->in_op);
		if ((*pipe)->in_dir > 0)
			close((*pipe)->in_dir);
		(*pipe)->in_dir = open(file, O_RDONLY);
		free(file);
		return ;
	}
	(*pipe)->in_dir = -42;
	(*pipe)->in_op = file;
}
