//Напишите программу заполняющую квадратный двумерный массив, как показано в примере. 
//На главной диагонали стоят нули, а на остальных - удаление от главной диагонали.

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int N;
    cout << "Enter the dimension of the matrix" << endl;
    cin >> N;
    int mat[N][N];
    int i,j,k,d;
    for( k =0; k < N; k++){
        i = 0; j = k; d = k;
        while( j < N){
            mat[i][j] = d;
            if( i != j) mat[j][i] = d;
            i++; j++;
        }
    }
    for( i = 0; i < N; i++){
        for( j = 0; j < N; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
