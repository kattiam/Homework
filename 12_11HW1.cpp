//Напишите программу, которая удаляет из массива все простые числа, встречающиеся больше одного раза.
//ДОМАШНЯЯ РАБОТА НА КАНИКУЛЫ 31.10

#include <cstdlib>
#include <iostream>

using namespace std;

// Проверка на простоту числа a
bool isPrime(long a) {
    if( (a==0) || (a%2 == 0) ) return false;
    if ( a == 1 ) return false;
    int k = a/2;   // sqrt(a) не используем, чтобы не подключать math lib
    for( long i = 3; i <= k; i++)
      if( a % i == 0) return false;
    return true;
} 

int main(int argc, char *argv[])
{
    int N;
    cout << "Enter array size: ";
    cin >> N;
    long *p = new long [N];
    cout << "Enter numbers: ";
    for( int i=0; i < N; i++) cin >> p[i];
    
    bool isDubs = false;  // признак- есть помеченные к удалению
    long markDub;  //число, которым замещаются удаляемые числа
                          // будет использоваться 1-е простое число у которого есть дубли
    bool findDub = false;                      
    for( int i = 0; i < N-1; i++){
        long d = p[i];
        if( isDubs && ( d == markDub ) ) continue;
        if( isPrime(d) && i != N-1 ){
            // ищем и помечаем дубликаты
            findDub = false;
            for( int j = i+1; j < N; j++){
                if( p[j] == d){  //есть дубликат
                   findDub = true;
                   if( !isDubs ){  //еще не было дублей
                        isDubs = true;
                        markDub = d;
                   }
                   p[j] = markDub;
                }
            }
            if( findDub) p[i] = markDub;
        }
    }
    for (int i = 0; i < N; i++) {
        if (isDubs) {
            if (p[i] == markDub) continue; 
        }
        cout << p[i] << " ";
    }
    cout << "\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
