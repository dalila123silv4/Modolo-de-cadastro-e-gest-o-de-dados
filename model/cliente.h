#ifndef CLIENTE_H
#define CLIENTE_H

// =============================
// MODEL: representa os dados
// =============================

// Estrutura básica de Cliente
typedef struct {
    int id;
    int ativo;
    char nome[100];
    int idade;
    char endereço_completo[100];
    char cpf [20];
    char telefone [20];
    char email [100];
    char nome_contato [100];

    // Aqui você pode expandir: adicionar CPF, email, endereço, telefone, etc.
} Cliente;

typedef struct{
    Cliente conteudo;
   struct ListaCliente* prox;
}ListaCliente;

//===============================================================================
// funcoes do cliente
Cliente* criar_cliente(int id, const char* nome, int idade, const char* endereço_completo, const char* cpf, const char* telefone, const char* email, const char nome_contato);
void atualizar_cliente(Cliente* cliente, const char* nome, int idade);
void deletar_cliente(Cliente* cliente);
void buscar_cliente(Cliente*cliente);

//===============================================================================
// funcoes da lista

#endif
