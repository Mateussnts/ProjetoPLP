import Data.List
import System.IO
import System.Directory
 
-- //////////////////////////////////////  DATA  //////////////////////////////////////
data Car = Car {
nomeStore :: String,
cidade :: String,
codigo :: String,
modelo :: String,
quantidade :: Int,
capacidade :: Int,
diaria :: Float,
categoria :: String
} deriving (Show)
 
data Rent = Rent {
codigoRent :: String,
veiculo :: Car,
cidade_destino :: String,
diarias :: Float,
dias :: Int
} deriving (Show)
 
data Client = Client {
codigoCliente :: String,
nomeClient :: String,
cpf :: String,
cnh :: String,
alugueis :: [Rent]
} deriving (Show)
 
-- //////////////////////////////////////  CADASTRO INICIAL  //////////////////////////////////////
carro1 = Car {nomeStore = "Loja A", cidade = "João Pessoa", codigo = "1", modelo = "BMW", quantidade = 10, capacidade = 5, diaria = 500.00, categoria = "luxo"}
carro2 = Car {nomeStore = "Loja A", cidade = "João Pessoa", codigo = "2", modelo = "BMW2", quantidade = 5, capacidade = 2, diaria = 600.00, categoria = "luxo"}
carro3 = Car {nomeStore = "Loja A", cidade = "João Pessoa", codigo = "3", modelo = "BMW3", quantidade = 2, capacidade = 10, diaria = 300.00, categoria = "normal"}
 
carro4 = Car {nomeStore = "Loja B", cidade = "Campina Grande", codigo = "1", modelo = "BMW", quantidade = 10, capacidade = 5, diaria = 500.00, categoria = "luxo"}
carro5 = Car {nomeStore = "Loja B", cidade = "Campina Grande", codigo = "2", modelo = "BMW2", quantidade = 5, capacidade = 2, diaria = 600.00, categoria = "luxo"}
carro6 = Car {nomeStore = "Loja B", cidade = "Campina Grande", codigo = "3", modelo = "BMW3", quantidade = 2, capacidade = 10, diaria = 300.00, categoria = "normal"}
 
carro7 = Car {nomeStore = "Loja C", cidade = "Cajazeiras", codigo = "1", modelo = "BMW", quantidade = 10, capacidade = 5, diaria = 500.00, categoria = "luxo"}
carro8 = Car {nomeStore = "Loja C", cidade = "Cajazeiras", codigo = "2", modelo = "BMW2", quantidade = 5, capacidade = 2, diaria = 600.00, categoria = "luxo"}
carro9 = Car {nomeStore = "Loja C", cidade = "Cajazeiras", codigo = "3", modelo = "BMW3", quantidade = 2, capacidade = 10, diaria = 300.00, categoria = "normal"}
 
 
carrosCadastrados=[carro1, carro2, carro3, carro4, carro5, carro6, carro7, carro8, carro9]
 
cliente1 = Client {codigoCliente = "1", nomeClient = "Jesus", cpf = "111.111.111-25", cnh = "1000",alugueis = []}
cliente2 = Client {codigoCliente = "2", nomeClient = "Deus", cpf = "222.111.111-25", cnh = "2000",alugueis = []}
cliente3 = Client {codigoCliente = "3", nomeClient = "Jafeh", cpf = "333.111.111-25", cnh = "3000",alugueis = []}
cliente4 = Client {codigoCliente = "4", nomeClient = "Judas", cpf = "444.111.111-25", cnh = "4000",alugueis = []}
cliente5 = Client {codigoCliente = "5", nomeClient = "Meria", cpf = "555.111.111-25", cnh = "5000",alugueis = []}
 
clientesCadastrados = [cliente1, cliente2, cliente3, cliente4, cliente5]
 
-- //////////////////////////////////////  MENU  //////////////////////////////////////
main :: IO ()
main = do
   menuPrint
   menuOpcao
 
 
menuPrint :: IO ()
menuPrint = do
   putStrLn "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "
   putStrLn "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"
   putStrLn "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"
   putStrLn "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"
   putStrLn "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"
   putStrLn "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "
 
 
menuOpcao :: IO()
menuOpcao = do
   putStrLn "À LOCALIZE CAR"
   putStrLn "O que você deseja fazer?"
   putStrLn "(1) Pesquisar/Alugar"
   putStrLn "(2) Devolver"
   putStrLn "(3) Sair"    
   putStrLn "\nOpcao: "
   opcao <- getLine
   if (read opcao) == 3 then putStrLn("Fim") else do opcaoEscolhida (read opcao)
 
-- //////////////////////////////////////  ESCOLHER OPÇÃO  //////////////////////////////////////
 
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
   putStrLn "==> Deseja alugar algum dos carros? "
   putStrLn "(1) SIM"
   putStrLn "(2) NÃO"      
   putStrLn "\nOpcao: "
   opcao <- getLine
   if (read opcao) == 2 then do {putStrLn "ok! voltemos ao menu principal" ; menuOpcao} else putStrLn "Vamos lá então!"
   do {alugarCarro}
   
alugarCarro :: IO()
alugarCarro = do
   putStrLn "==> to aqui "
   
 
novaPesquisa :: IO()
novaPesquisa = do
   putStrLn "==> Digite a CIDADE DE DESTINO: "
   cidadeDestino <- getLine
   putStrLn "==> Digite a CIDADE DE PARTIDA: "
   cidadePartida <- getLine
   putStrLn "==> Digite a QUANTIDADE DE PESSOAS: "
   quantidadeDePessoas <- getLine
   let carrosNoDestino = filter (\review -> cidade review == cidadeDestino) carrosCadastrados
   let carrosNaPartida = filter (\review -> cidade review == cidadePartida) carrosCadastrados
   let carrosNaPartidaComCapacidade = filter (\review -> capacidade review >= (read quantidadeDePessoas)) carrosNaPartida
   if contaNumeroDeCarros(carrosNoDestino) == 0 || contaNumeroDeCarros(carrosNaPartida) == 0 then do {putStrLn "Infelizmente não temos lojas/carros na cidade de destino/partida" ; menuOpcao}   else do {putStrLn(listarCarros(carrosNaPartidaComCapacidade))}
   do {alugar}
   
listarCarros :: [Car] -> String
listarCarros  [] = ""
listarCarros  (x:xs) = toStringCarro x ++ ['\n'] ++ listarCarros xs
 
contaNumeroDeCarros :: [Car] -> Int
contaNumeroDeCarros [] = 0
contaNumeroDeCarros (c : r) = 1 + contaNumeroDeCarros r
 
toStringCarro :: Car -> String
toStringCarro (Car {capacidade = capa, nomeStore = i, cidade = n, codigo = g, modelo = a, categoria = d, quantidade = q, diaria = dia}) = "NOME DA LOJA: " ++ i ++ " CIDADE: " ++ n  ++ " MODELO: " ++ a ++ " CATEGORIA: " ++ d ++ " CÓDIGO: " ++ g ++ " QUANTIDADE: " ++ show(q) ++ " VALOR DA DIÁRIA: " ++ show(dia) ++ " CAPACIDADE: " ++ show(capa)
   
devolver :: IO()
devolver = putStrLn ("\n\n\n" ++ "devolvendo...." ++ "\n\n")
 
printEspaco :: IO()
printEspaco = putStrLn "\n\n\n"
