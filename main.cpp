/**
* @file main.cpp
* @brief Arquivo principal para execução do programa
* @author Danilo Miranda de Medeiros Galvão, João Mendes Lopes Neto
* @since 24/04/2019
* @date 01/05/2019
*/

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
	int vencer = 0, count_rodada = 1, count_nao_ativo = 0, count_perdeu = 0, opcao = 2, cond_parada, result_dado1, result_dado2, vencedor_rodada = -1, empate = 0;
	// Dado dado;
	srand (time(NULL));

	while(vencer == 0){
		cout << "\nJOGADA " << count_rodada << endl;
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
			if(jogadores[i].get_status() == 0){ // o jogador só lança os dados se seu status ainda for ativo
				cout << "Jogador: " << jogadores[i].get_nome() << endl;
				result_dado1 = rand() % 6 + 1;
				result_dado2 = rand() % 6 + 1;
				jogadores[i].acumula_pontuacao(result_dado1);
				jogadores[i].acumula_pontuacao(result_dado2);

				cout << "Os resultados do seu lançamento foram: " << result_dado1 << " e " << result_dado2 << endl;

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
						while (opcao != 0 && opcao != 1){
							cout << "Deseja continuar? 0 - Não; 1 - Sim" << endl;
							cin >> opcao;
							if (opcao != 0 && opcao != 1){
								cout << "Digite 0 ou 1" << endl;
							} 
						}
						if(opcao == 0){ // se o jogador decidir não continuar, o seu status é alterado para inativo
							jogadores[i].altera_status(1);
						}
						opcao = 2;
					}
				}
			}
		}
		cout << "\nRESULTADO PARCIAL" << endl;
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
			if (jogadores[i].get_status() == 2) cout << jogadores[i].get_nome() << ": Perdeu" << endl;
			if (jogadores[i].get_status() != 2)	{
				cout << jogadores[i].get_nome() << ": " << jogadores[i].get_pontuacao() << endl;
			}
		}
		count_rodada += 1;

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
			if (vinte_um.get_qtd_jogadores() == count_nao_ativo && vinte_um.get_qtd_jogadores() != count_perdeu){ // condição de parada para o caso de todos os jogadores não estarem mais ativos
				vencer = 1;
				cond_parada = 2;
			}
			if (vinte_um.get_qtd_jogadores() == count_perdeu){ // condição de parada para o caso de todos os jogadores já terem perdido
				vencer = 1;
				cond_parada = 4;
			}
		}
		count_nao_ativo = 0;
		count_perdeu = 0;
	}

	cout << endl;

	if (cond_parada == 1){
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
			if (jogadores[i].get_status() != 2) cout << jogadores[i].get_nome() << " venceu a rodada!" << endl;
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
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){ // análise do caso se outro jogador atingiu a pontuação do ganhador, ou seja, houve empate
			if(jogadores[i].get_status() != 2){
				if (jogadores[i].get_pontuacao() == jogadores[vencedor_rodada].get_pontuacao() && i != vencedor_rodada) {
					if (empate == 0) cout << "Os vencedores foram " << jogadores[vencedor_rodada].get_nome();
					cout << ", " << jogadores[i].get_nome();
					empate = 1;
				}
			}
		}
		if (empate == 0) cout << jogadores[vencedor_rodada].get_nome() << " venceu a rodada!";
		cout << endl;
	}
	if (cond_parada == 3){
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
			if (jogadores[i].get_status() == 3) cout << jogadores[i].get_nome() << " venceu a rodada!" << endl;
		}
	}
	if (cond_parada == 4) {
		cout << "Não houve vencedores na rodada" << endl;
	}

	return 0;
}
