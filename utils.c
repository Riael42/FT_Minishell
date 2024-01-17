/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:44:20 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/21 15:13:28 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	jump_spaces(char *cmd, int *i)
{
	while (cmd[*i] && (cmd[*i] == ' ' || cmd[*i] == '\t'))
		(*i)++;
}

void	set_count(t_minidat **dat, t_pipecommand **pipe)
{
	t_pipecommand	*tmp;
	int				i;

	tmp = *pipe;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp-> next;
	}
	(*dat)->cmdnum = i;
}

void	normibuster(int argc, char **argv)
{
	argc = 0;
	if (argv)
		argv = NULL;
	argc++;
}
