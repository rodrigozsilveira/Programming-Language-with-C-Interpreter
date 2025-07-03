# Criação de uma linguagem de programação "C--"
Essa linguagem é baseada e intepretada em C, estamos usando o **bison** como analisador sintático e **FLEX** como analisador léxico.

## Instalação das dependências necessárias

```bash
sudo apt-get update
sudo apt-get install flex
sudo apt-get install bison
sudo apt-get install make
```
Caso não tenha o compilador de C, pode instalar com ``sudo apt-get install gcc``.

## Execução do programa

Ja temos 3 exemplos de programas em c- - (C menos menos), mas se deseja criar o seu próprio programa crie um arquivo.txt e execute da seguinte forma:

 * Cria o interpretador
```bash
make all
```
 * Roda o interpretador e executa o programa final
```bash
make run ENTRADA=arquivo.txt
make compile_output
make execute
```
Caso queira limpar os arquivos de intepretados e do programa gerado, faça ``make clean``.

## Desenvolvimento

Este trabalho foi desenvolvido para a matéria de ECOM06A, pelos alunos **Rodrigo Zaparoli Silveira** e **Luis Felipe de Moraes**.