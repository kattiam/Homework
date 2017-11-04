
/*
Напишите программу для работы с C-style строками. Такие строки
оканчиваются символом ‘\0’.
В программе должна быть структура с конструктором и деструктором,
хранящая динамический массив символов и и размер строки. В структуре
должны быть методы для получения длины(strlen), для получения символа по
индексу(get(i)), для изменения символа по индексу(set(i))
В структуре должны быть методы для конкатенации строки к
текущей(приписывание), поиска подстроки(возвращает номер первого символа
подстроки или -1, если такого нет), получения подстроки от i’ого до j’ого
индекса включительно.
*/

//ДОМАШНЯЯ РАБОТА 5.11.2017

#include <cstdlib>
#include <iostream>

using namespace std;

class TString{
  public:
  int len;
  char * str;
  int getlen(char* s);
  TString(char* s);
  ~TString(){
     if( str != 0) delete [] str;          
  };
  int strlen();
  char get(int i);
  void set(int i, char c);
  void concat(char *s);
  int indexOf(char *s);
  char * substr(int i1, int i2);
};
//конструктор
TString::TString(char* s){
  len = getlen(s);
  str = new char[len];
  for( int i=0; i < len; i++) str[i] = s[i];
}


int TString::getlen(char* s){
  int i = 0;
  while( s[i++] );
  return i; 
};

// return длину строки
int TString::strlen(){
  return len;  
}

// return символ на позиции i
char TString::get(int i){
  char ch = str[i];   
  return str[i];   
}
//заменить символ на позиции i
void TString::set(int i, char c){
  if(i < len-1) str[i] = c;   
}
// приклеить подстроку
void TString::concat(char * s){
  int slen = getlen(s);
  char *d = new char [len-1+slen];
  for(int i=0; i < len-1; i++) d[i] = str[i];
  for(int i=0; i< slen; i++) d[len-1+i] = s[i];
  delete [] str;
  str = d;
  len = len-1 + slen;   
}
// индекс подстроки 
int TString::indexOf(char* s){
  int slen = getlen(s);
  if(slen > len) return -1;
  for(int i=0; i<len-slen+1; i++){
    bool ok = true;
    for( int j=0; j<slen-1; j++){
      if( str[i+j] != s[j] ){ ok = false; break;}; 
    }
    if( ok ) return i;
  }
  return -1;  
}
//выделить подстроку от i1 до i2
char * TString::substr(int i1, int i2){
  if( i1 > i2) return " Error index";
  if(i2 > len-2) return "Error index";
  char *d = new char[i2-i1 +2];
  for(int i = i1; i < i2+1; i++) d[i-i1] = str[i]; 
  d[i2-i1+1] = '\0';
  return d;
}

int str2int(char * s, int &ind){
  char tmp[80];
  int i=ind;  
  for(i=0; s[i] != ' '; i++) tmp[i]=s[i];
  tmp[i]='\0';
  ind = i;
  return atoi(tmp); 
    
}    
int main(int argc, char *argv[])
{

// TString st = TString("Long string");
/*
 cout << st.strlen() << endl;
 cout << st.str << endl;
 cout << st.get(1) << endl;
 st.set(3,'d'); cout << st.str << endl;
 st.concat(" and small"); cout << st.str << endl;
 cout << st.indexOf("str") << endl;
 cout << st.substr(6,8) << endl;
 
*/
    char s[80];
    char tmp[80];
    int i;

    cout << "Program to work with string" << endl;
    cout << "Enter the base string: ";
    gets(s);
    TString st = TString(s);
    cout << " \
    There are the following commands:\n  \
    l - string length \n \
    g <i> - get char i \n \
    s <i> <char> - set char into string[i] \n \
    c <str> concatenate str to saved string \n \
    i <substring> - index of substring \n \
    u <i1> <i2> - get substring \ n \
    q - quit \n \
\n";

  bool ok = true;
  char cmd;
  
  while( ok ){
    cout << "Enter the command\n";
    cin >> cmd;
    switch(cmd){
      case 'q': {  // quit
           ok = false; 
           break; 
           st.~TString();  //destructor: освобождаем память строки
      };
      case 'l': { 
           cout << st.strlen() << " "; 
           cout << st.str << endl;
           break; 
      }
      case 'g': { // вывод символа
           int i;  cin >> i;
           cout << st.get(i) << endl; break;
      };
      case 's': { // заменить символ
           int i;
           cin >> i; 
           cin >> tmp; 
           st.set(i, tmp[0]);
           cout << st.str << endl; 
           break;
      };
      case 'c': {  //приклеить подстроку
        cin.getline(tmp,80);   //читаем остаток строки
        //cout << &tmp[1] << endl;   
        st.concat(&tmp[1]); 
        cout << st.str << endl; 
        break;     
      }  
      case 'i': {  // Index начала подстроки
        cin.getline(tmp,80);   //читаем остаток строки
        cout << st.indexOf(&tmp[1]) << endl; 
        break;   
      } 
      case 'u': {  //get substring
        int i1, i2;
        cin >> i1;
        cin >> i2;   
        cout << st.substr(i1, i2) << endl;
        break;   
           }  
      default: {cout << "Invalid command" << endl; break; };
    }  
}  

    system("PAUSE");
    return EXIT_SUCCESS;
}
