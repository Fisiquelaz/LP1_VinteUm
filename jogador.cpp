/**
* @file jogador.cpp
* @brief Métodos da classe Jogador
* @author Danilo Miranda de Medeiros Galvão, João Mendes Lopes Neto
* @since 24/04/2019
* @date 01/05/2019
*/

#include "jogador.h"
#include <string>
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
