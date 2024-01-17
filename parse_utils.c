/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:02:13 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/20 14:02:17 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**convert(t_strs *args, t_pipecommand **pipe)
{
	int		i;
	t_strs	*tmp;
	char	**ret;

	i = 0;
	tmp = args;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = args;
	ret = malloc(sizeof(char *) * (i + 1));
	if (ret == NULL)
		(*pipe)->malloc_err = 1;
	i = 0;
	while (tmp != NULL)
	{
		ret[i++] = tmp->s;
		tmp = tmp->next;
	}
	ret[i] = NULL;
	free_strs_conv(args);
	return (ret);
}
