#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG

#include <iomanip>

int turn = 0;
int wallCnt = 0;

typedef struct _point {
	int x;
	int y;
} POINT;

typedef struct _wallinfo {
	POINT point;
	string ori;
} WALLINFO;

typedef struct _playerinfo {
	POINT point[100];
	int wallsLeft;
} PLAYERINFO;

PLAYERINFO me;
PLAYERINFO enemy;
WALLINFO wallinfo[20];

void moveLeft();
void moveRight();
void moveUp();
void moveDown();
void buildWall(int x, int, y, string ori);

char map[18][18];

void initMap();
void printMap();

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	int w; // width of the board
	int h; // height of the board
	int playerCount; // number of players (2 or 3)
	int myId; // id of my player (0 = 1st player, 1 = 2nd player, ...)

	cin >> w >> h >> playerCount >> myId; cin.ignore();

	// game loop
	while (1) {
		for (int player = 0; player < playerCount; player++) {
			int x; // x-coordinate of the player
			int y; // y-coordinate of the player
			int wallsLeft; // number of walls available for the player
			cin >> x >> y >> wallsLeft; cin.ignore();
			cerr << "[DEBUG]:" << "player[" << ((player==0)?"me":"en") << "] (" << x << "," << y << "):" << wallsLeft << endl;
			if (player == 0) {
#ifdef DEBUG
				if (turn == 0) {
#endif
					me.point[turn].x = x;
					me.point[turn].y = y;
					me.wallsLeft = wallsLeft;
#ifdef DEBUG
				}
#endif
			}
			else {
				enemy.point[turn].x = x;
				enemy.point[turn].y = y;
				enemy.wallsLeft = wallsLeft;
			}
		}
		int wallCount; // number of walls on the board
		cin >> wallCount; cin.ignore();
		for (int i = 0; i < wallCount; i++) {
			int wallX; // x-coordinate of the wall
			int wallY; // y-coordinate of the wall
			string wallOrientation; // wall orientation ('H' or 'V')
			cin >> wallX >> wallY >> wallOrientation; cin.ignore();
			wallinfo[i].point.x = wallX;
			wallinfo[i].point.y = wallY;
			wallinfo[i].ori = wallOrientation;
			wallCnt = wallCount;
			cerr << "[DEBUG]:" << "wall[" << i << "] (" << wallX << "," << wallY << "):" << wallOrientation << endl;
		}

#ifdef DEBUG
		if (me.point[turn].x == 8 || enemy.point[turn].x == 0) {
			break;
		}
		else {
#endif
			turn++;
#ifdef DEBUG
		}
#endif

#ifdef DEBUG
		if (turn > 1) {
#endif
		moveRight(); // action: LEFT, RIGHT, UP, DOWN or "putX putY putOrientation" to place a wall
#ifdef DEBUG
		}
#endif
	}

#ifdef DEBUG
	initMap();
	printMap();
#endif
	return 0;
}

void moveLeft() {
#ifdef DEBUG
	me.point[turn].x = me.point[turn-1].x - 1;
#endif
	cout << "LEFT" << endl;
}
void moveRight() {
#ifdef DEBUG
	me.point[turn].x = me.point[turn-1].x + 1;
#endif
	cout << "RIGHT" << endl;
}
void moveUp() {
#ifdef DEBUG
	me.point[turn].y = me.point[turn-1].y - 1;
#endif
	cout << "UP" << endl;
}
void moveDown() {
#ifdef DEBUG
	me.point[turn].y = me.point[turn-1].y + 1;
#endif
	cout << "DOWN" << endl;
}

void buildWall(int x, int y, string ori) {
#ifdef DEBUG
#endif
	cout << x << ' ' << y << ' ' << ori << endl;
}

void initMap() {
	for (int row = 0; row < 18; row++) {
		for (int col = 0; col < 18; col++) {
			map[row][col] = '.';
		}
	}
}

void printMap() {
	int x = 0;
	int y = 0;
	int i = 0;

	// fill wall
	for (i = 0; i < wallCnt; i++) {
		x = wallinfo[i].point.x * 2;
		y = wallinfo[i].point.y * 2;
		map[y][x] = '+';
		if (wallinfo[i].ori == "H") {
			map[y][x+2] = '+';
		}
		else {
			map[y+2][x] = '+';
		}
	}
	// fill player
	for (i = 0; i < turn+1; i++) {
		x = me.point[i].x * 2 + 1;
		y = me.point[i].y * 2 + 1;
		map[y][x] = 'M';
		x = enemy.point[i].x * 2 + 1;
		y = enemy.point[i].y * 2 + 1;
		map[y][x] = 'E';
	}
	cout << "   ";
	for (int i = 0; i < 9; i++) {
		cout << i << ' ' << i << ' ';
	}
	cout << endl;
	// print map
	for (int row = 0; row < 18; row++) {
		cout << setw(2) << (row / 2) << ' ';
		for (int col = 0; col < 18; col++) {
			cout << map[row][col] << ' ';
		}
		cout << endl;
	}
}