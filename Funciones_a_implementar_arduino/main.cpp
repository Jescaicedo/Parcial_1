#include <iostream>

using namespace std;
void patron1(int **);
void patron2(int **);

int main()
{
    int filas = 8;
        int columnas = 8;
        int** matriz = new int*[filas];
        for (int i = 0; i < filas; ++i) {
            matriz[i] = new int[columnas];
        }
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                matriz[i][j] = 0;
            }
        }
        patron2(matriz);
        for(int i=0; i<8;i++){
            for(int j=0; j<8;j++){
                cout<<matriz[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int i = 0; i < filas; ++i) {
            delete[] matriz[i];
        }
        delete[] matriz;

        return 0;
}

void patron1(int **matriz)
{
    bool ban=false;
    int lim=3, cont=2, conta=0;
    for(int i=0; i<8;i++){
        for(int j=0; j<8;j++){
            if(j>lim-1 && conta<cont){
                matriz[i][j]=1;
                conta+=1;
            }
        }
        conta=0;
        if(!ban && lim!=0){
            lim-=1;
            cont+=2;
        }
        else if(ban){
            lim+=1;
            cont-=2;
        }
        else if(lim==0){
            ban=true;
        }
    }
}

void patron2(int **matriz)
{
    for(int i=0; i<8; i++){
        matriz[i][i]=1;
    }
    int cont=7;
    for(int i=0; i<8;i++){
        matriz[i][cont]=1;
        cont-=1;
    }

}
