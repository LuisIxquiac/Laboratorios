/*
Autor:   Lubuntu
Compilador:   gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
C
Compilado:  gcc problema1.c 
Fecha:  vie mar 27 18:22:06 CST 2020
Librerias:   stdio
Resumen:   Permite al usuario visualizar un vector de numeros pares entre 2 y 20 de forma acendente o desendente
Entradas:   Un menu de seleccion con dos opciones "a" y "b"
Salidas:   Un verctor de numeros
*/


#include <stdio.h>


// Se tendra un vector de longitud 10 por default. Primero se imprimira ese vector en pantalla. Luego, utilizando el metodo de ordenacion de burbuja, se procede a ordenar dicho vector de manera ascendente. Luego se crea un menu con 3 opciones: a, b, q. La opcion a imprime en pantalla el vector de manera ascendente. La opcion b lo imprime al reverso, de manera que se imprime de forma desendente. La opcion q es por si se desea salir de el programa. Si se ingresa alguna opcion que no sea alguna de las 3 mencionadas con anterioriad, se indicara que no era una opcion valida y se pedira al usuario que intente de nuevo ingresar una opcion valida.

//METODO DE ORDENACION DE BURBUJA:(Rcordatorio rapido de como funciona)
//Consiste en lo siguiente: 
//Se tiene un vector inicial de longitud n, sus entradas siendo numeros. Este metodo procede a reordenar dichos numeros de tal manera que queden de manera ascendente(o desendente). El metodo funciona de la siguiente manera:
//Para un vector de longitud n, el metodo realiza n-1 iteraciones (pasadas). En la primer pasada, se encarga de colocar al final de el vector a un numero perteneciente al vector tal que sea mayor o igual que el resto de las entradas. El como ocurre esto lo explicare al final. Por lo tanto, al finalizar esta pasada, se obtiene un vector tal que su ultima entrada es mayor o igual que todas las anteriores, dejando asi fija esa ultima entrada en el sentido que se queda fija porque esa parte de el vector ya esta bien deacuerdo a la ordenacion buscada. En la segunda pasada, se deja fijo a la penultima entrada de en vector. Siendo esta mayor o igual a todas las entradas que estan a su izquierda. En la tercera pasada, se deja fija a la antepenultima entrada. Y asi sucesivamente. Enla pasada n-1, se deja fija a la segunda entrada de izquierda a derecha. Siendo esta mayor o igual a la entrada que tiene a la izquierda. Una vez esta pasada esta terminada, la primera entrada es menor o igual a todas las que estan a su derecha. Por esta razon ya no se requiere de mas pasadas. RESPECTO A COMO SE LLEVA A CABO CADA PASADA: En la primera pasada, el proceso de llevar al valor de la entrada cuyo valor sea mayor o igual al resto de las entradas, hasta el final, se hace mediante comparaciones. En la primera pasada, se realizan n-1 comparaciones. (no dare mas detalles de como es este proceso, esto es solo un resumen para recordarme como funciona el metodo). En la segunda pasada, se realizan n-2 comparaciones (puesto que ya no se compara con el ultimo elemento de el vector, porque este ya esta fijo). En la tercera pasada, se realizan n-3 comparaciones. Y asi sucesivamente. En la pasada n-1, se realizan n-(n-1)=1 comparaciones (solo se compara la segunda con la tercera entrada).




//inicio de el programa
void main(void){

	int i;							//Se utilizara como contador para imprimir al vector cuando sea necesario
	int A[10]={8,2,12,16,20,4,2,4,14,10}; 			//Definicion de el vector a utilizar en este programa. Este contiene numeros pares entre 2 y 20 por instrucciones de el problema.
	char x;							//Se tendra un menu con 3 opciones: a,b,q. Esta variable x almacenara lo que el usuario ingrese a la computadora cuando se le solicite que escoja una opcion.
	int pasada=1;						//Sera un contador para la pasada que se este realizando
	int aux;						//Variable auxiliar que almacenara temporalmente una de las entradas de el vector para poder llevar a cabo el proceso de intercambio en el orden de las entradas de el vector.





	printf("El vector desordenado es:\n  \n");			//Muestra en pantalla la forma inicial de el vector.
	for(i=0;i<10;i++)
	{
		printf("%i, ", A[i]);

	}
								
	for(pasada=1;pasada<10;pasada++){			//El metodo de ordenacion burbuja. Aqui se reescribe el vector de tal manera que queda ordenado de manera ascendente.

		for(int j=0;j<10-pasada;j++)
		{
			if(A[j]>A[j+1]){
				aux=A[j];
				A[j]=A[j+1];
				A[j+1]=aux;
			}	
			
		
		}

	}
								//Fin metodo de ordenacion burbuja. Ahora el vector esta ordenado de manera ascendente.
		

	printf("\n \n \n");

	do{							//Ciclo que controla el funcionamiento de el menu para que opere de la manera descrita en la parte de arriba.
       	        printf("\n Escoja como desea visualizar el vector: \n");
	        printf("\n      a En forma ascendente");
       	        printf("\n      b En forma desendente\n \n");
		printf("\n      q salir de el programa\n \n \n");
		printf("Opcion: ");
		x = getchar();					//Como se meciono antes, se solicita que se escoja una de las 3 opciones de el menu y se almacena en la variable x.
		printf("\n \n \n");

		switch(x){					//switch que dirige que ocurrira dependiendo que que opcion se aya ingresado.

		        case 'a':
                        printf("El vector ordenado en forma ascendente es:\n \n");           //Si se escoge la opcion a, se imprime el vector de manera ascendente y el programa finaliza.
		        for(i=0;i<10;i++)
       		        {
        	        printf("%i, ", A[i]);
       		        }
			printf("\n");
			x='q';
			break;

                	case 'b':
			printf("El vector ordenado en forma desendente es:\n  \n");	    //Si se escoge la opcion b, se imprime el vector de manera desendente y el programa finaliza.
                        for(i=0;i<10;i++)
                        {
                        printf("%i, ", A[9-i]);
                        }
			printf("\n");
                        x='q';

			x='q';
			break;
			
			case 'q':							   //Si se escoge la opcion q, el programa finaliza.
			printf("\n Saliendo de el programa\n");
			break;
			
			default:
			printf("\n \n *****Por favor ingrese una opcion valida**** \n \n \n"); //Si no se escoge explicitamente ninguna de las opcionesanteriores, se repite el ciclo y se solicita de nuevo que se ingrese una de las opciones validas.

			break;
		}
			
	} while(x != 'q');


//FIN DE EL PROGRAMA.

}
