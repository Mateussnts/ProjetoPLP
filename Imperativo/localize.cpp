

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "estruturas.cpp"

using namespace std;


// função para extrair dados do csv. retorna um mapa contendo os dados do csv.
// filename -> nome do arquivo csv
// tamanho_item -> quantidade de itens de cada linha do csv
vector<vector<string>> extract_csv( string file_name, int tamanho_item) {
	
	ifstream file (file_name);
	string temp;
	vector<string> linha;
	vector<vector<string>> linhas;
	
	while(file.good()) {
		for(int i = 0; i < tamanho_item; i++) {
			getline ( file, temp, ';' );
			temp.erase(remove(temp.begin(), temp.end(), '\n'), temp.end()); // remove o endline
			linha.push_back(temp);
		}
		if(linha[0] != "") {  // evita que linhas nulas sejam adicionadas
			linhas.push_back(linha);
		}
		linha.clear();
	}
	return linhas;
}

// converte os dados do csv de clientes em structs
vector<client> inicializa_clientes() {
	
	vector<client> clientes;
	vector<vector<string>> linhas = extract_csv( "clientes.csv", 3);
	
	for(unsigned int i = 0; i < linhas.size(); i++) {
		clientes.emplace_back(linhas[i][0], linhas[i][1], linhas[i][2]);
	}
	return clientes;
}

// converte os dados do csv de veiculos em structs
vector<car> inicializa_veiculos() {
	
	vector<car> veiculos;
	vector<vector<string>> linhas = extract_csv( "carros.csv", 7);
	
	for(unsigned int i = 0; i < linhas.size(); i++) {
		veiculos.emplace_back(to_string(100+1), linhas[i][0], stoi(linhas[i][1]), stoi(linhas[i][2]), stof(linhas[i][3]), stoi(linhas[i][4]), linhas[i][5], linhas[i][6]);
	}
	return veiculos;
}
void apresentacao(){

	while(true){
	
    	cout << "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "<<endl;
        cout << "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"<<endl;
        cout << "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"<<endl;
        cout << "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"<<endl;
        cout << "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"<<endl;
		cout << "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "<<endl;
        cout << "À LOCALIZE CAR"<<endl;
        cout<<" "<<endl;
        cout << "COMO VOCÊ DESEJA SEGUIR?"<<endl;
        cout << "(1) PESQUISAR/ALUGAR"<<endl;
        cout << "(2) DEVOLVER"<<endl;
        cout << "(3) SAIR" <<endl;
    	int opcao;

        cin >> opcao;

        if (opcao == 3)
        {
            break;
        }
        else if (opcao == 1)
        {
            break;
        }
        else if (opcao == 2)
        {
           break;
        }
        else
        {
            cout << "SELECIONE UMA OPÇAO VALIDA!"<<endl;
            cout<<" "<<endl;
        }
    }
	
}

// metodo de pesquisa para aluguel de carros

void pesquisa() {
	
	string cidadeSaida;
	cout << "Informe a cidade de saída!" << endl;
	getline(cin, cidadeSaida);
	
	int qtdPassageiros;
	cout << "Informe a quantidade de Passageiros!" << endl;
	cin >> qtdPassageiros;

	vector<string> carrosDisponiveis;
	vector<car> veiculos = inicializa_veiculos();

	for (i = 0; i < veiculos.size(); i++)
	{
		if (veiculos[i].cidade_local == cidadeSaida && veiculos[i].capacidade == qtdPassageiros {
			carrosDisponiveis.push_back(veiculos[i].modelo + veiculos[i].cidade_local + veiculos[i].capacidade);
		}
	}
	
	if (carrosDisponiveis.empty() == true) {
		std::cout << "Não existe carros disponiveis no momento!" << endl;
	}
	else{
		int j;
		for (j = 0; j < carrosDisponiveis.size(); j++)
		{
			std::cout << carrosDisponiveis[j] << endl;
		}
	}
}

void apresentacao();
void pesquisa();

int main()
{
	 apresentacao();
	 pesquisa();

	// carrega o nome das cidades do sistema
	vector<string> cidades {"João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras", "Guarabira", "Cabedelo", "Santa Rita", "Monteiro", "Sumé"};
	
	// Lojas
	vector<store> lojas;
	
	// Localiza
	lojas.emplace_back("localiza", cidades);
	
	// Movida
	vector<string> cidades_movida {"João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras", "Cabedelo", "Santa Rita", "Monteiro"};
	lojas.emplace_back("Movida", cidades_movida);
	
	// Unidas
	vector<string> cidades_unidas {"João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras"};
	lojas.emplace_back("Unidas", cidades_unidas);
	
	// Heztz
	vector<string> cidades_heztz {"João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras", "Guarabira", "Cabedelo", "Sumé"};
	lojas.emplace_back("Heztz", cidades_heztz);
	
	
	// carrega os clientes do sistema
	vector<client> clientes = inicializa_clientes();
	
	// carrega os veículos do sistema
	vector<car> veiculos = inicializa_veiculos();
	
	// exemplo.
	cout << "nome: " << clientes[1].nome << " cpf: " << clientes[1].cpf << " cnh: " << clientes[1].cnh << endl;
	cout << "veículo: " << veiculos[1].modelo << " codigo: " << veiculos[1].codigo << " valor da diária: " << veiculos[1].diaria << endl;
	cout << "Loja: " << lojas[1].nome << " cidade 1: " << lojas[1].cidades[1] << endl;	
	
	
	return 0;
}
