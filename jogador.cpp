#include "jogador.h"

Jogador::Jogador(){
	pontuacao = 0;
	status = 0;
}

void Jogador::acumula_pontuacao(){
	// pontuacao = o resultado dos dados
}

void Jogador::altera_status(int novo_status){
	status = novo_status;
}