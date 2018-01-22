/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:09:59 by tlux              #+#    #+#             */
/*   Updated: 2018/01/20 17:32:31 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int store_pivot(int *pivot, char *str)
{
	static t_list *pivots;
	t_list *tmp;
	int *cmp;

	tmp = pivots;
	if (ft_strcmp(str, "add") == 0)
		ft_lstadd(&pivots, ft_lstnew((void *)pivot, sizeof(int)));
	if (ft_strcmp(str, "read") == 0)
	{
		while (tmp)
		{
			cmp = (int *)tmp->content;
			if (*cmp == *pivot)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}
