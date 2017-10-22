//Вычислить произведение двух чисел, не используя операцию умножения.

//ДОМАШНЯЯ РАБОТА 22.10

#include <iostream>

using namespace std;

int main() {
  int a, b, i;
  cin >> a >> b;
  for (i = 1; i < b; i++) {
    a = a + b;
  }
  cout << a;
  return 0;
}
