#include <stdio.h>
#include "touchecoule.h"
#include "init.h"
#include "turn.h"

int
main()
{
	Player player1, player2;
	int shipsize, turnc = 1, placetrig = 1;;
	char nextship;

	printf("Welcome to battleships,\n\n"
			"During this game, coordinates must be\n"
			"entered as two unsigned integers separated by a space\n"
			"\nThe coordinates 0 0 points to the upper left corner\n"
			"and the first coordinate represents the rows (the\n"
			"second is for the columns)\n\n"
			"The grid is 10x10, therefore the maximal coordinates\n"
			"are 9 9 (lower right corner)\n\n\n"
			"Press enter to start :");
	getchar();

	init_grid(player1.grid);
	init_grid(player1.hits);
	player1.id = 1;
	init_grid(player2.grid);
	init_grid(player2.hits);
	player2.id = 2;


	printf("You must now place your ships, enter the size of the\n"
			"first one :");
	while (placetrig){
		scanf("%i", &shipsize);
		getchar(); 
		//getchar is used in order to free the buffer for the next scan

		player1.lives += shipsize;
		player2.lives += shipsize;
		//lives are the number of ship boxes still alive

		place_ship(&player1, &player2, shipsize);

		printf("If you want to place another ship, press n\n"
				"esle, press any other key:");
		scanf("%c", &nextship);
		getchar();

		if (nextship == 'n'){
			printf("Enter the size of the next ship:");
		} else placetrig = 0;
	};


	while (player1.lives != 0 && player2.lives != 0){
		if (turnc & 1) turn(&player1, &player2);
		else turn(&player2, &player1);
		turnc++;
		//first argument of turn is the one who attacks, it needs to
		//change each turn (hence the parity test)
	};

	if (player1.lives == 0) printf("Well done Player 2, ");
	else printf("Well done Player 1, ");
	printf("here are the final grids :\n"
			"Player 1:\n");
	print_grid(player1.grid);
	printf("Player 2:\n");
	print_grid(player2.grid);

	return 0;
}


/* prints the given grid with the format :
 * [ x x x x x x x x x x ]
 * [ x x x x x x x x x x ]
 * [ x x x x x x x x x x ]
 * [ x x x x x x x x x x ]
 * [ x x x x x x x x x x ]
 * [ x x x x x x x x x x ]
 * [ x x x x x x x x x x ]
 * [ x x x x x x x x x x ]
 * [ x x x x x x x x x x ]
 * [ x x x x x x x x x x ] */
void
print_grid(char grid[10][10])
{
	size_t i, j;
	for (i = 0; i < 10; i++){
		printf("[");
		for(j = 0; j < 10; j++) printf(" %c ", grid[i][j]);
		printf("]\n");
	};
}


/* instead of a proper clear, just write enough newlines
 * in order to make it dissuasive to look back */
void
clear_screen(void)
{
	int i;
	for(i = 0; i < 100; i++) printf("\n");
}

