/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:53:34 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/21 20:48:52 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	exit_malloc_err(t_pipecommand **pipe, t_minidat *minidat)
{
	ft_putendl_fd("Malloc error, exiting...", 2);
	free_pipe(*pipe, minidat);
	minidat->last_exit = 1;
	minidat->err = 1;
	exit(1);
}

void	check_malloc_err(t_pipecommand **pipe, t_minidat *minidat)
{
	t_pipecommand	*tmp;

	tmp = *pipe;
	while (tmp != NULL)
	{
		if (tmp->malloc_err == 1)
			exit_malloc_err(pipe, minidat);
		tmp = tmp->next;
	}
}

void	ft_malloc_err(t_minidat *minidat)
{
	ft_putendl_fd("Error while mallocing!", 2);
	minidat->last_exit = 1;
	minidat->err = 1;
}

int	ft_malloc_err_int(t_minidat *minidat)
{
	ft_putendl_fd("Error while mallocing!", 2);
	minidat->last_exit = 1;
	minidat->err = 1;
	return (1);
}
