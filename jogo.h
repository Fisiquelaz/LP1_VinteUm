/**
* @file jogo.h
* @brief Classe Jogo
* @author Danilo Miranda de Medeiros Galvão, João Mendes Lopes Neto
* @since 24/04/2019
* @date 01/05/2019
*/

#ifndef JOGO_H
#define JOGO_H


class Jogo {
	private:
		int qtd_jogadores;
		int pontuacao_maxima;

	public:
		// metodos
		int get_qtd_jogadores();
		void set_qtd_jogadores(int qtd_jogadores);
		int get_pontuacao_maxima();
		void set_pontuacao_maxima(int pontuacao_maxima);
};

#endif