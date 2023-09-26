#include <iostream>

using namespace std;
void patron1(int **);
void patron2(int **);
void patron3(int **);
void patron4(int **);
void encendertodosleds(int **);

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
        encendertodosleds(matriz);
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

void patron3(int **matriz)
{
    int cont=0, aux=0;
    for(int i=0; i<8;i++){
        for(int j=0; j<8; j++){
            if(cont<2){
                matriz[i][j]=1;
                cont+=1;
            }
            else if(cont==2){
                cont=0;
            }
        }
        cont=aux;
        if(i%2==0){
            if(aux==0){
                aux=2;
            }
            else if(aux=2){
                aux=0;
            }
        }
    }
}

void patron4(int **matriz)
{
    bool ban=true;
    int cont=0, lim=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(j>=lim && cont<4){
                matriz[i][j]=1;
                cont+=1;
            }
        }
        cont=0;
        if(i==3){
            ban=false;
        }
        else if(ban){
            lim+=1;
        }
        else if(!ban){
            lim-=1;
        }
    }
}

void encendertodosleds(int **matriz)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matriz[i][j] = 1;
        }
    }
}
