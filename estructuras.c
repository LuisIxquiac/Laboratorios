/*
Autor:   Lubuntu
Compilador:   gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
C
Compilado:  gcc estructuras.c 
Fecha:  mar mar 31 22:33:43 CST 2020
Librerias:   stdio.h
Resumen:   Es un ejemplo de como funcionan las estructuras
Entradas:   No solicita entradas
Salidas:   Elementos pertenecientes a una base de datos previamente ingresada
*/

#include <stdio.h>

//Declaramos la estructura info y sus variables
struct info
{
       char direccion[30];
       char municipio[20];
       char departamento[20];
} inf1, inf2, inf3, inf4, inf5;


//Declaramos las estructuras trabajador y supervisos(ambas dependen de la estructura info) y a sus variables.
struct supervisor
{
	int id;
	char nombre[30];
	struct info info_supervisor;
	float sueldo;
} sup1, sup2;

struct trabajador
{
        int id;
        char nombre[30];
        struct info info_trabajador;
        float sueldo;
        struct supervisor supervisor_trabajador;
} trab1, trab2, trab3;

void main(void){
	
//Definimos las variables de la estructura info
	struct info inf1={"3 calle 3-50","Mixco","Guatemala"};
	struct info inf2={"1ra calle 43-54","Antigua","Zacatepeques"};
	struct info inf3={"8 calle 14-42","Guatemala","Guatemala"};
	struct info inf4={"5 calle 43-34","Zunil","Quetzaltenango"};
	struct info inf5={"1 calle 71-49","Guatemala","Guatemala"};
//Definimos las variables de las estructuras trabajador y supervisor, utilizando las variables ya definidas de la estructura info

	struct supervisor sup1={1,"Mynor",inf5,9999};
	struct supervisor sup2={2,"Laura",inf4,5000};

	struct trabajador trab1={1,"Juan",inf1,1000,sup1};
        struct trabajador trab2={2,"Maria",inf2,3000,sup2};
        struct trabajador trab3={3,"Marcela",inf3,500};





	printf("\n\ntrab 1 tiene la direccion: %s",trab1.info_trabajador.direccion);
	printf("\n\nLa direccion de el supervisor de trab2 es: %s\n",trab2.supervisor_trabajador.info_supervisor.direccion);




}




