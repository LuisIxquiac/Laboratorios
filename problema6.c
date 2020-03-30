/*
Autor:   Lubuntu
Compilador:   gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
C
Compilado:  gcc problema6.c 
Fecha:  sáb mar 28 17:27:21 CST 2020
Librerias:   stdio.h, math.h
Resumen:   Se tienen predefinidas 4 funciones. La funcion f y h  tienen como dominio el conjunto de los numeros naturales y las funciones g y r tienen  como dominio el conjunto de los numeros naturales exepto el 1. El usuario ingresa un numero natural, y el programa devuelve el valor que cada una de estas funciones asigna al numero ingresado(Si es el caso que el numero ingresado si pertenece al dominio de las funciones)
Entradas:   Un numero natural
Salidas:   4 numeros
*/



//INICIO DE EL PROGRAMA


#include <stdio.h>
#include <math.h>
				//Declaramos las 4 funciones de n que nos daran el resultado que buscamos
int f(int n);     
float g(int n);
float h(int n);
float r(int n);

void main(void){
	int x;			//La variable x almacenara el valor de el numero natural que ingresemos
	printf("\nIngrese un numero natural:\n\n");
	printf(" n= ");
	scanf("%i",&x);
				//Se procede a llamar a cada una de las funciones para imprimir el valor que estas asignan al numero natural n (si es que n si pertenece a su dominio)

	printf("\n f(n)= %i",f(x));
if(x>1){
        printf("\n g(n)= %f",g(x));
}

	printf("\n h(n)= %f",h(x));
if(x>1){
	printf("\n r(n)= %f",r(x));
}

	printf("\n");

}
					//A continuacion se define cada una de las 4 funciones a utilizar. Todas se definen de manera recursiva para llevar a cabo la sumatoria.
int f(int n){
	if(n==1){
		return -2;
	}	
	else{
		return (n*n*(n-3)+f(n-1));
	}

}

float g(int n){
	if(n==2){
		return 3;
	}
	else{
		return (3/(n-1))+g(n-1);
	}

}

float h(int n){
	if(n==1){
		return 1;	
	}
	else{
		return (((1/(sqrt(5)))*(pow(((1+(sqrt(5)))/(2)),n)))-((1/(sqrt(5)))*(((1-(sqrt(5)))/(2)),n)))+h(n-1);
	
	}

}


float r(int n){
	if(n==2){
                return (7/10);
        }
        else{
                return ((0.1)*(4+(3)*(pow(2,n-2))))+r(n-1);
        }

 
}


//FIN DE EL PROGRAMA.
