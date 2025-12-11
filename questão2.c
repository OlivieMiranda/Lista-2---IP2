/*2) Faça um programa em C que resolva o seguinte problema. Você foi contratado por uma empresa
para desenvolver um sistema e deve criar um programa que cadastre a empresa e seus funcionários
(15 funcionários), as informações a serem cadastradas são:
Endereço
• Rua;
• Número.
Funcionário
• Nome do funcionário;
• Cargo que exerce;
• Informações de endereço (Rua e Número).
Empresa
• Nome da empresa;
• CNPJ;
• Informações de funcionário (Nome, Cargo, Endereço do funcionário).
Obs.: O programa deve utilizar struct.
O programa deve criar 3 estruturas (Endereco, Funcionario, Empresa).
O programa deve armazenar as informações e mostrar tais informações.*/

#include <stdio.h>
#include <string.h>

struct Endereco //Struct de endereço geral
{
    char rua [50];
    int numero;
};

struct Funcionario //Struct dos funcionários
{
    char nome [100];
    char cargo [40];
    struct Endereco end; //Struct do endereço integrada
};

struct Empresa //Struct da Empresa
{
    char nomeEmpresa [100];
    char cnpj [20];
    struct Funcionario equipe[15]; //Struct dos funcionários integrada com um vetor pra armazenar os 15
};

int main() 
{
    struct Empresa minhaEmpresa; //Struct da empresa (que contém as demais) adicionada a main.
    int i;

    printf("Nome da Empresa: "); //Inserir nome da empresa
    scanf(" %[^\n]", minhaEmpresa.nomeEmpresa);

    printf("CNPJ: "); //Inserir CNPJ da empresa
    scanf(" %[^\n]", minhaEmpresa.cnpj);

    for(i = 0; i < 15; i++) //For de preenchimento de informações dos funcionários
    {
        printf("\nFuncionario %d:\n", i + 1); //Ordem de preenchimento do funcionário
        
        printf("Nome do Funcionario: "); //Inserir nome do funcionário
        scanf(" %[^\n]", minhaEmpresa.equipe[i].nome);
        
        printf("Cargo: "); //Inserir cargo do funcionário
        scanf(" %[^\n]", minhaEmpresa.equipe[i].cargo);

        printf("Rua: "); //Inserir rua do funcionário
        scanf(" %[^\n]", minhaEmpresa.equipe[i].end.rua);
        
        printf("Numero: "); //Inserir número da casa do funcionário
        scanf("%d", &minhaEmpresa.equipe[i].end.numero);
    }
    
    for (i = 0; i < 15; i++) //For que exibe todos os dados anteriores em ordem de preenchimento
    {
        printf("Funcionario %d\n", i + 1);
        printf("Nome: %s\n", minhaEmpresa.equipe[i].nome);
        printf("Cargo: %s\n", minhaEmpresa.equipe[i].cargo);
        printf("Endereco: Rua %s, N. %d\n", minhaEmpresa.equipe[i].end.rua, minhaEmpresa.equipe[i].end.numero);
    }
}
