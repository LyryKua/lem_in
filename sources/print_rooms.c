//
// Created by Kyrylo Hrecheniuk on 5/18/18.
//

#include <printf.h>
#include "libft.h"
#include "lem_in.h"

void print_rooms(t_list *rooms)
{
	t_room room;

	while (rooms != NULL)
	{
		room = *(t_room *)rooms->content;
		printf("+---------------+\n");
		printf("| name: %7s |\n", room.name);
		printf("| x: %10d |\n", room.x);
		printf("| y: %10d |\n", room.y);
		printf("| status: ");
		switch (room.status)
		{
			case start:
				printf("start");
				break;
			case end:
				printf("  end");
				break;
			default:
				printf("usual");
		}
		printf(" |\n");
		printf("| ants: %7d |\n", room.number_ants);
		printf("+---------------+\n");
		printf("        |        \n");
		printf("       \\ /        \n");
		rooms = rooms->next;
	}
}
