#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <ctime>

using std::string;
using std::vector;
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
		cidade_local(newcidade_local){}
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
