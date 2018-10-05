#include "LlistaBIO.h"
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