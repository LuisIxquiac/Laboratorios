/*
Autor:   Lubuntu
Compilador:   gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
C
Compilado:  gcc problema5.c 
Fecha:  sáb mar 28 16:33:29 CST 2020
Librerias:   stdio.h
Resumen:   El usuario ingresa un numero entero no negativo y el programa devuelve el factorial de el numero ingresado.
Entradas:   Un numero entero no negativo
Salidas:   Un numero entero no negativo
*/



//INICIO DE EL PROGRAMA


#include <stdio.h>

int fact(int n);                    //Declaramos la funcion fact. Esta recibe un numero entero no negativo y devuelve el factorial de este numero.
void main(void){

int a;				    //Esta variable entera a, almacenara el numero que el usuario ingrese que se ide a continuacion.
printf("Ingrese un numero entero no negativo: \n\n n= ");
scanf("%i",&a);

if(a>=0){
	printf("\n %i!= %i \n",a,fact(a));  //Una vez ingresado el numero, se manda a llamar a la funcion fact para imprimir el resultado de el factorial de el numero ingresado.



}
else printf("\n\nEl numero que ingreso era negativo\n");




}

int fact(int n){

	if(n==1 || n==0)
	{
		return 1;
	}
	else
	{
		return n*fact(n-1);
	}

}
