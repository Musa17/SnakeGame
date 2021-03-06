// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;

// Size of the field
const int width = 20;
const int height = 20;

// Position of player and fruit
int x, y, fruitX, fruitY, score;

// Tail
int tailX[100], tailY[100];
int nTail;

// Direction
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

void Setup()
{
	gameOver = false;

	// Setting player's start direction and position
	dir = STOP;
	x = width / 2;
	y = height / 2;

	// Setting fruit's start position
	fruitX = rand() % width;
	fruitY = rand() % height;

	score = 0;
}

void Draw()
{
	system("cls");

	// Making Top Border
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			// Making Left Border
			if (j == 0)
				cout << "#";

			if (i == y && j == x)
				cout << "O";

			else if (i == fruitY && j == fruitX)
			{
				cout << "F";
			}

			// Drawing tail
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}

				if (!print)
					cout << " ";
			}

			// Making Right Border
			if (j == (width - 1))
				cout << "#";
		}

		cout << endl;
	}


	// Making Bottom Border
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	cout << "Score:" << score << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;

	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	// Basic movement
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	// Game Over when player's head touch borders
	//if (x > width || x < 0 || y > height || y < 0)
	//  gameOver = true;

	// When player's head hit borders, player continue moving in same direction
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	// Game Over when player eat himself
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;

	// Eating fruit
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
