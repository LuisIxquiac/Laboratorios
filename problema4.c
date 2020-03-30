/*
Autor:   Lubuntu
Compilador:   gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
C
Compilado:  gcc problema4.c 
Fecha:  sáb mar 28 19:02:06 CST 2020
Librerias:   stdio.h, math.h
Resumen:   El programa solicita al usuario que ingrese las entradas de dos matrices cuadradas de 3x3. El programa devolvera 9 resultados de operaciones que involucran las 2 matrices ingresadas.
Entradas:   numeros reales
Salidas:   numeros reales y matrices
*/


#include <stdio.h>

void main(void){

	float matA[3][3];
	float matB[3][3];
	float c;

	printf("\n A continuacion, ingrese las entradas de la matriz A:\n\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
	
			printf("\n A%i%i= ",i+1,j+1);
			scanf("%f",&matA[i][j]);

		}
	}

	printf("\n\n\n A continuacion, ingrese las entradas de la matriz B:\n\n");
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){

                        printf("\n B%i%i= ",i+1,j+1);
                        scanf("%f",&matB[i][j]);

                }
        }

        printf("\n\n\n A continuacion, ingrese un valor para definir una constante c:\n\n");
	printf("\n c= ");
	scanf("%f",&c);



	printf("\n\n\n***Los valores ingresados fueron***\n\n");
	printf("\n\nLa matriz A es: \n\n");
	for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%f  ",matA[i][j]);
                }
		printf("\n\n");
        }

	printf("\n\nLa matriz B es: \n\n");
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%f  ",matB[i][j]);
                }
                printf("\n\n");
        }

	printf("\n\nLa constante c es:  c= %f \n\n",c);
	
	printf("\n\n\n***Los resultados obtenidos son***\n\n");


	//Definicion de las variables donde se almacenaran los resultados:
	float mulAc[3][3];
	float suAB[3][3];
	float resAB[3][3];
	float mulAB[3][3];
	float detA;
	float trB[3][3];
	float invA[3][3];
	float rgjA[3][3];
	float rgjjA[3][3];
	float rgjB[3][3];
	float coA[3][3]; 
	float adjA[3][3];

	//Calculo de los resultados
	
	//Calculo Multiplicacion de la matriz A por la constante c
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			mulAc[i][j]=c*matA[i][j];
		}
	}

	//Calculo suma de las matrices A y B
	for(int i=0;i<3;i++)
        {
                for(int j=0;j<3;j++)
                {
			suAB[i][j]=matA[i][j]+matB[i][j];
                }
        }
	
	//Calculo de la resta de las matrices A y B
	for(int i=0;i<3;i++)
        {
                for(int j=0;j<3;j++)
                {
			resAB[i][j]=matA[i][j]-matB[i][j];


                }
        }

	//Calculo de la multiplicacion de las matrices A y B
	for(int i=0;i<3;i++)
        {
                for(int j=0;j<3;j++)
                {
                        mulAB[i][j]=0;
			for(int k=0;k<3;k++)
			{
				mulAB[i][j]=mulAB[i][j]+(matA[i][k])*(matB[k][j]);
			}

                }
        }


	//Calculo de el determinante de la matriz A
	detA=((matA[0][0])*((matA[1][1])*(matA[2][2])-(matA[1][2])*(matA[2][1])))-((matA[0][1])*((matA[1][0])*(matA[2][2])-(matA[1][2])*(matA[2][0])))+((matA[0][2])*((matA[1][0])*(matA[2][1])-(matA[1][1])*(matA[2][0])));

	
	//Calculo de la matriz transpuesta de la matriz B
	
	for(int i=0;i<3;i++)
        {
                for(int j=0;j<3;j++)
                {
			trB[i][j]=matB[j][i];
		
                }
        }



	//Calculo de la inversa de la matriz A (si es que existe)
	
		//Primero se calculara la matriz de cofactores de A: coA:
		

		coA[0][0]=(1)*((matA[1][1])*(matA[2][2])-(matA[1][2])*(matA[2][1]));
		coA[0][1]=(-1)*((matA[1][0])*(matA[2][2])-(matA[1][2])*(matA[2][0]));
		coA[0][2]=(1)*((matA[1][0])*(matA[2][1])-(matA[1][1])*(matA[2][0]));
		coA[1][0]=(-1)*((matA[0][1])*(matA[2][2])-(matA[0][2])*(matA[2][1]));
		coA[1][1]=(1)*((matA[0][0])*(matA[2][2])-(matA[0][2])*(matA[2][0]));
		coA[1][2]=(-1)*((matA[0][0])*(matA[2][1])-(matA[0][1])*(matA[2][0]));
		coA[2][0]=(1)*((matA[0][1])*(matA[1][2])-(matA[0][2])*(matA[1][1]));
		coA[2][1]=(-1)*((matA[0][0])*(matA[1][2])-(matA[0][2])*(matA[1][0]));
		coA[2][2]=(1)*((matA[0][0])*(matA[1][1])-(matA[0][1])*(matA[1][0]));

		//Calculamos la matriz adjunta de la matriz A. Esta es igual a la transpuesta de coA:

		for(int i=0;i<3;i++)
	        {
        	        for(int j=0;j<3;j++)
			{
                       		 adjA[i][j]=coA[j][i];
			}
	       	}

		//Ahora si se calcula la inversa

	if(detA != 0){

		for(int i=0;i<3;i++)
                {
               		 for(int j=0;j<3;j++)
                         {
                       		 invA[i][j]=(adjA[i][j])/(detA);
                         }
                }
		
	
	}




		//Calculo de rgjA
		float aux;
       		for(int i=0;i<3;i++)  //Copiamos la matriz A a la matriz rgjA.
                {
               		 for(int j=0;j<3;j++)
               		 {
                       		 rgjA[i][j]=matA[i][j];
              		 }
                }
		


		if(rgjA[0][0] !=0 || rgjA[1][0] !=0 || rgjA[2][0] !=0 ){
			//Si se esta en este punto, es porque almenos una de las entradas de la primera columna de A es distinta de cero. Se procedera asegurarse que la primera fila de A sea una fila tal que su primera entrada sea distinta de cero. Para esto, a continuacin se utilizara una serie de if's, en la que: A la primera entrada distinta de cero de la primera columna de A que se encuentre, se intercambiara toda la fila correspondiente a esa entrada con la primera fila de A. En el caso que la primera fila de A cumpla con que su primera entrada sea distinta de cero, entonces se quedara igual.
			if(rgjA[0][0] != 0){
								//Este es el caso donde la primera fila tiene una entrada distinta de cero en la primera columna. AQUI NO OCURRE NINGUN INTERCAMBIO.		

			//Ahora que estamos seguros que la primera fila tiene una entrada distinta de cero en la primera columna, se procede a hacer igual a 1 dicha entrada.
			for(int i=0;i<3;i++)
                        {	 
			   aux=rgjA[0][0];	
                    	   rgjA[0][i]=(rgjA[0][i])/(aux);
                       		 
                        }

			//Ahora que la entrada de la primera fila y la primera columna es igual a 1, procedemos a hacer cero todas las entradas restantes de esta misma columna.
			for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA10
                        {
                           aux=(-1)*(rgjA[1][0]);
                           rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                        }
			for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA20
                        {
                           aux=(-1)*(rgjA[2][0]);
                           rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                        }

			//AQUI CONCLUYE EL ANALISIS RESPECTO A LA PRIMERA COLUMNA. AHORA CONTINUA EL ANALISIS PARA LA SEGUNDA COLUMNA:
//******************
			//Ahora solo se analizaran las filas 2 y 3: Es decir, si hablamos de columnas, nos restringimos a las entradas de estas filas.
			//Se procedera a evaluar cual es la columna mas a la izquierda que tiene entradas distintas de cero. La primera columna obviamente no puede ser porque en los pasos anteriores se iso igual a cero todas sus entradas.
				if(rgjA[1][1] != 0 || rgjA[2][1] != 0){
					//Almenos una de las entradas de la segunda columna es distinta de cero
					//Se procede a encontrar la primera entrada de arriba para abajo que sea distinta de cero en esta segunda columna:
					if(rgjA[1][1] != 0){
						//La entrada de la segunda fila es distinta de cero
						//Entonces no se hace ningun intercambio. Solo se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.
						for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                             	   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
						for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                             	   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
						for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
						//AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

							//Se procedera a verificar si la entrada rgj22 es distinta de cero
							if(rgjA[2][2] != 0){
								//La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
								//Aqui la ago igual a 1
                                                   		rgjA[2][2]=1;
								//Haciendo a las entradas de arriba iguales a cero:
								rgjA[0][2]=0;
								rgjA[1][2]=0;

							}else{
								//La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
							}



					
					}else if(rgjA[2][1]){

						 //La entrada de la segunda es cero y la entrada de la tercera fila es distinta de cero.
                                                //Entonces se procede a hacer el intercambio. Luego se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.
                                        
						//Se procede a intercambiar la segunda fila con la tercera fila:
						for(int i=1;i<3;i++){
                                                   aux=rgjA[1][i];
                                                   rgjA[1][i]=rgjA[2][i];
                                                   rgjA[2][i]=aux;
                                                }

						for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }


					}
				
				}else if(rgjA[1][2] != 0 || rgjA[2][2] != 0){
					//Almenos una de las entradas de la tercera columna es distinta de cero
					//Se procede a encontrar cual es la entrada distinta de cero, ubicarla en la segunda fila, igualarla a uno y hacer a las entradas arriba y abajo de esta iguales a cero.
					if(rgjA[1][2] != 0){
						//La entrada rgjA12 es distinta de cero. Entonces no se realiza ningun cambio. Solo se procede a hacerla igual a uno y a hacer cero la entrada arriba y abajo de esta.		
						//Haciendola igual a 1:
						rgjA[1][2]=1;

						//Haciendo el resto de entradas iguales a cero:
						rgjA[0][2]=0;
						rgjA[2][2]=0;

					}else if(rgjA[2][2] != 0){
						//La entrada rgjA22 es distinta de cero. Entonces se procede a intercambiarla a la segunda fila, hacerla igual a uno y hacer cero el resto. Este proceso se puede simplificar como se muestra a continuacion.
						rgjA[1][2]=1;
						rgjA[0][2]=0;
						rgjA[2][2]=0;
					}

				}else{
					//Si se llego a este punto, es porque las cuatro entradas inferiores de la derecha son cero.
					//En este caso, no importa si las entradas de la primera fila y la segunda y tercera columa son distintas o iguales a cero. El algoritmo a terminado.
				}
//****************			

			}else if(rgjA[1][0] != 0){
								//Este es el caso donde el caso anterior no se cumplio y es la segunda fila la que tiene la entrada distinta de cero en la primera columna. AQUI SE INTERCAMBIA LA PRIMERA FILA CON LA SEGUNDA FILA.
				for(int i=0;i<3;i++){
					aux=rgjA[0][i];
					rgjA[0][i]=rgjA[1][i];
					rgjA[1][i]=aux;
				}

			//Ahora que estamos seguros que la primera fila tiene una entrada distinta de cero en la primera columna, se procede a hacer igual a 1 dicha entrada.
                        for(int i=0;i<3;i++)
                        {
                           aux=rgjA[0][0];
                           rgjA[0][i]=(rgjA[0][i])/(aux);

                        }
			//Ahora que la entrada de la primera fila y la primera columna es igual a 1, procedemos a hacer cero todas las entradas restantes de esta misma columna.
                        for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA10
                        {
                           aux=(-1)*(rgjA[1][0]);
                           rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                        }
                        for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA20
                        {
                           aux=(-1)*(rgjA[2][0]);
                           rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                        }
			//AQUI CONCLUYE EL ANALISIS RESPECTO A LA PRIMERA COLUMNA. AHORA CONTINUA EL ANALISIS PARA LA SEGUNDA COLUMNA:


//*******
                        //Ahora solo se analizaran las filas 2 y 3: Es decir, si hablamos de columnas, nos restringimos a las entradas de estas filas.
                        //Se procedera a evaluar cual es la columna mas a la izquierda que tiene entradas distintas de cero. La primera columna obviamente no puede ser porque en los pasos anteriores se iso igual a cero todas sus entradas.
                                if(rgjA[1][1] != 0 || rgjA[2][1] != 0){
                                        //Almenos una de las entradas de la segunda columna es distinta de cero
                                        //Se procede a encontrar la primera entrada de arriba para abajo que sea distinta de cero en esta segunda columna:
                                        if(rgjA[1][1] != 0){
                                                //La entrada de la segunda fila es distinta de cero
                                                //Entonces no se hace ningun intercambio. Solo se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.
                                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }




                                        }else if(rgjA[2][1]){

                                                 //La entrada de la segunda es cero y la entrada de la tercera fila es distinta de cero.
                                                //Entonces se procede a hacer el intercambio. Luego se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.

                                                //Se procede a intercambiar la segunda fila con la tercera fila:
                                                for(int i=1;i<3;i++){
                                                   aux=rgjA[1][i];
                                                   rgjA[1][i]=rgjA[2][i];
                                                   rgjA[2][i]=aux;
                                                }

                                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }


                                        }

                                }else if(rgjA[1][2] != 0 || rgjA[2][2] != 0){
                                        //Almenos una de las entradas de la tercera columna es distinta de cero
                                        //Se procede a encontrar cual es la entrada distinta de cero, ubicarla en la segunda fila, igualarla a uno y hacer a las entradas arriba y abajo de esta iguales a cero.
                                        if(rgjA[1][2] != 0){
                                                //La entrada rgjA12 es distinta de cero. Entonces no se realiza ningun cambio. Solo se procede a hacerla igual a uno y a hacer cero la entrada arriba y abajo de esta.          
                                                //Haciendola igual a 1:
                                                rgjA[1][2]=1;

                                                //Haciendo el resto de entradas iguales a cero:
                                                rgjA[0][2]=0;
                                                rgjA[2][2]=0;

                                        }else if(rgjA[2][2] != 0){
                                                //La entrada rgjA22 es distinta de cero. Entonces se procede a intercambiarla a la segunda fila, hacerla igual a uno y hacer cero el resto. Este proceso se puede simplificar como se muestra a continuacion.
                                                rgjA[1][2]=1;
                                                rgjA[0][2]=0;
                                                rgjA[2][2]=0;
                                        }

                                }else{
                                        //Si se llego a este punto, es porque las cuatro entradas inferiores de la derecha son cero.
                                        //En este caso, no importa si las entradas de la primera fila y la segunda y tercera columa son distintas o iguales a cero. El algoritmo a terminado.
                                }
//****************                  

			}else if(rgjA[2][0] != 0){
								//Este es el caso donde ninguno de los dos casos anteriores se cumplieron y es la tercera fila la que tiene la entrada distinta de cero en la primera columna. AQUI SE INTERCAMBIA LA PRIMERA FILA CON LA TERCERA FILA.
				for(int i=0;i<3;i++){
                                        aux=rgjA[0][i];
                                        rgjA[0][i]=rgjA[2][i];
                                        rgjA[2][i]=aux;
                                }

			
				//Ahora que estamos seguros que la primera fila tiene una entrada distinta de cero en la primera columna, se procede a hacer igual a 1 dicha entrada.
                        for(int i=0;i<3;i++)
                        {
                           aux=rgjA[0][0];
                           rgjA[0][i]=(rgjA[0][i])/(aux);

                        }
			//Ahora que la entrada de la primera fila y la primera columna es igual a 1, procedemos a hacer cero todas las entradas restantes de esta misma columna.
                        for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA10
                        {
                           aux=(-1)*(rgjA[1][0]);
                           rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                        }
                        for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA20
                        {
                           aux=(-1)*(rgjA[2][0]);
                           rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                        }
			//AQUI CONCLUYE EL ANALISIS RESPECTO A LA PRIMERA COLUMNA. AHORA CONTINUA EL ANALISIS PARA LA SEGUNDA COLUMNA:


//*******
                        //Ahora solo se analizaran las filas 2 y 3: Es decir, si hablamos de columnas, nos restringimos a las entradas de estas filas.
                        //Se procedera a evaluar cual es la columna mas a la izquierda que tiene entradas distintas de cero. La primera columna obviamente no puede ser porque en los pasos anteriores se iso igual a cero todas sus entradas.
                                if(rgjA[1][1] != 0 || rgjA[2][1] != 0){
                                        //Almenos una de las entradas de la segunda columna es distinta de cero
                                        //Se procede a encontrar la primera entrada de arriba para abajo que sea distinta de cero en esta segunda columna:
                                        if(rgjA[1][1] != 0){
                                                //La entrada de la segunda fila es distinta de cero
                                                //Entonces no se hace ningun intercambio. Solo se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.
                                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }




                                        }else if(rgjA[2][1]){

                                                 //La entrada de la segunda es cero y la entrada de la tercera fila es distinta de cero.
                                                //Entonces se procede a hacer el intercambio. Luego se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.

                                                //Se procede a intercambiar la segunda fila con la tercera fila:
                                                for(int i=1;i<3;i++){
                                                   aux=rgjA[1][i];
                                                   rgjA[1][i]=rgjA[2][i];
                                                   rgjA[2][i]=aux;
                                                }

                                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }


                                        }

                                }else if(rgjA[1][2] != 0 || rgjA[2][2] != 0){
                                        //Almenos una de las entradas de la tercera columna es distinta de cero
                                        //Se procede a encontrar cual es la entrada distinta de cero, ubicarla en la segunda fila, igualarla a uno y hacer a las entradas arriba y abajo de esta iguales a cero.
                                        if(rgjA[1][2] != 0){
                                                //La entrada rgjA12 es distinta de cero. Entonces no se realiza ningun cambio. Solo se procede a hacerla igual a uno y a hacer cero la entrada arriba y abajo de esta.          
                                                //Haciendola igual a 1:
                                                rgjA[1][2]=1;

                                                //Haciendo el resto de entradas iguales a cero:
                                                rgjA[0][2]=0;
                                                rgjA[2][2]=0;

                                        }else if(rgjA[2][2] != 0){
                                                //La entrada rgjA22 es distinta de cero. Entonces se procede a intercambiarla a la segunda fila, hacerla igual a uno y hacer cero el resto. Este proceso se puede simplificar como se muestra a continuacion.
                                                rgjA[1][2]=1;
                                                rgjA[0][2]=0;
                                                rgjA[2][2]=0;
                                        }

                                }else{
                                        //Si se llego a este punto, es porque las cuatro entradas inferiores de la derecha son cero.
                                        //En este caso, no importa si las entradas de la primera fila y la segunda y tercera columa son distintas o iguales a cero. El algoritmo a terminado.
                                }
 //****************                  ****************************************************************















}
		
//***************************************		
		
		}else if(rgjA[0][1] !=0 || rgjA[1][1] !=0 || rgjA[2][1] !=0){
			//Si se llego a este punto, es porque las entradas de la primera columna de la matriz A, eran todas iguales a cero, pero en la segunda columna, hay almenos una entrada distinta de cero.  
	
//****************
//***************
//*************
			//Se procede a encontrar cual de las 3 entradas de la segunda columna es distinta de cero, intercambiar su fila con la primera fila, hacer la entrada igual a 1 y por ultimo hacer cero el resto de las entradas.
			if(rgjA[0][1] != 0){
				//Aqui no hay que hacer ningun intercambio. Se procede a hacerla igual a uno y a hacer igual a cero el resto.

				for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                {
                                     aux=rgjA[0][1];
                                     rgjA[0][i]=(rgjA[0][i])/(aux);

                                }

			        for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA11
                                {
                                      aux=(-1)*(rgjA[1][1]);
                                      rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                                }

				for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                {
                                      aux=(-1)*(rgjA[2][1]);
                                      rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                                }
				//FINALIZA EL ANALISIS DE LA SEGUNDA COLUMNA. Ahora inicia el analicis de la tercera columna.

				//Se preocede a verificar si alguna de las 2 entradas inferiores derechas son distinta de cero.
				if(rgjA[1][2] != 0 || rgjA[2][2]!=0 ){
					//Almenos una de las 2 entradas inferiores derechas es distinta de cero. Entonces las entradas de esta columna quedan como sigue:
					rgjA[1][2]=1;
					rgjA[2][2]=0;
					rgjA[0][2]=0;
				}
				//Si no se cumplio la condicion anterior, es porque las 2 entradas inferiores derechas de la 3 columna son iguales a cero. Si la primera entrada de la tercera columna es o no distinta de cero no importa. El algoritmo a terminado.



			}else if(rgjA[1][1] != 0){
				//Se intercambia la segunda fila con la primera fila. Se procede a hacerla igual a uno y a hacer igual a cero el resto.

				//Aqui se intercambia la segunda fila con la primer fila:
				

				for(int i=1;i<3;i++){
                                        aux=rgjA[0][i];
                                        rgjA[0][i]=rgjA[1][i];
                                        rgjA[1][i]=aux;
	                        }


				for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                {
                                     aux=rgjA[0][1];
                                     rgjA[0][i]=(rgjA[0][i])/(aux);

                                }

                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA11
                                {
                                      aux=(-1)*(rgjA[1][1]);
                                      rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                                }

                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                {
                                      aux=(-1)*(rgjA[2][1]);
                                      rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                                }
                                //FINALIZA EL ANALISIS DE LA SEGUNDA COLUMNA. Ahora inicia el analicis de la tercera columna.

                                //Se preocede a verificar si alguna de las 2 entradas inferiores derechas son distinta de cero.
                                if(rgjA[1][2] != 0 || rgjA[2][2]!=0 ){
                                        //Almenos una de las 2 entradas inferiores derechas es distinta de cero. Entonces las entradas de esta columna quedan como sigue:
                                        rgjA[1][2]=1;
                                        rgjA[2][2]=0;
                                        rgjA[0][2]=0;
                                }
                                //Si no se cumplio la condicion anterior, es porque las 2 entradas inferiores derechas de la 3 columna son iguales a cero. Si la primera entrada de la tercera columna es o no distinta de cero no importa. El algoritmo a terminado.



			}else if(rgjA[2][1] != 0){
				//Se intercambia la tercer fila con la primer fila. Se procede a hacerla igual a uno y a hacer igual a cero el resto.

				//Aqui se intercambia la tercer fila con la primer fila:


                                for(int i=1;i<3;i++){
                                        aux=rgjA[0][i];
                                        rgjA[0][i]=rgjA[2][i];
                                        rgjA[2][i]=aux;
                                }


                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                {
                                     aux=rgjA[0][1];
                                     rgjA[0][i]=(rgjA[0][i])/(aux);

                                }

                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA11
                                {
                                      aux=(-1)*(rgjA[1][1]);
                                      rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                                }

                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                {
                                      aux=(-1)*(rgjA[2][1]);
                                      rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                                }
                                //FINALIZA EL ANALISIS DE LA SEGUNDA COLUMNA. Ahora inicia el analicis de la tercera columna.

                                //Se preocede a verificar si alguna de las 2 entradas inferiores derechas son distinta de cero.
                                if(rgjA[1][2] != 0 || rgjA[2][2]!=0 ){
                                        //Almenos una de las 2 entradas inferiores derechas es distinta de cero. Entonces las entradas de esta columna quedan como sigue:
                                        rgjA[1][2]=1;
                                        rgjA[2][2]=0;
                                        rgjA[0][2]=0;
                                }
                                //Si no se cumplio la condicion anterior, es porque las 2 entradas inferiores derechas de la 3 columna son iguales a cero. Si la primera entrada de la tercera columna es o no distinta de cero no importa. El algoritmo a terminado.


			}













//                                                                                             ************************




		}else if(rgjA[0][2] !=0 || rgjA[1][2] !=0 || rgjA[2][2] !=0){
			//Si se llego a este punto, es porque las entradas de la segunda columna tambien resultaron ser todas iguales a cero, pero en esta tercera columna hay almenos una entrada distinta de cero.
			//Se procede a hacer la entrada rgjA02=1 y el resto iguales a cero:
						rgjA[0][2]=1;
                                                rgjA[1][2]=0;
                                                rgjA[2][2]=0;

		}
		//Si ninguno de los casos anteriores se cumplio, es porque todas las entradas de la matriz A son cada una igual a cero. Entonces la matriz ya se encuentra en la forma escalonada reducida.




















































//AQUI FINALIZA EL CALCULO DE rgjA
//A continuacion iniciare el calculo de rgjB, realizare una maniobra para no tener que cambiar en todo el codigo A por B:

 for(int i=0;i<3;i++)  //Copiamos la matriz rgjA a la matriz rgjjA.
 {
             for(int j=0;j<3;j++)
             {
                     rgjjA[i][j]=rgjA[i][j];
             }
 }
//Y entonces lo que are sera lo siguiente: Para imprimir a la matriz rgjA, voy a imprimir a la matriz rgjjA. Y para imprimir a la matriz rgjB, voy a imprimir a la matriz rgjA que es la que va a tener la informacion de la matriz B en el siguiente codigo.

//*****************************************************************************************************************************************************************************
////*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************

  //Calculo de rgjB
                
                for(int i=0;i<3;i++)  //Copiamos la matriz B a la matriz rgjA.
                {
                         for(int j=0;j<3;j++)
                         {
                                 rgjA[i][j]=matB[i][j];
                         }
                }



                if(rgjA[0][0] !=0 || rgjA[1][0] !=0 || rgjA[2][0] !=0 ){
                        //Si se esta en este punto, es porque almenos una de las entradas de la primera columna de A es distinta de cero. Se procedera asegurarse que la primera fila de A sea una fila tal que su primera entrada sea distinta de cero. Para esto, a continuacin se utilizara una serie de if's, en la que: A la primera entrada distinta de cero de la primera columna de A que se encuentre, se intercambiara toda la fila correspondiente a esa entrada con la primera fila de A. En el caso que la primera fila de A cumpla con que su primera entrada sea distinta de cero, entonces se quedara igual.
                        if(rgjA[0][0] != 0){
                                                                //Este es el caso donde la primera fila tiene una entrada distinta de cero en la primera columna. AQUI NO OCURRE NINGUN INTERCAMBIO.            

                        //Ahora que estamos seguros que la primera fila tiene una entrada distinta de cero en la primera columna, se procede a hacer igual a 1 dicha entrada.
                        for(int i=0;i<3;i++)
                        {
                           aux=rgjA[0][0];
                           rgjA[0][i]=(rgjA[0][i])/(aux);

                        }

                        //Ahora que la entrada de la primera fila y la primera columna es igual a 1, procedemos a hacer cero todas las entradas restantes de esta misma columna.
                        for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA10
                        {
                           aux=(-1)*(rgjA[1][0]);
                           rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                        }
                        for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA20
                        {
                           aux=(-1)*(rgjA[2][0]);
                           rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                        }

                        //AQUI CONCLUYE EL ANALISIS RESPECTO A LA PRIMERA COLUMNA. AHORA CONTINUA EL ANALISIS PARA LA SEGUNDA COLUMNA:
//******************
                        //Ahora solo se analizaran las filas 2 y 3: Es decir, si hablamos de columnas, nos restringimos a las entradas de estas filas.
                        //Se procedera a evaluar cual es la columna mas a la izquierda que tiene entradas distintas de cero. La primera columna obviamente no puede ser porque en los pasos anteriores se iso igual a cero todas sus entradas.
                                if(rgjA[1][1] != 0 || rgjA[2][1] != 0){
                                        //Almenos una de las entradas de la segunda columna es distinta de cero
                                        //Se procede a encontrar la primera entrada de arriba para abajo que sea distinta de cero en esta segunda columna:
                                        if(rgjA[1][1] != 0){
                                                //La entrada de la segunda fila es distinta de cero
                                                //Entonces no se hace ningun intercambio. Solo se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.
                                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }




                                        }else if(rgjA[2][1]){

                                                 //La entrada de la segunda es cero y la entrada de la tercera fila es distinta de cero.
                                                //Entonces se procede a hacer el intercambio. Luego se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.

                                                //Se procede a intercambiar la segunda fila con la tercera fila:
                                                for(int i=1;i<3;i++){
                                                   aux=rgjA[1][i];
                                                   rgjA[1][i]=rgjA[2][i];
                                                   rgjA[2][i]=aux;
                                                }

                                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }


                                        }

                                }else if(rgjA[1][2] != 0 || rgjA[2][2] != 0){
                                        //Almenos una de las entradas de la tercera columna es distinta de cero
                                        //Se procede a encontrar cual es la entrada distinta de cero, ubicarla en la segunda fila, igualarla a uno y hacer a las entradas arriba y abajo de esta iguales a cero.
                                        if(rgjA[1][2] != 0){
                                                //La entrada rgjA12 es distinta de cero. Entonces no se realiza ningun cambio. Solo se procede a hacerla igual a uno y a hacer cero la entrada arriba y abajo de esta.          
                                                //Haciendola igual a 1:
                                                rgjA[1][2]=1;

                                                //Haciendo el resto de entradas iguales a cero:
                                                rgjA[0][2]=0;
                                                rgjA[2][2]=0;

                                        }else if(rgjA[2][2] != 0){
                                                //La entrada rgjA22 es distinta de cero. Entonces se procede a intercambiarla a la segunda fila, hacerla igual a uno y hacer cero el resto. Este proceso se puede simplificar como se muestra a continuacion.
                                                rgjA[1][2]=1;
                                                rgjA[0][2]=0;
                                                rgjA[2][2]=0;
                                        }

                                }else{
                                        //Si se llego a este punto, es porque las cuatro entradas inferiores de la derecha son cero.
                                        //En este caso, no importa si las entradas de la primera fila y la segunda y tercera columa son distintas o iguales a cero. El algoritmo a terminado.
                                }
//****************                      

                 

                        }else if(rgjA[1][0] != 0){
                                                                //Este es el caso donde el caso anterior no se cumplio y es la segunda fila la que tiene la entrada distinta de cero en la primera columna. AQUI SE INTERCAMBIA LA PRIMERA FILA CON LA SEGUNDA FILA.
                                for(int i=0;i<3;i++){
                                        aux=rgjA[0][i];
                                        rgjA[0][i]=rgjA[1][i];
                                        rgjA[1][i]=aux;
                                }

                        //Ahora que estamos seguros que la primera fila tiene una entrada distinta de cero en la primera columna, se procede a hacer igual a 1 dicha entrada.
                        for(int i=0;i<3;i++)
                        {
                           aux=rgjA[0][0];
                           rgjA[0][i]=(rgjA[0][i])/(aux);

                        }
                        //Ahora que la entrada de la primera fila y la primera columna es igual a 1, procedemos a hacer cero todas las entradas restantes de esta misma columna.
                        for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA10
                        {
                           aux=(-1)*(rgjA[1][0]);
                           rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                        }
                        for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA20
                        {
                           aux=(-1)*(rgjA[2][0]);
                           rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                        }
                        //AQUI CONCLUYE EL ANALISIS RESPECTO A LA PRIMERA COLUMNA. AHORA CONTINUA EL ANALISIS PARA LA SEGUNDA COLUMNA:


//*******
                        //Ahora solo se analizaran las filas 2 y 3: Es decir, si hablamos de columnas, nos restringimos a las entradas de estas filas.
                        //Se procedera a evaluar cual es la columna mas a la izquierda que tiene entradas distintas de cero. La primera columna obviamente no puede ser porque en los pasos anteriores se iso igual a cero todas sus entradas.
                                if(rgjA[1][1] != 0 || rgjA[2][1] != 0){
                                        //Almenos una de las entradas de la segunda columna es distinta de cero
                                        //Se procede a encontrar la primera entrada de arriba para abajo que sea distinta de cero en esta segunda columna:
                                        if(rgjA[1][1] != 0){
                                                //La entrada de la segunda fila es distinta de cero
                                                //Entonces no se hace ningun intercambio. Solo se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.
                                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }




                                        }else if(rgjA[2][1]){

                                                 //La entrada de la segunda es cero y la entrada de la tercera fila es distinta de cero.
                                                //Entonces se procede a hacer el intercambio. Luego se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.

                                                //Se procede a intercambiar la segunda fila con la tercera fila:
                                                for(int i=1;i<3;i++){
                                                   aux=rgjA[1][i];
                                                   rgjA[1][i]=rgjA[2][i];
                                                   rgjA[2][i]=aux;
                                                }

                                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }


                                        }

                                }else if(rgjA[1][2] != 0 || rgjA[2][2] != 0){
                                        //Almenos una de las entradas de la tercera columna es distinta de cero
                                        //Se procede a encontrar cual es la entrada distinta de cero, ubicarla en la segunda fila, igualarla a uno y hacer a las entradas arriba y abajo de esta iguales a cero.
                                        if(rgjA[1][2] != 0){
                                                //La entrada rgjA12 es distinta de cero. Entonces no se realiza ningun cambio. Solo se procede a hacerla igual a uno y a hacer cero la entrada arriba y abajo de esta.          
                                                //Haciendola igual a 1:
                                                rgjA[1][2]=1;

                                                //Haciendo el resto de entradas iguales a cero:
                                                rgjA[0][2]=0;
                                                rgjA[2][2]=0;

                                        }else if(rgjA[2][2] != 0){
                                                //La entrada rgjA22 es distinta de cero. Entonces se procede a intercambiarla a la segunda fila, hacerla igual a uno y hacer cero el resto. Este proceso se puede simplificar como se muestra a continuacion.
                                                rgjA[1][2]=1;
                                                rgjA[0][2]=0;
                                                rgjA[2][2]=0;
                                        }

                                }else{
                                        //Si se llego a este punto, es porque las cuatro entradas inferiores de la derecha son cero.
                                        //En este caso, no importa si las entradas de la primera fila y la segunda y tercera columa son distintas o iguales a cero. El algoritmo a terminado.
                                }
//****************                  

            

                        }else if(rgjA[2][0] != 0){
                                                                //Este es el caso donde ninguno de los dos casos anteriores se cumplieron y es la tercera fila la que tiene la entrada distinta de cero en la primera columna. AQUI SE INTERCAMBIA LA PRIMERA FILA CON LA TERCERA FILA.
                                for(int i=0;i<3;i++){
                                        aux=rgjA[0][i];
                                        rgjA[0][i]=rgjA[2][i];
                                        rgjA[2][i]=aux;
                                }


                                //Ahora que estamos seguros que la primera fila tiene una entrada distinta de cero en la primera columna, se procede a hacer igual a 1 dicha entrada.
                        for(int i=0;i<3;i++)
                        {
                           aux=rgjA[0][0];
                           rgjA[0][i]=(rgjA[0][i])/(aux);

                        }
                        //Ahora que la entrada de la primera fila y la primera columna es igual a 1, procedemos a hacer cero todas las entradas restantes de esta misma columna.
                        for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA10
                        {
                           aux=(-1)*(rgjA[1][0]);
                           rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                        }
                        for(int i=0;i<3;i++) //Haciendo cero a la entrada rgjA20
                        {
                           aux=(-1)*(rgjA[2][0]);
                           rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                        }
                        //AQUI CONCLUYE EL ANALISIS RESPECTO A LA PRIMERA COLUMNA. AHORA CONTINUA EL ANALISIS PARA LA SEGUNDA COLUMNA:


//*******
                        //Ahora solo se analizaran las filas 2 y 3: Es decir, si hablamos de columnas, nos restringimos a las entradas de estas filas.
                        //Se procedera a evaluar cual es la columna mas a la izquierda que tiene entradas distintas de cero. La primera columna obviamente no puede ser porque en los pasos anteriores se iso igual a cero todas sus entradas.
                                if(rgjA[1][1] != 0 || rgjA[2][1] != 0){
                                        //Almenos una de las entradas de la segunda columna es distinta de cero
                                        //Se procede a encontrar la primera entrada de arriba para abajo que sea distinta de cero en esta segunda columna:
                                        if(rgjA[1][1] != 0){
                                                //La entrada de la segunda fila es distinta de cero
                                                //Entonces no se hace ningun intercambio. Solo se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.
                                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }




                                        }else if(rgjA[2][1]){

                                                 //La entrada de la segunda es cero y la entrada de la tercera fila es distinta de cero.
                                                //Entonces se procede a hacer el intercambio. Luego se procede a hacerla igual a uno y a hacer cero las entradas arriba y abajo de esta.

                                                //Se procede a intercambiar la segunda fila con la tercera fila:
                                                for(int i=1;i<3;i++){
                                                   aux=rgjA[1][i];
                                                   rgjA[1][i]=rgjA[2][i];
                                                   rgjA[2][i]=aux;
                                                }

                                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                                {
                                                   aux=rgjA[1][1];
                                                   rgjA[1][i]=(rgjA[1][i])/(aux);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA01
                                                {
                                                   aux=(-1)*(rgjA[0][1]);
                                                   rgjA[0][i]=(rgjA[0][i])+(aux)*(rgjA[1][i]);

                                                }
                                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                                {
                                                   aux=(-1)*(rgjA[2][1]);
                                                   rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[1][i]);

                                                }
                                                //AQUI CONCLUYE EL ANALISIS DE LA 2DA COLUMNA. AHORA SOLO FALTA ANALIZAR LA TERCERA COLUMNA.

                                                        //Se procedera a verificar si la entrada rgj22 es distinta de cero
                                                        if(rgjA[2][2] != 0){
                                                                //La entrada rgj22 es distinta de cero. Se procede a hacerla igual a uno y a hacer cero las 2 entradas que estan arriba de esta:
                                                                //Aqui la ago igual a 1
                                                                rgjA[2][2]=1;
                                                                //Haciendo a las entradas de arriba iguales a cero:
                                                                rgjA[0][2]=0;
                                                                rgjA[1][2]=0;

                                                        }else{
                                                                //La entrada rgj22 es cero. La entradas arriba de esta pueden entonces ser cero o distintas de cero. No importa. El algoritmo a terminado.
                                                        }


                                        }

                                }else if(rgjA[1][2] != 0 || rgjA[2][2] != 0){
                                        //Almenos una de las entradas de la tercera columna es distinta de cero
                                        //Se procede a encontrar cual es la entrada distinta de cero, ubicarla en la segunda fila, igualarla a uno y hacer a las entradas arriba y abajo de esta iguales a cero.
                                        if(rgjA[1][2] != 0){
                                                //La entrada rgjA12 es distinta de cero. Entonces no se realiza ningun cambio. Solo se procede a hacerla igual a uno y a hacer cero la entrada arriba y abajo de esta.          
                                                //Haciendola igual a 1:
                                                rgjA[1][2]=1;

                                                //Haciendo el resto de entradas iguales a cero:
                                                rgjA[0][2]=0;
                                                rgjA[2][2]=0;

                                        }else if(rgjA[2][2] != 0){
                                                //La entrada rgjA22 es distinta de cero. Entonces se procede a intercambiarla a la segunda fila, hacerla igual a uno y hacer cero el resto. Este proceso se puede simplificar como se muestra a continuacion.
                                                rgjA[1][2]=1;
                                                rgjA[0][2]=0;
                                                rgjA[2][2]=0;
                                        }

                                }else{
                                        //Si se llego a este punto, es porque las cuatro entradas inferiores de la derecha son cero.
                                        //En este caso, no importa si las entradas de la primera fila y la segunda y tercera columa son distintas o iguales a cero. El algoritmo a terminado.
                                }
//****************                  






}

//***************************************               

                }else if(rgjA[0][1] !=0 || rgjA[1][1] !=0 || rgjA[2][1] !=0){
                        //Si se llego a este punto, es porque las entradas de la primera columna de la matriz A, eran todas iguales a cero, pero en la segunda columna, hay almenos una entrada distinta de cero.  

//****************
//***************
//*************
                        //Se procede a encontrar cual de las 3 entradas de la segunda columna es distinta de cero, intercambiar su fila con la primera fila, hacer la entrada igual a 1 y por ultimo hacer cero el resto de las entradas.
                        if(rgjA[0][1] != 0){
                                //Aqui no hay que hacer ningun intercambio. Se procede a hacerla igual a uno y a hacer igual a cero el resto.

                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                {
                                     aux=rgjA[0][1];
                                     rgjA[0][i]=(rgjA[0][i])/(aux);

                                }

                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA11
                                {
                                      aux=(-1)*(rgjA[1][1]);
                                      rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                                }

                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                {
                                      aux=(-1)*(rgjA[2][1]);
                                      rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                                }
                                //FINALIZA EL ANALISIS DE LA SEGUNDA COLUMNA. Ahora inicia el analicis de la tercera columna.

                                //Se preocede a verificar si alguna de las 2 entradas inferiores derechas son distinta de cero.
                                if(rgjA[1][2] != 0 || rgjA[2][2]!=0 ){
                                        //Almenos una de las 2 entradas inferiores derechas es distinta de cero. Entonces las entradas de esta columna quedan como sigue:
                                        rgjA[1][2]=1;
                                        rgjA[2][2]=0;
                                        rgjA[0][2]=0;
                                }
                                //Si no se cumplio la condicion anterior, es porque las 2 entradas inferiores derechas de la 3 columna son iguales a cero. Si la primera entrada de la tercera columna es o no distinta de cero no importa. El algoritmo a terminado.



                        }else if(rgjA[1][1] != 0){
                                //Se intercambia la segunda fila con la primera fila. Se procede a hacerla igual a uno y a hacer igual a cero el resto.

                                //Aqui se intercambia la segunda fila con la primer fila:


                                for(int i=1;i<3;i++){
                                        aux=rgjA[0][i];
                                        rgjA[0][i]=rgjA[1][i];
                                        rgjA[1][i]=aux;
                                }


                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                {
                                     aux=rgjA[0][1];
                                     rgjA[0][i]=(rgjA[0][i])/(aux);

                                }

                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA11
                                {
                                      aux=(-1)*(rgjA[1][1]);
                                      rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                                }

                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                {
                                      aux=(-1)*(rgjA[2][1]);
                                      rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                                }
                                //FINALIZA EL ANALISIS DE LA SEGUNDA COLUMNA. Ahora inicia el analicis de la tercera columna.

                                //Se preocede a verificar si alguna de las 2 entradas inferiores derechas son distinta de cero.
                                if(rgjA[1][2] != 0 || rgjA[2][2]!=0 ){
                                        //Almenos una de las 2 entradas inferiores derechas es distinta de cero. Entonces las entradas de esta columna quedan como sigue:
                                        rgjA[1][2]=1;
                                        rgjA[2][2]=0;
                                        rgjA[0][2]=0;
                                }
                                //Si no se cumplio la condicion anterior, es porque las 2 entradas inferiores derechas de la 3 columna son iguales a cero. Si la primera entrada de la tercera columna es o no distinta de cero no importa. El algoritmo a terminado.



                        }else if(rgjA[2][1] != 0){
                                //Se intercambia la tercer fila con la primer fila. Se procede a hacerla igual a uno y a hacer igual a cero el resto.

                                //Aqui se intercambia la tercer fila con la primer fila:


                                for(int i=1;i<3;i++){
                                        aux=rgjA[0][i];
                                        rgjA[0][i]=rgjA[2][i];
                                        rgjA[2][i]=aux;
                                }


                                for(int i=1;i<3;i++)  //Aqui la e echo igual a 1
                                {
                                     aux=rgjA[0][1];
                                     rgjA[0][i]=(rgjA[0][i])/(aux);

                                }

                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA11
                                {
                                      aux=(-1)*(rgjA[1][1]);
                                      rgjA[1][i]=(rgjA[1][i])+(aux)*(rgjA[0][i]);

                                }

                                for(int i=1;i<3;i++) //Haciendo cero a la entrada rgjA21
                                {
                                      aux=(-1)*(rgjA[2][1]);
                                      rgjA[2][i]=(rgjA[2][i])+(aux)*(rgjA[0][i]);

                                }
                                //FINALIZA EL ANALISIS DE LA SEGUNDA COLUMNA. Ahora inicia el analicis de la tercera columna.

                                //Se preocede a verificar si alguna de las 2 entradas inferiores derechas son distinta de cero.
                                if(rgjA[1][2] != 0 || rgjA[2][2]!=0 ){
                                        //Almenos una de las 2 entradas inferiores derechas es distinta de cero. Entonces las entradas de esta columna quedan como sigue:
                                        rgjA[1][2]=1;
                                        rgjA[2][2]=0;
                                        rgjA[0][2]=0;
                                }
                                //Si no se cumplio la condicion anterior, es porque las 2 entradas inferiores derechas de la 3 columna son iguales a cero. Si la primera entrada de la tercera columna es o no distinta de cero no importa. El algoritmo a terminado.


                        }



                }else if(rgjA[0][2] !=0 || rgjA[1][2] !=0 || rgjA[2][2] !=0){
                        //Si se llego a este punto, es porque las entradas de la segunda columna tambien resultaron ser todas iguales a cero, pero en esta tercera columna hay almenos una entrada distinta de cero.
                        //Se procede a hacer la entrada rgjA02=1 y el resto iguales a cero:
                                                rgjA[0][2]=1;
                                                rgjA[1][2]=0;
                                                rgjA[2][2]=0;

                }
                //Si ninguno de los casos anteriores se cumplio, es porque todas las entradas de la matriz A son cada una igual a cero. Entonces la matriz ya se encuentra en la forma escalonada reducida.







//FINALIZA CALCULO DE rgjB














//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************






	for(int i=0;i<3;i++)
        {
                for(int j=0;j<3;j++)
                {
                        

                }
        }


	//Impresion de los resultados:
	

	//Imprecion de cA
	printf("\n\ncA= \n\n");
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%f  ",mulAc[i][j]);
                }
                printf("\n\n");
        }
	
	//Imprecion de A+B
	printf("\n\nA+B= \n\n");
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%f  ",suAB[i][j]);
                }
                printf("\n\n");
        }
	
	//Impresion de A-B
 	printf("\n\nA-B= \n\n");
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%f  ",resAB[i][j]);
                }
                printf("\n\n");
        }
	

	//Imprecion de AB
	printf("\n\nAB= \n\n");
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%f  ",mulAB[i][j]);
                }
                printf("\n\n");
        }

	//Impresion de det(A)
	printf("\n\ndet(A)= %f\n\n",detA);


	//Impresion de inv(A), si es que existe
	if(detA != 0){
                 printf("\n\ninv(A)= \n\n");
	        for(int i=0;i<3;i++){
               		 for(int j=0;j<3;j++){
                        	  printf("%f  ",invA[i][j]);
               		 }
                printf("\n\n");
                }
	}
	else{
		printf("\n\nComo detA=0 , inv(A) no existe.\n\n");
	}

	//Impresion de trB
	printf("\n\ntrB= \n\n");
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%f  ",trB[i][j]);
                }
                printf("\n\n");
        }

	//Imprecion de rgjA
	printf("\n\nrgjA= \n\n");
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%f  ",rgjjA[i][j]);
                }
                printf("\n\n");
        }

	//Imprecion de rgjB
        printf("\n\nrgjA= \n\n");
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        printf("%f  ",rgjA[i][j]);
                }
                printf("\n\n");
        }



}


