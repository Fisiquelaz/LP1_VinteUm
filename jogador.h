#ifndef JOGADOR_H
#define JOGADOR_H

class Jogador {
	private:
		// string nome;
		int pontuacao;
		int status; // 0 - ativo; 1 - inativo; 2 - perdeu; 3 - ganhou

	public:
		// construtor
		Jogador();
		// metodos
		// string get_nome();
		// void set_nome();
		int get_pontuacao();
		void acumula_pontuacao(); // DÚVIDA de modularização: Devo colocar o resultado dos dados como parâmetro ou não?
		int get_status();
		void altera_status(int novo_status);
};

#endif