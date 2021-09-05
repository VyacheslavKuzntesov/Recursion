#include<iostream>
using namespace std;

const char* menu[] =
{
	" 1. Factorial;",
	" 2. Power;",
	" 3. Fibonacci;",
};

int Menu()
{
	int selected = 0;
	for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++)cout << menu[i] << endl;
}

void main()
{
	setlocale(LC_ALL, "RUS");

}