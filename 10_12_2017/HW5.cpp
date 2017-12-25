//Не было отладки. Возможна ошибка.


/*Напишите программу, которая находит количество сократимых правильных 
дробей вида m/n для заданного знаменателя .
*/
#include <cstdlib>
#include <iostream>
#include <math.h>
 
 
using namespace std;
 
 
//Функция getFrac определяет НОД текущих числителя и знаменателя. Если НОД не 
//равен 1, то функция возвращает true. 
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
 
bool getFrac(int &a, int &b){
	int nod = gcd(a, b);
    if( nod != 1){ 
         return true; }
     else return false;
}
 
int main(int argc, char *argv[]){
    int N;
    cout << "Enter the denominator ";
    cin >> N;
    int cnt = 1; //Счётчик сократимых дробей, начиная с 0/N
    for( int nm = 1; nm < N; nm++){
        if( getFrac(N, nm) ) cnt++;
        else continue;
    }
    cout << cnt;     
    system("PAUSE");
    return EXIT_SUCCESS;
 
}
