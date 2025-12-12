#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[50], s3[50], res[200];
    char temp[50];
    int i = 0;

    printf("Digite S1: ");
    scanf(" %[^\n]", s1);

    printf("Digite S2: ");
    scanf(" %[^\n]", s2);

    printf("Digite S3: ");
    scanf(" %[^\n]", s3);

    res[0] = '\0';  // resultado começa vazio

    while (i < strlen(s1))
    {
        // copia da posição i um pedaço do tamanho de s2
        strncpy(temp, &s1[i], strlen(s2));
        temp[strlen(s2)] = '\0';  // garante fim da string

        // verifica se esse pedaço é igual a s2
        if (strcmp(temp, s2) == 0)
        {
            // copia s3 para o resultado
            strcat(res, s3);
            i += strlen(s2);  // pula a substring s2
        }
        else
        {
            // copia apenas 1 caractere de s1
            char c[2];
            c[0] = s1[i];
            c[1] = '\0';
            strcat(res, c);
            i++;
        }
    }

    printf("\nResultado: %s\n", res);

    return 0;
}
