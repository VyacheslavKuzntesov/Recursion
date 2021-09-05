#include <iostream>

using namespace std;

#define tab "\t"
long long int factorial(long long int n);
double Power(double a, int n);
void Fibonacci(int n/*, int a = 0, int b = 1*/);

void main()
{
	setlocale(LC_ALL, "Rus");
	/*int n;
	cout << "¬ведите число дл€ вычислени€ факториала: "; cin >> n;
	cout << n << "! = " << factorial(n) << endl;*/

	/*int a;
	int n;
	cout << "¬ведите основание и показатель степени: "; cin >> a >> n;
	cout << Power(a, n) << endl;*/

	int n;
	cout << "ƒо какого предельного значени€ нужно вывести р€д фибоначи: "; cin >> n;
	Fibonacci(n);
	cout << endl;
}

long long int factorial(long long int n)
{
	//if (n == 0)return 1;
	//return n * factorial(n - 1);

	return (n == 0) ? 1 : n * factorial(n - 1);
}

double Power(double a, int n)
{
	/*if (n == 0)return 1;
	if (n < 0) 
	{
		double N = 1 / a * Power(a, n + 1);
		return N;
	}
	else
	{
		int N = a * Power(a, n - 1);
		return N;
	}*/

	return n == 0 ? 1 : n > 0 ? a * Power(a, n - 1) : 1 / a * Power(a, n + 1);
}

void Fibonacci(int n/*, int a, int b*/)
{
	static int a = 0, b = 1, c = 1;
	if (a > n)return;
	cout << a << tab;

	/*Fibonacci(n, b, a + b);
	a = b;
	b = c;
	c = a + b;*/

	c = (a = b) + (b = c);
	Fibonacci(n);
}

