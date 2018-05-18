/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:45:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/20 16:45:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"
#include "get_next_line.h"

/**/#include <printf.h>

bool is_room(char *line)
{
	int words;
	char **tbl;
	bool answer;

	tbl = ft_strsplit(line, ' ');
	words = 0;
	while (tbl[words])
		words++;
	if (words == 3 && tbl[0][0] != 'L' && tbl[0][0] != '#'
		&& ft_isnumber(tbl[1]) && ft_isnumber(tbl[2]))
		answer = true;
	else
		answer = false;
	words = 0;
	while (tbl[words])
		ft_strdel(&tbl[words++]);
	free(tbl);
	return (answer);
}

bool is_start_or_end(const char *line)
{
	return (ft_strequ(line, "##start") || ft_strequ(line, "##end") ? true
																   : false);
}

bool is_comment(const char *line)
{
	return (*line == '#' && !ft_strequ(line, "##start") &&
			!ft_strequ(line, "##end") ? true : false);
}

t_room get_room(char *line, enum e_status status)
{
	t_room room;
	char **tbl;
	int i;

	tbl = ft_strsplit(line, ' ');

	if (!is_room(tbl))
		error_exit("Wrong input for room!\nFormat: [name coord_x coord_y]");
	room.name = ft_strdup(tbl[0]);
	room.x = ft_atoi(tbl[1]);
	room.y = ft_atoi(tbl[2]);
	room.status = status;
	room.number_ants = 0;
	i = 0;
	while (tbl[i])
	{
		ft_strdel(&tbl[i]);
		i++;
	}
	free(tbl);
	return (room);
}

int get_number_of_ants()
{
	int ants;
	char *line;
	int c;

	ants = -42;
	if ((c = get_next_line(STDIN_FILENO, &line)) == 1)
	{
		if (!ft_isnumber(line))
		{
			ft_strdel(&line);
			error_exit("ERROR");
		}
		ants = ft_atoi(line);
		ft_putendl(line);
		ft_strdel(&line);
	}
	printf("%d\n", c);
	return (ants);
}

int main(void)
{
	char *line;
	char **tbl;
	int ants;
	t_list *lst;
	t_room room;
	enum e_status status;

	ants = get_number_of_ants();
	printf("ants = %i\n", ants);
	while (42);
	return (0);
}
