#include <stdio.h>
#include <string.h>
#include "touchecoule.h"
#include "init.h"


void
init_grid(char grid[10][10])
{
	int i, j;
	for (i = 0; i < 10; i++){
		for(j = 0; j < 10; j++) grid[i][j] = '~';
	};
}


void
place_ship(Player *player1, Player *player2, int shipsize)
{
	Shipadd ship1, ship2;
	int set_ret = 1;;
	memcpy(ship1.grid, player1->grid, sizeof(player1->grid));
	memcpy(ship2.grid, player2->grid, sizeof(player2->grid));
	ship1.size = shipsize;
	ship2.size = shipsize;

	while (set_ret != 0){
		printf("Player 1, press enter to place your ship\n");
		getchar();
		printf("Here's your actual grid :\n");
		print_grid(ship1.grid);
		
		printf("select the direction of your ship :\n"
				"h : horizontal, the coordinates will be the ones\n"
				"    of the box on the left\n"
				"v : vertical, the coordinates will be the ones of\n"
				"    the upper box\n");
		scanf("%c", &ship1.direction);
		getchar();
		printf("Now enter the coordinates :");
		scanf("%i %i", &ship1.x, &ship1.y);
		getchar();

		set_ret = set_ship(&ship1);
		switch(set_ret) {
			case 0 :
				printf("Your new grid is :\n");
				print_grid(ship1.grid);
				memcpy(player1->grid, ship1.grid, sizeof(ship1.grid));
				printf("press enter:");
				getchar();
				clear_screen();
				break;
			case 1 :
				printf("This is over another ship, place it again\n");
				break;
			case OORANGE :
				printf("Coordinates are too big, place it again\n");
				break;
			case UKVAL :
				printf("Wrong orientation, place it again\n");
				break;
		}
	};

	set_ret = 1;
	while (set_ret != 0){
		printf("Player 2, press enter to place your ship\n");
		getchar();
		printf("Here's your actual grid :\n");
		print_grid(ship2.grid);
		
		printf("select the direction of your ship :\n"
				"h : horizontal, the coordinates will be the ones\n"
				"    of the box on the left\n"
				"v : vertical, the coordinates will be the ones of\n"
				"    the upper box\n");
		scanf("%c", &ship2.direction);
		printf("Now enter the coordinates :");
		scanf("%i %i", &ship2.x, &ship2.y);
		getchar();

		set_ret = set_ship(&ship2);
		switch(set_ret) {
			case 0 :
				printf("Your new grid is :\n");
				print_grid(ship2.grid);
				memcpy(player2->grid, ship2.grid, sizeof(ship2.grid));
				printf("press enter:");
				getchar();
				clear_screen();
				break;
			case 1 :
				printf("This is over another ship, place it again\n");
				break;
			case OORANGE :
				printf("Coordinates are too big, place it again\n");
				break;
			case UKVAL :
				printf("Wrong orientation, place it again\n");
				break;
		}
	};
}


int
set_ship(Shipadd *ship)
{
	int i;
	if (ship->direction == 'v'){
		if (ship->x + ship->size > 10){
			return OORANGE;
		};
		for (i = 0; i < ship->size; i++){
			if (ship->grid[ship->x+i][ship->y] == 'S') return 1;
		};
		for (i = 0; i < ship->size; i++){
			ship->grid[ship->x+i][ship->y] = 'S';
		};
		return 0;
	};
	if (ship->direction == 'h'){
		if (ship->y + ship->size > 10){
			return OORANGE;
		};
		for (i = 0; i < ship->size; i++){
			if (ship->grid[ship->x][ship->y+i] == 'S') return 1;
		};
		for (i = 0; i < ship->size; i++){
			ship->grid[ship->x][ship->y+i] = 'S';
		};
		return 0;
	};
	return UKVAL;
}

