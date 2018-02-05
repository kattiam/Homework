/*Реализовать структуру(а лучше класс) для работы со строками(можно довести до ума структуру из прошлом домашнем по структурам)
и программу с примером работы этой структуры. 
Структура должна уметь не меньше чем в прошлом дз, но кроме того: 
удовлетворять Правилу Трёх,иметь конструктор принимающий C-style строки и конструктор принимающий длину строки ,
иметь перегруженным оператор квадратные скобки для доступа к символам по индексам. Пример, кроме всего прочего, 
должен содержать замену некоторой строки на строку с Вашим ФИО. В данной программе запрещено пользоваться
стандартными строками C++.
*/

/*
Вся работа со строками преведена в программе из прошлой домашней работы. Ниже приведены работы с конструкторами и
перегрузка операторов.
ПРОШЛОЕ ДЗ: https://github.com/leserpenteau/Homework/blob/master/05_11_2017/HW3.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class Tstr{
     char* str;

     public:
     Tstr() { str = 0; } //Обычный конструктор
     Tstr(char* s);
     Tstr(const Tstr &obj); //Конструктор-copy
     ~Tstr();

     void set(char* s);
     char* get();

     Tstr operator+(Tstr t);
     Tstr& operator=(Tstr t);
     char operator[](int i){ return str[i]; }
};

Tstr::Tstr(char* s){
     str = new char [strlen(s)];
     strcpy(str, s);
}

Tstr::Tstr(const Tstr &obj){
      char *s = obj.str;
      str = new char [strlen(s)];
      strcpy(str, s);
}

Tstr::~Tstr(){ if( str != 0) delete [] str;}

void Tstr::set(char* s){
      if( str != 0) delete [] str;
      str = new char [strlen(s)];
      strcpy(str, s);
}

char* Tstr::get(){ return str; }

Tstr Tstr::operator+(Tstr t){
      int N = strlen(str) + strlen(t.str);
      char* s = new char [N];
      Tstr tmp;
      strcpy(s, str);
      strcat(s, t.str);
      tmp.str = s;
      return tmp;
}

Tstr& Tstr::operator=(Tstr t){
      if( str != 0) delete [] str;
      int N = strlen(t.str);
      str = new char [N];
      strcpy(str, t.str);
      return *this;
}


int main(int argc, char *argv[]) //Пример работы с классом 
{
     cout << "Enter the string ";
     char s[80];
     gets(s);
     Tstr a(s);
     cout << a.get() << endl;
     Tstr b = a;
     cout << b.get() << endl;
     b.set("Privet");  //Ну, чисто для примера, ага
     cout << b.get() << endl;
     Tstr c;
     c = a + b;
     cout << c.get() << endl;
     cout << c[2] << endl;


     system("PAUSE");
     return EXIT_SUCCESS;
}
