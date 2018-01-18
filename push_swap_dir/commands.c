/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:50:16 by tlux              #+#    #+#             */
/*   Updated: 2018/01/18 19:50:41 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void s(int *tab, int lentab)
{
	ft_swap(&(tab[lentab - 1]), &(tab[lentab - 2]));
}
void r(int *tab, int lentab, int nb)
{
	int i;

	while (nb > 0)
	{
		i = lentab;
		while (--i > 0)
			ft_swap(&(tab[i]), &(tab[i - 1]));
		nb--;
	}
}

void pa(int *a, int *b, int *lena, int *lenb)
{
	a[*lena] = b[*lenb - 1];
	(*lena)++;
	(*lenb)--;
}

void pb(int *a, int *b, int *lena, int *lenb)
{
	b[*lenb] = a[*lena - 1];
	(*lenb)++;
	(*lena)--;
}

void rr(int *tab, int lentab, int nb)
{
	int i;

	while (nb > 0)
	{
		i = -1;
		while (++i < lentab - 1)
			ft_swap(&(tab[i]), &(tab[i + 1]));
		nb--;
	}
}
