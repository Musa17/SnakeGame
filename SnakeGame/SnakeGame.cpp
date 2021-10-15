// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
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

			else
				cout << " ";

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
