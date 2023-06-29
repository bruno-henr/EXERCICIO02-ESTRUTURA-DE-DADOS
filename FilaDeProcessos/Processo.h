
/// @brief 
struct processo {
	int id;    // ID do processo
	struct processo *prox;
};

struct processo* criarProcesso();
void imprimirId(struct processo* p);
