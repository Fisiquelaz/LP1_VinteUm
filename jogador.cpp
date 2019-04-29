#include "jogador.h"
#include <string>
#include <random>
using namespace std;

Jogador::Jogador(){
	pontuacao = 0;
	status = 0;
}

string Jogador::get_nome() {
	return nome;
}

void Jogador::set_nome(string novo_nome){
	nome = novo_nome;
}

int Jogador::get_pontuacao(){
	return pontuacao;
}
void Jogador::acumula_pontuacao(int lancamento){
	pontuacao += lancamento;
}
int Jogador::get_status(){
	return status;
}
void Jogador::altera_status(int novo_status){
	status = novo_status;
}