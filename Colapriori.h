#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif

#define max 5

typedef struct cola
{
	int idTarea[max],prioridad[max],posicion;
}cola;

cola *Crearcola()
{
	int i;
	cola *c;
	c=malloc(sizeof(cola));
	for(i=0;i<max;i++)
	{
		c->prioridad[i]= NULL;
		c->idTarea[i]=NULL;
	}
	c->posicion=0;
}

void Agregatarea(cola *c, int id, int priori)
{
	int i;int j;
	if(c->posicion<max)
	{
		if(c->posicion == 0)
		{
			c->idTarea[c->posicion]=id;
			c->prioridad[c->posicion]=priori;
			c->posicion++;
		}
		else if(esmenor(c,priori))
		{
			i=c->posicion;
			j=particion(c,priori);
			while (i>j)
			{
				c->prioridad[i]=c->prioridad[i-1];
				c->idTarea[i]=c->idTarea[i-1];
				i--;
			}
			c->idTarea[i]=id;
			c->prioridad[i]=priori;
			c->posicion++;			
		}
		else if(!esmenor(c,priori))
		{
			c->idTarea[c->posicion]=id;
			c->prioridad[c->posicion]=priori;
			c->posicion++;
		}
	}
	else printf("Cola Llena");
}


int particion(cola *c,int priori)
{
	int i=0;int aux;
	while (i<c->posicion)
	{
		if(priori<=c->prioridad[i])
		{
			aux=i;
			return aux;
		}
		i++;
	}
}


int esmenor(cola *c,int priori)
{
	int i=0;
	while (i<c->posicion)
	{
		if(priori<=c->prioridad[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

int Sacartarea(cola *c)
{
	int i=0;
	while(i<c->posicion)
	{
		c->prioridad[i]=c->prioridad[i+1];
		c->idTarea[i]=c->idTarea[i+1];
		i++;	
	}
	c->posicion--;
}

void imprimir(cola *c)
{
	int i=0;
	while (i<c->posicion)
	{
		printf("Prioridad = %i | IdTarea = %i \n",c->prioridad[i],c->idTarea[i]);
		i++;
	}
}

int Posicion(cola *c,int id)
{
	int i=0;
	while (i<c->posicion)
	{
		if(c->idTarea[i]==id)
		{
			return i;
		}
		i++;
	}
	return 0;
}

int Cambiar(cola *c,int id,int priori)
{
	int i,j;
	c->posicion--;
	i=c->posicion;
	j=Posicion(c,id);
	while (i>j)
	{
		c->prioridad[j]=c->prioridad[j+1];
		c->idTarea[j]=c->idTarea[j+1];
		j++;
	}
	Agregatarea(c,id,priori);
}
