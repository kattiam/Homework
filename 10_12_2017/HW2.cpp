/*Гоночная трасса состоит из двух основных дорог и нескольких переездов с одной
дороги на другую (переходить можно только в одну сторону от A к B). Зная количество
переездов (N) и время переходов от A(i) к B(i), A(i) к A(i+1), B(i) к B(i+1), найти
минимальное время прохождения трассы от A(0) к B(N).
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    int N, t; //Количество переходов и время перехода
    int a, b; //Время перехода из A(i) в B(i)
    cout << "Enter the quantity of the transitions ";
    cin >> N;
    cout << "Enter the time of transition ";
    cin >> t;
    int A = 0; //Текущее время прохождения двух участков
    int B = t;            //A(0)A(N) и B(0)B(N)
    int temp1, temp2;
    for( int i = 0; i < N; i++){
        cout << "Enter the time of overcoming A(" << i << ") and B(" << i << ")" << endl;
        cin >> a >> b;
        A = A + a;
        temp1 = B + b;
        temp2 = A + t;
        if( temp1 > temp2){ B = temp2;} else{B = temp1;}

    }
    cout << "The minimum time of the race is " << B << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
