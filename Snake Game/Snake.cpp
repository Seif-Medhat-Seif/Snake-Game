#include <iostream>
#include <conio.h>   // _getch()
#include <windows.h> // Sleep()
#include <cstdlib>   // rand()
#include <ctime>     // time(0)

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;
class Snake
{
	int X, Y, fruitX, fruitY, lastX, lastY, score;
	int End_Right = 82, End_Left = 1, End_Up = 1, End_Down = 22;
	int snakeX[100], snakeY[100];
	char fruit;
	string snake;
public:
	Snake()
	{
		X = 5; // Start Game X
		Y = 7; // Start Game Y
		lastX = lastY = score = 0;
		fruitX = fruitY = 0;
		fruit = '%';
		snake = "@**";
		snakeX[0] = X;
		snakeX[1] = X - 1;
		snakeX[2] = X - 2;
		snakeY[0] = Y;
		snakeY[1] = Y;
		snakeY[2] = Y;
	}

	void Game_Over()
	{
		cout << "\033[" << 10 << ";" << 37 << "H" << "Game Over!";
		cout << "\033[24;1H";
		exit(0);
	}

	void Board()
	{
		cout << " ";
		for (int x = 0; x < 80; ++x)
			cout << "#";
		cout << endl;

		for (int i = 0; i < 20; ++i)
		{
			cout << "#";
			for (int x = 0; x < 80; ++x)
				cout << " ";
			cout << "#\n";
		}

		cout << " ";
		for (int x = 0; x < 80; ++x)
			cout << "#";
		cout << endl << "SCORE : " << score << endl;

		Showfruit();
		Right();
	}

	void ShowScore()
	{
		score += 10;
		// Move cursor to the last line
		cout << "\033[23;1H";  // Move to the 23rd line, 1st column (adjust if your console has more lines)
		cout << "SCORE : " << score << "     ";  // Update the score and clear any trailing characters

		// Move cursor back to where the snake is
		cout << "\033[" << Y << ";" << X << "H";

	}

	void Movement()
	{
		for (int i = snake.size() - 1; i > 0; --i)
		{
			snakeX[i] = snakeX[i - 1];
			snakeY[i] = snakeY[i - 1];
		}
		snakeX[0] = X;
		snakeY[0] = Y;
		
		for (int i = 0; i < snake.size(); ++i)
			cout << "\033[" << snakeY[i] << ";" << snakeX[i] << "H" << snake[i]; // Print

		lastX = snakeX[snake.size() - 1];
		lastY = snakeY[snake.size() - 1];

		if (fruitX == X && fruitY == Y)
		{
			ShowScore();
			Showfruit();
		}

		if (X == End_Right || X == End_Left || Y == End_Up || Y == End_Down)
			Game_Over();

		Sleep(100);
		cout << "\033[" << lastY << ";" << lastX << "H" << ' ';     // Delete
	}

	void Right()
	{
		for (; X <= End_Right; ++X)
		{
			Movement();

			if (_kbhit())
			{
				char c = _getch();
				if (c == 'w' || c == 's' || c == KEY_UP || c == KEY_DOWN)
					Input(c);
			}
		}
	}

	void Up()
	{
		for (; Y >= End_Up; --Y)
		{
			Movement();

			if (_kbhit())
			{
				char c = _getch();
				if (c == 'd' || c == 'a' || c == KEY_RIGHT || c == KEY_LEFT)
					Input(c);
			}
		}
	}

	void Left()
	{
		for (; X >= End_Left; --X)
		{
			Movement();

			if (_kbhit())
			{
				char c = _getch();
				if (c == 'w' || c == 's' || c == KEY_UP || c == KEY_DOWN)
					Input(c);
			}
		}
	}

	void Down()
	{
		for (; Y <= End_Down; ++Y)
		{
			Movement();

			if (_kbhit())
			{
				char c = _getch();
				if (c == 'd' || c == 'a' || c == KEY_RIGHT || c == KEY_LEFT)
					Input(c);
			}
		}
	}

	void Showfruit()
	{
		bool issnake = 0;
		srand(time(0));
		fruitY = rand() % (18 - 2 + 1) + 2;
		fruitX = rand() % (78 - 2 + 1) + 2;

		for (int i = 0; i < snake.size(); ++i) // because fruit don't be overwritten by snake
		{
			if (fruitX == snakeX[i] && fruitY == snakeY[i])
				issnake = 1;
		}

		if (!issnake)
			cout << "\033[" << fruitY << ";" << fruitX << "H" << fruit;
		else
			Showfruit();

		if ((score / 2) % 2 == 0 && score != 0)
			snake.insert(snake.size() - 1, "*");
	}

	void Input(char ch)
	{
		switch (ch)
		{
		case 'a':
		case KEY_LEFT:
			X--;
			Left();
			break;

		case 'w':
		case KEY_UP:
			Y--;
			Up();
			break;

		case 'd':
		case KEY_RIGHT:
			X++;
			Right();
			break;

		case 's':
		case KEY_DOWN:
			Y++;
			Down();
			break;

		case 'p':

			exit(0);
			break;

		default:

			Input(ch);
			break;
		}
	}

};

void hideCursor() // To hide the cursor sign '_' that taking input on the console
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Game_Start()
{
	cout << "\n W ---> Move Up\n";
	cout << " S ---> Move Down\n";
	cout << " D ---> Move Right\n";
	cout << " A ---> Move Left\n\n";

	cout << " THE GAME WILL START AFTER : ";
	for (int i = 5; i >= 1; --i)
	{
		cout << "\033[" << 7 << ";" << 35 << "H" << i;
		Sleep(1500);
		cout << "\033[" << 7 << ";" << 35 << "H" << ' ';
	}

	cout << "\033[2K";
	cout << "\033[G";
	Sleep(500);

	cout << "LET'S G";
	for (int i = 0; i < 20; ++i)
	{
		Sleep(50);
		cout << "O";
	}
	cout << "!";
	Sleep(500);
}

int main()
{
	hideCursor();
	Game_Start();
	system("CLS");
	Snake s;
	s.Board();
}