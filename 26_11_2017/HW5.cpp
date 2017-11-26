/*
Напишите программу для работы с информацией о кредитах.
Программа должна содержать структуру содержащую информацию о
 ФИО
 ИНН(12-значный номер)
 Дата выдачи и срок кредита. Будем считать опаздывающих с оплатой нет.
 Размер кредита
 Месячная процентная ставка (2 процента - 1.02).
 Будем считать, что долг увеличивается на этот процент в конце
 каждого месяца(после ежемесячного платежа), с округлением до 1 рубля вверх
 Информация о суммах платежей по месяцам. Считаем информацию корректной.

Структура должна с помощью соответствующих методов уметь:
  Вычислять остаток долга
  Добавлять информацию о платеже
  Рассчитывать ежемесячный платеж необходимый для своевременного
  погашения кредита, при условии что суммы будут одинаковыми каждый месяц.
  Рассчитывать сумму переплаты по процентам, в случае
  немедленного погашения кредита
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct TCredit {
    string name;   // ФИО
    string inn;    // ИНН
    string date;   // Дата кредита
    long cred;     // сумма кредита
    int months;    // на сколько месяцев
    float proc;    // процент в месяц + 1 (процентная ставка)
    long * pay;    // платеж по месяцам. pay[i]- платеж за месяц i от начала
    long debt;     // долг после последнего платежа
    int lastpay;   // последний месяц когда платили

    TCredit();
    ~TCredit();
    /*Параметры кредита
    sdate-  дата кредита
    cr-     сумма кредита
    m-      на сколько месяцев
    prc-    месячный процент
    */
    void startCredit(string sdate, long cr, int m, float prc ); //new credit
    //платеж: m- какой по счету месяц от начала, sum- сумма
    void payment(int m, int sum);
    // расчет долга на месяц m
    long getDebt(int m);
    // сумма переплаты по процентам, в случае немедленного погашения кредита
    long getOverPay();
    // сколько надо платить поровну ежемесячно, чтобы погасить долг
    long getMonthPay();
    //Печать информации о платежах по месяцам
    void printPay();
};

TCredit::TCredit(){
    months = 0;
    lastpay = 0;
}

TCredit::~TCredit(){
    if( months != 0 ) delete [] pay;
}
void TCredit::startCredit(string sdate, long cr, int m, float prc ){
    if( months != 0 ) delete [] pay;
    pay = new long [m+1];
    for(int i = 1; i < m+1; i++) pay[i] = 0;
    date = sdate;
    months = m;
    proc = prc/100.0 + 1.0;
    cred = cr;
    debt = cr;
    pay[0] = debt;
    lastpay = 0;
}

    //платеж: m- какой по счету месяц отначала, sum- сумма
    //m должен быть больше lastpay- месяц последнего платежа
void TCredit::payment(int m, int sum){
    if( m > lastpay){
      pay[m] = sum;
      debt = getDebt(m); // новый долг
      lastpay = m;
    }
}
    // Вычисляем долг на месяц m от начала кредита
long TCredit::getDebt(int m){
    double d = cred; //сумма кредита
    //сначала платим потом берем процеит от  остатка
    for (int i=1; i <= m; i++){
        d = (d - (double)pay[i])*proc;
        if( d < 0 ) d = 0;
    }
    // округляем до большего
    long r = int(d);
    if( d-r > 0 ) r++; // +1 рубль. Округляем до 1 рубля вверх
    return r;
}
    // сколько надо платить поровну ежемесячно, чтобы погасить долг
/*
Алгоритм:
   Пусть
S- сумма кредита, d- сумма долга, т.е. сколько еще платить,
a= 1+p/100, - p- ежемесячный процент, Х- по скольку нада
платить каждый месяц):

1 месяц- был d=S, стал d=(S-Х)*a = S*а-Х*a
2 месяц- был d=S*а-Х*a стал d=(S*а-Х*a-X)*a=S*а^2-Х*a^2-X*a=S*а^2-Х*(a^2+a)
...
k месяц- d=S*a^k-X*(а^k+a^(k-1)+...+a)
В скобках сумма геом. прогрессии G=a*(a^k-1)/(a-1).
Приравняем к нулю и определяем Х=S*a^k*(a-1)/( a*(a^k-1) )
*/
long TCredit::getMonthPay(){
    double ak = pow(proc,months);
    double x= double(cred)*ak*(proc-1);
    x /= (ak-1);
    x /= proc;
    long r = int(x);
    if( x-r > 0 ) r++; // +1 рубль. Округляем до 1 рубля вверх
    return r;
}

    // сумма переплаты по процентам, в случае немедленного погашения кредита
long TCredit::getOverPay(){
     long d = 0;
     for( int i=1; i <= lastpay; i++) d += pay[i]; // сколько всего заплатили
     d += debt;  //заплатили весь оставшийся долг
     return d-cred;
}
     // Печать информации о платежах по месяцам
void TCredit::printPay(){
     if( lastpay == 0 ){
         cout << "No any payments" << endl;
         return;
     } else{
         for( int i=1; i <= lastpay; i++)
           cout << "Month " << i << " " << pay[i] << " rub." << endl;
     }
}


int main(int argc, char** argv) {
    TCredit cred = TCredit();
    cout << " \
    There are the following commands:\n  \
    ( Only English words accepted in names) \n \
    n <name> - Enter name \n \
    i <INN> - Enter INN\n \
    r <01/02/2017> <sum> <number of months> <procent> - new credit\n \
    p <m> <sum> - payment for month number m from the begining of credit\n \
    d - Get current debt \n \
    e - procent overpayment if repay the debt immediately \n \
    m - calc payment by month \n \
    s - print payments by months \n \
    q - quit \n \
\n";

  string cmd, s, dt;
  long sum;
  int m;
  float prc;
  bool ok = true;
  while(ok) {
    cout << "Enter the command\n";
    cin >> cmd;
    switch(cmd[0]){
      case 'q': {ok = false; break; };
      case 'n': {   // имя кредитора
           getline(cin, s);
           s.erase(0,1); // удаляем 1-й пробел
           cred.name = s;
           break;
      };
      case 'i': { // ИНН
           getline(cin, s);
           s.erase(0,1); // удаляем 1-й пробел
           cred.inn = s;
           break;
      }
      case 'r': {
           cin >> dt;
           cin >> sum;
           cin >> m;
           cin >> prc;
           cout << sum <<" " << m << " " << prc << endl;
           cred.startCredit(dt, sum,m, prc);
           cout << cred.cred <<" " << cred.months << " " << cred.proc << endl;
           cout << "Current debt=" << cred.debt << endl;
           break;
      }
      case 'p': {
           cin >> m;
           cin >> sum;
           cout << sum <<" " << m << endl;
           if( cred.months == 0 ){
               cout << " No credit" << endl;
               break;
           }
           if( m > cred.lastpay ){
               cred.payment(m, sum);
               cout << "Current debt=" << cred.debt << endl;
           } else {
               cout << "Month must be > " << cred.lastpay << endl;
           }
           break;
      }
      case 'd': {
           if( cred.months == 0 ){
               cout << " No credit" << endl;
               break;
           }

           cout << cred.getDebt(cred.lastpay) << endl;
           break;
      }
      case 'm': {
           if( cred.months == 0 ){
               cout << " No credit" << endl;
               break;
           }
          long x = cred.getMonthPay();
          cout << "Pay " << x << " rub each month" << endl;
          cout << "Overpayment=" << x*cred.months-cred.cred << endl;
          break;
      }
      case 'e': {
           if( cred.months == 0 ){
               cout << " No credit" << endl;
               break;
           }
           cout << "Overpayment=" << cred.getOverPay() << endl;
           break;
      }
      case 's': {
           if( cred.months == 0 ){
               cout << " No credit" << endl;
               break;
           }
           cred.printPay();
           break;
      }
      default: {
          // чистим cin;
          cin.ignore();
          cin.sync(); // clear the input buffer
          getline(cin, s);
          cout << "Invalid command " << cmd << endl; break;
      };
    }
  }

    system("pause");
    return 0;
}
