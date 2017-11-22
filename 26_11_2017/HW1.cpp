//Напишите программу, которая удаляет из массива все простые числа встречающиеся больше одного раза.


#include <iostream>
#include <cstdlib>

using namespace std;

// Проверка на простоту числа a
bool isPrime(long a){
    if( a == 2) return true; 
    if( (a==0) || (a%2 == 0) ) return false;
    if ( a == 1 ) return false;
    int k = a/2;   // sqrt(a) не используем, чтобы не подключать math lib
    for( long i = 3; i <= k; i++)
      if( a % i == 0) return false;
    return true;
}

/*
Алгоритм: ищем простые числа, у которых есть дубли
и замещаем их 1-м простым числом, у которого есть дубли
Затем создаем новый дин. массив и переписываем непомеченные
числа в него.
Адрес исходного массива и размер замещаем на новые значения.
*/
void delDubPrimes(long **a, int *N){
    long *p = *a;  // pointer to input array
    bool isDubs = false;  // признак- есть помеченные к удалению
    long markDub;  //число, которым замещаются удаляемые числа
                   // будет использоваться 1-е простое число 
                   //у которого есть дубли
    long NN = 0;   // число дублей
    long d;

    for( int i = 0; i < *N-1; i++){ // цикл до предпоследнего
        d = p[i];
        if( isDubs && ( d == markDub ) ) continue;
        if( isPrime(d) ){
            // ищем и помечаем дубликаты
            bool findDub = false;   //нашелся ли дубль для d
            for( int j = i+1; j < *N; j++){
                if( p[j] == d){  //есть дубликат
                   findDub = true;
                   if( !isDubs ){  //еще не было дублей
                        isDubs = true;
                        markDub = d;
                   }
                   p[j] = markDub;
                   NN++;
                }
            }
            if( findDub) {
                p[i] = markDub;
                NN++;
            }
        }
    }
    if( !isDubs) return;  // дублей не было
    NN = *N - NN; //число оставшихся чисел
    if( NN == 0){  //все числа имели дубли
        *N = 0;
        delete [] p;  //удалить входной массив
        return;
    }
    long *b = new long [NN];  //создаем массив для результата
    //Запись оставшихся чисел в новый массив
    long j = 0;
    for( int i = 0; i < *N; i++) {
        if( p[i] != markDub ) {    b[j] = p[i]; j++; };
    }
    delete [] p; //удалить входной массив
    *N = NN;     //новый размер
    *a = b;      // новый адрес массива
    return;

}

int main(int argc, char** argv) {
    int N;
    cout << "Enter array size: ";
    cin >> N;
    long *a = new long [N];
    cout << "Enter numbers: ";
    for( int i=0; i < N; i++) cin >> a[i];

    delDubPrimes( &a, &N );

    if( N == 0 ){
        cout << "all numbers was deleted\n";
        return 0;
    }
    //cout << N << "\n";
    for( int i = 0; i < N; i++ ) cout << a[i] << " ";
    cout << "\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}

