#ifndef JOGADOR_H
#define JOGADOR_H

class Jogador {
	public:
		// string nome;
		int pontuacao;
		int status; // 0 - ativo; 1 - inativo; 2 - perdeu; 3 - ganhou

		// construtor
		Jogador();
		// metodos
		void acumula_pontuacao(); // DÚVIDA de modularização: Devo colocar o resultado dos dados como parâmetro ou não?
		void altera_status(int novo_status);
}

#endif