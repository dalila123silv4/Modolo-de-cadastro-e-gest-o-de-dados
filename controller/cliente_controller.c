#include <stdlib.h>
#include "../model/cliente.h" //posso incluir eles no ponto h
#include "../view/cliente_view.h" 
#include "cliente_controller.h"//deixa aqui so ponto h

void criarCliente(Cliente* cliente){
    // Agora usamos a função com retorno
    Cliente temp = ler_dados_cliente();

    if (cliente) {
        exibir_mensagem("Já existe um cliente. Delete-o antes de criar outro.");
    } else {
        cliente = criar_cliente(temp.id, temp.nome, temp.idade);
        exibir_mensagem("Cliente criado com sucesso!");
    }

}

void iniciar_sistema() { //lista-cliente

    
    Cliente** cliente = NULL; //isso so serve para um cliente. temos que substitirur por lista 
    int opcao;
    //teste de commit
    do {
        opcao = exibir_menu();
        switch (opcao) {
            case 1: {
                criarCliente(*cliente);
                break;
            }
            case 2: {
                if (!cliente) {
                    exibir_mensagem("Nenhum cliente cadastrado!");
                } else {
                    char nome[50];
                    int idade;
                    ler_dados_atualizacao(nome, &idade);
                    atualizar_cliente(cliente, nome, idade);
                    exibir_mensagem("Cliente atualizado!");
                }
                break;
            }
            case 3:
                exibir_cliente(cliente);
                break;
            case 4:
                if (!cliente) {
                    exibir_mensagem("Nenhum cliente para deletar!");
                } else {
                    deletar_cliente(cliente);
                    cliente = NULL;
                    exibir_mensagem("Cliente deletado!");
                }
                break;
            case 0:
                exibir_mensagem("Saindo...");
                break;
            default:
                exibir_mensagem("Opção inválida!");
        }
    } while (opcao != 0);

    if (cliente) deletar_cliente(cliente);
}
