/*
Напишите программу, которая подсчитывает, сколько раз в строке встретился
символ ‘w’
    Input:
    Wshdfggweewhwvwvw        //строка
    Output
    5
*/    
#include <cstdlib>
#include <iostream>

using namespace std;


/*
 Используем cin.get(), чтобы вводить по символам
*/
int main(int argc, char *argv[])
{
    cout << "Enter string: ";
  char c;
  int N = 0;
  c = cin.get();
  do {
    if( c == '\n' ) break;
    if(c == 'w') N++;
    c = cin.get();
  } 
  while(c !='\n');
  cout << "Number of char w= " << N << endl;
  
    system("PAUSE");
    return EXIT_SUCCESS;
}
