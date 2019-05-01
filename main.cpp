#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;

#include "jogador.h"
#include "jogo.h"
// #include "dado.h"

using namespace std;

int main(){
	Jogo vinte_um;
	int q, n;
	string nome;

	cout << "Quantos jogadores participarão?" << endl;
	cin >> q;

	cout << "Qual será a pontuação máxima?" << endl;
	cin >> n;

	vinte_um.set_qtd_jogadores(q);
	vinte_um.set_pontuacao_maxima(n);

	Jogador jogadores[vinte_um.get_qtd_jogadores()];

	cout << "Digite os nomes dos jogadores" << endl;

	for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
		cout << "Nome do jogador " << i + 1 << ":" << endl;
		cin >> nome;
		jogadores[i].set_nome(nome);
	}
	int vencer = 0, count_rodada = 1, count_nao_ativo = 0, count_perdeu = 0, opcao, cond_parada, result_dado, vencedor_rodada = -1;
	// Dado dado;
	srand (time(NULL));

	while(vencer == 0){
		cout << "\nJOGADA " << count_rodada << endl;
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
			if(jogadores[i].get_status() == 0){ // o jogador só lança os dados se seu status ainda for ativo
				cout << jogadores[i].get_nome() << endl;
				result_dado = rand() % 6 + 1;
				jogadores[i].acumula_pontuacao(result_dado);

				cout << "O resultado do seu lançamento foi: " << result_dado << endl;

				if(jogadores[i].get_pontuacao() > vinte_um.get_pontuacao_maxima()){ // se a pontuação acumulada do jogador for maior que a pontuação máxima, ele perde
					jogadores[i].altera_status(2);
					cout << "Você perdeu :(" << endl;
				}
				else{
					if(jogadores[i].get_pontuacao() == vinte_um.get_pontuacao_maxima()){ // se a pontuação acumulada do jogador for igual a pontuação máxima, ele ganha e o jogo acaba
						jogadores[i].altera_status(3);
						vencer = 1;
						cond_parada = 3; // condição de parada para o caso de algum jogador ter atingido a pontuação máxima
						break;
					}
					else{
						cout << "Deseja continuar? 0 - Não; 1 - Sim" << endl;
						cin >> opcao;
						if(opcao == 0){ // se o jogador decidir não continuar, o seu status é alterado para inativo
							jogadores[i].altera_status(1);
						}
					}
				}
			}
		}
		cout << "\nRESULTADO PARCIAL" << endl;
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
			if (jogadores[i].get_status() == 2) cout << jogadores[i].get_nome() << ": Perdeu" << endl;
			if (jogadores[i].get_status() != 2)	{
				cout << jogadores[i].get_nome() << ": " << jogadores[i].get_pontuacao() << endl;
				if (vencedor_rodada == -1) vencedor_rodada = i;
				else {
					if (jogadores[i].get_pontuacao() > jogadores[vencedor_rodada].get_pontuacao()) vencedor_rodada = i;
				}
			}
		}
		cout << "Vencedor da rodada: " << jogadores[vencedor_rodada].get_nome() << endl;
		count_rodada += 1;
		vencedor_rodada = -1;

		if(vencer == 0){
			for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
				if(jogadores[i].get_status() != 0){
					count_nao_ativo += 1;
				}
				if(jogadores[i].get_status() == 2){
					count_perdeu += 1;
				}
			}
			if (vinte_um.get_qtd_jogadores() - 1 == count_perdeu){ // condição de parada para o caso de todos os jogadores exceto 1 já terem perdido
				vencer = 1;
				cond_parada = 1;
			}
			if (vinte_um.get_qtd_jogadores() == count_nao_ativo){ // condição de parada para o caso de todos os jogadores não estarem mais ativos
				vencer = 1;
				cond_parada = 2;
			}
		}
		count_nao_ativo = 0;
		count_perdeu = 0;
	}

	cout << endl;

	if (cond_parada == 1){
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
			if (jogadores[i].get_status() != 2) cout << jogadores[i].get_nome() << " venceu!" << endl;
		}
	}
	if (cond_parada == 2){
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
			if(jogadores[i].get_status() != 2){
				if (vencedor_rodada == -1) vencedor_rodada = i;
				else{
					if (jogadores[i].get_pontuacao() > jogadores[vencedor_rodada].get_pontuacao()) vencedor_rodada = i;
				}
			}
		}
		cout << jogadores[vencedor_rodada].get_nome() << " venceu!" << endl;
	}
	if (cond_parada == 3){
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
			if (jogadores[i].get_status() == 3) cout << jogadores[i].get_nome() << " venceu!" << endl;
		}
	}

	return 0;
}
