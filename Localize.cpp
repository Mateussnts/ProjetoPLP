#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

// estrutura das lojas
struct store {
	string nome;
	vector<string> cidades; // coleção de cidades onde a loja trabalha
	store(string newnome, vector<string> newcidades): 
		nome(newnome),
		cidades(newcidades) {}
};

// estrutura dos carros
struct car {
	string codigo;
	string modelo;
	int quantidade;
	int capacidade;
	float diaria;
	int categoria; // 0 para normal e 1 para luxo
	string nome_loja;
	string cidade_local; // cidade onde o veículo está localizado no momento
	car(string newcodigo, string newmodelo, int newquantidade, int newcapacidade, float newdiaria, int newcategoria, string newnome_loja, string newcidade_local): 
		codigo(newcodigo),
		modelo(newmodelo),
		quantidade(newquantidade),
		capacidade(newcapacidade),
		diaria(newdiaria),
		categoria(newcategoria),
		nome_loja(newnome_loja),
		cidade_local(newcidade_local) {}
};

// estrutura do aluguel
struct rent {
	int codigo_usuario;
	car veiculo;
	string cidade_destino;
};

struct client {
	string nome;
	string cpf;
	string cnh;
	int numero_aluguel;
	vector<rent> locacoes;
	client(string newnome, string newcpf, string newcnh): 
		nome(newnome),
		cpf(newcpf),
		cnh(newcnh) {}
};

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

int main() {
	
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
