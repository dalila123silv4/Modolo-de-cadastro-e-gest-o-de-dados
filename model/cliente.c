#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

// // Cria e inicializa um cliente
// Cliente* criar_cliente(int id, const char* nome, int idade) {
//     Cliente* novo = (Cliente*) malloc(sizeof(Cliente));
//     f (!novo) {
//         return NULL; // erro de memória
//     }
//     novo->id = id;
//     strncpy(novo->nome, nome, sizeof(novo->nome));
//     novo->idade = idade;

    
//     return novo;
// }i

// Atualiza os dados do cliente
void atualizar_cliente(Cliente* cliente, const char* nome, int idade) {
    if (!cliente) return;
    strncpy(cliente->nome, nome, sizeof(cliente->nome));
    cliente->idade = idade;
}

// Remove o cliente (libera memória)
void deletar_cliente(Cliente* cliente) {
    if (cliente) free(cliente);
}

// aloca o espaço da memoria 
int inserir_lista_cliente(ListaCliente** lista, Cliente novo_cliente){
    // aloca o novo no
    ListaCliente* novo= (ListaCliente*) malloc(sizeof(ListaCliente));
    if (!novo){
        return 0; 
    }

    // atribui os valores de um no novo
    novo->conteudo = novo_cliente; // atribui os dados no novo no
    novo->conteudo.ativo = 1;      // novo no smp e ativo
    novo->prox = NULL;             // como ta no final, o prox e NULL


    // FALTOU CONFERIR SE A LISTA ESTA VAZIA

    // percorre ate o final da lista 
    //NULL é para parar como se fosse o final
    ListaCliente* aux=lista;
    while (aux->prox != NULL){
        aux=aux->prox;
    }

    // atribui o novo no
    aux->prox=novo;
    return 1;
}
//agora falta, remover buscar e atualizar o inserir ja fizemos
//para apagar hard delete
// ou ao inves de apagar colocar  funçaa tivo e desatividado soft delet
//inicializar cliente la em cima
//gerador de id sequencial 

// remover soft delete 
int remover_lista_cliente(ListaCliente* lista, int id ){
    ListaCliente* aux=lista;

    while (aux->prox != NULL){
        if (aux->conteudo.id == id){
            aux->conteudo.ativo=0;
            return 1;
        }
        
        aux=aux->prox;
    }

    //nao encontrou e retorna 0
    return 0;
}
