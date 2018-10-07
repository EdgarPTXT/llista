#ifndef _LLISTA_H_
#define _LLISTA_H_

typedef struct N {
	int enter;
	struct N*ant;
	struct N*seg;
}Node;

typedef struct {
	Node * pri;
	Node * ult;
	Node * pdi;
}LlistaBIO;

LlistaBIO LLISTABIO_crea();
void LLISTABIO_insereixOrdenat(LlistaBIO * l, int num);
void LLISTABIO_esborra(LlistaBIO * l);
int LLISTABIO_consulta(LlistaBIO l);
int LLISTABIO_buida(LlistaBIO l);
void LLISTABIO_vesInici(LlistaBIO * l);
void LLISTABIO_vesFi(LlistaBIO * l);
void LLISTABIO_avanca(LlistaBIO * l);
void LLISTABIO_retrocedeix(LlistaBIO * l);
int LLISTABIO_inici(LlistaBIO l);
int LLISTABIO_fi(LlistaBIO l);
void LLISTABIO_destrueix(LlistaBIO * l);

#endif