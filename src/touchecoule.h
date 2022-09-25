#define OORANGE 10
#define UKVAL 20


typedef struct {
	char grid[10][10];
	int lives;
	char hits[10][10];
	int id;
} Player;

void print_grid(char [10][10]);
void clear_screen(void);
