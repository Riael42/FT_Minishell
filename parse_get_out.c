/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:53:08 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/19 17:53:12 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	get_out(char *s, int *i, t_pipecommand **pipe)
{
	int		flag;
	int		start;
	int		end;
	char	*file;

	flag = O_CREAT;
	(*i)++;
	if (s[*i] == '>' && (*i)++)
		flag = O_APPEND;
	jump_spaces(s, i);
	set_start_end(s, i, &start, &end);
	file = get_name(s, start, end, pipe);
	if ((*pipe)->out_dir >= 0)
		close((*pipe)->out_dir);
	if (flag == O_APPEND)
		(*pipe)->out_dir = open(file, O_CREAT | O_RDWR | O_APPEND, 0000600);
	else
		(*pipe)->out_dir = open(file, O_CREAT | O_RDWR, 0000600);
	free(file);
}
