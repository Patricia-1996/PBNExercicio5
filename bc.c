#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int scale = 0;

void mostrar_banner(){
    printf("bc 1.07.1\n");
    printf("Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006, 2008, 2012-2017 Free Software Foundation, Inc.");
    printf("This is free software with ABSOLUTELY NO WARRANTY".\n);
    printf("For details type 'warranty'. \n");
}

void processar_calculo(char *input){
    double n1,n2;
    char operacao;

    //Se o usuário digitar o 'scale=X'
if(strncmp(input, "scale=", 6)==0 ){
    scale = atoi(&input[6]);
    return;
}
//Se o usuario digitar 'quit' o programa fecha
if(strcmp(input, "quit") == 0){
    exit(0);
}

//Tenta ler a operação (ex: 10 / 3)
if(sscanf(input, "%lf %c %lf", &n1, &operacao, &n2) == 3){
    char formato[20];
    //Cria dinamicamente o formato de saida baseado no scale atual
    sprintf(formato, "%%.%df\n", scale);

    switch(operacao){
        case'+': printf(formato, n1 + n2); break;
        case'-': printf(formato, n1 - n2); break;
        case'*': printf(formato, n1 * n2); break;
        case'/': 
        if(n2 != 0)
        printf(formato, n1 / n2); 
        else
        printf("Runtime error: Divide by zero\n");
        break;
    default: printf("syntax error\n");
    }
    else if(strlen(input)> 0){
        //Se não for uma conta valida nem um numero conhecido
        printf("syntax error\n")
    }
}


}

int main(){
    char linha[1024];
    mostrar_banner();

    //loop infinito como o do terminal
    while (1)
    {
        //o bc nao tem ">", fica apenas esperando em uma linha vazia
        /* code */
        if(fgets(linha, sizeof(linha), stdin) == NULL){
            break;//Sai com ctrl D
        }
        //Remove o \n do final da String
        linha[strcspn]
    }
    

}

