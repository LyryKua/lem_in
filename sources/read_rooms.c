//
// Created by Kyrylo Hrecheniuk on 5/19/18.
//

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"
#include "get_next_line.h"

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

bool is_valid_room(char *line)
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

t_room get_room(char *line, enum e_status status)
{
	t_room room;
	char **tbl;
	int i;

	tbl = ft_strsplit(line, ' ');
	room.name = ft_strdup(tbl[0]);
	room.x = ft_atoi(tbl[1]);
	room.y = ft_atoi(tbl[2]);
	room.status = status;
	room.number_ants = 0;
	i = 0;
	while (tbl[i])
		ft_strdel(&tbl[i++]);
	free(tbl);
	return (room);
}

t_list *read_rooms(void)
{
	t_list *rooms;
	t_room room;
	char *line;

	rooms = NULL;
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		if (is_valid_room(line))
		{
			room = get_room(line, usual);
			ft_lstadd(&rooms, ft_lstnew(&room, sizeof(room)));
		}
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (rooms);
}
