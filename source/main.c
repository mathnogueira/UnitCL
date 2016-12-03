#include <stdio.h>
#include <stdlib.h>
#include <unitcl/unitcl.h>

TEST(Analise, ListarTecnicos) {
	printf("Sera? \n");
	int i = 1;
	ASSERT(i == 3)
}

TEST(Analise, ListarTecnico) {
	printf("Outra funcao? \n");
	int i = 1;
	ASSERT(i == 3)
}

TEST(CadastroUsoAgua, ListarIntervencoes) {
	printf("Canal \n");
	int i = 8;
	ASSERT(i == 8)
}

SUITE(Analise) {
	ADD_TEST(Analise, ListarTecnicos)
	ADD_TEST(Analise, ListarTecnico)
}

SUITE(CadastroUsoAgua) {
	ADD_TEST(CadastroUsoAgua, ListarIntervencoes)
	ADD_SUITE(Analise, CadastroUsoAgua)
}

int main(int argc, char **argv) {
	UNITCL_INIT();
	RUN_SUITE(CadastroUsoAgua);
	return 0;
}