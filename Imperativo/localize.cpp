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
#include "estruturas.cpp"

using namespace std;

/*
 * Função para extrair dados do csv. retorna um mapa contendo os dados do csv.
 * file_name representa o nome do arquivo csv
 * tamanho_item representa a quantidade de itens de cada linha do csv.
 */
vector<vector<string>> extract_csv(string file_name, int tamanho_item) {

	ifstream file(file_name);
	string temp;
	vector < string > linha;
	vector < vector < string >> linhas;

	while (file.good()) {
		for (int i = 0; i < tamanho_item; i++) {
			getline(file, temp, ';');
			temp.erase(remove(temp.begin(), temp.end(), '\n'), temp.end()); // remove o endline
			linha.push_back(temp);
		}
		if (linha[0] != "") {  // evita que linhas nulas sejam adicionadas
			linhas.push_back(linha);
		}
		linha.clear();
	}
	return linhas;
}

/*
 * Função responsavel por transformar um palavra de entrada em minuscula
 */
string to_lower(string input) {
	for (unsigned int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}
	return input;
}

/*
 * pesquisa/retorna uma loja informando seu nome.
 * Se não existir loja com o nome informado, retorna uma loja fake que pode ser identificada pelo nome de "Sem Loja"
 */
store get_loja_por_nome(string nome_loja, vector<store> lojas) {
	for (unsigned int i = 0; i < lojas.size(); i++) {
		if (nome_loja == lojas[i].nome) {
			return lojas[i];
		}
	}
	vector < string > cidades;
	store loja = store("Sem Loja", cidades);
	return loja;
}

/*
 * pesquisa/retorna um cliente informando seu codigo.
 * se não existir cliente com o cÃ³digo informado, retorna um cliente fake que pode ser identificada pelo codigo "0"
 * ou nome de "Sem Cliente"
 */

client get_client_por_codigo(string codigoCliente, vector<client> clientes) {
	for (unsigned int i = 0; i < clientes.size(); i++) {
		if (codigoCliente == clientes[i].codigo) {
			return clientes[i];
		}
	}
	client cliente = client("0", "Sem Cliente", "", "");
	return cliente;
}

/*
 * Função para encontrar um carro utilizando o seu código
 * codigoVeiculo representa o código do veicula a ser procurado
 * veiculos representa o array quer armazena os veículos cadastrados
 */
car get_veiculo_por_codigo(string codigoVeiculo, vector<car> veiculos) {
	for (unsigned int i = 0; i < veiculos.size(); i++) {
		if (codigoVeiculo == veiculos[i].codigo) {
			return veiculos[i];
		}
	}
	vector < string > cidades;
	store loja = store("Sem Loja", cidades);
	car veiculo = car("0", "Sem Veiculo", 0, 0, 0, "", loja, "");
	return veiculo;
}

/*
 * pesquisa/retorna um carro informando seu modelo e a cidade onde ele esta
 * se não existir carro com o modelo e cidade informados, retorna um carro fake que pode ser identificada pelo codigo "0"
 * ou nome de "Sem Veiculo"
 */
car get_veiculo_por_modelo(string modelo, string cidadeLocal,
		vector<car> veiculos) {
	for (unsigned int i = 0; i < veiculos.size(); i++) {
		if (modelo == veiculos[i].modelo
				&& cidadeLocal == veiculos[i].cidade_local) {
			return veiculos[i];
		}
	}
	vector < string > cidades;
	store loja = store("Sem Loja", cidades);
	car veiculo = car("0", "Sem Veiculo", 0, 0, 0, "", loja, "");
	return veiculo;
}

/*
 * Função para encontrar o indice do cliente no array
 * cliente representa o usuário a ser procurado
 * clientes representa o array dos clientes cadastrados
 */
int get_client_indice(client cliente, vector<client> clientes) {
	for (unsigned int i = 0; i < clientes.size(); i++) {
		if (cliente.codigo == clientes[i].codigo) {
			return i;
		}
	}
	return -1;
}

/*
 * retorna o indice correspondente a posição do veiculo no vetor de veiculos
 * caso o veiculo não exista no vetor, retorna -1;
 */

int get_veiculo_indice(car veiculo, vector<car> veiculos) {
	for (unsigned int i = 0; i < veiculos.size(); i++) {
		if (veiculo.codigo == veiculos[i].codigo) {
			return i;
		}
	}
	return -1;
}

/*
 * converte os dados do csv de clientes em structs
 */
vector<client> inicializa_clientes() {

	vector<client> clientes;
	vector < vector < string >> linhas = extract_csv("clientes.csv", 3);

	for (unsigned int i = 0; i < linhas.size(); i++) {
		clientes.emplace_back(to_string(11 + i), linhas[i][0], linhas[i][1],
				linhas[i][2]);
	}
	return clientes;
}

/*
 * converte os dados do csv de veiculos em structs
 */
vector<car> inicializa_veiculos(vector<store> lojas) {

	vector<car> veiculos;
	vector < vector < string >> linhas = extract_csv("carros.csv", 7);

	for (unsigned int i = 0; i < linhas.size(); i++) {
		store loja = get_loja_por_nome(linhas[i][5], lojas);
		if (loja.nome != "Sem Loja") {
			veiculos.emplace_back(to_string(101 + i), linhas[i][0],
					stoi(linhas[i][1]), stoi(linhas[i][2]), stof(linhas[i][3]),
					linhas[i][4], loja, linhas[i][6]);
		}
	}
	return veiculos;
}

/*
 * menu de apresentação
 */
void apresentacao() {
	cout << endl;
	cout
			<< "â–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ•— â–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ•—â–ˆâ–ˆâ–ˆâ•—   â–ˆâ–ˆâ–ˆâ•—    â–ˆâ–ˆâ•—   â–ˆâ–ˆâ•—â–ˆâ–ˆâ•—â–ˆâ–ˆâ–ˆâ•—   â–ˆâ–ˆâ•—â–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ•—  â–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ•— "
			<< endl;
	cout
			<< "â–ˆâ–ˆâ•”â•�â•�â–ˆâ–ˆâ•—â–ˆâ–ˆâ•”â•�â•�â•�â•�â•�â–ˆâ–ˆâ–ˆâ–ˆâ•— â–ˆâ–ˆâ–ˆâ–ˆâ•‘    â–ˆâ–ˆâ•‘   â–ˆâ–ˆâ•‘â–ˆâ–ˆâ•‘â–ˆâ–ˆâ–ˆâ–ˆâ•—  â–ˆâ–ˆâ•‘â–ˆâ–ˆâ•”â•�â•�â–ˆâ–ˆâ•—â–ˆâ–ˆâ•”â•�â•�â•�â–ˆâ–ˆâ•—"
			<< endl;
	cout
			<< "â–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ•”â•�â–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ•—  â–ˆâ–ˆâ•”â–ˆâ–ˆâ–ˆâ–ˆâ•”â–ˆâ–ˆâ•‘    â–ˆâ–ˆâ•‘   â–ˆâ–ˆâ•‘â–ˆâ–ˆâ•‘â–ˆâ–ˆâ•”â–ˆâ–ˆâ•— â–ˆâ–ˆâ•‘â–ˆâ–ˆâ•‘  â–ˆâ–ˆâ•‘â–ˆâ–ˆâ•‘   â–ˆâ–ˆâ•‘"
			<< endl;
	cout
			<< "â–ˆâ–ˆâ•”â•�â•�â–ˆâ–ˆâ•—â–ˆâ–ˆâ•”â•�â•�â•�  â–ˆâ–ˆâ•‘â•šâ–ˆâ–ˆâ•”â•�â–ˆâ–ˆâ•‘    â•šâ–ˆâ–ˆâ•— â–ˆâ–ˆâ•”â•�â–ˆâ–ˆâ•‘â–ˆâ–ˆâ•‘â•šâ–ˆâ–ˆâ•—â–ˆâ–ˆâ•‘â–ˆâ–ˆâ•‘  â–ˆâ–ˆâ•‘â–ˆâ–ˆâ•‘   â–ˆâ–ˆâ•‘"
			<< endl;
	cout
			<< "â–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ•”â•�â–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ•—â–ˆâ–ˆâ•‘ â•šâ•�â•� â–ˆâ–ˆâ•‘     â•šâ–ˆâ–ˆâ–ˆâ–ˆâ•”â•� â–ˆâ–ˆâ•‘â–ˆâ–ˆâ•‘ â•šâ–ˆâ–ˆâ–ˆâ–ˆâ•‘â–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ•”â•�â•šâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ–ˆâ•”â•�"
			<< endl;
	cout
			<< "â•šâ•�â•�â•�â•�â•�â•� â•šâ•�â•�â•�â•�â•�â•�â•�â•šâ•�â•�     â•šâ•�â•�      â•šâ•�â•�â•�â•�  â•šâ•�â•�â•šâ•�â•�  â•šâ•�â•�â•�â•�â•šâ•�â•�â•�â•�â•�â•�  â•šâ•�â•�â•�â•�â•�â•� "
			<< endl;
	cout << "Ã€ LOCALIZE CAR" << endl << endl;

}

/*
 * menu principal
 */
void menu_principal() {

	cout << "O que vocÃª deseja fazer?" << endl << endl;
	cout << "(1) Pesquisar/Alugar" << endl;
	cout << "(2) Devolver" << endl;
	cout << "(3) Sair" << endl << endl;

}

/*
 * menu pesquisar e alugar
 */
void menu_pesquisar_alugar() {
	cout << "Escolha a opÃ§Ã£o desejada?" << endl << endl;
	cout << "(1) Alugar" << endl;
	cout << "(2) Nova pesquisa" << endl;
	cout << "(3) Sair" << endl << endl;
}

/*
 * metodo de pesquisa para aluguel de carros.
 * retorna um vetor de carros localizados na pesquisa
 * caso nÃ£o encontre carros, retorna um vector vazio
 */
vector<car> pesquisa(string cidade_retirada, string cidade_destino,
		int qtdPassageiros, vector<car> veiculos) {

	vector<car> carrosDisponiveis;

	// loop sobre veiculos
	for (unsigned int i = 0; i < veiculos.size(); i++) {
		bool tem_destino = false;
		// olha a loja do veÃ­culo e verifica se ela tem uma filial na cidade de destino
		for (unsigned int j = 0; j < veiculos[i].loja.cidades.size(); j++) {
			if (to_lower(veiculos[i].loja.cidades[j])
					== to_lower(cidade_destino)) {
				tem_destino = true;
				break;
			}
		}
		// Verifica se o veÃ­culo estÃ¡ na cidade de retirada, se a capacidade do carro Ã© suficiente e
		// se tem esse veÃ­culo em estoque.
		if (tem_destino
				&& to_lower(veiculos[i].cidade_local)
						== to_lower(cidade_retirada)
				&& veiculos[i].capacidade >= qtdPassageiros
				&& veiculos[i].quantidade >= 1) {
			carrosDisponiveis.push_back(veiculos[i]);
		}
	}
	return carrosDisponiveis;
}

/*
 * Metodo para alugar veiculos
 * veiculo representa o carro a ser alugado
 * cidade_destino representa onde o carro será devolvido
 * diaria representa o preço da diaria do veiculo
 * qtdDias representa a quantidade de dias que o veiculo será alugado
 * aluguel retorna o valor que o cliente pagará
 */
rent alugar(car veiculo, string cidade_destino, float diaria, int qtdDias) {
	rent aluguel = rent(veiculo, cidade_destino, diaria, qtdDias);
	return aluguel;
}

// retorna um novo codigo para se adicionar veiculos
string get_novo_veiculo_codigo(vector<car> veiculos) {
	return to_string(stoi(veiculos[veiculos.size() - 1].codigo) + 1);
}

int main() {

	// carrega o nome das cidades do sistema
	vector < string > cidades { "JoÃ£o Pessoa", "Campina Grande", "Patos",
			"Souza", "Cajazeiras", "Guarabira", "Cabedelo", "Santa Rita",
			"Monteiro", "SumÃ©" };

	// Lojas
	vector<store> lojas;

	// Localiza
	lojas.emplace_back("Localiza", cidades);

	// Movida
	vector < string
			> cidades_movida { "JoÃ£o Pessoa", "Campina Grande", "Patos",
					"Souza", "Cajazeiras", "Cabedelo", "Santa Rita", "Monteiro" };
	lojas.emplace_back("Movida", cidades_movida);

	// Unidas
	vector < string > cidades_unidas { "JoÃ£o Pessoa", "Campina Grande",
			"Patos", "Souza", "Cajazeiras" };
	lojas.emplace_back("Unidas", cidades_unidas);

	// Heztz
	vector < string > cidades_hertz { "JoÃ£o Pessoa", "Campina Grande", "Patos",
			"Souza", "Cajazeiras", "Guarabira", "Cabedelo", "SumÃ©" };
	lojas.emplace_back("Hertz", cidades_hertz);

	// carrega os clientes do sistema
	vector<client> clientes = inicializa_clientes();

	// carrega os veÃ­culos do sistema
	vector<car> veiculos = inicializa_veiculos(lojas);

	// mostra a apresentaÃ§Ã£o do sistema
	apresentacao();

	while (true) {

		menu_principal();
		string opcao;
		getline(cin, opcao);

		if (opcao == "1") {  // pesquisar/alugar

			// informa as cidades disponÃ­veis do sistema
			cout << endl << "Cidades disponÃ­veis: ";
			for (unsigned int i = 0; i < cidades.size(); i++) {
				if (i == cidades.size() - 1) {
					cout << cidades[i] << endl;
				} else {
					cout << cidades[i] << ", ";
				}
			}

			// informa os usuarios disponÃ­veis do sistema
			cout << "Usuarios disponÃ­veis: ";
			for (unsigned int i = 0; i < clientes.size(); i++) {
				if (i == clientes.size() - 1) {
					cout << clientes[i].codigo << " - " << clientes[i].nome
							<< endl;
				} else {
					cout << clientes[i].codigo << " - " << clientes[i].nome
							<< ", ";
				}
			}
			cout << endl;

			// coleta informaÃ§Ãµes da pesquisa
			string cidadeSaida;
			cout << "Informe a cidade de saÃ­da: ";
			getline(cin, cidadeSaida);

			string cidadeDestino;
			cout << "Informe a cidade de destino: ";
			getline(cin, cidadeDestino);

			int qtdPassageiros;
			cout << "Informe a quantidade de Passageiros: ";
			cin >> qtdPassageiros;
			cin.ignore();

			// cria um vetor dos carros disponÃ­veis com os critÃ©rios da pesquisa
			vector<car> carrosDisponiveis = pesquisa(cidadeSaida, cidadeDestino,
					qtdPassageiros, veiculos);

			if (carrosDisponiveis.empty() == true) {
				cout
						<< "NÃ£o existem carros disponÃ­veis com estes critÃ©rios de pesquisa! Por favor, tente novamente com outros dados!"
						<< endl;
				continue;
			} else {
				// mostra o resultado da pesquisa
				cout << "Resultado da pesquisa:" << endl << endl;
				cout << "CÃ³digo\t" << "| Modelo\t\t\t" << "| Capacidade\t"
						<< "| Quantidade\t" << "| DiÃ¡ria\t"
						<< "| Categoria\t\t" << "| Loja" << endl;
				cout
						<< "==============================================================================================================================="
						<< endl;
				for (unsigned int i = 0; i < carrosDisponiveis.size(); i++) {
					cout << carrosDisponiveis[i].codigo << "\t";
					cout << "| " << setw(25) << carrosDisponiveis[i].modelo
							<< "\t";
					cout << "| " << carrosDisponiveis[i].capacidade << "\t\t";
					cout << "| " << carrosDisponiveis[i].quantidade << "\t\t";
					cout << "| " << setw(8) << fixed << setprecision(2)
							<< carrosDisponiveis[i].diaria << "\t";
					cout << "| " << setw(9) << carrosDisponiveis[i].categoria
							<< "\t\t";
					cout << "| " << carrosDisponiveis[i].loja.nome << endl;
				}
				cout << endl;

				// coleta dados para o aluguel ou "0" para sair
				string codigoCliente;
				cout
						<< "Para alugar, informe o cÃ³digo do cliente ou digite '0' para sair: ";
				getline(cin, codigoCliente);

				if (codigoCliente == "0")
					continue;

				string codigoVeiculo;
				cout << "Informe o cÃ³digo do veÃ­culo: ";
				getline(cin, codigoVeiculo);

				int qtdDias;
				cout << "Informe a quantidade de dias para alugar: ";
				cin >> qtdDias;
				cin.ignore();

				//  verifica se existe um cliente com o cÃ³digo do cliente digitado e um veÃ­culo com o codigo do veÃ­culo digitado.
				if (get_client_por_codigo(codigoCliente, clientes).codigo != "0"
						&& get_veiculo_por_codigo(codigoVeiculo, veiculos).codigo
								!= "0") {

					// captura indices do veÃ­culo e do cliente
					int index_veiculo = get_veiculo_indice(
							get_veiculo_por_codigo(codigoVeiculo, veiculos),
							veiculos);
					int index_cliente = get_client_indice(
							get_client_por_codigo(codigoCliente, clientes),
							clientes);

					// Calcula o valor da diÃ¡ria. Se for usuÃ¡rio VIP (10 ou mais alugueis) e a categoria do veÃ­culo for
					// "Luxo", a diaria terÃ¡ um desconto de 15%.
					float diaria;
					if (clientes[index_cliente].numero_aluguel >= 10
							&& veiculos[index_veiculo].categoria == "Luxo") {
						diaria = veiculos[index_veiculo].diaria
								- (veiculos[index_veiculo].diaria * 0.15);
					} else {
						diaria = veiculos[index_veiculo].diaria;
					}

					// adiciona o aluguel ao cliente
					clientes[index_cliente].locacoes.push_back(
							alugar(veiculos[index_veiculo], cidadeDestino,
									diaria, qtdDias));

					// incrementa o numero de alugueis do cliente
					clientes[index_cliente].numero_aluguel += 1;

					// decrementa a quantidade de veÃ­culos deste modelo na cidade
					veiculos[index_veiculo].quantidade -= 1;

					// mostra informaÃ§Ãµes do aluguel
					cout << endl << "Aluguel realizado com sucesso!" << endl;
					for (unsigned int i = 0;
							i < clientes[index_cliente].locacoes.size(); i++) {
						cout << "Aluguel " << i + 1 << ": "
								<< clientes[index_cliente].codigo << " - "
								<< clientes[index_cliente].nome << " -> ";
						cout
								<< clientes[index_cliente].locacoes[i].veiculo.modelo
								<< " - Devolver em: "
								<< clientes[index_cliente].locacoes[i].cidade_destino
								<< " - Quantidade de dias: "
								<< clientes[index_cliente].locacoes[i].dias;
						cout << " - DiÃ¡ria: " << setw(8) << fixed
								<< setprecision(2)
								<< clientes[index_cliente].locacoes[i].diaria;
						cout << " - Total: " << setw(8) << fixed
								<< setprecision(2)
								<< clientes[index_cliente].locacoes[i].diaria
										* clientes[index_cliente].locacoes[i].dias
								<< endl << endl;
					}

				} else {
					cout << endl
							<< "NÃ£o foi possÃ­vel realizar o aluguel! Por favor, verifique os dados digitados."
							<< endl;
				}

			}

		} else if (opcao == "2") { //devolver

			// informa os usuarios disponÃ­veis do sistema
			cout << "Usuarios disponÃ­veis: ";
			for (unsigned int i = 0; i < clientes.size(); i++) {
				if (i == clientes.size() - 1) {
					cout << clientes[i].codigo << " - " << clientes[i].nome
							<< endl;
				} else {
					cout << clientes[i].codigo << " - " << clientes[i].nome
							<< ", ";
				}
			}
			cout << endl;

			// captura dados da devoluÃ§Ã£o
			string codigoCliente;
			cout << "Informe o cÃ³digo do cliente: ";
			getline(cin, codigoCliente);

			//  verifica se existe um cliente com o cÃ³digo do cliente digitado e se esse cliente tem locaÃ§Ãµes.
			if (get_client_por_codigo(codigoCliente, clientes).codigo != "0"
					&& get_client_por_codigo(codigoCliente, clientes).locacoes.size()
							> 0) {

				// captura indice do cliente
				int index_cliente = get_client_indice(
						get_client_por_codigo(codigoCliente, clientes),
						clientes);

				// mostra os aluguÃ©is do cliente
				for (unsigned int i = 0;
						i < clientes[index_cliente].locacoes.size(); i++) {
					cout << "Aluguel " << i + 1 << ": "
							<< clientes[index_cliente].codigo << " - "
							<< clientes[index_cliente].nome << " -> "
							<< clientes[index_cliente].locacoes[i].veiculo.modelo
							<< " - Devolver em: "
							<< clientes[index_cliente].locacoes[i].cidade_destino
							<< " - DiÃ¡ria: " << setw(8) << fixed
							<< setprecision(2)
							<< clientes[index_cliente].locacoes[i].diaria
							<< endl;
				}

				// captura o nÃºmero do aluguel a devolver
				unsigned int numero_locacao;
				cout << "Informe o nÃºmero do aluguel: ";
				cin >> numero_locacao;
				cin.ignore();

				// testa se o nÃºmero do aluguel Ã© vÃ¡lido
				if (numero_locacao < 1
						|| numero_locacao
								> get_client_por_codigo(codigoCliente, clientes).locacoes.size()) {
					cout << endl
							<< "VocÃª nÃ£o informou um nÃºmero de locaÃ§Ã£o vÃ¡lido!"
							<< endl;
					continue;
				}

				// captura indice do veÃ­culo alugado
				int index_veiculo =
						get_veiculo_indice(
								get_client_por_codigo(codigoCliente, clientes).locacoes[numero_locacao
										- 1].veiculo, veiculos);

				int index_newveiculo;

				// verifica se a cidade destino tem o modelo a ser devolvido
				if (get_veiculo_por_modelo(veiculos[index_veiculo].modelo,
						clientes[index_cliente].locacoes[numero_locacao - 1].cidade_destino,
						veiculos).codigo != "0") {

					// captura indice do veiculo da cidade destino
					index_newveiculo =
							get_veiculo_indice(
									get_veiculo_por_modelo(
											veiculos[index_veiculo].modelo,
											clientes[index_cliente].locacoes[numero_locacao
													- 1].cidade_destino,
											veiculos), veiculos);

					// incrementa a quantidade do veÃ­culo da cidade destino
					veiculos[index_newveiculo].quantidade += 1;

				} else {

					// cria um novo veÃ­culo do mesmo modelo na cidade de destino com quantidade 1 (um)
					veiculos.emplace_back(get_novo_veiculo_codigo(veiculos),
							veiculos[index_veiculo].modelo, 1,
							veiculos[index_veiculo].capacidade,
							veiculos[index_veiculo].diaria,
							veiculos[index_veiculo].categoria,
							veiculos[index_veiculo].loja,
							clientes[index_cliente].locacoes[numero_locacao - 1].cidade_destino);

					// captura indice do novo cveiculo da cidade destino
					index_newveiculo =
							get_veiculo_indice(
									get_veiculo_por_modelo(
											veiculos[index_veiculo].modelo,
											clientes[index_cliente].locacoes[numero_locacao
													- 1].cidade_destino,
											veiculos), veiculos);

				}

				// remove a locação do cliente
				clientes[index_cliente].locacoes.erase(
						clientes[index_cliente].locacoes.begin()
								+ numero_locacao - 1);

				// imprime os dados da devolução
				cout << "DevoluÃ§Ã£o realizada com sucesso!" << endl;
				cout << "VeÃ­culo " << veiculos[index_veiculo].codigo << " - "
						<< veiculos[index_veiculo].modelo << " devolvido em "
						<< veiculos[index_newveiculo].cidade_local << endl
						<< endl;

			} else {
				cout
						<< "NÃ£o foi possÃ­vel realizar a devoluÃ§Ã£o! O cliente nÃ£o existe ou nÃ£o possui locaÃ§Ãµes."
						<< endl;
			}

		} else if (opcao == "3") {
			cout << "vocÃª saiu do sistema!" << endl;
			break;
		} else {
			cout << "Selecione uma opÃ§Ã£o vÃ¡lida!" << endl;
		}

	}

	return 0;
}
