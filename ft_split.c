/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:38:39 by riael             #+#    #+#             */
/*   Updated: 2023/12/19 17:39:04 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static char	**ft_zerowords(void);

char	**ft_split(char *s, char c)
{
	int		wc;
	char	**final;
	int		i;

	wc = ft_countwords(s, c);
	if (wc == 0)
		return (ft_zerowords());
	final = (char **)malloc(sizeof(char *) * (wc + 1));
	if (final == ((void *)0))
		return ((void *)0);
	i = 0;
	while (i < wc)
	{
		final[i] = ft_createword(s, c, i);
		i += 1;
	}
	final[wc] = ((void *)0);
	return (final);
}

static char	**ft_zerowords(void)
{
	char	**s;

	s = (char **)malloc(sizeof(char *) * 1);
	s[0] = ((void *)0);
	return (s);
}
