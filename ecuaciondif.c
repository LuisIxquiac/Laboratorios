/*
Autor:   Lubuntu
Compilador:   gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
C
Compilado:  gcc ecuaciondif.c 
Fecha:  jue abr 23 22:06:32 CST 2020
Librerias:   stdio.h, math.h
Resumen:   Solucion de una ecuacion diferencial preestablecida mediante 4 metodos numericos distintos
Entradas:   ninguna
Salidas:   Tabla de valores numericos de la funcion solucion para cada uno de los 4 metodos
*/

#include <stdio.h>
#include <math.h>



//Se resolvera la ecuacion diferencial
//y'=f(t,y)
// con f(t,y)=y-t*t+1
// por medio de 3 metodos diferentes en en intervalo [0,2]. Metodo de Euler; metodo de punto medio; metodo de Heun.



//Devuelve f(ti,yi)
float fi(float ti, float yi){
        float fi = yi-ti*ti+1;
        return fi;
}



//NOTACION: m=i+1

//Metodo de Euler.
float yme(float h,float ti, float yi){
        float yme=yi+h*fi(ti,yi);
        return yme;
}


//NOTACION j=i-1
//
//Metodo de Punto Medio.
float ymp(float a,float h,float ti, float yi,float yj){
        float ymp;
        if (ti==a){
                //En este caso, yj no existe y por eso se utiliza el metodo de Euler
                ymp=yme(h,ti,yi);
        }else{
                ymp=yj+2*h*fi(ti,yi);
        }
        return ymp;
}




//Metodo de Euler Modificado.

float ymem(float h,float ti, float yi){
        float ymem=yi+(h/2)*(fi(ti,yi)+fi(ti+h,yi+h*fi(ti,yi)));
        return ymem;

}

//Metodo de Heun
float ymh(float h, float ti, float yi){
        float ymh=yi+(h/4)*(fi(ti,yi)+3*fi(ti+(2/3)*(h),yi+(2/3)*h*fi(ti,yi)));
        return ymh;

}
void main(){

        //Delimitamos el intervalo de solucion y su particion.
        float a,b,h;
        int n=10;
        a=0;
        b=2;
        h=(b-a)/n;
        //Ingresamos las condiciones iniciales.
        float yi=0.5, ti=0;
        float yie=yi, yip=yi, yiem=yi, yih=yi;
        float yjp,aux;

        //Imprimimos los resultados.
        printf("                   Metodo de Euler    Punto Medio        Euler Modificado   Heun   \n\n");
        printf("t0=%f        y0=%f        y0=%f        y0=%f        y0=%f         \n",ti,yie,yie,yie,yie);

        for(int i=1;i<n;i++){
                //Euler
                yie=yme(h,ti,yie);

                //Punto Medio
                aux=yip;
                yip=ymp(a,h,ti,yip,yjp);
                yjp=aux;

                //Euler Modificado
                yiem=ymem(h,ti,yiem);

                //Heun
                yih=ymh(h,ti,yih);

                ti=i*h;
                printf("t%i=%f        y%i=%f        y%i=%f        y%i=%f        y%i=%f   \n",i+1,ti,i+1,yie,i+1,yip,i+1,yiem,i+1,yih);
        }




        printf("\n\n*NOTA: El algoritmo matematico que utilize para el metodo de el punto medio no es el de la presentacion. Este lo encontre en internet.\n\n");

}
