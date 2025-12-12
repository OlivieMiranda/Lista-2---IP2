/*7) Desenvolva um programa em C que solicite as seguintes informações do usuário:
• Nome do produto;
• Quantidade no estoque;
• Preço;
• Fornecedor.
O programa deve conter um menu e disponibilizar ao usuário as operações: Cadastrar, Mostrar,
Buscar e Remover. Devem ser realizados quantos cadastros forem desejados.
Obs.: O arquivo deve ser estruturado em algum padrão, conforme abaixo:
Arroz Tio João ; 15 ; 4.50 ; Distribuidora Tio João
Macarrão Fortaleza ; 42 ; 3,75 ; Distribuidora Fortaleza
Detergente Limpol; 130 ; 6.00 ; Distribuidora Queiroz
....
Leite Integral Itambé ; 50 ; 10.50 ; Itambé Laticínios*/

#include <stdio.h>
#include <string.h>

struct cadastro_produto
{
    char nome_produto[100];
    int estoque;
    float preco;
    char fornecedor[100];
};

int main()
{
    
    FILE *fp;
    
    int i, total;
    int escolha; //escolha do usuario
    
    while(1)
    {
        printf("1 - Cadastrar.\n");
        printf("2 - Mostrar,\n");
        printf("3 - Buscar.\n");
        printf("4 - Remover.\n");
        printf("5 - Sair.\n");
        printf("Qual ação deseja realizar?\n");
        scanf ("%d", &escolha); 
    
        //sair do sistema
        if (escolha == 5)
        {
            printf("Fechando programa...\n");
            break;
        }
        
        //cadastrar
        else if (escolha == 1)
        {
            fp= fopen("operacoes.txt","a");
        
            if (fp == NULL)
            {
                printf("Deu ruim na hora de abrir\n");
            }
        
            else
            {
                printf("-----------------------------------\n");
                printf("Quantos produtos deseja cadastrar: ");
                scanf ("%d", &total);
                printf("-----------------------------------\n");
                
                //como o usuario delimita quantos ele quer cadastrar, entao usei total como o limite do vetor
                struct cadastro_produto cadastro[total];
    
                for (i=0; i<total; i++)
                {
                    printf("Nome do produto: ");
                    scanf(" %[^\n]", cadastro[i].nome_produto);
        
                    printf("Quantidade em estoque: ");
                    scanf ("%d", &cadastro[i].estoque);
        
                    printf("Preço: ");
                    scanf("%f", &cadastro[i].preco);
        
                    printf("Fornecedor: ");
                    scanf(" %[^\n]", cadastro[i].fornecedor);
        
                    fprintf(fp,"%s; %d ;%.2f ;%s\n", cadastro[i].nome_produto, cadastro[i].estoque, cadastro[i].preco, cadastro[i].fornecedor);
                }
            }    
        fclose(fp);
        }    
    
        else if (escolha ==2)
        {
            fp= fopen("operacoes.txt","r");
        
            if (fp == NULL)
            {
                printf("Deu ruim na hora de abrir, ou nao existe ainda.\n");
            }
        
            else
            {
                //esse 500 delimita o maximo de caracteres na linha, botei 500, mas podeira ser qualuqer valor alto
                char linha[500];
                //esse while vai deixar ficar se repetindo ate que recebea um NULL, ou seja, quando nao tem mais linhas e ta no fim do arquivo. esse fgets vai analisar linha por linha do arquivo, no caso 500. fp é o ponteiro pra abrir o arquivo. sizeoff evita lixo, pq eu botei 500, ent esse espaço vazio é descartado
                while (fgets(linha,sizeof (linha), fp))
                {
                    //nao usei o \n pq no fgets ele ja vem, dai no print sai tudo bonitinho
                    printf("%s", linha);
                }
            }
        fclose(fp);    
        }
        
        else if (escolha == 3)
        {
            fp =fopen ("operacoes.txt","r");
            
            if (fp == NULL)
            {
                printf("Produto não encontrado.\n");
            }
            
            else
            {
                char nome_busca[100];
                char linha[500];
                char nome[100];
                char fornecedor[100];
                int estoque;
                float preco;
                
                int encontrado = 0;

                printf("Qual produto quer procurar?\n");
                scanf(" %[^\n]", nome_busca);

                while (fgets(linha, sizeof(linha), fp))
                {
                    // separar tudo bacanudo como na questao, detalhe, to usando sscanf, que vai ler stirng, fazendo com que lemos os dados separadamente, basicamente a quebra da linha ate ver um ";"
                    // separando a linha em campos: nome até ';', estoque (int), preco (float), fornecedor até ';' ou '\n'

                    sscanf(linha, " %[^;]; %d ;%f ;%[^;\n]", nome, &estoque, &preco, fornecedor);

                    // Comparar o nome do produto, se existir, ele ja vai imprimindo
                    if (strcmp(nome, nome_busca) == 0)
                    {
                        printf("%s", linha); // mostrar linha inteira
                        encontrado = 1;
                    }
                }
                //caso encontrado nao exista, entao o produto nao existe
                if (!encontrado)
                {
                    printf("Produto não encontrado.\n");
                }
                fclose(fp);
            }
        }
        
        else if (escolha == 4)
        {
            char remover[100];
            char linha[500];
            char nome[100]; 
            char fornecedor[100];
            int estoque;
            float preco;
            int encontrado = 0;

            printf("Qual produto deseja remover?\n");
            scanf(" %[^\n]", remover);
            
            //arquivo original, pra visualizar
            fp = fopen("operacoes.txt", "r");
            
            //uma temporaria pra poder escrever
            FILE *temp = fopen("temp.txt", "w");
            
            //se um dos dois der falha, ou um outro, ja da tudo errado
            if (fp == NULL || temp == NULL)
            {
                printf("Erro ao abrir o arquivo.\n");
            }
            else
            {
                while (fgets(linha, sizeof(linha), fp))
                {
                    sscanf(linha, " %[^;]; %d ;%f ;%[^;\n]", nome, &estoque, &preco, fornecedor);
                    
                    //se nao for o nome digitado nao é oq o usuario quer remover, nós vai fazer uma cópia pro aqruivo temporario
                    if (strcmp(nome, remover) != 0)
                    {
                        //muda no arquivo temporari, com a linha baseado na linha feita
                        fprintf(temp, "%s", linha); 
                    }
                    
                    //se for o produto, encontramo
                    else
                    {
                        encontrado = 1;
                    }
                }

                fclose(fp);
                fclose(temp);

                // substitui o arquivo antigo pelo novo, ou seja, nós vai apagar o antigo
                remove("operacoes.txt");
                rename("temp.txt", "operacoes.txt");

                if (encontrado==1)
                {
                    printf("Produto removido com sucesso!\n");
                }
                else
                {
                    printf("Produto não encontrado.\n");
                }
        }
    }
}
