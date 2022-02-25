#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

namespace stats
{
using namespace std;


//Estructura

typedef struct
{

int tamanio;
int arreglo [200];

} Vector;

// Funciones

double promedio_vector(Vector datos)
 {
     double promedio=0;
     for (int a=0;a<datos.tamanio;a++)
     {
         promedio +=datos.arreglo[a];
     }
     promedio= promedio/datos.tamanio;
     return promedio;
};

int mediana_vector (Vector datos){
	sort(datos.arreglo, datos.arreglo+ datos.tamanio);

	int mitad= datos.tamanio/2;
	
    return mitad;
};



int moda_vector (Vector datos){
	//int mod [datos.tamanio];
	
	int rango=0;
	int repeticiones=0;
	int moda;
	int frecuencias[251];
	
	for (int i=0; i<251; i++){frecuencias[i]=0;}

	for (int b=0; b<datos.tamanio; b++){
		frecuencias[datos.arreglo[b]]++;
	}	
		
	   for (rango= 0; rango <=250; rango++) {
	   if (frecuencias[rango] > repeticiones) {
	   	repeticiones= frecuencias [rango];
		moda= rango;
	             }
	   }

	return moda;

}

double varianza_vector(Vector datos){

	double s_2;
	double promedio;
	
	promedio= promedio_vector(datos);
	
	for (int a=0;a<datos.tamanio;a++){
		s_2+= pow(datos.arreglo [a]-promedio,2);
	}

        s_2= s_2/(datos.tamanio-1);
	
	return s_2;
}


double desviacion_estandar (Vector datos){

        double desviacion_e;

	   desviacion_e= sqrt(varianza_vector (datos));
	
	return desviacion_e;
}


}

using namespace stats;
//Vector de tamaño 200/
int main(){
const int n=200;

	Vector vector1;

vector1.tamanio= 200;
	int i;

	srand (time(0));
for (i=0; i<200; i++){

	vector1.arreglo[i]= rand()% 150+100;
	
	printf("%d \n", vector1.arreglo[i]);
           }
	
//Pruebas
double promedio= promedio_vector(vector1);
printf("El promedio es: %f \n", promedio);

int mediana= mediana_vector(vector1);
printf("La mediana es: %d \n", mediana);

int moda= moda_vector(vector1);
printf("La moda es: %d \n", moda);

double varianza= varianza_vector(vector1);
printf("La varianza es: %f \n", varianza);

double DE= desviacion_estandar(vector1);
printf("La desviacion estandar es: %f\n", DE);

}

