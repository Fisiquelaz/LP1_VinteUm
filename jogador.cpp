#include "jogador.h"

Jogador::Jogador(){
	pontuacao = 0;
	status = 0;
}

int Jogador::get_pontuacao(){
	return pontuacao;
}
void Jogador::acumula_pontuacao(){
	// pontuacao = o resultado dos dados
}
int Jogador::get_status(){
	return status;
}
void Jogador::altera_status(int novo_status){
	status = novo_status;
}