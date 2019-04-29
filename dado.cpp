// #include <random>
#include "dado.h"
#include <cstdlib>
#include <stdlib.h>

// Dado::Dado():rd(), gen(rd()), dis(1, 6) {
// 	valor = std::round(dis(gen));
// }

int Dado::jogar() {
	valor = 1 + rand() % 6; // LEMBRAR QUE SERÃO DOIS DADOS
	return valor;
}