// Project_4.cpp: определяет точку входа для консольного приложения.
/*
    Ковряков, 5 группа, задача 4.
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

int input_variable();
int input_variable(int N);
bool found_sequence(int *Sequence, bool **graph, int M, int N);

int main()
{
	setlocale(LC_ALL, "rus");
	bool check_repeat;
	do
	{
		int N, M;
		N = input_variable();
		M = input_variable();
		bool **graph = new bool*[N];
		for (int i = 0; i < M; i++)
			*(graph + i) = new bool[N];
		for (int i = 0; i < M; i++)
		{
			int i1, j1;
			i1 = input_variable(N);
			j1 = input_variable(N);
			graph[i1 - 1][j1 - 1] = true;
		}
		int *Sequence = new int[N];
		bool check_rez = found_sequence(Sequence, graph, M, N);
		if (check_rez == true)
		{
			cout << "Yes" << endl;
			for (int i = 0; i < N; i++)
				cout << Sequence[i]+1 << " ";
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
bool found_sequence(int *Sequence, bool **graph, int M, int N)
{
	int count_people = -1;
	for (int i = 0; i < N; i++)
	{
		int i_del = -1;
		for (int k = 0; k <= count_people; k++)
			if (Sequence[k] == i)
				i_del = k;
		if (i_del == -1)
		{
			count_people++;
			Sequence[count_people] = i;
		}
		for (int j = 0; j < N; j++)
			if (graph[i][j] == true)
			{
				if (i_del != -1)
					for (int i1 = i_del; i1 < count_people; i++)
						Sequence[i1] = Sequence[i1 - 1];
				int j_new = -1;
				for (int k = 0; k <= count_people; k++)
					if (Sequence[k] == j)
						j_new = k;
				if (j_new == -1)
				{
					for (int j1 = count_people; j1 > j; j1--)
						Sequence[j1] = Sequence[j1 - 1];
					Sequence[j] = i;
				}
				else
				{
					count_people++;
					Sequence[count_people] = j;
				}
			}


	}
	if (count_people == N - 1)
		return true;
	else
		false;
}
