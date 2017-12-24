/*Напишите программу выводящую все несократимые дроби с неотрицательными
знаменателем и числителем не превышающим N, в порядке возрастания. 
Будем считать дробь 1/0 - максимальной несократимой. 
*/

/* 
????: В условии задачи написано, что все дроби должны быть несократимыми, но в 
примере выводных данных присутствуют сократимые дроби типа 3/1 (= 3). 
*/
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

//Функция getFrac определяет НОД текущих числителя и знаменателя. Если НОД не 
//равен 1, то функция делит числитель и знаменатель на НОД для получения 
//правильной дроби. Возвращает числитель и знаменатель.

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}



bool getFrac(int &a, int &b){
     int nod = gcd(a, b);
     if( nod != 1){ 
         return false; }
     else return true;
}

int main(int argc, char *argv[]){
    int N;
    cout << "Enter the adjoining number ";
    cin >> N;
    int numerator[100]; //Массив числителей
    int denominator[100]; //Массив знаменателей
    int i = 0;
    //Генерация дробей (т.е числителей и знаменателей)
    int t;
    for( int dm = N; dm >= 2; dm--){
         for( int nm = 1; nm <= N; nm++){
              //cout << "start" << endl; 
              //cin >> t;              
              if( !getFrac(dm, nm) ) continue;
              //cout << dm << " " << nm << endl;
              numerator[i] = nm;
              denominator[i] = dm;
              i++;
         }
    }
    int index[i];
    //Индексная сортировка массива
    for( int j = 0; j < i; j++){
         index[j] = j;
    }
    for( int j = 1; j < i; j++){
         for( int k = j; k > 0; k--){
              int i1 = index[k];
              int i2 = index[k-1];
              int dn1 = denominator[i1];
              int dn2 = denominator[i2];
              int nm1 = numerator[i1];
              int nm2 = numerator[i2];
              if((nm1*dn2 - nm2*dn1) < 0){
                          swap(index[k], index[k-1]);
              } else {break;}
         }
    }
    cout << "0/1 ";
    for( int j = 0; j < i; j++){
         int k = index[j];
         cout << numerator[k] << "/" << denominator[k] << " ";
    }
    cout << N << "/1" << " 1/0";
    cout << endl;        
    system("PAUSE");
    return EXIT_SUCCESS;
}
