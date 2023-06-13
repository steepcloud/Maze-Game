#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define GRID_SIZE 12
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

// Arrays to represent movement in different directions
short moveX[4] = { 0, 0, -1, 1 };
short moveY[4] = { -1, 1, 0, 0 };

int playerX = GRID_SIZE - 1, playerY = 0; // Initial position of the player

char player[4] = { '^', 'v', '<', '>' }; // Characters to represent the player in different directions

bool running = true; // Flag to control the main game loop

int sw, shot; // Variables to store the user input and flag for shooting

char aux; // Temporary variable for swapping characters in the grid

long score; // Player score

 /*
  * Controls:
  *		i - move up
  *		j - move left
  *		k - move down
  *		l - move right
  *		s - shoot
  *		q - terminate program
  *
  * Environment:
  *		1 - wall
  *		0 - clear path
  *		<, ^, v, > - player
  *		T - treasure
  *		M - monster
  */

char grid[GRID_SIZE][GRID_SIZE] = { {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				    {'0', '1', '0', '0', '1', '0', '0', 'M', '0', '0', 'T', '0'},
				    {'0', '1', 'T', '0', '1', '0', '0', '0', '0', '1', '0', '0'},
				    {'0', '1', '0', '0', '1', '0', '1', '1', '0', '1', '0', '0'},
				    {'0', '1', '1', '1', '1', '0', '0', '0', '0', '1', '0', '0'},
				    {'0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'M'},
				    {'0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0'},
				    {'0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				    {'0', '1', '0', '0', '0', '0', '0', '1', '1', '1', '1', '0'},
				    {'0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				    {'0', '0', '0', '1', '1', '1', '1', '0', 'T', '0', '0', '0'},
				    {'>', '0', '0', '0', '0', 'M', '0', '0', '0', '0', '0', '0'} };

// Draw the game board with current state
void draw_board() {
	cout << endl;
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			cout << grid[i][j] << " | ";
		}

		cout << endl;

		for (int j = 0; j < GRID_SIZE; j++) {
			cout << "----";
		}
		cout << endl;
	}
	cout << "\n\nScore: " << score;
}

// Shoot in the specified direction and update the grid and score
void shoot(int direction, int x, int y) {
	if (grid[x + moveY[direction]][y + moveX[direction]] == 'M') {
		grid[x + moveY[direction]][y + moveX[direction]] = '0';
		score += 50; //+50 points per monster killed
	}
	score -= 26; //-25 points for every shot fired, -1 point for shooting
}

// Check if there is a wall or out of grid bounds in the given direction
int check_wall(int direction, int x, int y) {
	if (grid[x + moveY[direction]][y + moveX[direction]] == '1' || !(x + moveY[direction] >= 0 && y + moveX[direction] >= 0 && x + moveY[direction] <= (GRID_SIZE - 1) && y + moveX[direction] <= (GRID_SIZE - 1)))
		return 0;
	return 1;
}

// Determine the player's direction and set the shot flag
void check_shot(int& direction) {
	for (int i = 0; i < 4; i++) {
		if (grid[playerX][playerY] == player[i]) {
			direction = i;
		}
	}
	shot = 1;
}

// Move the player or perform other actions based on user input and game rules
void move() {
	int direction = -1;

	shot = 0;

	if (sw > 0) {
		switch (sw) {
		case 'i':
			direction = UP;
			break;
		case 'j':
			direction = LEFT;
			break;
		case 'k':
			direction = DOWN;
			break;
		case 'l':
			direction = RIGHT;
			break;
		case 's':
			check_shot(direction);
			shoot(direction, playerX, playerY);
			break;
		case 'q':
			running = false;
			break;
		}
	}

	if (direction >= 0 && direction <= 3 && !shot) {
		if (grid[playerX][playerY] == player[direction]) {
			if (check_wall(direction, playerX, playerY)) {
				int x = playerX,
				    y = playerY;

				playerX += moveY[direction];
				playerY += moveX[direction];

				if (grid[playerX][playerY] == 'M') {
					grid[x][y] = aux;
					grid[playerX][playerY] = player[direction];
					score -= 200; //-200 points for being in a cell with the monster
				}
				else
					if (grid[playerX][playerY] == 'T') {
						grid[x][y] = aux;
						grid[playerX][playerY] = player[direction];
						score += 100; //+100 points if treasure found
					}
					else {
						aux = grid[playerX][playerY];
						grid[playerX][playerY] = grid[x][y];
						grid[x][y] = aux;
						score--; //-1 point for moving in another cell
					}
			}
		}
		else {
			grid[playerX][playerY] = player[direction];
			score--; //-1 point for moving in the same cell
		}
	}
}

// Initialize the game and run the main game loop
int main() {
	draw_board();

	while (running) {
		sw = _getch();
		move();
		system("cls");
		draw_board();
	}

	return 0;
}
