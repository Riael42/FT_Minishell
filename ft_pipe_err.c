/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:11:25 by riael             #+#    #+#             */
/*   Updated: 2023/12/21 16:08:16 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_dup_err(t_minidat *minidat)
{
	ft_putstr_fd("There was an error while duping!\n", 2);
	minidat->err = 1;
	minidat->last_exit = -42;
}

void	ft_pipe_err(t_minidat *minidat)
{
	ft_putstr_fd("There was an error while pipe!\n", 2);
	minidat->err = 1;
	minidat->last_exit = -42;
}

void	ft_fork_err(t_minidat *minidat)
{
	ft_putstr_fd("There was an error while forking!\n", 2);
	minidat->err = 1;
	minidat->last_exit = -42;
}

void	ft_alpha_part(t_minidat *minidat)
{
	ft_putstr_fd("You are getting alpha particle'd\n", 2);
	ft_putstr_fd("Please do not resist!\n", 2);
	minidat->err = 1;
	minidat->last_exit = 420;
}
