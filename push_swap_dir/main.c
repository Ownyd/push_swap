/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpushswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 02:51:18 by tlux              #+#    #+#             */
/*   Updated: 2018/01/18 19:12:48 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	int i;
	int *tab;

	i = 1;
	tab = (int *)malloc(sizeof(*tab) * (argc - 1));
	while (i < argc)
	{
		tab[i - 1] = ft_atoi(argv[i]);
//		printf("%d",tab[i - 1]);
		i++;
	}
	rotate_push(tab, argc - 1);
	return(0);
}
