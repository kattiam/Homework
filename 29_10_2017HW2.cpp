//Напишите рекурсивную функцию pow( быстрое возведение вещественного числа в целую степень) и пример программы её использующей. 
//ДОМАШНЯЯ РАБОТА 29.10

include <cstdlib>
#include <iostream>

using namespace std;

double pow(double x, int N){
   if (N == 0) return 1;
   if (N == 1) return x;
   return x*pow(x, N-1);
}

int main(int argc, char *argv[])
{
     double n;
     cin >> n;
     int m;
     cin >> m;
     cout << pow(n, m) << "\n";
     system("PAUSE");
     return EXIT_SUCCESS;
}
