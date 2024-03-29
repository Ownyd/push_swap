/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:53:06 by tlux              #+#    #+#             */
/*   Updated: 2018/01/17 17:42:45 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_issort(int *tab, int lentab)
{
	int i;

	i = 0;
	while (i < lentab - 1)
	{
		if (tab[i] < tab[i+1])
			return (0);
		i++;
	}
	return (1);
}
