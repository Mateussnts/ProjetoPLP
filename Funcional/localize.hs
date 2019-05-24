import Data.List
import System.Directory
import System.IO.Unsafe(unsafeDupablePerformIO)
import Data.List.Split
 
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
 

-- /////////// AUXILIARES //////////////////////
carregaClientes :: [Client]
carregaClientes = do
  let file = unsafeDupablePerformIO (readFile "clientes.csv")
  let lista =  ((map ( splitOn ";") (lines file))) 
  let lista_clientes = ((map (mapeiaCliente +1)) (lista))
  return lista_clientes !! 0
  
mapeiaCliente :: [String] -> Client
mapeiaCliente lista codigo = 
  Client { codigoCliente = (codigo),
  nomeClient = (lista) !! 0,
  cpf = (lista !! 1),
  cnh = (lista !! 2),
  alugueis = []
  }


carregaCarros :: [Car]
carregaCarros = do
  let file = unsafeDupablePerformIO (readFile "carros.csv")
  let lista =  ((map ( splitOn ";") (lines file))) 
  let lista_carros = ((map (mapeiaCarro +1)) (lista))
  return lista_carros !! 0
  
  
mapeiaCarro :: [String] -> Car
mapeiaCarro lista codigo = 
  Car { nomeStore = (lista) !! 5,
  cidade = (lista) !! 6,
  codigo = (codigo),
  modelo = (lista) !! 0,
  quantidade = read((lista) !! 1),
  capacidade = read((lista) !! 2),
  diaria = read((lista) !! 3),
  categoria = (lista) !! 4}
  
 
-- //////////////////////////////////////  MENU  //////////////////////////////////////
main :: IO ()
main = do
   let carros = carregaCarros
   let clientes = carregaClientes
   menuPrint
   menuOpcao carros clientes
 
 
menuPrint :: IO ()
menuPrint = do
   putStrLn "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "
   putStrLn "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"
   putStrLn "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"
   putStrLn "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"
   putStrLn "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"
   putStrLn "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "
 
 
menuOpcao :: [Car] -> [Client] -> IO()
menuOpcao carros clientes = do
   
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
    putStrLn "Para alugar, informe o código do cliente"
    codigoCliente <- getLine
    putStrLn "Informe o código do veículo"
    codigoVeiculo <- getLine
    putStrLn "Informe a quantidade de dias para alugar"
--  qtdDias <- getLine
    
   

novaPesquisa :: IO()
novaPesquisa = do
   putStrLn "==>  Digite a CIDADE DE DESTINO: "
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
