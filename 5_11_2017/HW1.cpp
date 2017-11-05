/*
Напишите программу для работы с датами согласно григорианскому календарю.
В программе должны присутствовать:
структура хранящая год,месяц, число и умеющая(с помощью соответствующего
метода) определять по дате день недели
3 функции определяющие сколько лет, месяцев и дней прошло между двумя
датами
*/

/*
День недели определяется по следующему алгоритму
(найдено в Интернете)
a = (14 - месяц) / 12
y = год - a
m = месяц + 12 * a - 2
ДеньНедели = (7000 + день + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)% 7
Результат: 0 — воскресенье, 1 — понедельник и т.д.
*/


#include <iostream>
#include <cstdlib>
#include <cstdio>  //для gets
#include <string.h>

using namespace std;

struct struct_date
{
    short day;
    short month;
    short year;
};

class TDate{
    public:
   struct_date date;
   //unsigned short int yy, mm,dd;
   char sdate[11];
 //public:
   void setDate(char *dt);
   void transDate(char *dt, struct_date *d);
   string getDayWeek();
   int getYearDif(char *dt);
   int getMonDif(char *dt);
   bool isLeapYear (int year);  //високосный ли год
   int KolDays(int d1,int m1,int d2,int m2,int y);  //кол-во дней в пределах года
   long getDayDif(struct_date &d1, struct_date &d2);
};

void TDate::transDate(char *dt, struct_date *d){
    char tmp[5];
    tmp[0] = dt[0]; tmp[1] = dt[1]; tmp[2] = '\0';
    //cout << tmp[0]  << tmp[1] << endl;
    d->day = atoi(tmp);
    tmp[0] = dt[3]; tmp[1] = dt[4]; tmp[2] = '\0';
        //cout << tmp[0]  << tmp[1] << endl;
    d->month = atoi(tmp);

    for( int i=6; dt[i]; i++) tmp[i-6] = dt[i];
    d->year = atoi(tmp);
}


void TDate::setDate(char *dt){
    transDate(dt,&date);
    strcpy(sdate,dt);
}

string TDate::getDayWeek(){
    const string days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + 12 * a - 2;
    a = (7000 + (date.day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
    return days[a];
}

int TDate::getYearDif(char *dt){
    int y,m;
    m = getMonDif(dt);
    y = m/12;
    return y;
}

int TDate::getMonDif(char *dt){
    int m1,m2;
    struct_date d;
    transDate(dt, &d);
    m1 = d.year*12+d.month;
    m2 = date.year*12+date.month;
    return abs(m1-m2);
}

bool TDate::isLeapYear (int year) { //високосный год?
   if (((year%4==0) && (year%100!=0)) || (year%400==0)) return true;
   else return false;
}

//кол-во дней в пределах года
int TDate::KolDays (int d1,int m1,int d2,int m2,int y) {
 int i,s;
 int mondays[12]= {31,28,31,30,31,30,31,31,30,31,30,31};


 if (isLeapYear(y)) mondays[1]=29;
 if (m1==m2){ s=abs(d2-d1); return s;}
 else {
  if(m1 > m2){ //меняем даты местами
    i = m2; s = d2;
    m2 = m1; d2 = d1;
    m1 = i; d1 = s;
  }
  s=mondays[m1-1]-d1+1;   //дней осталось в этом месяце
  for (i=m1+1;i<m2;i++) s+=mondays[i-1];  //дней до след. месяца
  s+=(d2-1);  //дней в месяце m2
 }
 return s;
}

    //дней между датами
    // 1-я дата меньше второй
long TDate::getDayDif(struct_date &d1, struct_date &d2){

 int day1, mon1, year1;
 int day2, mon2, year2;
 int i,f;

 if (d1.year > d2.year){
    day2 = d1.day; mon2 = d1.month; year2 = d1.year;
    day1 = d2.day; mon1 = d2.month; year1 = d2.year;
 }else{
    day2 = d2.day; mon2 = d2.month; year2 = d2.year;
    day1 = d1.day; mon1 = d1.month; year1 = d1.year;
 }

 if (year1 == year2){
    f = KolDays(day1,mon1,day2,mon2,year1);
    return f;
 }

 f=KolDays(day1,mon1,31,12,year1)+1;
 for (i=year1+1; i<year2; i++) {
   f+=365;
   if (isLeapYear(i)) f++;
 }
 f+=(KolDays(1,1,day2,mon2,year2));
 return f;
}

// хоть и неполная, но некоторая проверка правильности даты
// пока не работает :(
bool checkDate(char *dt){
     return true;
     if( !( (dt[2] == '/') && (dt[5] == '/') )) return false;
     int len = 0;
     while(dt[len++]); // len == длина строки
     for( int i=0; i < len-1; i++ ){ // все цифры?
       if( i== 2 || i == 5 ) continue;  // символ / пропускаем
         if( !( ((int)dt[i]>47) && ((int)dt[i]<58) )) return false;
       }
     int d,m,y;
     dt[2] = '\0';
     d = atoi(dt);
     dt[5] = '\0';
     m = atoi(&dt[3]);
     y = atoi(&dt[6]);
     //cout << d << " " << m << " " << y << endl;
     if( y < 1582 ) return false;
     if ( d < 1 || d > 31 ) return false;
     if ( m < 1 || m > 12 ) return false;
}

int main()
{
 //   setlocale(LC_CTYPE, "rus");
    char s[80];
    TDate d;
    struct_date dt;

    cout << " \
    Program to work with dates \n \
    Dates must be after 15 October 1582 \n \
    Comands: \n \
    s <date>  - dd/mm/yyyy> Save date  \n \
    w - day of week \n \
    y <date>  - Difference in years with date saved (y 02/09/2017) \n \
    m <date>  - Difference in months with date saved (m 02/09/2017) \n \
    d <date>  - Difference in days with date saved (d 02/09/2017) \n \
    q - quit \n";
    bool ok = true;
    while(ok){
      cout << "Enter the command: ";
      gets(s);
      if( (s[0] != 'w') && (s[0] != 'q') ){  //check date format
        if( !checkDate(&s[2]) ){
          cout << "Invalid date" << endl;
          continue;
        }  
      }
      switch (s[0]) {
        case 'q' :  { ok = false; break; };
        case 's' :{
          d.setDate(&s[2]);
          cout << "Date is saved" << endl; 
          break;
        }
        case 'w' :{
          cout << d.getDayWeek() << endl;  break;
        }
        case 'y' :{
          cout << "Full years: " << d.getYearDif(&s[2]) << endl;  
          break;
        }
        case 'm' :{
          cout << "Full months: " << d.getMonDif(&s[2]) << endl;  break;
        }
        case 'd' :{
          d.transDate(&s[2], &dt);
          cout << "Days: " << d.getDayDif(dt, d.date) << endl; break;
        }
        default: cout << "Invalid command" << endl;
      }
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}



