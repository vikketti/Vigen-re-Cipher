//Vigenère Cipher
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	// вводим переменные: А - используемый алфавит 
	// В - исходное слово, С - ключ, D - ключ по длине исх. слова
	string A = "abcdefghijklmnopqrstuvwxyz";
	string B, C, D = "";
	setlocale(LC_ALL, "Rus");
	cout << "Нужно ввести исходное слово и ключ, используя буквы английского алфавита. \n";
	cout << "Введите слово:";
    cin >> B;
	cout << "Введите ключ:";
	cin >> C;
	int c = C.size();
	int b = B.size();
	int* F = new int[B.size()];
	int* G = new int[B.size()];
	// 1) ищем D, когда ключ короче, чем исходное слово или такое же по длине
	// растягиваем ключ по длине слова
	if (b >= c)
	{
		for (int i = 0; i < (b / c); i++)
		{
			D = D + C;
		}
		for (int j = 0; j < (b % c); j++)
		{
			D = D + C[j];
		}
	}
	// 2) ищем D, когда ключ длинее, чем исходное слово
	// сокращаем ключ до длины слова
	else
	{
		for (int s = 0; s < b; s++)
		{
			D = D + C[s];
		}
	}
	cout << D << endl; // выводим слово нужного размера состоящее из слова-ключа

	// шифрование(замена) символов 
	for (int k = 0; k < b; k++)
	{
		for (int n = 0; n < 26; n++)
		{
			if (B[k] == A[n])
			{
				F[k] = n;
			}
			if (D[k] == A[n])
			{
				G[k] = n;
			}
		}
	}

	int e = 0; //необходимо для того, чтобы по достижению 26 символа, программа начала с первого
	for (int u = 0; u < b; u++)
	{
		e = ((F[u] + G[u]) % 26);
		B[u] = A[e];
	}

	cout << "Ваше зашифрованное слово:" << B << endl;

	return 0;
}
	