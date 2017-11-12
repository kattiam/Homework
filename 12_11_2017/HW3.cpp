/*
Напишите программу, которая находит во входном потоке простые числа.
Входной поток заканчивается символом ‘!’.
Input:
11        //1 строка
22        //2 строка
1A1        //3 строка
2        //4 строка
3  7        //5 строка
Output:
11: Prime
22: Composite
1A1: Not a number
2: Prime
3  7: Not a number
*/

/*
Алгоритм:
Так как количество вводимых строк неизвестно, будем увеличивать
начальный размер массива строк на addN (равное 5), когда текущий массив
заполнен. Затем определяем тип каждого элемента массива.
*/

// ДОМАШНЯЯ РАБОТА 5.11.2017

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Проверка на простоту числа a
bool isPrime(long a){
    if (a == 2) return true;
    if (a == -2) return true;
    if( (a==0) || (a%2 == 0) ) return false;
    if ( a == 1 ) return false;
    if ( a == -1) return false;
    int k = a/2;   // sqrt(a) не используем, чтобы не подключать math lib
    for( long i = 3; i <= k; i++)
      if( a % i == 0) return false;
    return true;
}
// Возвращает тип введённой строки: 0 - Prime, 1 - Composite, 2 - Not a num
int getStrType(string s) {
    for (int i = 0; i < s.size(); i++) {
      if( s[0] == '-') continue;
      if ( !(s[i] >= '0' && s[i] <= '9')) return 2;
    }
    long k = atoi(s.c_str()); //String to Int
    if( isPrime(k)) return 0; else return 1;

}
// Увеличиваем размер динамического массива
//addN - на сколько увеличить
//N - размер старого массива
//arr - адрес переменной, содержащей адрес входного массива
void incArrLen(int addN, int &N, string **arr) {
     string* newArr = new string [N + addN]; // выделяем новый массив
     string* p = *arr; // P - указатель на входной массив (адрес первого
                       // элемента)
     for (int i = 0; i < N; i++) newArr[i] = p[i]; // заполняем новый массив
     delete [] p; // удаляем старый массив
     N = N + addN; // изменяем входное значение N
     *arr = newArr; // изменяем указатель на входной массив
}

int main(int argc, char *argv[])
{
    char* strType[] = {"Prime","Composite","Not a number"};
    string s;
    int N = 5;
    int addN = 5;   // сколько добавлять к размеру массива
    int cnt = 0;
    string* arr = new string [N];
    cout << "Enter the strings." << endl;
    cout << "The \"!\" is the end of the input." << endl;
    while (true) {
      getline(cin, s);
      if( s[0] == '!') break;
      if( cnt >= N){ // массив заполнен полностью?
        incArrLen(addN, N, &arr); // увеличение размера массива
      }
      arr[cnt] = s;
      cnt++;
    }
    for( int i = 0; i < cnt; i++) {
      int ind = getStrType(arr[i]);
      cout << arr[i] << ":" << " " << strType[ind] << endl;
    }


    system("PAUSE");
    return EXIT_SUCCESS;
}
