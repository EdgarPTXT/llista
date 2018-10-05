#include "llista.h"
#include <stdio.h>

int main (){

	LlistaBIO llista = LLISTABIO_crea();
	int numero;
	int count = 0;

	while(cout != '3'){
		printf("Numero a inserir: ");
		scanf("%d", &numero);
		printf("\n");
		LLISTABIO_insereixOrdenat(&llista, numero);
		count = count + 1;
	}

	printf("\nMostrarem al llista ordenada;\n");
	LLISTABIO_vesInici(&llista);
	while(!LLISTABIO_fi()){
		numero = LLISTABIO_consulta(llista);
		LLISTABIO_avanca(llista);
		printf("%d\n", numero);
	}
	return 0;
}