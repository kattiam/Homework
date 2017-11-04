/*
Напишите программу для работы с оценками за сессию студентов.
 В программе должна присутствовать структура хранящая ФИО, оценки за 6
экзаменов для каждого ученика и умеющая (соответствующими методами)
вычислять средний балл студента, наличие стипендии(стипендия начисляется
закрывшим сессию без троек),  задолженностей (сессия считается закрытой
без долгов, если все оценки выше 2)

в программе должны быть функции для работы с массивом студентов находящие
средний балл(всех без двух лучших и двух худших), количества
стипендиатов, должников и отчисленных(более двух долгов)
*/

//ДОМАШНЯЯ РАБОТА 5.11.2017

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class TStudent{
    public:
  char fio[80];   //ФИО студента
  short score[6]; // Оценки за 6 экзаменов
  
  void setStudent(char *s); // Строка: Ivanov I.I. 3 4 5 4 3 5
  float getAvg(); // Средняя успеваемость
  int getSum();  //Сумма балов
  bool isGrant(); //Есть стипендия?
  int getSumDebt(); // Cколько двоек
  bool isDebt();  //Есть долги?
};

  // сохранить данные о студенте
  void TStudent::setStudent(char *s){
      //выделяем ФИО и баллы
    int cnt = 0;
    short k;
    for(int i=0; s[i]; i++){
      if(s[i] == ' ') cnt++;
      if( (s[i] == ' ') && (cnt == 2)){
        fio[i] = '\0';
        int j=0;
        while(s[i++]){
           if( s[i] == ' ') continue;
            k = s[i]-'0';
            score[j++] = k;
        }
      }else{
        fio[i] = s[i];
      }
    }
  }
  // return сумму балов
  int TStudent::getSum(){
      int s=0;
      for(int i=0; i<6; i++) s += score[i];
      return s;
  }
  // средняя оценка
  float TStudent::getAvg(){
        return (float)getSum()/6;
  }
  // Есть стипендия ?
  bool TStudent::isGrant(){
      for(int i=0; i<6; i++)
        if(score[i] < 4) return false;
      return true;
  }

  // число задолженностей
  int TStudent::getSumDebt(){
      int s = 0;
      for(int i=0; i<6; i++) if(score[i]<3) s++;
      return s;
  }
  // Должник?
  bool TStudent::isDebt(){
      if( getSumDebt() > 0) return true;
      return false;
  }

  //вывод ФИО и баллов каждого студента
void printStudentInfo(TStudent &st){
    cout << st.fio << " ";
    for(int i=0; i < 6; i++){
      int k = st.score[i];
      cout << k << " ";
    };
    cout << endl;
}
  //число стипендиатов
int numGrants(TStudent *a, int n){
  int s = 0;
  for( int i=0; i<n; i++)
    if( a[i].isGrant() ) {
      s += 1;
      printStudentInfo(a[i]);
    }
  return s;
}
  //число должников
int numDebts(TStudent *a, int n){
  int s = 0;
  for( int i=0; i<n; i++)
    if( a[i].isDebt() ) {
      s += 1;
      printStudentInfo(a[i]);
    }
  return s;
}
  //Средний бал по массиву без 2 лучших и худших
float getAvgArr(TStudent *a, int n){
  //начальный массив индексов
  int *inds = new int[n];
  for( int i=0; i<n; i++) inds[i] = i;
  //сортируем индексы методом вставки
  for(int i=1;i<n;i++){
    // пока j>0 и элемент j-1 > j, x-массив
    for(int j=i; (j>0) && ( a[inds[j-1]].getAvg() > a[inds[j]].getAvg() ); j--) {
       int k = inds[j];
       inds[j] = inds[j-1];
       inds[j-1] = k;
    }
  }
  int sum = 0;
  for( int i=2; i < n-2; i++) sum += a[ inds[i] ].getSum();
  float s = sum/6.0;
  delete [] inds;
  return (float)s/(n-4);
}
  //Сколько отчисленных
int getDebtors(TStudent *a, int n){
  int s = 0;
  for( int i=0; i<n; i++){
    if( a[i].getSumDebt() > 2) s +=1;
  }
  return s;
}

void debugArr(TStudent *arr, int &N){
  char s1[] = "Ivanov I.I. 5 5 5 5 5 5";
  char s2[] = "Petrov I.I. 5 5 5 5 5 5";
  char s3[] = "Sidorov I.I. 2 2 2 2 2 2";
  char s4[] = "Ivanova I.I. 2 2 4 2 3 2";
  char s5[] = "Petrova I.I. 4 4 4 5 5 5";
  char s6[] = "Sidorova I.I. 4 5 5 5 5 5";
  arr[0].setStudent(s1);
  arr[1].setStudent(s2);
  arr[2].setStudent(s3);
  arr[3].setStudent(s4);
  arr[4].setStudent(s5);
  arr[5].setStudent(s6);
  N = 6;
}


int main(int argc, char** argv) {
//    setlocale(LC_CTYPE, "rus");
    cout << " \
    There are the following commands:\n  \
    ( Only English words accepted in names) \n \
    n - Enter nsme and grade of new student (n Ivanov I.I. 5 5 4 3 4 4)\n \
        program output status of student \n \
    s - Avg students ball without 2 best and 2 bad \n \
    g - Number of grants \n \
    d - Number of debtors \n \
    e - More then two debt \n \
    p - print students \n \
    b - Create array for 6 students ( for demo) \
    q - quit \n \
\n";
  TStudent arr[100];
  int arrN =0;
  char s[80];
  bool ok = true;
  while(ok) {
    cout << "Enter the command\n";
    gets(s);
    switch(s[0]){
      case 'q': {ok = false; break; };
      case 'n': {
        arr[arrN].setStudent(&s[2]);
        cout << "Average:" << arr[arrN].getAvg() << endl;
        if(arr[arrN].isGrant()) cout << "Is "; else cout << "No ";
        cout << "grant" << endl;
        if(arr[arrN].isDebt()) cout << "Is "; else cout << "No ";
        cout << "debt" << endl;
        arrN++;
        break;
      }
      case 'g': {
        cout << "Number of grants: " << numGrants(arr,arrN) << endl;
        break;
      }
      case 'd': {
        cout << "Number of debtors: " << numDebts(arr,arrN) << endl;
        break;
      }
      case 'p': {
        if(arrN==0){cout << "No students in array" << endl; break; };
        for( int i=0; i<arrN; i++){printStudentInfo(arr[i]);};
        break;
      }
      case 'b': {
        debugArr(arr,arrN);
        for( int i=0; i<arrN; i++) printStudentInfo(arr[i]);
        break;
      }
      case 's': {
        if(arrN < 5){cout << "Number of students < 5" << endl;}
        else
           cout << "Avg = " << getAvgArr(arr, arrN) << endl;
        break;
      }
      case 'e': {
        cout << "Number of debtors= " << getDebtors(arr,arrN) << endl;
        break;
      }
      default: {cout << "Invalid command" << endl; break; };
    }
  }
//  return 0;
    system("PAUSE");
    return EXIT_SUCCESS;
}
