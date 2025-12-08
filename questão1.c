#include <stdio.h>
#include <string.h>

struct cadastro_produto
    {
        char nome_produto [100]; //limite de caracteres
        int quant_est;
        float preco;
        char fornecedor [100]; //limite de caracteres
    };
    
int main()
{
    struct cadastro_produto produtos [50]; //nesse produtos 50, a gente substitui uma possivel variavel que sairia da struct la em cima, nao tendo a necessidade dela e nela é criada a variavel produtos
    
    int i, quantidade;
    
    printf("-------------------------------------------\n");
    printf ("Quantidade de produtos que vai cadastrar: ");
    scanf ("%d", &quantidade);
    printf("-------------------------------------------\n");
    
    if (quantidade > 50) //se passar de 50 ai nao pode, pq a questao só quer ate 50
    {
        printf ("Só pode até 50.");
    }
    
    else //caso ele seja menor ou igual a 50, ele pode puxar os dados do usuario
    {
        for (i=0; i<quantidade; i++)
        {
            
            printf ("Nome do produto: ");
            scanf(" %[^\n]", produtos[i].nome_produto); // esse [^\n] serve pro scanf ir ate onde o usuario apertar o enter, pq se fosse só o %s, ele nao conseguirira anotar tipo, coca cola, ele ia pegar so o coca
    
            printf ("Quantidade no estoque: ");
            scanf ("%d", &produtos[i].quant_est); // usei de vetor pra ele puxar cada um dos dados la da struct
    
            printf ("Preço do produto: ");
            scanf ("%f", &produtos[i].preco);
    
            printf ("Fornecedor: ");
            scanf (" %[^\n]", produtos[i].fornecedor);
            
            printf("\n");
        }
        
        for (i=0; i<quantidade;i++) //aqui ele printa separadamente os produtos que foram cadastrados
        {
            printf("\n----------Dados do %d produto:----------\n", i+1);
            printf("Nome do produto:  %s\n", produtos[i].nome_produto);
            printf("Quantidade no estoque: %d\n", produtos[i].quant_est);
            printf("Preço do produto: %.2f\n", produtos[i].preco);
            printf("Fornecedor:  %s\n", produtos[i].fornecedor); 
        }
    }
}


