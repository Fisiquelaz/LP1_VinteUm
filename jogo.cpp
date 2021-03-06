/**
* @file jogo.cpp
* @brief Métodos da classe Jogo
* @author Danilo Miranda de Medeiros Galvão, João Mendes Lopes Neto
* @since 24/04/2019
* @date 01/05/2019
*/

#include "jogo.h"

int Jogo::get_qtd_jogadores(){
	return qtd_jogadores;
}
void Jogo::set_qtd_jogadores(int q_j){
	qtd_jogadores = q_j; // A propriedade da classe é diferente do método do atributo aqui? Preciso colocar o this.
}
int Jogo::get_pontuacao_maxima(){
	return pontuacao_maxima;
}
void Jogo::set_pontuacao_maxima(int p_m){
	pontuacao_maxima = p_m;
}