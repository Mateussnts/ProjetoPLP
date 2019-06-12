:- initialization(main).

/*=========================== Auxiliares===============================*/
%Store(nome, [String]).
store("Localiza", cidadesTodas).
store("Movida", cidadesMovida).
store("Movida", cidadesMovida).
store("Hertz", cidadesHertz).

%Car( cod, model, amount, capacity, valorDiaria, category, store, localCity).
car("1", "BMW", 10, 5, 500.00, "luxo", "Loacalize", "João Pessoa").
car("2", "BMW2", 5, 2, 600.00, "luxo", "Loacalize", "João Pessoa").
car("3", "BMW3", 2, 10, 300.00, "normal", "Loacalize", "João Pessoa").
car("4", "BMW", 10, 5, 500.00, "luxo", "Loacalize", "Campina Grande").
car("5", "BMW2", 5, 2, 600.00, "luxo", "Loacalize", "Campina Grande").
car("6", "BMW3", 2, 10, 300.00, "normal", "Loacalize", "Campina Grande").
car("7", "BMW", 10, 5, 500.00, "luxo", "Loacalize", "Cajazeiras").
car("8", "BMW2", 5, 2, 600.00, "luxo", "Loacalize", "Cajazeiras").
car("9", "BMW3", 2, 10, 300.00, "normal", "Loacalize", "Cajazeiras").

%Rent(Car, destinationCity, diary, days).

%Client(cod, name, cpf, cnh, amountRent, [Rent]).
client("1", "Jesus", "111.111.111-25", "1000", 0, []).
client("2", "Deus", "222.111.111-25", "2000", 0, []).
client("3", "Jafeh", "333.111.111-25", "3000", 0, []).
client("4", "Judas", "444.111.111-25", "4000", 0, []).
client("5", "Maria", "555.111.111-25", "5000", 0, []).
	
menu() :- 
	writeln("Bem Vindo!").
	 	  	
opcao(1) :-	
	writeln("==> Digite a CIDADE DE PARTIDA: "), read(CidadeP),
	writeln("==> Digite a CIDADE DE DESTINO: "), read(CidadeD),
	writeln("==> Digite a QUANTIDADE DE PESSOAS: "), read(Qtdpessoas),
	imprimeCarros().
			
opcao(2) :- writeln("VAMOS DEVOLVER O CARRO"),
			write("Devolver").

opcao(3) :- halt.

opcao(_) :- writeln("Opcao invalida, tente outra!").
				
menuOpcoes() :-  	
	writeln(" "),
	writeln("1 - Pesquisar/Alugar"),
	writeln("2 - Devolver"),
	writeln("3 - Sair"),
	writeln("\nOpcao: "),
	read(A),
	opcao(A),
	menuOpcoes().
		
main :-
	menu(),	
	menuOpcoes().

listarCarros([]).
	listarCarros([Head|Tail]) :-
	car(Head,Nome,Qtd,Cap,Dia, Cat, Loja, Cidade),
	write(Head),
	write(" - "),
	write(Nome),
	write(" - "),
	write(Qtd),
	write(" - "),
	write(Cap),
	write(" - "),
	write(Dia),
	write(" - "),
	write(Cat),
	write(" - "),
	write(Loja),
	write(" - "),
	writeln(Cidade),
	 
	listarCarros(Tail).
	
imprimeCarros() :-
	writeln( "Código | Modelo | Capacidade | Quantidade | Diária | Categoria | Loja"),
	findall(Codigo, car(Codigo,_,_,_,_,_,_,_), Carros),
	listarCarros(Carros), menuAlugar. 

opcaoAlugar(1) :-
	opcao(1).
opcaoAlugar(2) :-
	writeln("Alugando...").
opcaoAlugar(3) :-
	halt.
opcaoAlugar(_) :-
	writeln("Opcao invalida, tente outra!"),
	menuAlugar.
	
menuAlugar :-
	writeln("O que deseja fazer? "),
	writeln("1 - Nova pesquisa"),
	writeln("2 - Alugar"),
	writeln("3 - Sair"),
	writeln("\nOpcao: "),
	read(A),
	opcaoAlugar(A).	
