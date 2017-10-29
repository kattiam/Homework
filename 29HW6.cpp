//Напишите процедуру удаляющую из массива все элементы, которые уже встречались(повторы), 
//и пример программы её использующую. Массив передаваемый в эту функцию должен уменьшиться, также как и переменная, передающая
//в функцию размер массива.
//ДОМАШНЯЯ РАБОТА 29.10


#include <iostream>

using namespace std;

void delDup( int **a, int *N){ 
   int *pa = *a;  
   int *aa = new int[*N];
   int i,j;
   aa[0] = pa[0];
   int NN = 1;
   for( int i=1; i< *N; i++){
     if( pa[i] != pa[i-1] ) {
       aa[NN] = pa[i];
       NN++;
     }
   }
   int *bb = new int[NN];
   for( int i=0; i< NN; i++) {bb[i] = aa[i];}
   delete pa;
   delete aa;
   *a = bb;
   *N = NN;
}

int main(int argc, char *argv[])
{
     int N;
     cin >> N;
     int *a = new int [N];
     for (int i=0; i < N; i++) { cin >> a[i]; }
     int temp; 
     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                }
                }
                }
     delDup( &a, &N);
     for( int i=0; i<N; i++) {cout << a[i] << "\n";}
     system("PAUSE");
     return EXIT_SUCCESS;
}
