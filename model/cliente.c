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


    // função para conferir se a lista esta vazia
    // Caso 1: A lista está vazia. O novo nó é o primeiro.
    if (*lista == NULL) {
        *lista = novo;
    } else {
        // Caso 2: A lista não está vazia. Percorre até o final.
        ListaCliente* aux = *lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        // Atribui o novo nó no final da lista
        aux->prox = novo;
    }
    return 1;
}


/**
 * @brief Busca um cliente na lista pelo nome.
 *
 * @param lista Ponteiro para o início da lista.
 * @param nome O nome do cliente a ser buscado.
 * @return Retorna um ponteiro para o nó (ListaCliente*) se encontrar o cliente ativo,
 * ou NULL se não encontrar.
 */
ListaCliente* buscar_cliente_por_nome(ListaCliente* lista, const char* nome) {
    ListaCliente* aux = lista;

    // Percorre a lista enquanto não chegar ao fim
    while (aux != NULL) {
        // Compara o nome do cliente atual com o nome buscado
        // e verifica se o cliente está ativo
        if (strcmp(aux->conteudo.nome, nome) == 0 && aux->conteudo.ativo) {
            return aux; // Encontrou, retorna o ponteiro para o nó
        }
        aux = aux->prox; // Move para o próximo nó
    }

    return NULL; // Não encontrou o cliente na lista
}

/**
 * @brief Realiza a remoção lógica de um cliente, marcando-o como inativo.
 *
 * @param lista Ponteiro para o início da lista.
 * @param nome O nome do cliente a ser "removido".
 * @return Retorna 1 se o cliente foi encontrado e marcado como inativo, 0 caso contrário.
 */
int remover_soft_delete_cliente_por_nome(ListaCliente* lista, const char* nome) {
    // Reutiliza a função de busca para encontrar o cliente
    ListaCliente* no_cliente = buscar_cliente_por_nome(lista, nome);

    if (no_cliente != NULL) {
        no_cliente->conteudo.ativo = 0; // Marca como inativo
        return 1; // Sucesso
    }

    return 0; // Cliente não encontrado
}

/**
 * @brief Remove fisicamente um cliente da lista e libera sua memória.
 *
 * @param lista Ponteiro para o ponteiro do início da lista (para poder modificar o início).
 * @param nome O nome do cliente a ser deletado.
 * @return Retorna 1 se o cliente foi removido com sucesso, 0 se não foi encontrado.
 */
int remover_fisico_cliente_por_nome(ListaCliente** lista, const char* nome) {
    if (*lista == NULL) return 0; // Lista vazia, não há o que remover

    ListaCliente* atual = *lista;
    ListaCliente* anterior = NULL;

    // Percorre a lista para encontrar o nó a ser removido
    while (atual != NULL && strcmp(atual->conteudo.nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se atual é NULL, o cliente não foi encontrado
    if (atual == NULL) {
        return 0;
    }

    // Caso 1: O nó a ser removido é o primeiro da lista
    if (anterior == NULL) {
        *lista = atual->prox; // A cabeça da lista agora é o próximo nó
    } else {
        // Caso 2: O nó está no meio ou no fim da lista
        anterior->prox = atual->prox; // O nó anterior aponta para o nó seguinte ao atual
    }

    free(atual); // Libera a memória do nó removido
    return 1;    // Sucesso
}

/**
 * @brief Atualiza o nome e a idade de um cliente na lista.
 *
 * @param lista Ponteiro para o início da lista.
 * @param nome_busca Nome do cliente a ser atualizado.
 * @param novo_nome O novo nome para o cliente.
 * @param nova_idade A nova idade para o cliente.
 * @return Retorna 1 se o cliente foi encontrado e atualizado, 0 caso contrário.
 */
int atualizar_dados_cliente_por_nome(ListaCliente* lista, const char* nome_busca, const char* novo_nome, int nova_idade) {
    // Usa a função de busca para encontrar o nó do cliente
    ListaCliente* no_cliente = buscar_cliente_por_nome(lista, nome_busca);

    if (no_cliente != NULL) {
        // Se encontrou, chama a função auxiliar para atualizar os dados do cliente
        atualizar_cliente(&(no_cliente->conteudo), novo_nome, nova_idade);
        return 1; // Sucesso
    }

    return 0; // Cliente não encontrado
}

// Libera a memória de todos os nós da lista
void liberar_lista_completa(ListaCliente** lista) {
    ListaCliente* atual = *lista;
    ListaCliente* proximo;

    while (atual != NULL) {
        proximo = atual->prox; // Guarda o próximo nó
        free(atual);           // Libera o nó atual
        atual = proximo;       // Avança para o próximo
    }

    *lista = NULL; // Deixa o ponteiro original como nulo para segurança
}
// // percorre ate o final da lista 
//    //NULL é para parar como se fosse o final
//     //ListaCliente* aux=lista;
//  //   while (aux->prox != NULL){
//         aux=aux->prox;
//     }

//     // atribui o novo no
//     aux->prox=novo;
//     return 1;
// }
//agora falta, remover buscar e atualizar o inserir ja fizemos
//para apagar hard delete
// ou ao inves de apagar colocar  funçaa tivo e desatividado soft delet
//inicializar cliente la em cima
//gerador de id sequencial 

// remover soft delete 
// int remover_lista_cliente(ListaCliente* lista, int id ){
//     ListaCliente* aux=lista;

//     while (aux->prox != NULL){
//         if (aux->conteudo.id == id){
//             aux->conteudo.ativo=0;
//             return 1;
//         }
        
//         aux=aux->prox;
//     }

//     //nao encontrou e retorna 0
//     return 0;
// }
