#include <iostream>
//#include <iomanip> //for setw;
#include <windows.h> //for Sleep();
#include <random>

using namespace std;
const int size1 = 6, size2 = 6, size3 = 6;

void new_array(int* p, int size)
{
	int* p_end = p + size * size - 1;
	for (int* i = p; i <= p_end; i++)
		*i = rand() % 99;
}

void fillZero(int* p, int size)
{
	int* p_end = p + size * size - 1;
	for (int* i = p; i <= p_end; i++)
		*i = 0;
}

void printArray(int* p, int size) 
{
	int* p_end = p + size * size - 1;
	for (int* i = p; i <= p_end; i++) {
		cout << "[" << (*i < 10 ? " " : "") << *i << "]";
		if ((i - p) % size == (size - 1))
			cout << '\n';
		else
			cout << ' ';
	}
}

void fillSnailMethod(int* p, int size) 
{
	fillZero(p, size);
	printArray(p, size);
	Sleep(100);
	for (int param = 0; param < size / 2; param++)
	{
		int* p1 = p + param * (size + 1);
		int* p2 = p + (param + 1) * (size - 1);
		int* p3 = p + size * size - 1 - param * (size + 1);
		int* p4 = p + size * (size - 1) - param * (size - 1);
		for (int* i = p1; i < p2; i++)
		{
			*i = rand() % 99;
			system("cls");
			printArray(p, size);
			Sleep(100);
		}
		for (int* i = p2; i < p3; i += size)
		{
			*i = rand() % 99;
			system("cls");
			printArray(p, size);
			Sleep(100);
		}
		for (int* i = p3; i > p4; i--)
		{
			*i = rand() % 99;
			system("cls");
			printArray(p, size);
			Sleep(100);
		}
		for (int* i = p4; i > p1; i -= size)
		{
			*i = rand() % 99;
			system("cls");
			printArray(p, size);
			Sleep(100);
		}
	}
}
void fillSnakeMethod(int* p, int size)
{
	fillZero(p, size);
	printArray(p, size);
	Sleep(100);
	for (int i = 0; i < size / 2; i++)
	{
		int* p1 = p + i * 2;
		int* p2 = p + size * (size - 1) + i * 2;
		for (int* i = p1; i <= p2; i += size)
		{
			*i = rand() % 99;
			system("cls");
			printArray(p, size);
			Sleep(100);
		}
		for (int* i = p2 + 1; i >= p1 + 1; i -= size)
		{
			*i = rand() % 99;
			system("cls");
			printArray(p, size);
			Sleep(100);
		}
	}
}
void Changeblocksclockwise(int* p, int size) 
{
	int tmp;
	cout << "Initial array:\n";
	printArray(p, size);
	cout << "\n\n";
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			int* p1 = p + i * size + j;
			int* p2 = p + size / 2 + i * size + j;
			int* p3 = p1 + (size / 2) * size;
			int* p4 = p2 + (size / 2) * size;
			tmp = *p1;
			*p1 = *p3;
			*p3 = *p4;
			*p4 = *p2;
			*p2 = tmp;
		}
	}

	cout << "\n\nNew Array:\n";
	printArray(p, size);
}

void Changingblocksdiagonally(int* p, int size) 
{
	cout << "Initial array:\n";
	printArray(p, size);
	cout << "\n\n";
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			int* p1 = p + i * size + j;
			int* p2 = p + size / 2 + i * size + j;
			int* p3 = p1 + (size / 2) * size;
			int* p4 = p2 + (size / 2) * size;
			swap(*p1, *p4);
			swap(*p2, *p3);

		}
	}

	cout << "\n\nNew Array:\n";
	printArray(p, size);

}



void  Changingblocksvertically(int* p, int size) 
{
	cout << "Initial array:\n";
	printArray(p, size);
	cout << "\n\n";
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			int* p1 = p + i * size + j;
			int* p2 = p + size / 2 + i * size + j;
			int* p3 = p1 + (size / 2) * size;
			int* p4 = p2 + (size / 2) * size;
			swap(*p1, *p3);
			swap(*p2, *p4);

		}
	}

	cout << "\n\nNew Array:\n";
	printArray(p, size);

}

void  Changingblockshorizontally(int* p, int size)
{
	cout << "Initial array:\n";
	printArray(p, size);
	cout << "\n\n";
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			int* p1 = p + i * size + j;
			int* p2 = p + size / 2 + i * size + j;
			int* p3 = p1 + (size / 2) * size;
			int* p4 = p2 + (size / 2) * size;
			swap(*p1, *p2);
			swap(*p3, *p4);

		}
	}

	cout << "\n\nNew Array:\n";
	printArray(p, size);
}


void shakerSort(int* p, int size)
{
	int* first = p, * last = p + size * size - 1;
	while (first < last)
	{
		for (int* f_i = first; f_i < last; f_i++)
		{
			if (*f_i > *(f_i + 1))
				swap(*f_i, *(f_i + 1));
		}
		last--;
		for (int* f_i = last; f_i > first; f_i--)
		{
			if (*(f_i - 1) > *f_i)
				swap(*f_i, *(f_i - 1));
		}
		first++;
	}
}

void add(int* p, int size, int number) 
{
	int* p_end = p + size * size - 1;
	for (int* i = p; i <= p_end; i++)
		*i += number;
}
void sub(int* p, int size, int number) 
{
	int* p_end = p + size * size - 1;
	for (int* i = p; i <= p_end; i++)
		*i -= number;
}
void mult(int* p, int size, int number)
{
	int* p_end = p + size * size - 1;
	for (int* i = p; i <= p_end; i++)
		*i *= number;
}
void div(int* p, int size, int number) 
{
	int* p_end = p + size * size - 1;
	for (int* i = p; i <= p_end; i++)
		*i /= number;
}
void  Matrixcalculus(int* p, int size) 
{
	int number, punktchoice;
	cout << "Enter the value with which the mathematical operations will be performed >>> ";
	cin >> number;
	cout << "\nWhich operation do you want to perform? Choose the number\n"
		<< "1 - Addition\n"
		<< "2 - Subtraction\n"
		<< "3 - Multiplication\n"
		<< "4 - Division\n"
		<< "0 - Exit in menu\n\n";
	cin >> punktchoice;
	cout << '\n';
	switch (punktchoice)
	{
	case 1:
		add(p, size, number);
		printArray(p, size);
		break;
	case 2:
		sub(p, size, number);
		printArray(p, size);
		break;
	case 3:
		mult(p, size, number);
		printArray(p, size);
		break;
	case 4:
		div(p, size, number);
		printArray(p, size);
		break;
	case 0:
		break;
	default:
		cout << "Error! Repeat, please, choose correct operation from 1 to 4";
		Matrixcalculus(p, size);
		break;
	}
}


void IDZ(int* p, int size) 
{
	cout << "Matrix transposition #IDZ9\n"
		<< "Initial matrix:\n";
	printArray(p, size);
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = size - 1 - i; j >= 1; j--) 
		{
			swap(*(p + i * size + j + i), *(p + (j + i) * size + i));
			cout << "\n";
			printArray(p, size);
		}
	}
}
void menu(int* p, int size)
{
	int choice;
	system("cls");
	cout << "What operation do you want to perform? Enter a number from 1 to 8:\n"
		<< "1 - Fill the matrix using the snail method\n"
		<< "2 - Fill matrix using the snake method\n"
		<< "3 - Changing matrix blocks clockwise\n"
		<< "4 - Changing matrix blocks diagonally\n"
		<< "5 - Changing matrix blocks vertically\n"
		<< "6 - Changing matrix blocks horizontally\n"
		<< "7 - Sort matrix\n"
		<< "8 - Matrix calculus\n"
		<< "9 - IDZ\n"
		<< "0 - Exit\n"
		<< ">>> ";
	cin >> choice;
	switch (choice)
	{
	case 0:
		break;
	case 1:
		system("cls");
		fillSnailMethod(p, size);
		system("Pause");
		system("cls");
		menu(p, size);
		break;
	case 2:
		system("cls");
		fillSnakeMethod(p, size);
		system("Pause");
		system("cls");
		menu(p, size);
		break;
	case 3:
		system("cls");
		new_array(p, size);
		Changeblocksclockwise(p, size);
		system("Pause");
		system("cls");
		menu(p, size);
		break;
	case 4:
		system("cls");
		new_array(p, size);
		Changingblocksdiagonally(p, size);
		system("Pause");
		system("cls");
		menu(p, size);
		break;
	case 5:
		system("cls");
		new_array(p, size);
		Changingblocksvertically(p, size);
		system("Pause");
		system("cls");
		menu(p, size);
		break;
	case 6:
		system("cls");
		new_array(p, size);
		Changingblockshorizontally(p, size);
		system("Pause");
		system("cls");
		menu(p, size);
		break;
	case 7:
		system("cls");
		new_array(p, size);
		shakerSort(p, size);
		printArray(p, size);
		system("Pause");
		system("cls");
		menu(p, size);
		break;
	case 8:
		system("cls");
		new_array(p, size);
		printArray(p, size);
		Matrixcalculus(p, size);
		system("Pause");
		system("cls");
		menu(p, size);

		break;
	case 9:
		system("cls");
		new_array(p, size);
		IDZ(p, size);
		system("Pause");
		system("cls");
		menu(p, size);
		break;

	default:
		cout << "Error! Please and enter a permissible operation from 1 to 8";
		system("Pause");
		break;
	}
}

int main()
{
	int size, arr6[size1][size1], arr8[size2][size2], arr10[size3][size3];
	int* p = NULL;
	cout << "Hello, please enter the size of a two-dimensional array (6, 8, 10) >>> ";
	cin >> size;
	switch (size) 
	{
	case 6:
		p = *arr6;
		menu(p, size);
		break;
	case 8:
		p = *arr8;
		menu(p, size);
		break;
	case 10:
		p = *arr10;
		menu(p, size);
		break;
	default:
		cout << "Error! Please and enter a permissible size of a two-dimensional array (6, 8, 10)";
		system("Pause");
		break;
	}

}
