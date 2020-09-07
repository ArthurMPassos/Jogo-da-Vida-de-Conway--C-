# Jogo da Vida de Conway (em C)
## Conceito
O autômato celular Jogo da Vida de John Conway consiste na interação entre cada célula do sistema e as 8 células ao redor.

## Funcionamento 
Cada célula pode estar em um de 2 estados: viva ou morta (aqui representados respectivamente por "X" e por "-").

Cada célula tem 8 vizinhos imediatamente ao seu redor (em cima, embaixo, à direita, à esquerda e todas as 4 diagonais) e consegue "enxergar" o estado desses vizinhos. 

Assim, após a configuração inicial, cada célula respeita as seguintes regras para cada iteração do jogo:

1. Se a célula estiver **morta** e precisamente com **três** vizinhos vivos, ela se torna **viva**, por expansão;
2. Se a célula estiver **viva** e com **menos de dois** vizinhos vivos, ela se torna morta por solidão;
3. Se a célula estiver **viva**  e com **mais de três** vizinhos vivos, ela se torna **morta** por excesso de população;
4. Se a célula estiver **viva** com **dois ou três** vizinhos vivos, ela se mantem **viva**.
 
Existem várias configurações iniciais conhecidas e estudadas, aqui de exemplo é usado o "Exploder" em uma matriz 15x15, considerando as bordas da matriz mortas.