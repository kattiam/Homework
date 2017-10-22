//Напишите программу проверяющую N чисел на четность. В программе гарантируется, что все числа целые и их не менее одного.
//ДОМАШНЯЯ РАБОТА 22.10

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n, i++)
	{
		int k;
		cin >> k;
		if (k % 2 == 0) {
			cout << "Even";
		} else {
			cout << "Odd";
		}
	}
	return 0;
}
