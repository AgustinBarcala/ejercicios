#include <stdio.h>
#include <stdlib.h>

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError, int maximo, int minimo, int maximoDeReintentos);


int main(void){
	setbuf(stdout, NULL);

	int numeroUno;
	int retornoGetInt;

	retornoGetInt = getInt(&numeroUno,"Ingrese un numero entero:\n","El numero es incorrecto:\n",10,1,2);
	if(retornoGetInt == 0){
		printf("%d" , numeroUno);
	}else{
		printf("El numero no fue ingresado bien");
	}


	return 0;
}

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError, int maximo, int minimo, int maximoDeReintentos){
	int auxNumeroIngresado;
	int retorno;
	retorno = -1;
	printf("%s" , mensaje);
	scanf("%d" , &auxNumeroIngresado);


	do{
		printf("%s" , mensaje);
		scanf("%d" , &auxNumeroIngresado);
		maximoDeReintentos--;

		if(auxNumeroIngresado > minimo && auxNumeroIngresado < maximo){
				*pNumeroIngresado = auxNumeroIngresado;
				retorno = 0;
				break;
		}else{
			printf("%s" , mensajeError);
		}

		if(maximoDeReintentos == 0){
			break;
		}
	}while(auxNumeroIngresado < minimo || auxNumeroIngresado > maximo);



	return retorno;
}
