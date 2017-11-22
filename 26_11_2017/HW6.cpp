/*Задано число n. Требуется найти число от 1 до n, включительно, которое имеет максимальное число
положительных целых делителей.
Если есть несколько чисел от 1 до n с максимальным числом делителей, выведите любое из них.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

// Количество делителей
int cntDividers(long a){
    long cnt = 1;
    if ( a == 1 ) return 1;
    int k = a / 2;
    for( long i = 1; i <= k; i++){
      if( a % i == 0) cnt++;
    }
    return cnt;
}

int main(int argc, char** argv){
    int N;
    int temp;
    int k;
    int max = 0; // максимальное количество делителей числа k;
    cout << "Enter the number" << endl;
    cout << " 1 <= your number <= 100 000" << endl;
    cin >> N;
    for (int i = 1; i <= N; i++){
        temp = cntDividers(i);
        if( temp > max) {
            max = temp;
            k = i;
        }
    }

    cout << "The number with max dividers is " << k << endl;
    cout << "With max dividers " << max << endl;

    system("PAUSE");
    return EXIT_SUCCESS;


}
