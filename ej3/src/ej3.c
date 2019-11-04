////////////////////////////////////////////////////////////////////////////////
/*Realice un programa en omp que realice la suma de vectores de tamaño N (1024,
 *2048, 4096) utilizando 2, 4, 6 y 8 procesos. Tome tiempos de ejecución y mues-
 * tre un gráfico que indique la escalabilidad del sistema.
 */
////////////////////////////////////////////////////////////////////////////////
//Diego Martínez Guillén-dmartinez17@alu.ucam.edu
////////////////////////////////////////////////////////////////////////////////
////////////////////////////INCLUDES////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
/////////////////////////////MACROS/////////////////////////////////////////////
#define N    131072
#define NHILOS 2
/////////////////CABECERAS DE MÉTODOS Y FUNCIONES///////////////////////////////

//////////////////////////////MAIN//////////////////////////////////////////////
int main () {
    int i;
    int n=N;
    int nhilos;
    //Creación de vectores con memória dinámica
    float *x=NULL;float *y=NULL;float *z=NULL;
    x = (float*)malloc(N*sizeof(float));
    y = (float*)malloc(N*sizeof(float));
    z = (float*)malloc(N*sizeof(float));
    //Inicializamos vectores con valores de 0 a 9999
    for (i = 0; i < N; i++){
        x[i] = y[i] = z[i] = (float)(rand()%10000);
    }
    omp_set_num_threads(NHILOS);
    double tbegin = omp_get_wtime();//inicio medida del tiempo
    #pragma omp parallel for private(i)
        for (i = 0; i < n; i++) 
        {
            x[i] = y[i] + z[i];
        }
    //fín de la región paralela
    double wtime = omp_get_wtime() - tbegin;//fín medida del tiempo
    printf("\nLa operacion ha tardado %fs\n",wtime);
}