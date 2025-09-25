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

    
    ListaCliente** lista = NULL; //isso so serve para um cliente. temos que substitirur por lista 
    int opcao;
    //teste de commit
    do {
        opcao = exibir_menu();
        switch (opcao) {
            case 1: {
                
                break;
            }
            case 2: {
                
                break;
            }
            case 3:
                
                break;
            case 4:
                break;
            case 0:
                exibir_mensagem("Saindo...");
                break;
            default:
                exibir_mensagem("Opção inválida!");
        }
    } while (opcao != 0);

    if (lista) deletar_cliente(lista);
}
