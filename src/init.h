typedef struct {
	char grid[10][10];
	int size;
	int x;
	int y;
	char direction;
} Shipadd;

void init_grid(char[10][10]);
void place_ship(Player *, Player *, int);
int set_ship(Shipadd *);
