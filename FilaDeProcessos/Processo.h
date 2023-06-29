
typedef struct processo Processo;

struct processo {
	int id;    // ID do processo
	Processo *prox;
};

struct processo* criarProcesso();
void imprimirId(struct processo* p);
