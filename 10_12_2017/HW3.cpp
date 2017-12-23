/*
Напишите функцию, находящую k-ую порядковую статистику в массиве. Программа должна
состоять из этой функции и примера её использования в main.
*/

/*
ОПРЕДЕЛЕНИЕ: k-ой порядковой статистикой набора элементов линейно упорядоченного
множества называется такой его элемент,
который является k-ым элементом набора в порядке сортировки.

Для сортировки массива использовался алгоритм QuckSort.
*/


#include <iostream>
#include <cstdlib>

using namespace std;

// Сортировка массива методом разделения его на подмассивы.
int cut(int *mas, int l, int r) {
  if (l!=r)
    swap(mas[l + rand() % (r - l)], mas[r]);
  int x = mas[r];
  int i = l-1;
  for (int j = l; j <= r; j++) {
    if (mas[j] <= x)
      swap(mas[++i],mas[j]);
  }
  return i;
}
//Нахождение k-ой порядковой статистики.
int kth(int *mas, int n, int len) {
  int l = 0, r = len - 1;
  for(;;) {
    int pos = cut(mas,l,r);
    if (pos < n)
      l = pos + 1;
    else if (pos > n)
      r = pos - 1;
    else return mas[n];
  }
}

int main(int argc, char** argv){
  int N;
  cout << "Enter the quantity of elements ";
  cin >> N;
  int mas[N];
  cout << "Enter the number of ordinal statistics ";
  int l;
  cin >> l;
  int k = kth(mas, l, N);
  cout << k << endl;
  system("PAUSE");
  return EXIT_SUCCESS;
}
