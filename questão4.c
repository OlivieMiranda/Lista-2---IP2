/*4) Escreva um programa em C que verifique se uma determinada expressão está correta ou
incorreta. O programa deve solicitar uma string do usuário, esta string corresponde a uma expressão
contendo variáveis, constantes, operadores e parênteses. O programa deve verificar se os parênteses
estão corretos em quantidade e ordem, como nos exemplos abaixo:
(a+(b+c*(d/e))) – correta
(a+(b+c*(d/e)) – incorreta
(a-1)*(b-2)+((c+3)*(d+4)) – correta
(a-1)*(b-2)+)(c+3)*(d+4)) – incorreta*/

#include <stdio.h>
#include <string.h>

int main()
{
    char operacao[100]; 
    int i, checa = 0; // Checa verifica a aparição de '(' e ')'

    printf("Digite uma expressão: "); // Usuário insere expressão
    scanf(" %[^\n]", operacao);

    for (i = 0; i < 100; i++) // For percorre toda a string
    {
        if (operacao[i] == '(') // Se tiver abre parenteses, checador ganha um contador a mais
        {
            checa++;
        }
        else if (operacao[i] == ')') // Se tiver fecha parenteses, checador decresce um número
        {
            if (checa==0) // Se checador estivesse inalterado, significa que a expressão já está automaticamente incorreta
            {
                printf("Incorreta\n");
                return 0;
            }
            
            checa--;
        }
    }

    if (checa==0) // Se checador se manter em 0, a expressão com parenteses está correta
    {
        printf("Correta\n");
    }

    else // Caso contrário, está incorreta
    {
        printf("Incorreta\n");
    }
    
    

}
