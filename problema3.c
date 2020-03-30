/*
Autor:   Lubuntu
Compilador:   gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
C
Compilado:  gcc problema3.c 
Fecha:  sáb mar 28 13:08:01 CST 2020
Librerias:   stdio.h math.h
Resumen:   Solicita al usuario que increse las coordenadas respecto a una base ortonormal de dos vectores en pertenecientes a un espacio vectorial de dimencion finita 3. El programa luegevuelve los valores de: a) norma de cada vectos  b)suma de los dos vectores  c) producto escalar de los 2 vectores  d)producto vectorial de los 2 vectores
Entradas:   las 3 coordenadas en una base ortonormal de dos vectores pertenecientes a un espacio vectorial de dimencion 3
Salidas:   valor de la norma de cada vector ingresado, un vector igual a la suma de los dos vectores ingresados, el producto escalar y el producto vectorial de los 2 vectores ingresados.
*/


//***NOTA IMPORTANTE. PARA COMPILAR EL PROGRAMA LO TUVE QUE HACE UTILIZANDO EL COMANDO: gcc problema3.c -lm  . Aun no entiendo a pronfundidad que hace esto, pero era necesario para solucionar el siguiente problema: La funcion sqrt de math.h, no funcionaba si como argumento introducia a una variable. Es decir:
// el siguiente codigo no funcionaba:  double c=5; d=sqrt(c);. Pero el siguiente codigo si lo hacia: d=sqrt(5);




//INICIO DE EL PROGRAMA

#include <stdio.h>
#include <math.h>
void main(void){

	float X[3];     //Se declaran los 2 vectores X y Y de longitud 3 cada uno.
	float Y[3];
			
			//Se ingresan las coordenadas de ambos vectores.
	printf("A continuacion se le solicitara que ingrese las 3 coordenadas respecto a una base ortonormal de 2 vectores pertenecientes a un espacio vectorial de dimencion3\n\n\n");

	printf("Coordenadas de el vector X:\n\n");
	for(int i=0;i<3;i++)
	{
		printf("Ingrese la coordena X%i: ",i);
		scanf("%f",&X[i]);
	
	
	}

	printf("\n\n\nCoordenadas de el vector y:\n\n");
        for(int i=0;i<3;i++)
        {
                printf("Ingrese la coordena Y%i: ",i);
                scanf("%f",&Y[i]);


        }

			//Se muestra en pantalla cuales fueron los vectores ingresados.
	printf("\n\n\nEl vector X es:  ");
	for(int i=0;i<3;i++)
	{
		printf("%f, ",X[i]);
	}
	
	printf("\n\n\nEl vector Y es:  ");
        for(int i=0;i<3;i++)
        {
                printf("%f, ",Y[i]);
        }

			//Se procede a calcular toda las salidas de este programa. Cada una de estas salidas depende unicamente de los datos que ya se ingresaron de los vectores.
	//Calculando Suma
	float sumav[3]={X[0]+Y[0],X[1]+Y[1],X[2]+Y[2]};
	//Calculando Norma de X
	float normax=sqrtf(X[0]*X[0]+X[1]*X[1]+X[2]*X[2]);
	//Claculando Norma de Y
	float normay=sqrtf(Y[0]*Y[0]+Y[1]*Y[1]+Y[2]*Y[2]);
	//Calculando Producto escalar X.Y
	float pescalarxy=X[0]*Y[0]+X[1]*Y[1]+X[2]*Y[2];
	//Calculando Producto vectorial X x Y
	float pvectorialxy[3]={X[1]*Y[2]-X[2]*Y[1],X[2]*Y[0]-X[0]*Y[2],X[0]*Y[1]-X[1]*Y[0]};
			
			//Una vez calculadas todas las salidas, se procede a mostrar en pantalla los resultados obtenidos.
	//Imprimiendo Suma
	printf("\n\n\n X+Y=  ");
	for(int i=0;i<3;i++)
        {
                printf("%f, ",sumav[i]);
        }
	//Imprimiendo Norma de X
	printf("\n\n norm(X)= %f",normax);
	//Impreimiendo Norma de Y
	printf("\n\n norm(Y)= %f",normay);
	//Impreimiendo producto escalar X.Y
	printf("\n\n X.Y= %f",pescalarxy);
	//imprimiendo producto vectorial X x Y
	printf("\n\n XxY= ");
        for(int i=0;i<3;i++)
        {
                printf("%f, ",pvectorialxy[i]);
        }

	
	printf("\n");

}


//FIN DE EL PROGRAMA



