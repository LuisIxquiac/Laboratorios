/*
Autor:   Lubuntu
Compilador:   gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
C
Compilado:  gcc problema2.c 
Fecha:  sáb mar 28 12:38:09 CST 2020
Librerias:   stdio
Resumen:   Solicita al usuaro que ingrese 5 numeros enteros, estos son almacenados en un vector, luego se ordenan de manera ascendente utilizando un metodo de ordenacion y finalmente se imprime el vector ordenado en pantalla,
Entradas:   5 numeros enteros.
Salidas:   vector de longitud 5
*/

//INICIO DE EL PROGRAMA

#include <stdio.h>


void main(void){

int A[5];                                       //En este vector se almacenaran los 5 numeros enteros que el usuario ingrese
int aux;					//Servira como variable auxiliar para llevar a cabo el proceso de intercambio en las posiciones de las entradas de el vector A al utilizar el metodo de ordenacion de burbuja.

printf("A continuacion, se le solicitara que ingrese 5 entradas de numeros enteros \n");

for(int i=0;i<5;i++)				//Este ciclo for almacena 5 numeros que se le solicitaran al usuario en el vector A
{
printf("\n Ingrese la entrada %i: ", i+1);
scanf("%i",&A[i]);
}

printf("\n\nEl vector ingresado es\n");		//Impreime en pantalla los 5 numeros ingresados
for(int i=0;i<5;i++)
{
printf("%i, ",A[i]);
}

for(int pasada=1;pasada<5;pasada++)		//Metodo de ordenacion de burbuja: Reordena el vector de manera que los valores en sus entradas queden de manera ascendente
{
	for(int i=0;i<5-pasada;i++)
	{
		if(A[i]>A[i+1]){
			aux=A[i];
			A[i]=A[i+1];
			A[i+1]=aux;
		
		}

	}
}
						//Una vez ordenado el vector, se imprime este en pantalla de manera ordenada ascendente.
printf("\n\nEl vector ordenado de manera ascendente es:\n");  
for(int i=0;i<5;i++)
{
printf("%i, ",A[i]);
}



printf("\n");
}

//FIN DE EL PROGRAMA
