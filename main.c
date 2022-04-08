#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "./src/functions.h"

int main()
{
    int n, id;

    //  0 - Sair, 1 - Cadastro, 2- Listar, 3- Buscar, 4- Excluir, 5 -Comprar, 6 - contar

    while (TRUE)
    {
        menu();
        printf("\nDigite a opcao desejada: ");

        scanf("%d", &n);

        switch (n)
        {
        case 0:
            saida();
            exit(1);
            break;
        case 1:
                 regist();

            break;
        case 2:
            // listar
            if (empty_())
                list_prod();
            break;
        case 3:
            // buscar
            if (empty_())
                search_(id);
            break;
        case 4:
            if (empty_())
            {
                delete_(id);
            }
            break;
        case 5:
            break;
        case 6:
            if (empty_())
                printf("Há %d produtos cadastrados!\n", qtd_produtos(id));
            break;

        default:
            break;
        }
    }
    printf("/n");
    return 0;
}