/*5) Elabore um programa em C que realize a encriptação de uma mensagem. O programa deve
solicitar do usuário uma string que corresponde a uma mensagem e codificar esta mensagem. A
estratégia de encriptação consiste em somar a posição inversa do caractere na string com o valor
correspondente do caractere na tabela ascii.
Exemplo:

9 - 8 - 7 - 6 - 5 - 4 - 3 - 2 - 1 - 0
e - n - g - e - n - h - a - r - I - a
101 - 110 - 103 - 101 - 110 - 104 - 97 - 114 - 105 - 97
n - v - n - k - s - l - d - t - j - a
110 - 118 - 110 - 107 - 115 - 108 - 100 - 116 - 106 - 97
Obs.: O símbolo de menor valor na tabela ascii é o ' ' com valor 32 e o caractere que apresenta
maior valor é o '~' com 126. O programa deve retornar ao início caso exceda o limite numérico da
tabela ascii.*/
  
#include <stdio.h>
#include <string.h>


int main()
{
    int i;
    char string[100];
    char resultado[100];
    
    printf("Digite sua string: ");
    scanf (" %[^\n]", string); //vai pegar apenas palavras, se vier composta nao cola
    
    int tamanho;
    tamanho= strlen(string); //esse strlen, serve pra ver quantos caracteres tem a string

    int soma_ascii=0;
    
    //imprimir dados pro usuario
    for(i=0;i<tamanho;i++)
    {
        int ascii= string[i]; //aqui cada letra da string é convertida em seu valor numerico de ascii

        printf("---------------\n");
        printf("Letra %c\n", string[i]); //imprime letra por letra da string
        printf("Na posição %d\n", i );
        printf("Ascii: %d\n", ascii);
        
        //essa parte é legal, mas se tu nao lembrar, imagina casa, tem 4 letras né? mas no programa ele le 0123, entao pra tu chegar na ultima posição, é 4 (que é o tanto de letras), menos 1, pra poder dar o 3 de 0123
        int ultima_posicao = tamanho - 1;
        
        //por que esse "i" fi?, lembra que começa do zero, entao ele pega 3-0 que vai da a ultima posicao, depois via ser 3-1 que vai ser a terceira posição, e assim vai
        int posicao_inversa = ultima_posicao - i;
        
        //criação de variavel pro nosso novo ascii
        int novo_ascii=0;

        //soma pra ver o valor total da nossa nova ascii, claro, ainda falta fazer o loop pra ela realemnte existir
        novo_ascii= posicao_inversa + ascii;
        
        //fazer o loop quando passar
        if (novo_ascii > 126)  //se o nov ascii passar de 126, vamo ter que fazer ele dar UMA volta
        {
            //a logica que eu usei foi o seguinte fi, o minimo é 32, verto? e o maximo 126. No momento que passa 1 de 126, ele vale 127. nós pegar o valor do ascii que com certeza passou de 126 e diminui 127, apos isso nós soma com 32 que vai dar o valor da tabela após UMA volta. (Caso na defesa tu nao lembre pq é 127, imagina que passou só um, vai zerar e da 32, que é uma volta)
            novo_ascii = 32 + (novo_ascii - 127);
        }

        printf("Posição inversa: %d\n", posicao_inversa);
        printf("Letra da posição inversa: %c\n", string[posicao_inversa]);
        printf("Nova ascii: %d\n", novo_ascii);
        printf("Caracter após o loop: %c\n", resultado[i]);
        
        //isso aqui serve pra fazer a construção da nova strind criptografada, ele pega a nova ascii, ja que nao é maior que 126, ele guarda os caracerr e vai acumulando, fazendo a nova string
        resultado[i] = novo_ascii;
        
    }
    
    // esse é bem legal tambem, lembra que o tamanho de casa é 4, e o codigo so le ate 3, entao assim que ele chegar no 4, ele anula e fecha a string
    resultado[tamanho] = '\0';  
    printf("\nMensagem criptografada: %s\n", resultado);

}
