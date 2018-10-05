#include "llista.h"
#include <stdio.h>

LlistaBIO LLISTABIO_crea(){
	LlistaBIO l;
	l.pri = (Node *) malloc (sizeof(Node));
	if (l.pri != NULL){
		l.ult = (Node *) malloc (sizeof(Node));
		if (l.ant != NULL){
			l.pri->seg = l.ant;
			l.pri->ant = NULL;
			l.ult->seg = NULL;
			l.ult->ant = l.pri;
			l.ult->enter = -999999999;
			l.pri->enter = 9999999999;
			l.pdi = l.pri;
		}else{
			printf("ERROR al crear la llista\n");
		}
	}else{
		printf("ERROR al crear la llista\n");
	}
	return l;
}

void LLISTABIO_insereixOrdenat(LlistaBIO * l, int num){
	Node * aux;
	aux = (Node *) malloc (sizeof(Node));
	if (aux != NULL){
		aux->enter = num;
		l->pdi = l->pri;
		if(l->pri->seg == l->ult){
			aux->ant = l->pri;
			aux->seg = l->ult;
			l->pri->seg = aux;
			l->ult->ant = aux;
		}else{
			int sortir = 0;
			while (sortir == 0){
				if(l->pdi->enter > num && l->pdi->seg != l->ult){
					l->pdi = l->pdi->seg;
				}else{
					sortir = 1;
				}
			}
			aux->ant = l->pdi->ant;
			aux->seg = l->pdi;
			l->pdi->ant = aux;
			aux->ant->seg = aux;
		}
	}else{
		printf ("ERROR al inserir el nou element\n");
	}
}

void LLISTABIO_esborra(LlistaBIO * l){
	Node * aux;
	if (l->pdi == l->pri || l->pdi == l->ult){
		printf("ERROR estas fora la llista\n");
	}else{
		aux = l->pdi;
		l->pdi->ant->seg = l->pdi->seg;
		l->pdi->seg->ant = l->pdi->ant;
		l->pdi = l->pdi->ant;
		free(aux);
	}
}

int LLISTABIO_consulta(LlistaBIO l){
	int enter;
	if(l.pdi == l.pri || l.pdi == l.ult){
		printf("ERROR estas fora de la llista\n");
		enter = 0;
	}else{
		enter = l.pdi->e;
	}
	return enter;
}

int LLISTABIO_buida(LlistaBIO l){
	return l.pri == l.ult;
}

void LLISTABIO_vesInici(LlistaBIO * l){
	l->pdi = l->pri->seg;
}

void LLISTABIO_vesFi(LlistaBIO * l){
	l->pdi = l->ult->ant;
}

void LLISTABIO_avanca(LlistaBIO * l){
	if (l->pdi->seg == l->ult){
		printf("ERROR estas al final de la llista\n");
	}else{
		l->pdi = l->pdi->seg;
	}
}

void LLISTABIO_retrocedeix(LlistaBIO * l){
	if (l->pdi->ant == l->pri){
		printf("ERROR estas a l'inicid de la llista\n");
	}else{
		l->pdi = l->pdi->ant;
	}
}

int LLISTABIO_inici(LlistaBIO l){
	return l.pdi->ant == l.pri;
}

int LLISTABIO_fi(LlistaBIO l){
	return l.pdi->seg == l.ult;
}

void LLISTABIO_destrueix(LlistaBIO * l){
	Node * aux;
	while(l->pri != NULL){
		aux = l->pri;
		l->pri = l->pri->seg;
		free(aux);
	}
	l->ult = NULL;
	l->pdi = NULL;
}