#include <stdio.h>
#include <string.h>

struct cadastro_setores
{
    char nome_setor [100]; //tamanho da string
    int quant_funcionarios;
    int matricula_func [100]; // vetor de numeros inteiros de ate 100 funcionarios
};

int main()
{
    int i;
    int j;
    int quant_set; //variavel para ver quantos steores o usuario quer registrar
    
    printf("---------------------------------------------\n");
    printf("Quantidade de setores (de 1 a 10): ");
    scanf("%d", &quant_set);
    printf("---------------------------------------------\n"); 
    
    if (quant_set > 10) //condicional pra caso ele digite mais que 10, dar erro
    {
        printf("Só pode até 10.");
    }
    
    else 
    {
        
        struct cadastro_setores setores [10]; //criação de um vetor que vai ate 10, sendo do stipo struct cadastro_setores, onde cada posição desse vetor, tem uma informação que puxa da struct la em cima
        
        for (i=0; i<quant_set ;i++) //limite deve ser ate a quantidade de setores
        {
            printf ("-------------Cadastro do setor %d:-------------\n", i+1); // i+1 é pra não ficar 0 
            printf("Nome do setor: \n");
            scanf (" %[^\n]", setores[i].nome_setor); //esse %[^\n] serve pra ele ler strings compostas, ele para de ler apenas quando clica enter (detalhe, esse espaço antes de colocar ele é obrigatorio para ele nao pular, por que ele pode ler o enter anterior, e ignorar a string que vai ser digitada
    
            printf("Quantidade de funcionarios: \n");
            scanf ("%d", &setores[i].quant_funcionarios); //ele vai armazenando os dados na struct criada, dentro da parte quant_funcionarios
    
            //cadastrar matriculas
            for (j=0; j<setores[i].quant_funcionarios; j++)
            {
                //dentro desse for, ele vai se limitar a quantidade de funcionarios, e vai sempre colocar na parte matricula de funcionarios da struct
                printf ("Matricula do %d funcionario: \n", j+1); //j+1 pra evitar que fique o zero ali
                scanf ("%d", &setores[i].matricula_func[j]);   //de cá ele escaneia e joga la na matricula 
            }
            printf("\n");
        }
        
        //mostrar os setores criados
        for(i=0; i< quant_set; i++) //de novo ele se limita até a quantidade de setores
        {
            printf("-------------------------------\n");
            printf("Setor %d\n", i+1);
            printf("Nome: %s\n", setores[i].nome_setor );
            printf("Quantidade de setores: %d\n", setores[i].quant_funcionarios);
            for (j=0; j<setores[i].quant_funcionarios; j++)
            {
                 printf("Matrícula %d: %d\n", j+1, setores[i].matricula_func[j]);
            }
        }
        
    char sessao[100]; //é uma string de ate 100 caracteres
    printf("-------------------------------------\n");
    printf("Digite o nome da sessao para buscar: ");
    scanf (" %[^\n]", sessao); //aqui caso o nome da sessao seja composta
    
    int existe=0; //isso aqui serve pra separar, caso a sessao digitada, exista, de cara nós considera como nao existe, mas dentro do for ele verifica
    
    //busca pelo setor digitado
    for(i=0; i< quant_set;i++)
    {
        if (strcmp(sessao, setores[i].nome_setor)==0) //esse strcmp, significa stringcompare, ele que vai dizer se a string digitada pelo usuario, tem na struct, se tiver, pode prosseguir fi
        {
            //aqui o existe que era 0, agora vale 1, por que achamos a ela na struct
            existe = 1;
            //aqui imprime os dados da sessao que foi solicitada
            printf("-----------Setor existente-----------\n");
            printf("Nome do setor: %s\n", setores[i].nome_setor);
            printf("Quantidade de funcionarios: %d\n", setores[i].quant_funcionarios);
            for (j=0; j< setores[i].quant_funcionarios; j++)
            {
                printf("Matricula do funcionario %d: %d\n", j+1, setores[i].matricula_func[j]);
            }
        }
    }
    //aqui é caso ele nao passe pelo iff, entao a variavel existe continua sendo 0
    if (existe==0)
        {
            printf("--------------------\n");
            printf("Setor não encontrado\n");
        }
    }
}

