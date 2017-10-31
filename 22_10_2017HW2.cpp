//Напишите программу проверяющую является ли число составным. В программе гарантируется, что число - натуральное.
//ДОМАШНЯЯ РАБОТА 22.10

#include <iostream>
#include <math.h>

using namespace std;

int main() 
{
	int k, i;
	cin >> k;
	double l = sqrt(k);
	l = round(l*10)/10;
	int p = 0;
	for (i = 2, i < l, i++ ) {
		if (k % i == 0) {
			p = 1;
		} 
	}
	if (p == 1) {
		cout << "Not prime";
	} else {
		cout << "Prime";
	}
	return 0;
}
