/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 00:35:07 by tlux              #+#    #+#             */
/*   Updated: 2018/01/20 00:55:12 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int *ft_int_tab_dup(int *tab, int start, int end)
{
	int *ret;
	int i;
	int j;

	j = 0;
	ret = (int *)malloc(sizeof(*ret) * (end - start + 1));
	i = start;
	
	while (i <= end)
	{
		ret[j] = tab[i];	
		i++;
		j++;
	}
//	get_length(ret, NULL, end - start + 1, 0);
	return(ret);
}
