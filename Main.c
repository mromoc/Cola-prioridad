#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif

#ifndef Colapriori_h
#include "Colapriori.h"
#define Colapriori_h
#endif

int main()
{
	cola *c=Crearcola();
	Agregatarea(c,5,4);
	Agregatarea(c,45,3);
	Agregatarea(c,544,9);
	Agregatarea(c,65,7);
	Agregatarea(c,123,1);
	imprimir(c);
	Cambiar(c,45,10);
	printf("aca el prioridad 3 pasa a ser 10 \n");
	imprimir(c);
	Cambiar(c,5,1);
	printf("aca el prioridad 4 pasa a ser 1 \n");
	imprimir(c);
		Cambiar(c,544,2);
	printf("aca el prioridad 9 pasa a ser 2 \n");
	imprimir(c);
	
}
