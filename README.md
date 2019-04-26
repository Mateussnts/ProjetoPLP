# Localize Car

O projeto consiste na criação de uma locadora de carros, possibilitando ações entre lojas e usuários.
O usuário será cadastrado no sistema e com base em suas informações e pesquisas o sistema
irá recomendar a melhor opção de veículo relacionado ao destino que o usuário irá percorrer.

# Operações

Cliente: é cadastrado com código, nome, cpf e o número de registro da sua CNH. Um cliente é reconhecido pelo seu código ou número do seu cpf e são divididos em clientes normais com menos de 10 aluguéis e clientes VIP com 10 ou mais aluguéis. Os clientes VIPs têm descontos de 15% alugando os carros de luxo.

Carros: um carro cadastrado tem as seguintes características: o modelo do veículo, o código, quantidade de carros disponíveis, o valor do aluguel (diária) e quantidade de passageiros que ele transporta. Os carros são divididos em duas categorias: econômico e luxo, com valores de aluguel diferentes para cada categoria e caso o cliente seja vip terá um desconto ao alugar um carro da categoria luxo. 

Lojas: as locadoras têm um sistema integrado e estão localizadas em algumas cidades da Paraíba. Se o cliente aluga o carro em Campina Grande e devolve na cidade de Cajazeiras, por exemplo, o carro alugado é retirado da loja de CG e passa a ficar disponível na loja de CZ, após a devolução do veículo; 

Pesquisar: o usuário informa a cidade de saída, a cidade de destino e a quantidade de passageiros, e o sistema informa os carros disponíveis para aluguel, caso existam, O sistema indica a melhor opção de carro para o número de passageiros.

Alugar: depois do veículo pesquisado o usuário poderá efetuar o aluguel informando o código do cliente, o código do veículo e a quantidade de diárias.  Após a confirmação do aluguel o carro fica indisponível na loja alugada e após a sua devolução ficará disponível na loja da cidade de destino.

Devolver: o usuário informa o código do usuário e o código do aluguel, o carro ficará novamente disponível para ser alugado.

# Desenvolvedores

- Mateus Santos
- Gilmar Silva
- Jailson Campos
- João Barbosa
- Enzo Candido
- Plínio Neto
