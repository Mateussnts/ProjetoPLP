#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "estruturas-alternativo.cpp"

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

string to_lower(string input) {
	for (unsigned int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
    }
    return input;
}

store get_loja_por_nome(string nome_loja, vector<store> lojas) {
	for(unsigned int i = 0; i < lojas.size(); i++) {
		if(nome_loja == lojas[i].nome) {
			return lojas[i];
		}
	}
	vector<string> cidades;
	store loja = store("Sem Loja", cidades);
	return loja;
}

client get_client_por_codigo(string codigoCliente, vector<client> clientes) {
	for(unsigned int i = 0; i < clientes.size(); i++) {
		if(codigoCliente == clientes[i].codigo) {
			return clientes[i];
		}
	}
	client cliente = client("0","Sem Cliente", "", "");
	return cliente;
}

car get_veiculo_por_codigo(string codigoVeiculo, vector<car> veiculos) {
	for(unsigned int i = 0; i < veiculos.size(); i++) {
		if(codigoVeiculo == veiculos[i].codigo) {
			return veiculos[i];
		}
	}
	vector<string> cidades;
	store loja = store("Sem Loja", cidades);
	car veiculo = car("0","Sem Veiculo", 0, 0, 0, "", loja, "");
	return veiculo;
}

int get_client_indice(client cliente, vector<client> clientes) {
	for(unsigned int i = 0; i < clientes.size(); i++) {
		if(cliente.codigo == clientes[i].codigo) {
			return i;
		}
	}
	return -1;
}

int get_veiculo_indice(car veiculo, vector<car> veiculos) {
	for(unsigned int i = 0; i < veiculos.size(); i++) {
		if(veiculo.codigo == veiculos[i].codigo) {
			return i;
		}
	}
	return -1;
}

// converte os dados do csv de clientes em structs
vector<client> inicializa_clientes() {
	
	vector<client> clientes;
	vector<vector<string>> linhas = extract_csv( "clientes.csv", 3);
	
	for(unsigned int i = 0; i < linhas.size(); i++) {
		clientes.emplace_back(to_string(11+i),linhas[i][0], linhas[i][1], linhas[i][2]);
	}
	return clientes;
}

// converte os dados do csv de veiculos em structs
vector<car> inicializa_veiculos(vector<store> lojas) {
	
	vector<car> veiculos;
	vector<vector<string>> linhas = extract_csv( "carros-alternativo.csv", 7);
	
	for(unsigned int i = 0; i < linhas.size(); i++) {
		store loja = get_loja_por_nome(linhas[i][5], lojas);
		if(loja.nome != "Sem Loja") {
			veiculos.emplace_back(to_string(101+i), linhas[i][0], stoi(linhas[i][1]), stoi(linhas[i][2]), stof(linhas[i][3]), linhas[i][4], loja, linhas[i][6]);
		}
	}
	return veiculos;
}

void apresentacao() {
	cout << endl;
	cout << "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "<< endl;
    cout << "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"<< endl;
    cout << "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"<< endl;
    cout << "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"<< endl;
    cout << "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"<< endl;
	cout << "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "<< endl;
    cout << "À LOCALIZE CAR" << endl << endl;
    
}

void menu_principal() {
	
    cout << "O que você deseja fazer?" << endl << endl;
    cout << "(1) Pesquisar/Alugar" << endl;
    cout << "(2) Devolver" << endl;
    cout << "(3) Sair" << endl << endl;
    
}

void menu_pesquisar_alugar() {
	cout << "Escolha a opção desejada?" << endl << endl;
    cout << "(1) Alugar" << endl;
    cout << "(2) Nova pesquisa" << endl;
    cout << "(3) Sair" << endl << endl;
}

// metodo de pesquisa para aluguel de carros

vector<car> pesquisa(string cidade_retirada, string cidade_destino, int qtdPassageiros, vector<car> veiculos) {

	vector<car> carrosDisponiveis;
	
	for(unsigned int i = 0; i < veiculos.size(); i++) {
		bool tem_destino = false;
		for(unsigned int j = 0; j < veiculos[i].loja.cidades.size(); j++ ) {
			if(to_lower(veiculos[i].loja.cidades[j]) == to_lower(cidade_destino)) {
				tem_destino = true;
				break;
			}
		}
		if(tem_destino && to_lower(veiculos[i].cidade_local) == to_lower(cidade_retirada) &&
			veiculos[i].capacidade >= qtdPassageiros &&
			veiculos[i].quantidade >= 1) {
				carrosDisponiveis.push_back(veiculos[i]);
		}
	}
	return carrosDisponiveis;
	
	
}

rent alugar(car veiculo, string cidade_destino, float diaria, int qtdDias) {
	rent aluguel = rent(veiculo, cidade_destino, diaria, qtdDias);
	return aluguel;	
}

int main() {

	// carrega o nome das cidades do sistema
	vector<string> cidades {"João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras", "Guarabira", "Cabedelo", "Santa Rita", "Monteiro", "Sumé"};
	
	// Lojas
	vector<store> lojas;
	
	// Localiza
	lojas.emplace_back("Localiza", cidades);
	
	// Movida
	vector<string> cidades_movida {"João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras", "Cabedelo", "Santa Rita", "Monteiro"};
	lojas.emplace_back("Movida", cidades_movida);
	
	// Unidas
	vector<string> cidades_unidas {"João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras"};
	lojas.emplace_back("Unidas", cidades_unidas);
	
	// Heztz
	vector<string> cidades_hertz {"João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras", "Guarabira", "Cabedelo", "Sumé"};
	lojas.emplace_back("Hertz", cidades_hertz);
	
	
	// carrega os clientes do sistema
	vector<client> clientes = inicializa_clientes();
	
	// carrega os veículos do sistema
	vector<car> veiculos = inicializa_veiculos(lojas);
	
	apresentacao();
	
	while(true) {
		
		menu_principal();
		string opcao;
		getline(cin, opcao);

		if (opcao == "1") {
			
			cout << endl << "Cidades disponíveis: ";
			for(unsigned int i = 0; i < cidades.size(); i++) {
				if(i == cidades.size()-1) {
					cout << cidades[i] << endl;
				} else {
					cout << cidades[i] << ", ";
				}
			}
			
			cout << "Usuarios disponíveis: ";
			for(unsigned int i = 0; i < clientes.size(); i++) {
				if(i == clientes.size()-1) {
					cout << clientes[i].codigo << " - " << clientes[i].nome << endl;
				} else {
					cout << clientes[i].codigo << " - " << clientes[i].nome << ", ";
				}
			}
			cout << endl;
				
			string cidadeSaida;
			cout << "Informe a cidade de saída: ";
			getline(cin, cidadeSaida);
					
			string cidadeDestino;
			cout << "Informe a cidade de destino: ";
			getline(cin, cidadeDestino);
			
			int qtdPassageiros;
			cout << "Informe a quantidade de Passageiros: ";
			cin >> qtdPassageiros;
			cin.ignore();
					
			vector<car> carrosDisponiveis = pesquisa(cidadeSaida, cidadeDestino, qtdPassageiros, veiculos);
					
			if (carrosDisponiveis.empty() == true) {
				cout << "Não existem carros disponíveis com estes critérios de pesquisa! Por favor, tente novamente com outros dados!" << endl;
				continue;
			} else {
				cout << "Resultado da pesquisa:" << endl << endl;
				cout << "Código\t" << "| Modelo\t\t\t" << "| Capacidade\t" << "| Quantidade\t" << "| Diária\t" << "| Categoria\t\t" << "| Loja" << endl;
				cout << "===============================================================================================================================" << endl;
				for(unsigned int i = 0; i < carrosDisponiveis.size(); i++) {
					cout << carrosDisponiveis[i].codigo << "\t";
					cout << "| " << setw(25) << carrosDisponiveis[i].modelo << "\t";
					cout << "| " << carrosDisponiveis[i].capacidade << "\t\t";
					cout << "| " << carrosDisponiveis[i].quantidade << "\t\t";
					cout << "| " << setw(8) << fixed << setprecision(2) << carrosDisponiveis[i].diaria << "\t";
					cout << "| " << setw(9) << carrosDisponiveis[i].categoria << "\t\t";
					cout << "| " << carrosDisponiveis[i].loja.nome << endl;
				}
				cout << endl;
				
				string codigoCliente;
				cout << "Para alugar, informe o código do cliente ou digite '0' para sair: ";
				getline(cin, codigoCliente);
				
				if(codigoCliente == "0") continue;
				
				string codigoVeiculo;
				cout << "Informe o código do veículo: ";
				getline(cin, codigoVeiculo);
				
				int qtdDias;
				cout << "Informe a quantidade de dias para alugar: ";
				cin >> qtdDias;
				cin.ignore();
				
				if(get_client_por_codigo(codigoCliente, clientes).codigo != "0" && get_veiculo_por_codigo(codigoVeiculo, veiculos).codigo != "0") {
				
					int index_veiculo = get_veiculo_indice(get_veiculo_por_codigo(codigoVeiculo, veiculos), veiculos);
					int index_cliente = get_client_indice(get_client_por_codigo(codigoCliente, clientes), clientes);
					
					float diaria;
					if(clientes[index_cliente].numero_aluguel >= 10 && veiculos[index_veiculo].categoria == "Luxo") {
						diaria = veiculos[index_veiculo].diaria - (veiculos[index_veiculo].diaria * 0.15);
					} else {
						diaria = veiculos[index_veiculo].diaria;
					}
					
					clientes[index_cliente].locacoes.push_back(alugar(veiculos[index_veiculo], cidadeDestino, diaria, qtdDias));
					clientes[index_cliente].numero_aluguel += 1;
					veiculos[index_veiculo].quantidade -= 1;
		
					cout << endl << "Aluguel realizado com sucesso!" << endl;
					for(unsigned int i = 0; i < clientes[index_cliente].locacoes.size(); i++) {
						cout << "Aluguel " << i+1 << ": " << clientes[index_cliente].codigo << " - " << clientes[index_cliente].nome << " -> ";
						cout << clientes[index_cliente].locacoes[i].veiculo.modelo << " - " << clientes[index_cliente].locacoes[i].cidade_destino << " - Quantidade de dias: " << clientes[index_cliente].locacoes[i].dias;
						cout << " - Diária: " << setw(8) << fixed << setprecision(2) << clientes[index_cliente].locacoes[i].diaria;
						cout << " - Total: " << setw(8) << fixed << setprecision(2) << clientes[index_cliente].locacoes[i].diaria * clientes[index_cliente].locacoes[i].dias << endl << endl;
					}
					
				} else {
					cout << endl << "Não foi possível realizar o aluguel! Por favor, verifique os dados digitados." << endl;
				}
				
			}
				
		} else if (opcao == "2") {
			
			cout << "Usuarios disponíveis: ";
			for(unsigned int i = 0; i < clientes.size(); i++) {
				if(i == clientes.size()-1) {
					cout << clientes[i].codigo << " - " << clientes[i].nome << endl;
				} else {
					cout << clientes[i].codigo << " - " << clientes[i].nome << ", ";
				}
			}
			cout << endl;

			string codigoCliente;
			cout << "Informe o código do cliente: ";
			getline(cin, codigoCliente);
			
			if(get_client_por_codigo(codigoCliente, clientes).codigo != "0" && get_client_por_codigo(codigoCliente, clientes).locacoes.size() > 0) {
				
				int index_cliente = get_client_indice(get_client_por_codigo(codigoCliente, clientes), clientes);
				for(unsigned int i = 0; i < clientes[index_cliente].locacoes.size(); i++) {
					cout << "Aluguel " << i+1 << ": " << clientes[index_cliente].codigo << " - " << clientes[index_cliente].nome << " -> " << clientes[index_cliente].locacoes[i].veiculo.modelo << " - " << clientes[index_cliente].locacoes[i].cidade_destino << " - Diária: " << setw(8) << fixed << setprecision(2) << clientes[index_cliente].locacoes[i].diaria << endl;
				}
				
				unsigned int numero_locacao;
				cout << "Informe o número do aluguel: ";
				cin >> numero_locacao;
				cin.ignore();
				
				if( numero_locacao < 1 || numero_locacao > get_client_por_codigo(codigoCliente, clientes).locacoes.size()) {
					cout << endl << "Você não informou um número de locação válido!" << endl;
					continue;
				}
					
				int index_veiculo = get_veiculo_indice(get_client_por_codigo(codigoCliente, clientes).locacoes[numero_locacao-1].veiculo, veiculos);
									
				clientes[index_cliente].locacoes.erase(clientes[index_cliente].locacoes.begin()+numero_locacao-1);
				veiculos[index_veiculo].quantidade += 1;
				veiculos[index_veiculo].cidade_local = clientes[index_cliente].locacoes[numero_locacao-1].cidade_destino;
				cout << "Devolução realizada com sucesso!" << endl;
				cout << "Veículo " << veiculos[index_veiculo].codigo << " - " << veiculos[index_veiculo].modelo << " devolvido em " << veiculos[index_veiculo].cidade_local << endl << endl;
					
			} else {
				cout << "Não foi possível realizar a devolução! O cliente não existe ou não possui locações." << endl;
			}
				
		} else if (opcao == "3") {
			cout << "você saiu do sistema!" << endl;
			break;
		} else {
			cout << "Selecione uma opção válida!" << endl;
		}
		
    }
	
	
	
	return 0;
}
