import Data.List
import Data.Char
import System.IO
import System.Directory

-- //////////////////////////////////////  DATA  ////////////////////////////////////// --

data Store = Store {
   nomeStore :: String,
   cidades :: [String]
} deriving (Show)

data Car = Car {
   codigo :: String,
   modelo :: String,
   quantidade :: Int,
   capacidade :: Int,
   valorDiaria :: Float,
   categoria :: String,
   loja :: Store,
   cidadeLocal :: String
} deriving (Show)

-- gera uma string com os dados de um carro
toStringCarro :: Car -> String
toStringCarro (Car {
   codigo = g, modelo = a, quantidade = q, capacidade = c, valorDiaria = dia, categoria = d, loja = l
   }) = g ++ "\t" ++ a ++ "\t" ++ show(c) ++ "\t\t" ++ show(q) ++ "\t\t" ++ show(dia) ++ "\t" ++ d ++ "\t\t" ++ show(nomeStore l)

-- testa se a loja a qual o carro pertence possui filial na cidade de destino
carroTemDestino :: String -> Car -> Bool
carroTemDestino cidadeDestinoTeste carTeste = elem (cidadeDestinoTeste) ((cidades (loja carTeste)))

-- imprime os carros de uma lista
listarCarros :: [Car] -> String
listarCarros  [] = ""
listarCarros  (x:xs) = toStringCarro x ++ ['\n'] ++ listarCarros xs

-- retorna o carro pelo seu código
getCarroPorCodigo :: String -> Car
getCarroPorCodigo codCarTeste = (filter (\review -> codigo review == codCarTeste) carrosCadastrados) !! 0

data Rent = Rent {
   veiculo :: Car,
   cidadeDestino :: String,
   diaria :: Float,
   dias :: Int
} deriving (Show)

data Client = Client {
   codigoCliente :: String,
   nomeClient :: String,
   cpf :: String,
   cnh :: String,
   locacoes :: Int,
   alugueis :: [Rent]
} deriving (Show)

-- retorna o client pelo seu código
getClientePorCodigo :: String -> Client
getClientePorCodigo codClientTeste = (filter (\review -> codigoCliente review == codClientTeste) clientesCadastrados) !! 0



-- conta a quantidade de itens de uma lista
contaItens :: [a] -> Int
contaItens [] = 0
contaItens (c : r) = 1 + contaItens r

toLowerCase :: String -> String
toLowerCase x = map toLower x

-- carrega as cidades do sistema
cidadesTodas = ["João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras", "Guarabira", "Cabedelo", "Santa Rita", "Monteiro", "Sumé"]

-- carrega as lojas do sistema
-- Localiza
loja1 = Store {nomeStore = "Localiza", cidades = cidadesTodas}

-- Movida
cidadesMovida = ["João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras", "Cabedelo", "Santa Rita", "Monteiro"]
loja2 = Store {nomeStore = "Movida", cidades = cidadesMovida}

-- Unidas
cidadesUnidas = ["João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras"]
loja3 = Store {nomeStore = "Unidas", cidades = cidadesUnidas}

-- Heztz
cidadesHertz = ["João Pessoa", "Campina Grande", "Patos", "Souza", "Cajazeiras", "Guarabira", "Cabedelo", "Sumé"]
loja4 = Store {nomeStore = "Hertz", cidades = cidadesHertz}

lojasCadastradas = [loja1, loja2, loja3, loja4]

-- carrega os clientes do sistema
cliente1 = Client {codigoCliente = "1", nomeClient = "Jesus", cpf = "111.111.111-25", cnh = "1000", locacoes = 0, alugueis = []}
cliente2 = Client {codigoCliente = "2", nomeClient = "Deus", cpf = "222.111.111-25", cnh = "2000", locacoes = 0, alugueis = []}
cliente3 = Client {codigoCliente = "3", nomeClient = "Jafeh", cpf = "333.111.111-25", cnh = "3000", locacoes = 0, alugueis = []}
cliente4 = Client {codigoCliente = "4", nomeClient = "Judas", cpf = "444.111.111-25", cnh = "4000", locacoes = 0, alugueis = []}
cliente5 = Client {codigoCliente = "5", nomeClient = "Maria", cpf = "555.111.111-25", cnh = "5000", locacoes = 0, alugueis = []}

clientesCadastrados = [cliente1, cliente2, cliente3, cliente4, cliente5]

-- carrega os veícuos do sistema
carro1 = Car {codigo = "1", modelo = "BMW", quantidade = 10, capacidade = 5, valorDiaria = 500.00, categoria = "luxo", loja = loja1, cidadeLocal = "João Pessoa"}
carro2 = Car {codigo = "2", modelo = "BMW2", quantidade = 5, capacidade = 2, valorDiaria = 600.00, categoria = "luxo", loja = loja1, cidadeLocal = "João Pessoa"}
carro3 = Car {codigo = "3", modelo = "BMW3", quantidade = 2, capacidade = 10, valorDiaria = 300.00, categoria = "normal", loja = loja1, cidadeLocal = "João Pessoa"}
carro4 = Car {codigo = "4", modelo = "BMW", quantidade = 10, capacidade = 5, valorDiaria = 500.00, categoria = "luxo", loja = loja2, cidadeLocal = "Campina Grande"}
carro5 = Car {codigo = "5", modelo = "BMW2", quantidade = 5, capacidade = 2, valorDiaria = 600.00, categoria = "luxo", loja = loja2, cidadeLocal = "Campina Grande"}
carro6 = Car {codigo = "6", modelo = "BMW3", quantidade = 2, capacidade = 10, valorDiaria = 300.00, categoria = "normal", loja = loja2, cidadeLocal = "Campina Grande"}
carro7 = Car {codigo = "7", modelo = "BMW", quantidade = 10, capacidade = 5, valorDiaria = 500.00, categoria = "luxo", loja = loja3, cidadeLocal = "Cajazeiras"}
carro8 = Car {codigo = "8", modelo = "BMW2", quantidade = 5, capacidade = 2, valorDiaria = 600.00, categoria = "luxo", loja = loja3, cidadeLocal = "Cajazeiras"}
carro9 = Car {codigo = "9", modelo = "BMW3", quantidade = 2, capacidade = 10, valorDiaria = 300.00, categoria = "normal", loja = loja3, cidadeLocal = "Cajazeiras"}

carrosCadastrados=[carro1, carro2, carro3, carro4, carro5, carro6, carro7, carro8, carro9]



-- //////////////////////////////////////  MENU  //////////////////////////////////////
main :: IO ()
main = do
   menuPrint
   menuOpcao

menuPrint :: IO ()
menuPrint = do
   putStrLn ""
   putStrLn "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "
   putStrLn "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"
   putStrLn "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"
   putStrLn "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"
   putStrLn "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"
   putStrLn "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "
   putStrLn "À LOCALIZE CAR\n"

menuOpcao :: IO()
menuOpcao = do
   putStrLn "O que você deseja fazer?"
   putStrLn "(1) Pesquisar/Alugar"
   putStrLn "(2) Devolver"
   putStrLn "(3) Sair"    
   putStrLn "\nOpcao: "
   opcao <- getLine
   if (read opcao) == 3 then putStrLn("Fim\n") else do opcaoEscolhida (read opcao)

opcaoEscolhida :: Int -> IO()
opcaoEscolhida opcao
   | opcao == 1 = do {novaPesquisa}
   | opcao == 2 = do {devolver}
   | otherwise =  do {putStrLn "Opcao invalida, por favor escolha uma opcao valida" ; menuOpcao}

pesquisar :: IO()
pesquisar = putStrLn ("\n\n\n" ++ "pesquisando...." ++ "\n\n")

opcaoEscolhidaPesquisar :: Int -> IO()
opcaoEscolhidaPesquisar opcao
   | opcao == 1 = do {alugar}
   | opcao == 2 = do {novaPesquisa}
   | otherwise =  do {putStrLn "Opcao invalida, por favor escolha uma opcao valida" ; menuOpcao}

alugar :: IO()
alugar = do
   putStrLn "Deseja alugar algum dos carros? "
   putStrLn "(1) SIM"
   putStrLn "(2) NÃO"      
   putStrLn "\nOpcao: "
   opcao <- getLine
   if (read opcao) == 2 then do { 
      putStrLn "ok! voltemos ao menu principal" ; menuOpcao
   } else do {
      putStrLn "\n"
   }
   do {alugarCarro}

alugarCarro :: IO()
alugarCarro = do
   putStrLn "Digite o código do Usuário: "    
   uCode <- getLine
   putStrLn "Digite o código do Veículo: "    
   cCode <- getLine
   putStrLn "Digite a quantidade de dias para alugar: "    
   aDias <- getLine
   let atualCliente = getClientePorCodigo uCode
   let atualCar = getCarroPorCodigo cCode
   if(nomeClient atualCliente /= "" && modelo atualCar /= "") then do {
      putStrLn "G";
      --if(locacoes atualCliente > 10) then do {
      --   let locDiaria = (diaria atualCar - diaria atualCar * 0.15)
      --} else do {
       --  let locDiaria = diaria atualCar
         --putStrLn "G"
         -- alugueis atualCliente ++ [Rent { veiculo = atualCar, cidadeDestino = cidadeDestino, diaria = locDiaria, dias = aDias }]
      --}
   } else do {
      putStrLn "G";
   }
   do {alugarCarro}
   
 
novaPesquisa :: IO()
novaPesquisa = do
   putStrLn "==> Digite a CIDADE DE PARTIDA: "
   cidadePartida <- getLine
   putStrLn "==> Digite a CIDADE DE DESTINO: "
   cidadeDestino <- getLine
   putStrLn "==> Digite a QUANTIDADE DE PESSOAS: "
   quantidadeDePessoas <- getLine
   
   -- filtra carros onde sua cidade local é igual a cidade de partida
   let carrosNaPartida = filter (\review -> cidadeLocal review == cidadePartida) carrosCadastrados
   -- filtra carros onde a loja a qual o carro pertence possui filial na cidade de destino
   let carrosTemDestino = filter (carroTemDestino cidadeDestino ) carrosNaPartida
   -- filtra carros com a capacidade de passageiros >= ao necessário do usuário
   let carrosParaAlugar = filter (\review -> capacidade review >= (read quantidadeDePessoas)) carrosTemDestino
   
   -- lista os carros disponíveis, caso existam
   if contaItens(carrosParaAlugar) == 0 then do {
      putStrLn "\n==> Infelizmente não dispomos de veículos para o percurso escolhido de partida-destino <==\n" ; menuOpcao
   } else do {
      putStrLn "\nCódigo\t| Modelo\t\t\t| Capacidade\t| Quantidade\t| Diária\t| Categoria\t\t| Loja";
      putStrLn "===============================================================================================================================\n";
      putStrLn(listarCarros(carrosParaAlugar))
   }
   do {alugar} 


   

 

 
   
devolver :: IO()
devolver = putStrLn ("\n\n\n" ++ "devolvendo...." ++ "\n\n")

