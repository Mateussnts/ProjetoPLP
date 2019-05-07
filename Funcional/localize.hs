
import Data.List
import System.IO
import System.Directory

data Store = Store {
	nome :: String,
	cidades :: [String]
	} deriving (Show)
	
data Car = Car {
	codigo :: String,
	modelo :: String,
	quantidade :: Int,
	capacidade :: Int,
	diaria :: Float,
	categoria :: String,
	loja :: Store,
	cidade_local:: String 
	} deriving (Show)

data Rent = Rent {
	veiculo :: Car,
	cidade_destino :: String,
	diarias :: Float,
	dias :: Int
	} deriving (Show)

data Client = Client {
	codigoClient :: String,
	nomeClient :: String,
	cpf :: String,
	cnh :: String,
	numero_aluguel :: Int,
	locacoes :: String
	} deriving (Show)	

main = do
	putStrLn ""
