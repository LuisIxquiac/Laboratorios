#include <stdio.h>

void main(void){
//Declaramos las variables a utilizar.
//la variable x almacenara el numero a ser evaluado
//la variable n sera utilizada como un contador, mayor explicacion de su funcion se dara mas adelante
//la variable primo se utilizara como variable booleana para determinar si el numero es primo o no
	int x;
        int n=2, primo=1;
//Solicitamos ingresar un numero natural mayor que 1.
	printf("Introduzca un número entero mayor que 1: ");
	scanf("%i",&x);
	if(x>1){
	
		//Inicia la verificacion si es primo o no
		//En un inicio, la variable primo=1, como si el numero si fuera primo. El siguiente ciclo while se encarga de verificar si el numero x es divisible por todos los numeros menores a x-1.
		//Si en algun momento se encuentra que SI es divisible por alguno de estos, entonces primo toma el valor =0 y el ciclo while termina y posteriormente se indica que no era primo (porque fue divisible por un numero que no era ni 1 ni el mismo)
		//Si en ningun momento se encuentra que es divisible por alguno de esos numeros, entonces significa que no era divisible por ninguno de ellos y por lo tanto es primo. El ciclo while termina entonces cuando todos estos numeros han sido verificados. Luego, se imprime en pantalla que el numero si era primo.
		while(n<x && primo==1){
			int y;
			y=x%n;
			if(y==0){
				primo=0;
			
			}
			else{
				n=n+1;
			}

		}


		if(primo==1){
			printf("El numero ingresado SI es un numero primo");
		}
		else{
			printf("El numero ingresado NO es primo");
		}


	}
	else{
		printf("El numero que ingreso no cumple los requerimentos solicitaods");
	}






}










