/**
* @file jogador.h
* @brief Classe Jogador
* @author Danilo Miranda de Medeiros Galvão, João Mendes Lopes Neto
* @since 24/04/2019
* @date 01/05/2019
*/

#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
using namespace std;

class Jogador {
	private:
		string nome;
		int pontuacao;
		int status; //!< 0 - ativo; 1 - inativo; 2 - perdeu; 3 - ganhou

	public:
		// construtor
		Jogador();
		// metodos
		string get_nome();
		void set_nome(string nome);
		int get_pontuacao();
		void acumula_pontuacao(int lancamento); //!< Incrementa a pontuação do jogador com o lançamento de cada jogada 
		int get_status();
		void altera_status(int novo_status); //!< 0 - ativo; 1 - inativo; 2 - perdeu; 3 - ganhou
};

#endif
