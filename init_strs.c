/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:02:48 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 20:02:56 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_strs	*init_strs(void)
{
	t_strs	*ret;

	ret = malloc(sizeof(t_strs));
	ret->s = NULL;
	ret->next = NULL;
	return (ret);
}
