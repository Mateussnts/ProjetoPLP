import Data.List
import System.IO
import System.Directory
 
-- //////////////////////////////////////  DATA  //////////////////////////////////////
data City = City {
    nomeCidade :: String
} deriving (Show)

data Store = Store {
    nomeStore :: String,
    carros :: [Car],
    cidade :: City
} deriving (Show)

data Car = Car {
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
    cidade_destino :: City,
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
cidade1 = City {nomeCidade = "João Pessoa"}
cidade2 = City {nomeCidade = "Campina Grande"}
cidade3 = City {nomeCidade = "Cajazeiras"}

carro1 = Car {codigo = "1", modelo = "BMW", quantidade = 10, capacidade = 5, diaria = 500.00, categoria = "luxo"}
carro2 = Car {codigo = "2", modelo = "BMW2", quantidade = 10, capacidade = 2, diaria = 600.00, categoria = "luxo"}
carro3 = Car {codigo = "3", modelo = "BMW3", quantidade = 10, capacidade = 5, diaria = 300.00, categoria = "normal"}
carro4 = Car {codigo = "4", modelo = "BMW4", quantidade = 10, capacidade = 2, diaria = 200.00, categoria = "normal"}
carro5 = Car {codigo = "5", modelo = "BMW5", quantidade = 10, capacidade = 5, diaria = 100.00, categoria = "normal"}

carrosCadastrados = [carro1, carro2, carro3, carro4, carro5]
 
loja1 = Store {nomeStore = "Loja A", carros = carrosCadastrados, cidade = cidade1}
loja2 = Store {nomeStore = "Loja B", carros = carrosCadastrados, cidade = cidade1}
loja3 = Store {nomeStore = "Loja C", carros = carrosCadastrados, cidade = cidade2}
loja4 = Store {nomeStore = "Loja D", carros = carrosCadastrados, cidade = cidade2}
loja5 = Store {nomeStore = "Loja E", carros = carrosCadastrados, cidade = cidade3}
 
cliente1 = Client {codigoCliente = "1", nomeClient = "Jesus", cpf = "111.111.111-25", cnh = "1000", alugueis = []}
cliente2 = Client {codigoCliente = "2", nomeClient = "Deus", cpf = "222.111.111-25", cnh = "2000", alugueis = []}
cliente3 = Client {codigoCliente = "3", nomeClient = "Jafeh", cpf = "333.111.111-25", cnh = "3000", alugueis = []}
cliente4 = Client {codigoCliente = "4", nomeClient = "Judas", cpf = "444.111.111-25", cnh = "4000", alugueis = []}
cliente5 = Client {codigoCliente = "5", nomeClient = "Maria", cpf = "555.111.111-25", cnh = "5000", alugueis = []}
 
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


menuOpcao :: IO ()
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
   | opcao == 2 = do {pesquisar}
   | opcao == 3 = do {devolver}
   | otherwise =  do {putStrLn "Opcao invalida, por favor escolha uma opcao valida" ; menuOpcao}

pesquisar :: IO()
pesquisar = putStrLn ("\n\n\n" ++ "pesquisando...." ++ "\n\n")

devolver :: IO()
devolver = putStrLn ("\n\n\n" ++ "devolvendo...." ++ "\n\n")
