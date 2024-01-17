/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:39:15 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/20 14:39:19 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_strs	*init_vars(int *i, int *start,
	t_strs **strs, t_pipecommand **pipe)
{
	*i = 0;
	*start = 0;
	*strs = malloc(sizeof(t_strs));
	if (*strs == NULL)
		(*pipe)->malloc_err = 1;
	(*strs)->s = NULL;
	(*strs)->next = NULL;
	return (*strs);
}
