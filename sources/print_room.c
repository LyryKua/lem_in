//
// Created by Kyrylo Hrecheniuk on 5/18/18.
//

#include <printf.h>
#include "lem_in.h"

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
