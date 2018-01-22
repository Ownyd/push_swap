/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:54:18 by tlux              #+#    #+#             */
/*   Updated: 2018/01/20 21:33:18 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# define height params[2]
# define width params[3]
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define _IGREY "\x1b[40m"
#define _IRED "\x1b[41m"
#define _IGREEN "\x1b[42m"
#define _IYELLOW "\x1b[43m"
#define _IBLUE "\x1b[44m"
#define _IPURPLE "\x1b[45m"
#define _ICYAN "\x1b[46m"
#define _IWHITE "\x1b[47m"
#define _END "\x1b[0m"
#define BOLD "\x1b[1m"
static void display_middle(int *a, int *b, int *params)
{
	int i;
	i = height;
	while (--i >= 0)
		{
			if(params[0] > i)
			{
				if(store_pivot(&(a[i]), "read") == 1)
					printf(KCYN"\t|" KMAG"%*d"_END KCYN"|  ", width, a[i]);
				else if (i == get_place(a, params[0], a[i]))
					printf(KCYN"\t|" KGRN"%*d"_END KCYN"|  ", width, a[i]);
				else
				printf(KCYN"\t|" KYEL "%*d"_END KCYN"|  ", width, a[i]);

			}
			else
				printf(KRED"\t|%*s  ", width + 1, "|");
			if(params[1] > i)
			{
				if(store_pivot(&(b[i]), "read") == 1)
					printf(KCYN"|" KMAG"%*d"_END KCYN"|\n" KNRM, width, b[i]);
				else if (i == params[1] - 1 - get_place(b, params[1], b[i]))
				printf(KCYN"|" KGRN "%*d"_END KCYN"|\n" KNRM, width, b[i]);
				else
				printf(KCYN"|" KYEL "%*d"_END KCYN"|\n" KNRM, width, b[i]);
			}
			else
				printf(KRED"|%*c\n" KNRM, width + 1, '|');
		}
}

static void display_top(int *params)
{
	int i;

	i = -1;
	printf(KNRM"\t+");
	while (++i < width)
	printf(KNRM"-");
	printf(KNRM"+  +");
	i = -1;
	while (++i < width)
	printf(KNRM"-");
	printf(KNRM"+\n");
}

void get_length(int *a, int *b, int lena, int lenb)
{
	int i;
	int params[4];
	params[0] = lena;
	params[1] = lenb;
	height = lena >= lenb ? lena : lenb;
	width = 0;
	i = 0;
	while (i < lena)
	{
		if ((int)ft_strlen(ft_itoa(a[i])) > width)
			width = (int)ft_strlen(ft_itoa(a[i]));
		i++;
	}
	i = 0;
	while (i < lenb)
	{
		if ((int)ft_strlen(ft_itoa(b[i])) > width)
			width = (int)ft_strlen(ft_itoa(b[i]));
		i++;
	}
	if (width > 0 && height > 0)
	{
	display_top(params);
	display_middle(a, b, params);
	display_top(params);
	}
}
