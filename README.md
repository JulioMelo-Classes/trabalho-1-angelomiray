# Compilação
Nesta sessão será abordada a forma de compilação do projeto.

## Dependências

- Compilador C++.

- cmake.

Entre no diretório `build`. 

    cd build

Execute o comando do cmake para compilar o projeto:

    cmake --build .


# Execução 
Para que o projeto seja executado, entre no diretório `build`(caso não esteja) e, posteriormente, no diretório `input_files`:

    cd build/input_files

Caso já esteja no diretório `build`:

    cd input_files

Crie um arquivo de texto com entrada no formato:

    Quantidade de crédito inicial do jogador
    Número de rodadas a executadas
    Números que serão apostados(spots)
    
Onde a quantidade de crédito inicial é um número real, o número de rodadas um número inteiro e os spots são até 15 números inteiros maiores ou iguais à 0 e menores ou iguais à 80, únicos e  em qualquer ordem. Exemplo:

    1700.0
    3
    7 16 25 

Neste caso, serão apostados R$ 1700.0, ao longo de 3 rodadas e os spots foram: 7, 16 e 25.

Assim, para executar: 

    ./keno input_files/[nome_arquivo_de_entrada.dat]

No diretório input_files foram introduzidos alguns arquivos de entrada com erros. Dessa forma, por via de exemplo, uma maneira de executar o arquivo de aposta `repeated_numbers` seria: 

    ./keno input_files/repeated_numbers.dat


# Execução dos arquivos de teste
Nesta sessão serão abordados os resultados dos arquivos de testes que estão inseridos no `input_files`, no diretório `build`.

## diff_char.dat
Testa um arquivo de entrada com caracter estranho no input. 

- input:
``` 
    7000p0
    4
    7 16 25
```
- output:
``` 
    >>> Lendo arquivo de apostas [input_files/diff_char.dat], por favor aguarde...
    -------------------------------------------------------------------
    Ocorreu um erro ao processar o arquivo. Por favor, mantenha a formatação desejada.
    Encerrando o jogo... Tente novamente.

```
    
## diff_format.dat
Testa um arquivo com um formato diferente do esperado.

- input:
``` 
    10 20 30
    4
    1500.0
```
- output:
``` 
    >>> Lendo arquivo de apostas [input_files/diff_format.dat], por favor aguarde...
    -------------------------------------------------------------------
    Ocorreu um erro ao processar o arquivo. Por favor, mantenha a formatação desejada.
    Encerrando o jogo... Tente novamente.
```

## more_than_15.dat
Testa um arquivo em que o usuário solicitou uma quantidade de spots superior à 15.

- input:
``` 
    2300
    4
    01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
```
- output:
``` 
    >>> Lendo arquivo de apostas [input_files/more_than_15.dat], por favor aguarde...
    -------------------------------------------------------------------
    Não foi possível processar o número 16. Por favor, selecione até 15 números.
    Encerrando o jogo... Tente novamente.
```

## repeated_numbers.dat
Testa um arquivo em que o usuário inseriu um mesmo spot mais de uma vez. 

- input:
``` 
    1700
    9
    7 7 16 25
```
- output:
``` 
    >>> Lendo arquivo de apostas [input_files/repeated_numbers.dat], por favor aguarde...
    -------------------------------------------------------------------
    Número inválido: 7. Por favor, digite números únicos e que sejam maiores ou iguais à 0 e menores ou iguais à 80.
    Encerrando o jogo... Tente novamente.
```


## sucess_bet1.dat
Testa um arquivo em que o usuário insere os dados corretamente. 

- input:
``` 
    10000
    6
    4 7 11 16 25 44 10 79
```
- output:
``` 
    >>> Lendo arquivo de apostas [input_files/sucess_bet1.dat], por favor aguarde...
    -------------------------------------------------------------------
    >>> Aposta lida com sucesso!
    Você apostará um total de $10000 créditos.
    Jogará um total de 6 rodadas, apostando $1666.67 por rodada.

    Sua aposta tem 8 números, eles são: [ 4 7 10 11 16 25 44 79 ]
    ----------+-----------
    Hits      | Retorno
    0         | 0
    1         | 0.5
    2         | 0.5
    3         | 1
    4         | 3
    5         | 6
    6         | 19
    7         | 90
    8         | 720
    ----------------------
    Esta é a rodada #1, sua aposta é $1666.67. Boa sorte!
    Os números sorteados são: [ 30 49 23 37 11 16 44 63 7 10 31 45 64 40 53 47 62 9 68 78 ]

    Você acertou os números [ 7 10 11 16 44 ], um total de 5 hits de 8
    Sua taxa de retorno é 6. Assim, você sai com $10000
    Você possui um total de: $18333.3
    -------------------------------------------
    Esta é a rodada #2, sua aposta é $1666.67. Boa sorte!
    Os números sorteados são: [ 24 63 58 69 20 67 46 66 36 22 47 4 1 45 27 65 68 37 31 32 ]

    Você acertou os números [ 4 ], um total de 1 hits de 8
    Sua taxa de retorno é 0.5. Assim, você sai com $833.333
    Você possui um total de: $17500
    -------------------------------------------
    Esta é a rodada #3, sua aposta é $1666.67. Boa sorte!
    Os números sorteados são: [ 21 7 5 48 54 2 29 63 70 27 23 68 4 11 57 8 43 62 31 25 ]

    Você acertou os números [ 4 7 11 25 ], um total de 4 hits de 8
    Sua taxa de retorno é 3. Assim, você sai com $5000
    Você possui um total de: $20833.3
    -------------------------------------------
    Esta é a rodada #4, sua aposta é $1666.67. Boa sorte!
    Os números sorteados são: [ 66 32 70 29 58 1 64 25 38 71 46 5 60 48 35 43 53 78 56 17 ]

    Você acertou os números [ 25 ], um total de 1 hits de 8
    Sua taxa de retorno é 0.5. Assim, você sai com $833.333
    Você possui um total de: $20000
    -------------------------------------------
    Esta é a rodada #5, sua aposta é $1666.67. Boa sorte!
    Os números sorteados são: [ 12 79 24 4 7 2 66 54 27 52 21 33 16 70 26 17 53 51 56 59 ]

    Você acertou os números [ 4 7 16 79 ], um total de 4 hits de 8
    Sua taxa de retorno é 3. Assim, você sai com $5000
    Você possui um total de: $23333.3
    -------------------------------------------
    Esta é a rodada #6, sua aposta é $1666.67. Boa sorte!
    Os números sorteados são: [ 17 61 38 0 31 16 70 28 45 46 29 44 5 34 67 8 19 40 51 6 ]

    Você acertou os números [ 16 44 ], um total de 2 hits de 8
    Sua taxa de retorno é 0.5. Assim, você sai com $833.333
    Você possui um total de: $22500
    -------------------------------------------
    >>> Fim das rodadas!
    -------------------------------------------

    ======= Sumário =======
    >>> Você gastou um total de $10000 créditos
    >>> Você ganhou $12500 créditos.
    >>> Você está saindo do jogo com um total de $22500
```