/*
Напишите эффективную по времени и памяти программу,
которая для заданной последовательности целых чисел находит минимальную сумму
двух её элементов, номера которых различаются не менее чем на 5.
Значение каждого элемента последовательности не превышает 1000.
Количество элементов последовательности не превышает 10000.
*/


#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int d = 5;
    int N;
    int arr[5]; //Буфер для введённых чисел
    int x;
    int minnum; //Минимальное число
    int minsum; //Минимальная сумма
    cout << "Enter the quantity of the numbers ";
    cin >> N;
    for( int i = 0; i < d; i++){
         cin >> x;
         arr[i % d] = x;
         }
    minnum = 1001; minsum = 2001;
    for( int i = d + 1; i <= N; i++){
         cin >> x;
         if( arr[i % d] < minnum) minnum = arr[i % d];
         if( x + minnum < minsum) minsum = x + minnum;
         arr[i % d] = x;
         }
    cout << "The minimum amount is " << minsum << endl;;       
    system("PAUSE");
    return EXIT_SUCCESS;
}
