#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void clear();
void gotoxy(int x, int y);
void intro();
void game_system_select();
void game_system_drop(int b);

int move = 1;
int start;
int end ;
int board[21][10];

int main() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = 0;
		}
	}
	for (int i = 0; i < 10; i++) {
		board[20][i] = -1;

	}
	game_system_select();
	while (1) {
		
		game_system_drop(move);
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == 0) {
					printf("# ");
				}
				else if (board[i][j] == 1) {
					printf("Q ");
				}
				else if (board[i][j] == 2) {
					printf("@ ");
				}
			}
			printf("\n");

		}
	}
	while (1) {
		
		
	}
		
	

}

void clear() {
	system("cls");
}

void gotoxy(int x, int y) {
	x--;
	y--;
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void game_system_select() {
	srand((unsigned)time(NULL));
	int num = rand() % 1;
	if (num == 0) {
		board[0][2] = 2;
		board[0][3] = 2;
		board[0][4] = 2;
		board[0][5] = 2;
	}
}
void game_system_drop() {
	for (int i = 19; i > -1; i--) {
		for (int j = 9; j > -1; j--) {
			if (board[i][j] > 1) {
				if (board[i + 1][j] == 0) {
					board[i + 1][j] = board[i][j];
					board[i][j] = 0;

				}
				else {
					for (int x = i; x > -1; x--) {
						for (int y = j; y > -1; y--) {
							board[i + 1][j] = board[i][j];
							board[i][j] = 0;
						}
					}

				}
			}
		}
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 0) {
				printf("#  ");
			}
			else if (board[i][j] == 1) {
				printf("@  ");
			}
			else {
				printf("Q  ");
			}
		}
		printf("\n\n");

	}
	start = clock();
	while (1) {
		end = clock();
		if (end - start == 1000) {
			break;
		}
		else if (kbhit()) {
			scanf("%d", &move);	
			break;
		}


	}
	clear();
}
