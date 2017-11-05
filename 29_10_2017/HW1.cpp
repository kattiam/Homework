//Напишите функции min, max, avg, med, процедуру swap принимающие в себя три вещественных аргумента и программу с примером из 
//использования. min - находит минимальное из трех значений, max - максимальное, avg - среднее арифметическое, med  - медианное 
//(гуглим, что это такое). swap - переставляет значения по кругу ( первое во второе, второе в третье, третье в первое).
//ДОМАШНЯЯ РАБОТА 29.10

#include <cstdlib>
#include <iostream>

using namespace std;

float getMin(float a, float b, float c){

   if( (a <= b) && (a <= c)) return a;
   else
     if( (b <= a) && (b <= c) ) return b;
     else return c;
}

float getMax(float a, float b, float c){

   if( (a >= b) && (a >= c)) return a;
   else
     if( (b >= a) && (b >= c) ) return b;
     else return c;
}

float getAvg(float a, float b, float c){
   return (a+b+c)/3;
}

float getMedian(float a, float b, float c){
   float m;
   if(b<c && b<a) m = a<c ? a : c;
   else m = a>c ? a : c;
   return m;
}

void swap3(float &a,float &b, float &c){
      float t;
      t = c;
      c = b;
      b = a;
      a = t;
}

int main(int argc, char *argv[])
{
     float x,y,z;
     cout << getMin(1.1, 1.2, 1.7)<< "\n";
     cout << getMax(1.1, 1.2, 1.7) << "\n";
     cout << getAvg(1.1, 1.2, 1.7) << "\n";
     cout << getMedian(1.9, 1.2, 1.7) << "\n";
     x=1.1; y=1.2; z=1.7;
     cout << x  << " " << y  << " " << z << "\n";
     swap3(x,y,z);
     cout << x  << " " << y  << " " << z << "\n";

     system("PAUSE");
     return EXIT_SUCCESS;
}
