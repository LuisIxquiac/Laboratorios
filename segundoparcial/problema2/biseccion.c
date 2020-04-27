#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//Definimos los prototipos de las funciones a utilizar:

//Funcion promedio de dos numeros
float pro(float,float);

//Funcion de el metodo de la biseccion
void bisec(float,float,int,float*,float*,int*,int*);


//Iniciamos la funcion principal
void main(void){
	//Declaramos las variables a utilizar: n=numero de iteraciones; a,b=los extremos inciales de el dominio a tomar en cuenta en el metodo de la biseccion; flag= tomara el valor igual a 1 si en dado caso se llega a encontrar una raiz de forma exacta mientras se este llevando a cabo el algoritmo de la biseccion
	int n;
	float a=-0.55, b=0.5;
	int flag=0;
	
	//Solicitamos que se ingrese el numero de iteraciones maximo que se desearia realizar
	printf("\n***Calculo de una raiz de la funcion arcsin(x) mediante el metodo de la biseccion:***\n");
	printf("\nIngrese el numero de iteraciones que desear efectuar: n= ");
	scanf("%i",&n);


	//Se ejecuta n veces el algoritmo de la biseccion
	for(int i=0;i<n;i++){
		bisec(a,b,n,&a,&b,&i,&flag);	
	}
	
	//Se muestran los resultados de el algoritmo:
	//Si el algoritmo encontro una raiz de forma exacta, entonces flag toma el valor de 1 y a continuacion se muestra dicho valor
	//si el algoritmo solo encontro un intervalo, entonces lo muestra a continuacion.
	if(flag==0){
		printf("\n\n\nLa raiz se encuentra en el rango de [%f:%f]\n",a,b);

		//A continuacion, creamos un archivo donde guardaremos los datos obtenidos para graficarlos
		char linea2[30];
		char linea3[30];
		float t=0;
		sprintf(linea2,"%f,%f\n",a,t);
		sprintf(linea3,"%f,%f\n",b,t);
		
		FILE* fichero;
	        fichero = fopen("datos.txt", "wt");
  	        fputs("ejex,ejey\n", fichero);
  	        fputs(linea2, fichero);
   	        fputs(linea3, fichero);
                fclose(fichero);
                printf("\nPROCESO EN LENGUAGE C COMPLETADO\n");
               

	}else if(flag==1){
		printf("La raiz es: x= %f",a);
		//A continuacion, creamos un archivo donde guardaremos el dato obtenido para graficarlo
                char linea2[30];
                float t=0;
                sprintf(linea2,"%f,%f\n",a,t);

                FILE* fichero;
                fichero = fopen("datos.txt", "wt");
                fputs("ejex,ejey\n", fichero);
                fputs(linea2, fichero);
                fclose(fichero);
                printf("\nPROCESO EN LENGUAGE C COMPLETADO\n");

	}

}

//FUNCION PROMEDIO
//Recibe dos numeros y devuelve el valor promedio de estos
float pro(float a,float b){
	return ((a+b)/2);
}


//FUNCION DE EL ALGORITMO DE LA BISECCION
//Para cada iteracion:
//Recibe los valores a,b de los extremos, y segun el criterio de el algoritmo de la biseccion devuelve(mediante almacenar el valor en su respectiva direccion de memoria) los valores de el nuevo intervalo mas corto a',b'. Todo esto ocurre en caso de no obtener una raiz de forma exacta.
//En el caso que obtenga una raiz exacta, almacena este valor en la direccion de memoria de la variable a. Ademas cambia el valor de la variable flag a 1. De esta manera se puede ejecutar de manera correcta el unico if que se explico en la funcion main.
void bisec(float a,float b,int n, float *ma, float *mb, int *mi, int *flag){

	if((asin(a))*(asin(pro(a,b)))<0){
		*mb=pro(a,b);
	}else if(((asin(a))*(asin(pro(a,b))))>0){
		*ma=pro(a,b);
	}else if(((asin(a))*(asin(pro(a,b))))==0){
		*ma=pro(a,b);
		*mi=n;
		*flag=1;
	}

}

/*
int main() {
    FILE* fichero;
    fichero = fopen("datos.txt", "wt");
    fputs("23\n", fichero);
    fputs("11\n", fichero);
    fputs("21\n", fichero);
    fclose(fichero);
    printf("Proceso completado\n");
    return 0;
}
*/
