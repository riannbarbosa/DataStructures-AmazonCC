#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// importa as funcoes criadas (header)
#include "src/functions.h"

int main()
{
    int id, n, num, op, qntd;
    //  0 - Sair, 1 - Cadastro, 2- Listar, 3- Buscar, 4- Excluir, 5 -Comprar, 6 - contar
    while (TRUE)
    {
        // printa as opções do menu
        menu();
        printf("\nDigite a opcao desejada: ");
        // recebe a opção
        scanf("%d", &n);
        // menu
        switch (n)
        {
        case 0:
            // saida do programa
            saida();
            exit(1); // realiza a saida do sistema
            break;
        case 1:
            // cadastrar os produtos na loja
            regist();
            break;
        case 2:
            // listar
            if (empty_()) // verifica se a lista é vazia
                list_prod();
            break;

        case 3:
            // busca com base no id do produto
            if (empty_())
            {
                search_(id);
            }
            break;
        case 4:
            // excluir produto
            if (empty_())
            {
                printf("Digite o código do produto para excluir: ");
                scanf("%d", &id);
                delete_(id);
            }
            break;
            // menu do carrinho/comprar
        case 5:
            if (empty_())
            {
                while (TRUE)
                {
                    printf("\n-------- Compras --------\n");
                    printf("\n1 - Comprar\n2 - Lista de Produtos\n3 - Carrinho\n4 - Devolver\n5 - Voltar\n");
                    printf("Digite a opção: ");
                    scanf("%d", &num);
                    switch (num)
                    {
                    case 1:
                        // adiciona produtos ao carrinho
                        printf("\n-------- Produtos --------\n");
                        list_prod();
                        printf("\nSelecione os produtos por id: ");
                        scanf("%d", &id);
                        printf("\nDigite a quantidade: ");
                        scanf("%d", &qntd);
                        add_cart(id, qntd);
                        break;
                    case 2:
                        // lista os produtos
                        if (empty_())

                            list_prod();
                        break;
                    case 3:
                        // carrinho: lista o que foi adicionado ao carrinho, pode-se finalizar ou retornar ao menu
                        if (empty_2())
                        {
                            list_cart(qntd);

                            printf("\n0 - Finalizar\n1 - Voltar ao menu de compras\n");
                            printf("\n\nDigite a opção: \n\n");
                            scanf("%d", &op);

                            if (op == 0)
                            {
                                printf("\n-------- Compra Finalizada! :) --------\n");
                                // retorna ao menu e limpa a lista
                                exit_cart();
                                main();
                            }

                            else if (op == 1)
                            {
                                // volta ao submenu
                                returned();
                            }
                        }
                        break;
                    case 4: // devolve o produto selecionado a lista de produtos
                        if (empty_2())
                        {
                            list_cart(qntd);
                            printf("\nSelecione o código do produto : \n");
                            scanf("%d", &id);
                            take(id);
                        }
                        break;
                    case 5:
                        main();
                        printf("\n");
                    default:
                        break;
                    }
                }
            }

            break;
        case 6:
            if (empty_())
                printf("\nHá %d produtos cadastrados!\n\n", qtd_produtos(id));
            break;

        default:
            break;
        }
    }
    printf("/n");
    return 0;
}