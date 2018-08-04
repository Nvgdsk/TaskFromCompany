// ConsoleApplication13.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void getsimplenumbers(vector listnumber)
{
	bool simple;
	
	for (int i = 10001; i <= 99999; i = i + 2)
	{
		if (i % 2 == 0 || i % 5 == 0)
		{
			continue;
		}
		simple = true;
		for (int j = 2; j < sqrt(i) + 1; j++)
		{
			if (i % j == 0)
			{
				simple = !simple;
				break;
			}
		}
		if (simple)
		{
			listnumber.push_back(i);
		}
	}
}
void getresultpolindom(int num1, int num2, unsigned long long int max, vector listnumber)
{
	string word;
	bool polindrom;
	unsigned long long int result;
	for (int i = listnumber.size() - 1; i > 0; i--)
	{

		for (int j = i - 1; j >= 0; j--)
		{

			result = (unsigned long long int)listnumber[j] * listnumber[i];
			if (result < max)
			{
				continue;
			}
			word = to_string(result);
			polindrom = true;
			for (int z = 0; z < word.length() / 2; z++)
			{
				if (word[z] == word[word.length() - 1 - z])
				{

					continue;
				}
				else {

					polindrom = false;
					break;
				}

			}
			if (polindrom)// если число полиндром
			{

				max = result;
				num1 = myVector[i];
				num2 = myVector[j];
				//cout << max << endl;


			}
		}
	}
}
int main()
{
	vector <int> listnumber;
	getsimplenumbers(&listnumber);
	unsigned long long int max = 0;
	int num1, num2;
	getresultpolindom(&num1, &num2, &max, listnumber);
	cout << "Result: "<< max << "; First number - " << num1 << "; Second number - " << num2 << endl;
	std::system("PAUSE");
    return 0;
	
}

