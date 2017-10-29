//Напишите функцию sort упорядывающую массив целых чисел и программу с примером её использования. 
//В коде запрещается использовать обращения к массиву по индексу( Arr[i] ), т.е. нужно использовать указательную арифметику. 
//Эффективность в данной программе не приоритетна. Количество аргументов функции не должно превышать 2.
//ДОМАШНЯЯ РАБОТА 29.10

#include <cstdlib>
#include <iostream>

using namespace std;

void sort(int *p, int N){
   int tmp;
   for (int i = 0; i < N - 1; i++) {
         for (int j = 0; j < N - i - 1; j++) {
             if ( *(p+j) > *(p+j + 1) ) {
                 tmp = *(p+j);
                 *(p+j) = *(p+j + 1);
                 *(p+j + 1) = tmp;
             }
         }
}  }

int main(int argc, char *argv[])
{
     int N;
     cin >> N;
     int *a = new int [N];
     for (int i=0; i < N; i++) cin >> a[i];
     sort(a, N);
     for( int i=0; i < N; i++) cout << a[i] << "\n";

     system("PAUSE");
     return EXIT_SUCCESS;
}
