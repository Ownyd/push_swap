/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 01:50:00 by tlux              #+#    #+#             */
/*   Updated: 2018/01/18 18:46:11 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int test_error(char *cmd)
{
	if (strcmp(cmd, "sa") != 0)
		if (strcmp(cmd, "sb") != 0)
			if (strcmp(cmd, "ss") != 0)
				if (strcmp(cmd, "pa") != 0)
					if (strcmp(cmd, "pb") != 0)
						if (strcmp(cmd, "ra") != 0)
							if (strcmp(cmd, "rb") != 0)
								if (strcmp(cmd, "rr") != 0)
									if (strcmp(cmd, "rra") != 0)
										if (strcmp(cmd, "rrb") != 0)
											if (strcmp(cmd, "rrr") != 0)
												return(0);
	return(1);
}

void	checker_progressive(int args, char **tab)
{
	int i;
	int *a;
	int *b;
	i = 2;
	a = (int *)malloc(sizeof(*a) * (args - 2));
	b = (int *)malloc(sizeof(*a) * (args - 2));
	while (i < args)
	{
		a[i - 2] = ft_atoi(tab[i]);
		i++;
	}
	get_length(a, NULL, args - 2, 0);
	exec_progressive(a, b, args - 2, 0);
}
void	checker(int args, char **tab)
{
	int *a;
	int i;
	char *line;
	char *cmds;
	int begin = 0;

	if(ft_strcmp(tab[1], "-p") == 0)
	{
		checker_progressive(args, tab);
		return ;
	}
	i = 1;
	a = (int *)malloc(sizeof(*a) * (args - 1));
	while(i < args)
	{
		a[i - 1] = ft_atoi(tab[i]); //Ajouter condition check INT sur atoi
		i++;
	}
	while(get_next_line(0, &line)) //CTRL +D pour stop
	{
		if (test_error(line) == 0)
		{
			printf("Error");
			return ;
		}
		if (begin == 0)
		{
			cmds = ft_strdup(line);	
			begin = 1;
		}
		else
		{
			cmds = ft_strjoin(cmds, "\n");
			cmds = ft_strjoin(cmds, line);
		}
	}
	printf("\x1B[35m""\n     [---- COMMAND :""\x1B[33m"" %s""\x1B[35m"" ----]\n","init a b");
	get_length(a, NULL, args - 1, 0);
	if (begin != 0)
		exec_master(ft_strsplit(cmds, '\n'), a, args - 1);
}
