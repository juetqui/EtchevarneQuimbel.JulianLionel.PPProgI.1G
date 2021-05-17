/*
 ============================================================================
 Name        : Programacion1.c
 Author      : julian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

typedef struct{
	int id;
	char prosesador[LEN];
	char marca[LEN];
	int precio;
}eNotebook;

eNotebook notebooks[LEN] = {
	{0,"Intel","Omen",15000},
	{1,"Intel","Dell",17000},
	{2,"AMD","Dell",25000},
	{3,"AMD","Acer",12000},
	{4,"Intel","Omen",30000}
};

float aplicarDescuento(float* precio);
int ordenarPorMarcaPrecio(eNotebook* array, int limite);

int main(void)
{
	setbuf(stdout, NULL);

	eNotebook notebooks;
	float precio=100;
	float precioConDesc;

	precioConDesc=aplicarDescuento(&precio);
	printf("El precio con descuento es: %f\n", precioConDesc);

	ordenarPorMarcaPrecio(&notebooks, LEN);
	printf("%s",notebooks);

	return EXIT_SUCCESS;
}

float aplicarDescuento(float* precio)
{
	float resultado;
	float descuento=0.95;

	resultado = (*precio) * descuento;

	return resultado;
}

int ordenarPorMarcaPrecio(eNotebook* array, int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	eNotebook buffer;
	int auxiliar;

	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				auxiliar = strcmp(array[i].marca, array[i+1].marca);
				if(	auxiliar > 0 ||
					(auxiliar == 0 && array[i].precio < array[i+1].precio))
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1] = buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}





