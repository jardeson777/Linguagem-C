#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long int copia_lista (long int *lista, long int *copia, int cont){
    int i, j;

    for (i=0; i<cont; i++) //Copiando os valores da lista gerada para a que vai ser ordenada
    {
        copia[i] = lista[i];
    }

}
//=========================================================================================================

double bolha (long int *lista, int cont)
{
    int i, j, armazem;

    for (i=0; i<cont-1; i++) //Ordenando lista
    {
        for (j=i+1; j<cont; j++)
        {
            if (lista[i] > lista[j])
            {
                armazem = lista[j];
                lista[j] = lista[i];
                lista[i] = armazem;
            }
        }
    }
    return 0;
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

double insercao(long int *lista, int cont)
{

    int i, j, armazem;

    for (i=1; i<cont; i++) //ordenando lista
    {
        armazem = lista[i];
        for (j=i-1; j>=0 && armazem < lista[j]; j--)
        {
            lista[j+1] = lista[j];
        }
        lista[j+1] = armazem;
    }

    return 0;
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

double selecao (long int *lista, int cont)
{
    int i, j, armazem, menor;

    for(i=0; i<cont; i++) //ordenando
    {
        menor = i;
        for(j=i+1; j<cont; j++) //Selecionando o menor valor e guardando o indice
        {
            if (lista[j] < lista[menor])
            {
                menor = j;
            }
        }
        if ( i != menor)
        {
            armazem = lista[i];
            lista[i] = lista[menor];
            lista[menor] = armazem;
        }
    }

    return;
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void merge(long int *lista, int primeiro_indice, int indice_meio, int ultimo_indice){

    //Tamanho das listas
    int tamanho_1 = indice_meio - primeiro_indice + 1;
    int tamanho_2 = ultimo_indice - indice_meio;

    //Listas onde vai ficar a parte esquerda e direita da lista principal
    long int lista_esquerda[tamanho_1], lista_direita[tamanho_2];

    //Separando a lista
    int i = 0, j = 0, k = 0; //Zerando variaveis de controle para o while

    while (i<tamanho_1) //Passando os valores da lista principal(parte esquerda) para a nova lista
    {
        lista_esquerda[i] = lista[primeiro_indice + i];
        i++;
    }

    while (j<tamanho_2) //Passando os valores da lista principal(parte direita) para a nova lista
    {
        lista_direita[j] = lista[indice_meio + j + 1];
        j++;
    }

    i = 0; j = 0;
    k = primeiro_indice;

    while (i < tamanho_1 && j < tamanho_2){ //Verificar se ja foi toda percorrida

        if (lista_esquerda[i] <= lista_direita[j]){ //Se o valor da esquerda for menor que o da direita
            lista[k] = lista_esquerda[i]; //Passando para a lista o valor menor
            i++;
        }
        else{
            lista[k] = lista_direita[j]; //Passando para a lista o valor menor
            j++;
        }

        k++; //Corre o indice da lista principal
    }

    while (i<tamanho_1){ //Caso falte algum elemento no lado esquerdo
        lista[k] = lista_esquerda[i];
        i++;
        k++;
    }

    while (j<tamanho_2){ //Caso falte algum elemento no lado direito
        lista[k] = lista_direita[j];
        j++;
        k++;
    }

}

float merge_sort (long int *lista, int primeiro_indice, int ultimo_indice){

    if(primeiro_indice < ultimo_indice){ //Defini se ainda é preciso fazer a ordenação
        int indice_meio = primeiro_indice + (ultimo_indice - primeiro_indice) / 2; //Encontra o meio

        merge_sort(lista, primeiro_indice, indice_meio); //até o meio
        merge_sort(lista, indice_meio+1, ultimo_indice); //do meio até o final

        merge(lista, primeiro_indice, indice_meio, ultimo_indice);//Junta as listas que o merge_sort criou
    }
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
double quick_sort(long int *lista, int indice_inicial, int indice_final){

    int pivo, indice_meio, armazem;;
    int direito = indice_final;
    int esquerdo = indice_inicial;

    indice_meio = floor((indice_inicial + indice_final)/2); //Achando o indice do valor que esta no meio da lista
    pivo = lista[indice_meio]; //Pegando o valor que o indice do meio pertence


    while(direito > esquerdo){
        while(lista[esquerdo] < pivo){ //enquanto o valor estiver no lado certo, não faz nada, só continua analisando o proximo valor
            esquerdo++;
        }

        while(lista[direito] > pivo){ //enquanto o valor estiver no lado certo, não faz nada, só continua analisando o proximo valor
            direito--;
        }

        if(esquerdo <= direito){
            armazem = lista[esquerdo];
            lista[esquerdo] = lista[direito];
            lista[direito] = armazem;

            //isso é para os indices percorram em direção ao pivo
            esquerdo++;
            direito--;
        }
    }

    if(indice_inicial < direito){
        quick_sort(lista, indice_inicial, direito);
    }

    if(esquerdo < indice_final){
        quick_sort(lista, esquerdo, indice_final);
    }
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

int encontrando_maior(long int *lista, int tamanho){
    int i, maior=0;
    for (i=0; i<tamanho; i++){
        if (lista[i] > maior){
            maior = lista[i];
        }
    }
    return maior;
}


float count_sort(long int *lista, long int *ordenada, int tamanho){ //Montei o código pelo algoritmo mostrado nesse video  https://www.youtube.com/watch?v=7zuGmKfUt7s&ab_channel=GeeksforGeeks

    int i, k, j;
    int maior = encontrando_maior(lista, tamanho); //Achar o maior numero da lista, assim a lista de parametro
    long int indice[maior+1];//Maior mais 1 pq se o maior numero for 5 então os indice serão de 0 até 4, ou seja quando encontrar o numero 5 ele n irá conseguir implementar +1 na posição 5

    for(i=0; i<=maior+1; i++){
        indice[i] = 0;
    }

    for(i=0; i<tamanho; i++){
    // Aqui é onde acontece a contagem, se encontrou o numero 1, entao encrementa +1 na posição 1 da lista
        indice[lista[i]]++;
    }

    i = 0; //aqui zera o i para ser usado no while
    while (i != maior){
    //Esse while está somando um valor com o seu proximo e armazenando nesse proximo, o resultado dessa soma é a posição que tal numero vai ficar na lista ordenada.
        indice[i+1] = indice[i] + indice[i+1];
        i++;
    }


    for(i=0; i<tamanho; i++){
    //Aqui é onde está ordenando. O indice é o vetor com a posição certa(ordenada) para cada número da lista na posição i
        ordenada[indice[lista[i]]-1] = lista[i];
        indice[lista[i]]--;//aqui está sendo decrementado pq tipo, vamos supor que tenha dois numeros 5, se não decrementar o loop vai por os dois na msm posição, ou seja, esses dois numeros 5 vai virar um só. Decrementando, se for 4 posições, o 5 for o maior valor e tiver 2 numeros 5, então primeiro vai ser colocado na posição 3 e o outro numero 5 vai ser colocado na posição 2.
    }

}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
double tempo_bolha(long int *lista, int cont){

    //Contador
    clock_t t_inicial, t_final;
    double tempo;

    t_inicial = clock(); //inicio
    //================================================================================
    bolha(lista, cont);
    //================================================================================
    t_final = clock(); //final
    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC;

    return tempo; //Tempo de execusao

}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
double tempo_insercao(long int *lista, int cont){

    //Contador
    clock_t t_inicial, t_final;
    double tempo;

    t_inicial = clock(); //inicio
    //================================================================================
    insercao(lista, cont);
    //================================================================================
    t_final = clock(); //final
    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC;

    return tempo; //Tempo de execusao

}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
double tempo_selecao(long int *lista, int cont){

    //Contador
    clock_t t_inicial, t_final;
    double tempo;

    t_inicial = clock(); //inicio
    //================================================================================
    selecao(lista, cont);
    //================================================================================
    t_final = clock(); //final
    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC;

    return tempo; //Tempo de execusao

}
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

double tempo_merge_sort(long int *lista, int primeiro_indice, int ultimo_indice){

    //Contador
    clock_t t_inicial, t_final;
    double tempo;

    t_inicial = clock(); //inicio
    //================================================================================
    merge_sort(lista, primeiro_indice, ultimo_indice);
    //================================================================================
    t_final = clock(); //final
    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC;

    return tempo; //Tempo de execusao

}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
double tempo_quick_sort(long int *lista1, int indice_inicial, int indice_final){

    //Contador
    clock_t t_inicial, t_final;
    double tempo;

    t_inicial = clock(); //inicio
    //================================================================================
    quick_sort(lista1, indice_inicial, indice_final);
    //================================================================================
    t_final = clock(); //final
    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC;

    return tempo; //Tempo de execusao

}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

double tempo_count_sort(long int *lista, long int *ordenada, int tamanho){

    //Contador
    clock_t t_inicial, t_final;
    double tempo;

    t_inicial = clock(); //inicio
    //================================================================================
    count_sort(lista, ordenada, tamanho);
    //================================================================================
    t_final = clock(); //final
    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC;

    return tempo; //Tempo de execusao

}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

int main ()
{
    int intervalo_inicial=0, intervalo_final=0, i, cont=0, valor=0;

    printf("Digite o menor valor que pode ser colocado na lista: ");
    scanf("%d", &intervalo_inicial);

    printf("Digite o maior valor que pode ser colocado na lista: ");
    scanf("%d", &intervalo_final);

    printf("Digite quantos numeros vc quer gerar: ");
    scanf("%d", &cont);

    long int lista_de_valores[cont];

    //==========================================================================================================

    int final_positivo = fabs(intervalo_final), inicio_positivo = fabs(intervalo_inicial); //Variaveis que guarda o valor positivo no final e do inicio

    //==========================================================================================================

    srand((unsigned)time(NULL)); //ISSO É PARA O RAND FUNCIONAR PERFEITAMENTE E MUDAR O VALOR A CADA LOOP

    //==========================================================================================================


    for(i=0; i<cont; i++) //VAI FICAR EM LOOP A QUANTIDADE DE VEZES QUE O USUARIO DETERMINAR
    {
        //=======================================GERANDO VALORES ALEATORIO=======================================

        if (intervalo_inicial >= 0) //Se o menor falor que pode ser gerado for positivo ou igual a 0
        {
            lista_de_valores[i] = intervalo_inicial + rand() % (intervalo_final - intervalo_inicial + 1);
            //Aqui o rand gera um valor da diferença dos dois numeros, exemplo se o maior valor for 8 e o menor for 2
            //o rand vai gerar de 0 até 6, logo após isso ele é somado ao valor 2, ou seja, se gerar um valor 0
            //então será salvo o valor 2, que satisfas o usuário. Se gerar o valor 6, somando aos 2 terá o valor 8
            //que também satisfas o usuário.
        }
        //======================================================================================================
        else if (intervalo_inicial < 0 && intervalo_final >= 0)//Se o menor valor for negativo e o maior falor for positivo ou igual a 0
        {
            lista_de_valores[i] = intervalo_inicial + rand() % (final_positivo + inicio_positivo + 1);
            //Aqui o rand gera um valor de 0 até a soma do menor valor possivel com o maior valor possivel,
            //só que nesse caso eles foram convertidos para positivo. Se o usuário falar que os numeros gerados serão de
            //-3 até 5, então o rand irá gerar de 0 até 8. Se cair o valor 8 no rand, o valor salvo será de 5, e isso
            //satisfas o usuário. Se o rand gerar o numero 0, então será salvo o valor -3, que satisfas o usuário.
        }
        //======================================================================================================
        else if(intervalo_inicial < 0 && intervalo_final < 0)//Se o menor e o maior valor for negativo
        {
            lista_de_valores[i] = intervalo_inicial + rand() % (final_positivo - inicio_positivo + 1);
            //Aqui o rand gera um valor de 0 até a diferença do maior valor possivel com o menor valor possivel,
            //só que nesse caso eles foram convertidos para positivo. Se o usuário falar que os numeros gerados serão de
            //-10 até -1, então o rand irá gerar de 0 até 9. Se cair o número 9, então o valor salvo será de -1, porque
            //ele soma com o valor inicial, nesse caso é o -10. Se cair o número 0, então o valor salvo será de -10.
            //Ambos valores satisfas o usuário.
        }
        //======================================================================================================
    }

    //==============================================================================================================
    long int lista_ord_cont[cont];
    long int lista1[cont], lista2[cont], lista3[cont], lista4[cont], lista5[cont], lista6[cont]; //Listas que serão ordenadas

    copia_lista(lista_de_valores, lista1, cont);
    copia_lista(lista_de_valores, lista2, cont);
    copia_lista(lista_de_valores, lista3, cont);
    copia_lista(lista_de_valores, lista4, cont);
    copia_lista(lista_de_valores, lista5, cont);
    copia_lista(lista_de_valores, lista6, cont);
    copia_lista(lista_de_valores, lista_ord_cont, cont);


    double tempo_b = tempo_bolha(lista1, cont);
    double tempo_i = tempo_insercao(lista2, cont);
    double tempo_s = tempo_selecao(lista3, cont);
    double tempo_merge = tempo_merge_sort(lista4, 0, cont);
    double tempo_quick = tempo_quick_sort(lista5, 0, cont);

    printf("\nBolha: %lf\n", tempo_b);
    printf("Insercao: %lf\n", tempo_i);
    printf("Selecao: %lf\n", tempo_s);
    printf("Merge sort: %lf\n", tempo_merge);
    printf("Quick sort: %lf\n", tempo_quick);

    if(intervalo_inicial < 0 || intervalo_final <0){
        printf("\nCout sort: Nao consegui fazer ele ordena numeros negativo, somente os positivos\n");
    }
    else{  
        double tempo_count = tempo_count_sort(lista6, lista_ord_cont, cont);
        printf("Count sort: %lf\n", tempo_count);
    }
}
