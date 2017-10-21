//Написать программу, вычисляющую среднее арифметическое нечётных чисел среди всех введённых.
#include <iostream>

using namespace std;

int main()
{
	int i, k, cnt, sum;
	cin >> k;
	cnt = 0;
	sum = 0;
	if (k % 2 != 0) {
		cnt = cnt + 1;
		sum = sum + k;
	}
	while (k != 0) {
		cin >> k;
		if (k % 2 != 0) {
			cnt = cnt + 1;
			sum = sum + k;
		}
	}
	double l;
	l = sum / cnt;
	cout << l;
	

}
