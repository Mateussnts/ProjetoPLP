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
	string categoria; // Econômica e Luxo
	store loja;
	string cidade_local; // cidade onde o veículo está localizado no momento
	car(string newcodigo, string newmodelo, int newquantidade, int newcapacidade, float newdiaria, string newcategoria, store newloja, string newcidade_local): 
		codigo(newcodigo),
		modelo(newmodelo),
		quantidade(newquantidade),
		capacidade(newcapacidade),
		diaria(newdiaria),
		categoria(newcategoria),
		loja(newloja),
		cidade_local(newcidade_local) {}
};

// estrutura do aluguel
struct rent {
	car veiculo;
	string cidade_destino;
	float diaria;
	int dias;
	rent(car newveiculo, string newcidade_destino, float newdiaria, int newdias): 
		veiculo(newveiculo),
		cidade_destino(newcidade_destino),
		diaria(newdiaria),
		dias(newdias) {}
};

// estrutura dos clientes
struct client {
	string codigo;
	string nome;
	string cpf;
	string cnh;
	int numero_aluguel = 0;
	vector<rent> locacoes;
	client(string newcodigo, string newnome, string newcpf, string newcnh): 
		codigo(newcodigo),
		nome(newnome),
		cpf(newcpf),
		cnh(newcnh) {}
};
