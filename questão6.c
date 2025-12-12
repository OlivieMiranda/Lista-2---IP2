/*6) Faça uma função que receba como entrada três strings (s1, s2 e s3) e retorne uma quarta string
formada pela substituição de todas as ocorrências da string s2 pela string s3 dentro da string s1.
Exemplo:
• s1 = “A bola bateu na trave”
• s2 = “A bola”
• s3 = “O chute”
◦ A resposta deve ser: “O chute bateu na trave*/

#include <stdio.h>
#include <string.h>

// Função receb s1, s2, s3 e onde vamos guardar o texto final (res)
void substituir(char *s1, char *s2, char *s3, char *res) 
{
    char *achou;    // vai guardar o endereço de onde achou a palavra s2
    char *p = s1;   // ponteiro auxiliar para percorrer a frase s1
    
    res[0] = '\0';  // começa a string de resposta vazia

    // strstr procura s2 dentro de p. Se achar, retorna o endereço, senão retorna NULL.
    while ((achou = strstr(p, s2)) != NULL) 
    {
        
        // Copia a parte do texto que vem ANTES da palavra encontrada.
        // A conta (achou - p) dá exatamente o tamanho desse pedaço.
        strncat(res, p, achou - p);

        // Concatena a palavra nova (s3) no lugar da antiga.
        strcat(res, s3);

        // Pula a palavra antiga (s2) na string original para continuar procurando.
        p = achou + strlen(s2);
    }

    // Copia o que sobrou da frase original (o finalzinho dela).
    strcat(res, p);
}

int main() 
{
    char s1[100], s2[50], s3[50], res[200];

    printf("Digite S1: ");
    scanf(" %[^\n]", s1);

    printf("Digite S2: ");
    scanf(" %[^\n]", s2);

    printf("Digite S3: ");
    scanf(" %[^\n]", s3);

    // Chama a função passando as strings
    substituir(s1, s2, s3, res);

    printf("\nResultado: %s\n", res);

    return 0;
}

