#include <stdio.h>
#include <stdlib.h>
#include <unitcl/unitcl.h>

TEST(Analise, ListarTecnicos) {
	int i = 1;
	ASSERT(i == 3)
}

SUITE(Analise) {
	ADD_TEST(Analise, ListarTecnicos)
	ADD_TEST(Analise, ListarTecnicos)
}

int main(int argc, char **argv) {
	RUN_SUITE(Analise);
	return 0;
}