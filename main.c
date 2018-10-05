#include "llista.h"
#include <stdio.h>

int main (){

	int seleccio = 0;
	int numero;
	LlistaBIO llista = LLISTABIO_crea();

	while (seleccio != 6){

		seleccio = 0;
		while (seleccio < 1 || seleccio > 6){
			printf("\n");
			printf("1. Introduir numero\n");
			printf("2. Consultar pdi\n");
			printf("3. Avançar pdi\n");
			printf("4. Restrocedir pdi\n");
			printf("5. Mostrar tota la llista\n");
			printf("6. Sortir\n");
			scanf("%d", &seleccio);

			if (seleccio < 1 || seleccio > 6){
				printf("Opcio no valida\n");
			}
		}

		if (seleccio == 1){
			printf("\nNumero a inserir major a 0: ");
			scanf("%d", &numero);
			printf("\n");
			LLISTABIO_insereixOrdenat(&llista, numero);
		}

		if (seleccio == 2){
			numero = LLISTABIO_consulta(llista);
			if (numero != 0){
				printf("%d\n", numero);
			}
		}
		if (seleccio == 3){
			LLISTABIO_avanca(&llista);
		}

		if (seleccio == 4){
			LLISTABIO_retrocedeix(&llista);
		}

		if (seleccio == 5){
			LLISTABIO_vesInici(&llista);
			while(!LLISTABIO_fi()){
				numero = LLISTABIO_consulta(llista);
				LLISTABIO_avanca(&llista);
				printf("%d\n", numero);
			}
		}
	}
	return 0;
}