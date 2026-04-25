/*
* Programa: Tradutor de Código Morse com Detecção de Letras Corrompidas
* Descrição: Este programa converte mensagens em Código Morse para o alfabeto.
* Ele identifica espaços duplos como separadores de palavras e trata
* códigos terminados em '*' como letras corrompidas, listando todas as 
* possibilidades de tradução baseadas no prefixo fornecido, ou seja, trazendo
* todas as letras que começam com a mesma sequência de pontos e traços.
* 
* Autores: 
* - Eduarda Cristina Teixeira Silva | RA: 10436696
* - Maria Eduarda Aquino | RA: 107
*
* Entrada:
* - Uma string contendo sequências de pontos (.), traços (-) e asteriscos (*).
* - Letras separadas por um espaço e palavras por dois espaços.
*
* Saída:
* - A mensagem traduzida em letras maiúsculas.
* - Letras corrompidas exibidas entre colchetes [ ], em ordem alfabética.
*
*/

#include <stdio.h>
#include <string.h>

// Dicionário com o alfabeto e seus respectivos códigos Morse
char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *morse[] = {
".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",
".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.",
"...",  "-",    "..-",  "...-", ".--",  "-..-", "-.--", "--.."
};

// Função que traduz um código íntegro (sem *)
void traduzirIntegro(char *codigo) {
for (int i = 0; i < 26; i++) {
if (strcmp(codigo, morse[i]) == 0) { 
printf("%c", letras[i]);
return; 
}
}
}

// Função que busca todas as letras que começam com o prefixo corrompido
void traduzirCorrompido(char *prefixo) {
prefixo[strlen(prefixo) - 1] = '\0'; // Remove o * do final do prefixo
printf("["); 
for (int i = 0; i < 26; i++) {
    // strncmp compara apenas os primeiros caracteres de acordo com o tamanho do prefixo 
    if (strncmp(morse[i], prefixo, strlen(prefixo)) == 0) { 
        printf("%c", letras[i]);
    }
}
printf("]");
}

void processarMensagem() {
char entrada[500];
char copiaEntrada[500];
fgets(entrada, sizeof(entrada), stdin);

entrada[strcspn(entrada, "\n")] = 0; // Procura a quebra de linha no final da string digitada e remove
strcpy(copiaEntrada, entrada);

char *trechoCodigo = strtok(entrada, " "); // Divide a string em partes menores, usando como critério o espaço
int espacosSeguidos = 0; 

char *posicao = copiaEntrada; // Ponteiro que percorre  string original

while (trechoCodigo != NULL) {
    // Executa enquanto ouverem trechos do código Morse para processar
    while (posicao < copiaEntrada + (trechoCodigo - entrada)) { // Serve para detectar espaços
        if (*posicao == ' ') espacosSeguidos++;
        else espacosSeguidos = 0;
        posicao++;
    }

    if (espacosSeguidos >= 2) {
        printf(" "); // Nova palavra
    }

    
    if (strchr(trechoCodigo, '*') != NULL) { // Procura string corrompida
        traduzirCorrompido(trechoCodigo);
    } else {
        traduzirIntegro(trechoCodigo);
    }

    posicao = copiaEntrada + (trechoCodigo - entrada) + strlen(trechoCodigo); // segue para ao próximo trecho do código morse
    trechoCodigo = strtok(NULL, " "); // A variavel recebe o próximo trecho
    espacosSeguidos = 0;
}
printf("\n");
}

int main() {
processarMensagem();
return 0;
}
