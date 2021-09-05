#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

#define VERTICAL_OFFSET		"\n\n\n\n\n\n"
#define HORIZONTAL_OFFSET	"\t\t\t\t\t\t"

void InitField(char field[], const unsigned int n);
void PrintField(char field[], const unsigned int n, char player);
void Move(char field[], const unsigned int n, char player);
void Check(char field[], const unsigned int n, char player);

void main()
{
	setlocale(LC_ALL, "Rus");
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/*COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);*/
	const unsigned int n = 9;//размер игрового поля
	char field[n] = {};//игровое поле
	InitField(field, n);
	PrintField(field, n,'0');
	cout << "Еще разочек? :-)\nДля выхода нажмите Escape, для продолжения нажмите любую клавишу.";
	if (_getch() != 27)main();
}

void InitField(char field[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		field[i] = ' ';
	}
}

void PrintField(char field[], const unsigned int n, char player)
{
	system("cls");
	cout << VERTICAL_OFFSET;
	for (int i = 6; i >= 0; i -= 3)
	{
		cout << HORIZONTAL_OFFSET;
		cout << " ";
		for (int j = 0; j < 3; j++)
		{
			cout << field[i + j];
			if (j < 2)cout << " | ";
		}
		cout << endl;
		cout << HORIZONTAL_OFFSET;
		if(i>0)cout << "--- --- ---" << endl;
	}
	Check(field, n,player);
}

void Move(char field[], const unsigned int n, char player)
{
	char key;
	bool busy;
	do
	{
		busy = false;
		do
		{
			key = _getch();
			if (key == 27)return;
			if (key < '1' || key > '9')cout << "Вы вышли за пределы игрового поля" << endl;
		} while (key < '1' || key > '9');
		if (field[key - '1'] == ' ')field[key - '1'] = player;
		else
		{
			busy = true;
			cout << endl << "Клетка уже занята!" << endl;
		}
	} while (busy);
	PrintField(field, n, player);
}

void Check(char field[], const unsigned int n, char player)
{
	bool game_over = false;

	//1 Diagonal check:
	if (field[0] == field[4] && field[0] == field[8] && field[0] != ' ')game_over = true;
	if (field[2] == field[4] && field[2] == field[6] && field[2] != ' ')game_over = true;

	//2 Horizontal check:
	for (int i = 0; i <=6; i+=3)
	{
		if (field[i] == field[i + 1] && field[i] == field[i + 2] && field[i] != ' ')game_over = true;
	}

	//3 Vertical check:	
	for (int i = 0; i < 3; i++)
	{
		if (field[i] == field[i + 3] && field[i] == field[i + 6] && field[i] != ' ')game_over = true;
	}

	if (game_over)
	{
		cout << player << " победил!\n";
		return;
	}

	bool draw = true;
	for (int i = 0; i < 9; i++)
	{
		if (field[i] == ' ')
		{
			draw = false;
			break;
		}
	}

	if (draw)
	{
		cout << "Ничья" << endl;
		return;
	}

	if (player == 'X')Move(field, n, '0');
	else Move(field, n, 'X');
}