#!/bin/bash
echo "***INICIANDO PROGRAMA PARA ENCONTRAR UNA RAIZ POR MEDIO DE EL METODO DE LA BISECCION:***"
gcc biseccion.c -lm
./a.out

echo "Iniciando proceso en GNULPOT"
gnuplot "graficador.txt"
echo "Proceso en GNUPLOT completado."
echo "La imagen grafica.jpeg a sido creada"
rm datos.txt

