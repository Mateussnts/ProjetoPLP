:- initialization(main).

menu() :- 
	writeln("Bem Vindo!").
	  	
opcao(1) :-	
	writeln("==> Digite a CIDADE DE PARTIDA: "), read(CIDADEP),
	writeln("==> Digite a CIDADE DE DESTINO: "), read(CIDADED),
	writeln("==> Digite a QUANTIDADE DE PESSOAS: "), read(QTDPESSOAS),
	listarCarros(QUANTIDADEP).
			
opcao(2) :- writeln("VAMOS DEVOLVER O CARRO"),
			write("Devolver").

opcao(0) :- halt.

opcao(X) :- writeln("Opcao invalida, tente outra!").
				
menuOpcoes() :-  	
	writeln("1 - Pesquisar/Alugar"),
	writeln("2 - Devolver"),
	writeln("3 - Sair"),
	writeln("\nOpcao: "),
	read(A),
	opcao(A).
		
main :-
	menu(),	
	menuOpcoes().

listarCarros(X) :- 
	writeln("==>LISTAR CARROS<=="), 
	menuOpcoes().
	
