#include <stdio.h>
#include "touchecoule.h"
#include "turn.h"


/* returns the result of the shooting at these coordinates,
 * and updates the grids in consequence */
int
aim_coord(int x, int y, char playgrd [10][10], char advgrd [10][10])
{
	if (x >= 10 || y >= 10){
		return OORANGE;
	} else if (advgrd[x][y] == '~'){
		advgrd[x][y] = 'X';
		playgrd[x][y] = 'X';
		printf("\n\nMissed...\n");
		return 0;
	} else {
		advgrd[x][y] = 'D';
		playgrd[x][y] = 'O';
		printf("\n\nHit !!\n");
		return 1;
	};
}


/* handles the turn of player shooting on advers. we need 2 calls to
 * turn in order to complete a full turn*/
void
turn(Player *player, Player *advers)
{
	int x, y, res;

	printf("Player %i : press enter to start your turn\n", player->id);
	getchar();
	clear_screen();

	printf("Your grid is now :\n");
	print_grid(player->grid);
	printf("\nYour hits are :\n");
	print_grid(player->hits);

	printf("Where do you want to shoot ?\n"
			"you must put a space between coordinates :");
	scanf("%i %i", &x, &y);
	getchar();

	res = aim_coord(x, y, player->hits, advers->grid);
	//if player shoots out of the grid, we consider it their fault and
	//they loose their turn
	if (res == OORANGE) printf("coordinates were out of the grid\n");
	else if (res == 1){
		advers->lives--;
		printf("Well done, your new hit grid is :\n");
		print_grid(player->hits);
	} else {
		printf("your new hit grid is :\n");
		print_grid(player->hits);
	};

	printf("Press enter to end your turn\n");
	getchar();
	clear_screen();
}

