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
			error_exit(
					"Wrong input for number of ants!\nOnly numbers are allowed");
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
	return (words != 3 || !ft_isnumber(tbl[1]) || !ft_isnumber(tbl[2]) ? false : true);
}

t_room get_room(char *line)
{
	t_room room;
	char **tbl;

	tbl = ft_strsplit(line, ' ');
	if (is_valid_room(tbl))
	{

	}

	return (room);
}

bool is_start_or_end(const char *line)
{
	return (ft_strequ(line, "##start") || ft_strequ(line, "##end") ? true : false);
}

bool is_comment(const char *line)
{
	return (*line == '#' ? true : false);
}

int main(void)
{
	char *line;
	int ants;
	t_list lst;
	t_room room;

	ants = get_number_of_ants();
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		if (is_start_or_end(line) || is_comment(line))
		{
			ft_putendl(line);
			continue;
		}
		room = get_room(line);
		ft_putendl(line);
		ft_strdel(&line);
	}
	return 0;
}
