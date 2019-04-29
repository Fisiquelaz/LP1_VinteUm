#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

#include "jogador.h"
#include "jogo.h"
#include "dado.h"

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

	for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
		cin >> nome;
		jogadores[i].set_nome(nome);	
	}

	int vencer = 0, count_nao_ativo = 0, count_perdeu = 0, opcao, cond_parada;
	Dado dado;

	while(vencer == 0){
		for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
			if(jogadores[i].get_status() == 0){
				jogadores[i].acumula_pontuacao(dado.jogar());

				if(jogadores[i].get_pontuacao() > vinte_um.get_pontuacao_maxima()){
					jogadores[i].set_status(2);
				}
				if(jogadores[i].get_pontuacao() == vinte_um.get_pontuacao_maxima()){
					jogadores[i].set_status(3);
					vencer = 1;
					break;
				}
				else{
					cout << "Deseja continuar:\n0 - Não 1 - Sim" << endl;
					cin >> opcao;
					if(opcao == 0){
						jogadores[i].set_status(1);
					}
				}
			}
		}
		if(vencer == 0){
			for(int i = 0; i < vinte_um.get_qtd_jogadores(); i++){
				if(jogadores[i].get_status != 0){
					count_nao_ativo += 1;
				}
				if(jogadores[i].get_status == 2){
					count_perdeu += 1;
				}
			}
			if (vinte_um.get_qtd_jogadores() - 1 == count_perdeu){
				vencer = 1;
				cond_parada = 1;
			}
			if (vinte_um.get_qtd_jogadores() == count_nao_ativo){
				vencer = 1;
				cond_parada = 2;
			}
		}
	}

	// cout << vinte_um.get_qtd_jogadores() << endl;

	return 0;
}