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