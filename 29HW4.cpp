//Напишите программу находящую минимальную сумму пары элементов массива отстоящих друг от друга не менее чем на 4 элемента
//(первый и пятый элемент могут подходить, а первый и третий - нет). Эффективность в данной программе не приоритетна. 
//ДОМАШНЯЯ РАБОТА 29.10

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
     int N;
     int min;
     cin >> N;
     int *ar = new int [N];
     for (int i=0; i < N; i++) cin >> ar[i];
     min = ar[0] + ar[5];  
     for( int i=0; i < N-5; i++){
       for( int j=i; j < N-5; j++){
         if( (ar[j] + ar[j+5]) < min ) {
             min = ar[j] + ar[j+5];
             cout << i << "," << j << "\n";
         }
       }
     }
     cout << "Min:" << min << "\n";
     system("PAUSE");
     return EXIT_SUCCESS;
}
