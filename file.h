#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


/*============= Clone File =================
duplicates a file, used by writing functions
return -1 in error, 0 in success.


duplica um arquivo, usado pelas funcoes de escrita
retorna -1 em erro, 0 em sucesso.
====================================*/
int clone_file(const string &path, const string &path_clone);


/*============= Write Comment =================
write a comment in one line of file,
if the line is less than 0 or greater than the file
the comment is write in last line.
(Does not replace the current line)
return -1 in error, 0 in success.


escreve um texto em uma linha do arquivo,
se a linha for menor que 0 ou maior que o arquivo
o comentario e escrito na ultima linha.
(Nao subistitui o texto da linha atual)
retorna -1 em erro, 0 em sucesso.
====================================*/
int write_comment(string path, int n_line, string comment);



/*============= Write Variable =================
write one value in variable, if it does not exist will be created
return -1 in error, 0 in success.


escreve um valor na variavel, se ela nao existir sera criada,
retorna -1 em erro, 0 em sucesso.
====================================*/
int write_variable(string path, string variable_name, string variable_value);


/*============= Read Variable =================
read variable in file and return value in string,
return "null" if value is missing or "erro_file" if error in open file.


le a variabel no arquivo e retorna o valor em uma string,
retorna "null" se o valor nao existir ou "erro_file" se nao conseguir abrir o arquivo.
====================================*/
string read_variable(string path, string variable_name);
