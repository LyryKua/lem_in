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
/**/#include "tmp.h"

int read_number_of_ants(void)
{
	int ants;
	char *line;

	ants = 0;
	if (get_next_line(STDIN_FILENO, &line) == 1)
	{
		if (!ft_isnumber(line))
		{
			ft_strdel(&line);
			error_exit("ERROR");
		}
		ants = ft_atoi(line);
		if (!ants)
			error_exit("ERROR");
		ft_strdel(&line);
	}
	if (!ants)
		error_exit("ERROR");
	return (ants);
}

int main(void)
{
	char *line;
	char **tbl;
	int ants;
	t_list *rooms;
	t_room room;
	enum e_status status;
	int tmp;

	ants = read_number_of_ants();
	rooms = read_rooms();
//	links = read_links();
//	printf("ants = %i\n", ants);
//	print_rooms(rooms);
	return (0);
}
