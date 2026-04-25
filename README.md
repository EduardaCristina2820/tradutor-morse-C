# Tradutor de Código Morse com Detecção de Letras Corrompidas

## Descrição

Este projeto consiste no desenvolvimento de um programa em linguagem C capaz de converter mensagens em Código Morse para o alfabeto.

O sistema identifica corretamente separadores de letras e palavras, além de tratar casos de dados corrompidos. Quando um código termina com o caractere `*`, o programa considera a entrada como incompleta e retorna todas as possíveis letras compatíveis com o prefixo informado entre colchetes.

## Funcionalidades

* Tradução de sequências em Código Morse (pontos e traços) para letras do alfabeto
* Identificação de letras separadas por espaço simples
* Identificação de palavras separadas por espaço duplo
* Tratamento de códigos corrompidos representados por `*`
* Geração de múltiplas possibilidades de tradução para entradas incompletas
* Exibição de alternativas em ordem alfabética entre colchetes

## Entrada

O programa recebe como entrada:

* Uma string contendo:

  * Pontos (`.`)
  * Traços (`-`)
  * Asteriscos (`*`) para indicar possíveis corrupções
* Letras separadas por um espaço
* Palavras separadas por dois espaços

## Saída

O programa retorna:

* A mensagem traduzida em letras maiúsculas
* Letras com ambiguidade exibidas entre colchetes `[ ]`, contendo todas as possibilidades válidas em ordem alfabética

## Tecnologias Utilizadas

* Linguagem C
* Manipulação de strings
* Estruturas condicionais e de repetição


## Autoras

Eduarda Cristina Teixeira Silva

Maria Eduarda Aquino

## Observações

Este projeto foi desenvolvido com foco na aplicação de conceitos fundamentais de programação, incluindo lógica algorítmica, tratamento de exceções em entrada de dados e manipulação de cadeias de caracteres.

