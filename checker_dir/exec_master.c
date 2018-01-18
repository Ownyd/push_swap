/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:52:33 by tlux              #+#    #+#             */
/*   Updated: 2018/01/18 18:47:05 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"

int	exec_progressive(int *a, int *b, int lena, int lenb)
{
	char *line;

	int i;
	if (!get_next_line(0, &line))
		return (0);
		i = -1;
		while (++i < (lena >= lenb ? lena : lenb) + 3)
		printf("\E[M\E[A");
	//	printf("\n");
			if ((strcmp(line, "sa") == 0 && lena > 1) ||
				(strcmp(line, "ss") == 0 && lena > 1))
			ft_swap(&(a[lena - 1]), &(a[lena - 2]));
		if ((strcmp(line, "sb") == 0 && lenb > 1) ||
				(strcmp(line, "ss") == 0 && lenb > 1))
			ft_swap(&(b[lenb - 1]), &(b[lenb - 2]));
		if (strcmp(line, "pa") == 0 && lenb > 0)
		{
			a[lena] = b[lenb - 1];
			lena++;
			lenb--;
		}
		if (strcmp(line, "pb") == 0 && lena > 0)
		{
			b[lenb] = a[lena - 1];
			lenb++;
			lena--;
		}
		if ((i = -1) == -1 && ((strcmp(line, "rra") == 0 && lena > 1)
					|| (strcmp(line, "rrr") == 0 && lena >1)))
			while (++i < lena - 1)
				ft_swap(&(a[i]), &(a[i + 1]));
		if ((i = -1) == -1 && ((strcmp(line, "rrb") == 0 && lenb > 1)
					|| (strcmp(line, "rrr") == 0 && lenb > 1)))
			while (++i < lenb - 1)
				ft_swap(&(b[i]), &(b[i + 1]));
		if (((i = lena) == lena && ((strcmp(line, "ra") == 0) && lena > 1))
				|| ((strcmp(line, "rr") == 0 && lena > 1)))
			while (--i > 0)
				ft_swap(&(a[i]), &(a[i - 1]));
		if (((i = lenb) == lenb && ((strcmp(line, "rb") == 0) && lenb > 1))
				|| ((strcmp(line, "rr") == 0 && lenb > 1)))
			while (--i > 0)
				ft_swap(&(b[i]), &(b[i - 1]));
		get_length(a, b, lena, lenb);
		return(exec_progressive(a, b, lena, lenb));
}



void exec_master(char **cmds, int *a, int lena)
{
	int *b;
	int lenb;
	int i;

	lenb = 0;
	b = (int *)malloc(sizeof(*b) * (lena));
	while(*cmds != NULL)
	{
		if ((strcmp(*cmds, "sa") == 0 && lena > 1) ||
				(strcmp(*cmds, "ss") == 0 && lenb > 1 && lena > 1))
			ft_swap(&(a[lena - 1]), &(a[lena - 2]));
		if ((strcmp(*cmds, "sb") == 0 && lenb > 1) ||
				(strcmp(*cmds, "ss") == 0 && lenb > 1 && lena > 1))
			ft_swap(&(b[lenb - 1]), &(b[lenb - 2]));
		if (strcmp(*cmds, "pa") == 0 && lenb > 0)
		{
			a[lena] = b[lenb - 1];
			lena++;
			lenb--;
		}
		if (strcmp(*cmds, "pb") == 0 && lena > 0)
		{
			b[lenb] = a[lena - 1];
			lenb++;
			lena--;
		}
		if ((i = -1) == -1 && ((strcmp(*cmds, "rra") == 0 && lena > 1)
					|| (strcmp(*cmds, "rrr") == 0 && lena >1)))
			while (++i < lena - 1)
				ft_swap(&(a[i]), &(a[i + 1]));
		if ((i = -1) == -1 && ((strcmp(*cmds, "rrb") == 0 && lenb > 1)
					|| (strcmp(*cmds, "rrr") == 0 && lenb > 1)))
			while (++i < lenb - 1)
				ft_swap(&(b[i]), &(b[i + 1]));
		if (((i = lena) == lena && ((strcmp(*cmds, "ra") == 0) && lena > 1))
				|| ((strcmp(*cmds, "rr") == 0 && lena > 1)))
			while (--i > 0)
				ft_swap(&(a[i]), &(a[i - 1]));
		if (((i = lenb) == lenb && ((strcmp(*cmds, "rb") == 0) && lenb > 1))
				|| ((strcmp(*cmds, "rr") == 0 && lenb > 1)))
			while (--i > 0)
				ft_swap(&(b[i]), &(b[i - 1]));


		printf("\x1B[35m""     [---- COMMAND :""\x1B[33m"" %s""\x1B[35m"" ----]\n",*cmds);
		get_length(a, b, lena, lenb);
		cmds++;
	}
}
