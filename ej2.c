#include <stdio.h>
//El funcionamiento de esta funcion pr se basa en el funcionamiento de el primer ejecicio de este laboratorio. Esta funcion recibe un numero entero mayor que uno u devuelve: 1 si el numero era primo, o 0 si el numero no era primo.
int pr(int x)
{
        int n=2, primo=1;
    
        if(x>1){
		while(n<x && primo==1){
                        if((x%n)==0){
                                primo=0;
                        }
                        else{
				n=n+1;
                        }

                }
                if(primo==1){
                        return 1;
                }
                else{
                        return 0;
                }
        }
}


void main(void){
//Declaramos las variables a y b donde se espera almacenar los numeros que determinaran los extremos de un intervalo. Este intervalo se espera que este formado por numeros enteros mayores a uno.
//Si se ingresa como extremo de el intervalo un numero que no satisfaga esto, se indicara su error al usuario y el programa finalizara.
	int a,b;
	printf("Ingrese un numero entero mayor a uno: ");
	scanf("%i",&a);

	if(a>1){
		printf("\n Ingrese otro numero entero mayor que uno: ");
		scanf("%i",&b);
		if(b>1){
			//Si se llego hasta este punto, ambos numeros ingresados cumplieron los requerimentos.
			//A continuacion se utiliza un condicional if para establecer cual de los numeros ingresados sera el extremo menor de el intervalo y cual sera el extremo mayor de el intervalo. En base a cada uno de estos dos casos, el codigo que sigue sera analogo para mabos casos. La unica diferencia sera de donde a donde se barreran las variables para ir verificando numero a numero si son o no primos.

			if(b>a){
				//En este caso b>a, se declara una varibale m=a, la cual mediante un ciclo while se ira variando a travez de todos los numeros entre a y b. Co l aayuda de la funcion pr se determinara si el numero es primo o no. Si si es primo, entonces se indicara en pantalla. Se declara tambien la variable y que servira como contador de cuantos numero primos se van encontrando. Al finalizar, se mostrara el resultado de cuantos numeros primos se encontraron en total.
				int y=0;
				int m=a;
				while(m<=b){
					if((pr(m))==1){
						printf("\n   El numero %i es primo",m);
						y++;

					}
					m++;

				}
				printf("\n  En total se encontraron %i numeros primos entre %i y %i",y,a,b);
			
			}
			else{
				//El codigo es analogo al caso anterior.
				int y=0;
                                int m=b;
                                while(m<=a){
                                        if((pr(m))==1){
                                                printf("\n  El numero %i es primo",m);
                                                y++;

                                        }
                                        m++;

                                }
                                printf("\n  En total se encontraron %i numeros primos entre %i y %i",y,b,a);



			}


		}

		else{
			printf("El numero ingresado no cumple con los requerimentos solucitados");
		}


	}
	else{
		printf("El numero ingresado no cumple con los requerimentos solicitados");
	}



}

