// Project_4.cpp: определяет точку входа для консольного приложения.
/*
    Ковряков, 5 группа, задача 4.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Pair {
	int p_high;
	int p_low;
};
int input_variable();
int input_variable(int N);
bool found_sequence(int *Sequence, Pair *List_pair, int M, int N);

int main()
{
	setlocale(LC_ALL, "rus");
	bool check_repeat;
	do
	{
		int N, M;
		N = input_variable();
		M = input_variable();
		Pair *List_pair = new Pair[M];
		for (int i = 0; i < M; i++)
		{
			
			List_pair[i].p_high = input_variable(N);
			List_pair[i].p_low = input_variable(N);
		}
		int *Sequence = new int[N];
		bool check = found_sequence(Sequence, List_pair, M, N);
		if (check)
		{
			cout << "Yes" << endl;
			for (int i = 0; i < N; i++)
				cout << Sequence[i] << " ";
			cout << endl;
		}
		else
			cout << "No" << endl;
		cout << "Введите 1 для повторного запуска программы" << endl;
		cin >> check_repeat;
	} while (check_repeat == 1);
    return 0;
}
int input_variable() //функция коректно вводит переменные типа int
{
	int variable_cin;
	cin >> variable_cin;
	if (cin.fail() || variable_cin <= 0)
		while (cin.fail() || variable_cin <= 0)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Вы ввели некоректное значение, введите его значение повторно" << endl;
			cin >> variable_cin;
		}
	cin.clear();
	return(variable_cin);
}
int input_variable(int N)
{
	int variable_cin;
	cin >> variable_cin;
	if (cin.fail() || variable_cin <= 0 || variable_cin>N)
		while (cin.fail() || variable_cin <= 0 || variable_cin>N)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Вы ввели некоректное значение, введите его значение повторно" << endl;
			cin >> variable_cin;
		}
	cin.clear();
	return(variable_cin);
}
bool found_sequence(int *Sequence, Pair *List_pair, int M, int N)
{
	for (int j = 0; j < M; j++)
	{
		Sequence[0] = List_pair[j].p_high;
		Sequence[1] = List_pair[j].p_low;
		for (int i = 1; i < N; i++)
			for (int j1 = 0; j1 < M; j1++)
				if (Sequence[i] == List_pair[j1].p_high)
				{
					if (i != N - 1)
						Sequence[i + 1] = List_pair[j1].p_low;
					else
						Sequence[0] = List_pair[j1].p_high;
					j1 = M + 1;
				}
		bool check = false;
		for (int i = 0; i < N; i++)
			for (int i1 = 0; i < N; i++)
				if ((i != i1 && Sequence[i] == Sequence[i1]) || Sequence[i] <= 0)
					check = true;
		if (!check)
			return true;
		else
			for (int i = 0; i < N; i++)
				Sequence[i] = 0;
	}

	return false;
}
