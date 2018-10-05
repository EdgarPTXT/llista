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