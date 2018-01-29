/*
1-2) Реализовать структуру или класс для работы с комплексными числами и программу с примером работы этой структуры. 
В структуре должны быть перегружены арифметика для комплексных и вещественных чисел,
сравнения и определены методы для получения/изменения вещественной и мнимой части, взятия модуля и сопряжения.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Complex         // класс "Комплексное число"
{
private:
  double re, im;      // действительная и мнимая части

public:
  // конструкторы 

  Complex ()  // конструктор без параметра
  {   };

  Complex (double r)   // конструктор только с действительной частью
  {
    re = r;
    im = 0;
  }

  Complex (double r, double i) // конструктор с действительной и мнимой частью
  {
    re = r;
    im = i;
  }

  Complex (const Complex &c)   // конструктор копирования
  {
    re = c.re;
    im = c.im;
  }

  // деструктор
  ~Complex ()
  {  }

  // остальные функции

  // Модуль комплексного числа
  double abs ()        
  {
    return sqrt (re * re + im * im);
  }

  // оператор присваивания
  Complex& operator = (Complex &c)   
  {
    re = c.re;
    im = c.im;

    return (*this);
  }


  // оператор +=
  Complex& operator += (Complex &c)   
  {
    re += c.re;
    im += c.im;
    return *this;
  }

  // оператор сложения
  Complex operator + (const Complex &c)   
  {
    return Complex (re + c.re, im + c.im);
  }

  // оператор вычитания
  Complex operator - (const Complex &c)   
  {
    return Complex(re - c.re, im - c.im);
  }

  // оператор умножения
  Complex operator * (const Complex &c)   
  {
    return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
  }

  // оператор деления
  Complex operator / (const Complex &c)   
  {
    Complex temp;

    double r = c.re * c.re + c.im * c.im;
    temp.re = (re * c.re + im * c.im) / r;
    temp.im = (im * c.re - re * c.im) / r;

    return temp;
  }

  // укажем дружественные операторы, которым мы разрешаем доступ
  // к личным (private) данным
  friend ostream & operator<< (ostream &, const Complex &);   
  friend istream & operator>> (istream &, Complex &);         

};

// перегрузка оператора <<
ostream& operator<< (ostream &out, const Complex &c)
{
  out << "(" << c.re << ", " << c.im << ")";
  return out;
}

// перегрузка оператора >>
istream& operator>> (istream &in, Complex &c)
{
  in >> c.re >> c.im;
  return in;
}

int
main ()
{
  Complex a (5, 2);
  Complex b (3, -3);

  cout << "a = " << a << "; b =" << b << endl;

  a += b;
 
  cout << "a = " << a << "; b =" << b << endl;

  Complex c = a + b;

  cout << c << endl;
  cout << a + b << endl;
  cout << a * b << endl;

  return 0;
}
