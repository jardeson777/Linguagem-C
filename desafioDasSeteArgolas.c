#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


long int quantidade_movimento(int argolas){
    long int movimentos = (pow(2, argolas+1)-2+(pow(-1, argolas+1)+1)/2)/3;//Formula para achar a quantidade de movimentos
    return movimentos;
}
//=============================================================================
void gerando_lista(long int argolas, long int *lista_argolas, int num){ //Transformando em lista
    int i;
    if(num == 1){ //Se for para retirar as argolas então vai montar uma lista com numero 1 do tamanho do numero de argolas
        for(i=0; i<argolas; i++){
            lista_argolas[i] = 1;
        }
    }
    else if(num == 0){ //Se for para colocar as argolas então vai montar uma lista com numero 0 do tamanho do numero de argolas
        for(i=0; i<argolas; i++){
            lista_argolas[i] = 0;
        }
    }
}
//=============================================================================
void print_lista (long int *lista, int cont){ //Função que printa os valores de dentro da lista, no caso uso ela a cada movimento feito nas argolas
    int i;

    printf("--> ");
    for(i=0; i<cont; i++){
        printf("%d", lista[i]);
    }
    printf("\n");
}
//=============================================================================
void retira_argola(long int *lista, int tamanho, int cont){
    int ultimo_valor = lista[tamanho-1]; //Ultimo valor da lista, ou melhor, ultima argola
    int i;
    int indice = 0; //indice do ultimo numero 1 encontrado
    int qtd_1 = 0; //quantidade de numero 1 que a lista possui

    for(i=0; i<tamanho; i++){ //Aqui acha a quantidade de numero 1 e salva o indice do ultimo numero 1
        if(lista[i] == 1){ //Se encontrar o numero 1 na lista então a quantidade recebe +1 e o indice é guardado, assim encontra o ultimo numero 1
            qtd_1++;
            indice = i;
        }
    }
    printf("%d ", cont);
    print_lista(lista, tamanho);

    if(qtd_1 != 0){

        if (qtd_1 % 2 != 0 && ultimo_valor == 0){ //Se a quantidade de numero 1 for impar e o ultimo valor da lista for 0, então muda o ultimo valor para 1
            lista[tamanho-1] = 1;
            retira_argola(lista, tamanho, cont+1);
        }
        else if(qtd_1 % 2 != 0 && ultimo_valor == 1){ //Se a quantidade de numero 1 for impar e o ultimo valor da lista for 1, então muda o ultimo valor para 0
            lista[tamanho-1] = 0;
            retira_argola(lista, tamanho, cont+1);
        }
        else if (qtd_1 % 2 == 0 && lista[indice-1] == 0){ //Se a quantidade de numero 1 for par e o numero antes do ultimo numero 1 for 0, muda ele para 1
            lista[indice-1] = 1;
            retira_argola(lista, tamanho, cont+1);
        }
        else if (qtd_1 % 2 == 0 && lista[indice-1]== 1){ //Se a quantidade de numero 1 for par e o numero antes do ultimo numero 1 for 1, muda ele para 0
            lista[indice-1] = 0;
            retira_argola(lista, tamanho, cont+1);
        }
    }
    else{ //Se não tiver mais nenhum numero 1 na lista então acaba a recursão
        return;
    }
}
//=============================================================================
void coloca_argola(long int *lista, int tamanho, int cont){
    int ultimo_valor = lista[tamanho-1], i; //ultimo valor da lista, ou melhor, ultima argola
    int qtd_1 = 0;
    int ultimo_1 = 0;

    for(i=0; i<tamanho; i++){ //Achando ultima posição do numero 1 e contando a quantidade de numero 1
        if(lista[i] == 1){
            qtd_1++;
            ultimo_1 = i;
        }
    }

    printf("%d ", cont);
    print_lista(lista, tamanho);

    if(qtd_1 < tamanho){ //Se a quantidade de 1 na lista menor do que a esperada então tem que continuar resolvendo o algoritmo
        if(qtd_1 == 0){ //Se todos os numeros da lista for iguais a 0 então muda o ultimo valor para 1
            lista[tamanho - 1] = 1;
            coloca_argola(lista, tamanho, cont+1);
        }
        else if(qtd_1 % 2 != 0 && lista[ultimo_1 - 1] == 0){ //Se a quantidade de numero 1 for impar e o numero antes do ultimo numero 1 encontrado for 0, troca ele para 1
            lista[ultimo_1 - 1] = 1;
            coloca_argola(lista, tamanho, cont+1);
        }
        else if(qtd_1 % 2 != 0 && lista[ultimo_1 - 1] == 1){//Se a quantidade de numero 1 for impar e o numero antes do ultimo numero 1 encontrado for 1, muda ele para 0
            lista[ultimo_1 - 1] = 0;
            coloca_argola(lista, tamanho, cont+1);
        }
        else if(qtd_1 % 2 == 0 && ultimo_valor == 0){//Se a quantidade de numero 1 for par e o ultimo valor da lista for 0, então muda ele para 1
            lista[tamanho-1] = 1;
            coloca_argola(lista, tamanho, cont+1);
        }
        else if(qtd_1 % 2 == 0 && ultimo_valor == 1){//Se a quantidade de numero 1 for par e o ultimo valor da lista for 1, então muda ele para 0
            lista[tamanho-1] = 0;
            coloca_argola(lista, tamanho, cont+1);
        }
    }
    else{
        return;
    }
}
//=============================================================================
void main(){
	system("color 0A"); //Aqui deixa o programa com o fundo preto e a letra verde
    int qtd_argolas, resposta=0, resposta2=0;


    printf("Quantas argolas o problema tem: ");
    scanf("%d", &qtd_argolas);

    if(qtd_argolas < 0){//Não pode colocar valor menor que 0, não existe numero de argola negativo
        printf("\n-----------------------------------------------------------");
        printf("\nOpcao invalida, tente novamente\n");
        printf("-----------------------------------------------------------\n");
        main();
    }

    while(resposta > 2 || resposta < 1){ //Isso vai repetir enquanto a resposta não for 1 ou 2
        printf("\nO que deseja fazer com as argolas? (1)para RETIRAR | (2)para COLOCAR: ");
        scanf("%d", &resposta);

        if(resposta > 2 || resposta < 1){
            printf("\n-----------------------------------------------------------");
            printf("\nOpcao invalida, tente novamente\n");
            printf("-----------------------------------------------------------\n");
        }
    }

    long int movimentos = quantidade_movimento(qtd_argolas);
    long int lista[qtd_argolas];

    if(resposta == 1){//Se a resposta for 1 de RETIRAR
        gerando_lista(qtd_argolas, lista, 1);
        retira_argola(lista, qtd_argolas, 0);
    }
    if(resposta == 2){//se a resposta for 2 de COLOCAR
        gerando_lista(qtd_argolas, lista, 0);
        coloca_argola(lista, qtd_argolas, 0);
    }

    do
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("Deseja continuar? (1) para SIM e (2) para NAO: ");
        scanf("%d", &resposta2);

        if(resposta2 > 2 || resposta2 < 1){
            printf("\n-----------------------------------------------------------");
            printf("\nOpcao invalida, tente novamente\n");
            printf("-----------------------------------------------------------\n");
        }

        else if(resposta2 == 1){
            printf("\n-----------------------------------------------------------\n");
            main();
        }

        else if(resposta2 == 2) break;
    } while (resposta2 > 2 || resposta2 < 1); // Vai repetir isso enquanto a resposta n for 1 ou 2
}
