//Напишите программу находящую в массиве сумму элементов делящихся либо на 72 либо на 27(не вместе).
//ДОМАШНЯЯ РАБОТА 29.10

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
     int s = 0;
     int a;
     int n;
     cout<<"Vvedite razmer massiva\n";
     cin>>n;
     for(int i = 0; i < n; i++);
       cin >> a;
       if( !( (a % 72 == 0 ) && (a % 27 == 0 ) ))
         if( (a % 27 == 0 ) || (a % 72 == 0 ) ){
             s = s+a;
             cout << "+" << a << "\n";
         }
     }
     cout << "summa=" << s << "\n";

     system("PAUSE");
     return EXIT_SUCCESS;
}
