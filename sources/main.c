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

int get_number_of_ants(void)
{
	int ants;
	char *line;

	ants = 0;
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		if (ft_isdigit(*line))
		{
			ft_putendl(line);
			ants = ft_atoi(line);
			ft_strdel(&line);
			break;
		}
		else
		{
			ft_strdel(&line);
			error_exit("The rooms’ coordinates should be integers.");
		}
	}
	return (ants);
}

bool is_valid_room(char **tbl)
{
	int words;

	words = 0;
	while (tbl[words])
		words++;
	return (words != 3 || !ft_isnumber(tbl[1]) || !ft_isnumber(tbl[2]) ? false
																	   : true);
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
	if (!is_valid_room(tbl))
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

void print_room(t_room room)
{
	printf(" -> room\nname: %s\n(%d, %d)\nstatus: ", room.name, room.x, room.y);
	switch (room.status)
	{
		case start:
			printf("start");
			break;
		case end:
			printf("end");
			break;
		default:
			printf("usual");
	}
	printf("\nnumber_ants = %d\n\n", room.number_ants);
}

int main(void)
{
	char *line;
	int ants;
	t_list lst;
	t_room room;
	enum e_status status;

	ants = get_number_of_ants();
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		if (is_comment(line))
		{
			ft_putendl(line);
			ft_strdel(&line);
			continue;
		}
		status = usual;
		if (is_start_or_end(line))
		{
			status = line[2] == 's' ? start : end;
			ft_putendl(line);
			ft_strdel(&line);
			if (get_next_line(STDIN_FILENO, &line) != 1)
				error_exit("After ##start or ##end should be a room!");
			if (*line == '#' || *line == 'L')
				error_exit("A room will never start with the character 'L' nor the character '#'");
		}
		room = get_room(line, status);
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (0);
}
