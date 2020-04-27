#!/bin/bash

echo "INICIANDO PROGRAMA PARA ENCONTRAR LA REGRECION LINEAL DE LOS DATOS DE EVOLUCION ATLETICA"
gcc minimos.c -lm
./a.out
echo "INICIANDO PROCESO PARA GENERAR LA GRAFICA"
gnuplot graficador.txt
echo "El archivo grafica.jpeg se a creado"
echo "FIN DE EL PROGRAMA"
