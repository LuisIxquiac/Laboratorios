#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Ingresamos los datos experimentales
float dat[2][7]={{1,2,3,4,5,6,7},{20,26,31,38,45,49,54}};

//Definimos los prototipos de las funciones a utilizar
//t representa a X o a Y: t0=x t1=y
float st(int i);
float st2(int i);
float sxy();
float m(float,float,float,float,float);
float b(float,float,float,float);
float dm(float,float,float,float);
float db(float,float);
float r(float,float,float,float,float,float);

//Iniciamos la funcion principal
void main(void){
	printf("\n***INICIANDO PROGRAMA EN C***\n\n");
	//Inicializamos algunas de las variables a utilizar
	float n=7;				//numero de parejas de datos experimentales
	float e=0.2;				//error en la variable x de los datos experimentales
	float vm=m(n,st(0),st(1),sxy(),st2(0)); //Valor de la pentiente
	float vb=b(n,st(0),st(1),vm);		//Valor del intersecto con el eje y
	float vdm=dm(n,st(0),st2(0),e);		//Incertesa en la pendiente
	float vdb=db(n,e);			//Incertesa en el intersecto con el eje y
	
//	float vr=(n,st(0),st(1),sxy(),st2(0),st2(1));
	//Se imprimen en pantalla los valores obtenidos con el metodo de minimos cuadrados
	printf("REGRECION LINEAL COMPLETADA\n");
	printf("Los valores obtenidos son:\n\n");
	printf("El valor de m es: m=%f\n",vm);
	printf("El valor de b es: b=%f\n",vb);
	printf("El valor de dm es: dm=%f\n",vdm);
	printf("El valor de db es: db=%f\n",vdb);

	printf("GENERANDO ARCHIVO PARA GRAFICAR");
	
	//Se procede a generar el archivo que despues se llamara con gnuplot para crear las graficas
	char linea1[100];
        sprintf(linea1,"plot ((%f)*x)+(%f),'data.txt' using 1:2 with points pt 4 ps 2    \n",vm,vb);

	FILE* fichero;
        fichero = fopen("graficador.txt", "wt");
        fputs("set terminal jpeg\n", fichero);
	fputs("set title 'Evolucion atletica'\n", fichero);
	fputs("set xlabel 'Semana'\n", fichero);
	fputs("set ylabel 'Peso(kg)'\n", fichero);
	fputs("set xrange [0:11]\n", fichero);
	fputs("set yrange [10:80]\n", fichero);
	fputs("set grid\n", fichero);
	fputs("set output 'grafica.jpeg'\n", fichero);
	fputs(linea1, fichero);
        
        fclose(fichero);




	printf("\nARCHIVO PARA GRAFICAR GENERADO\n");
	float est=((vm)*(12)+(vb));
	//Se da respuesta a una de las preguntas de el problema hacerca de si el atleta podra estar listo para su prueba segun el modelo de minimos cuadrados.
        printf("\n\n\nSegun el modelo de minimos cuadrados, para la semana de la competicion, el atleta podra levantar un peso de %f Kg. Esto es menor a 150Kg, por lo que el atleta no podra estar listo para evaluacion, suponiendo que su evlucion obedezca la prediccion de este modelo\n\n\n",est);

        printf("\n\nPROCESO EN LENGUAGE C COMPLETADO\n");


	
}

//A continuacion se definen todas las funciones a utilizar.
////La primeras 3 funciones implican unicamente sumatorias de los valores experimentales
//Las siguientes 4 funciones son los parametros de el modelo teorico de minimos cuadrados. Estas 4 funciones son unciones, en particular, de las primeras 3 funciones definidas a continuacion.
float st(int i){
	float res=0;
	for(int j=0;j<7;j++){
		res=res+dat[i][j];
	} 
	return res;
}

float sxy(){
	float res=0;
        for(int j=0;j<7;j++){
                res=res+(dat[0][j])*(dat[1][j]);
        }
        return res;
}

float st2(int i){
        float res=0;
        for(int j=0;j<7;j++){
                res=res+(dat[i][j])*(dat[i][j]);
        }
        return res;
}

float m(float n, float sx, float sy, float sxy, float sx2){
	return ((((n)*(sxy))-((sx)*(sy)))/(((n)*(sx2))-((sx)*(sx))));
}

float b(float n, float sx, float sy, float m){
	return (((sy)-((m)*(sx)))/(n));
}

float dm(float n, float sx, float sx2, float e){
	return (((sqrt(n))*(e))/(sqrt(((n)*(sx2))-((sx)*(sx)))));
	
}

float db(float n, float e){
	return ((e)/(sqrt(n)));
}
/*
float r(float n, float sx, float sy, float sxy, float sx2, float sy2){
	return ((((n)*(sxy))-((sx)*(sy)))/(sqrt((((n)*(sx2))-((sx)*(sx)))*(((n)*(sy2))-((sy)*(sy))))));
}
*/

