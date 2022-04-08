#ifndef FUNCTIONS_H // diretivas
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#include "structures.h"

// Verifica se o elemento está no meio

Product *aloc(int id)
{

    Product *aux = tail;
    if (head != NULL)
        return aux;

    for (aux = tail; aux->prev != NULL; aux = aux->prev)
    {
        return aux->prev;
    }
    return NULL;
}

Product *search_id(int id)
{
    Product *aux;

    for (aux = head; aux != NULL; aux = aux->next)
    {
        if (aux->id == id)
        {
            printf("Código do produto já existe!\n");
            return aux;
        }
    }

    return NULL;
}

void regist()
{
    int id;

   
    // leitura dos dados
    do
    {
        printf("Codigo: ");
        scanf("%d", &id);
    } while (search_id(id));

    Product *cadastro = (Product *) malloc(sizeof(Product));

    printf("Nome: "); // codigo
    scanf("%s", cadastro->name);
    printf("Preco: "); // nome
    scanf("%f", &cadastro->price);
    printf("Quantidade em estoque: "); // preço de venda
    scanf("%d", &cadastro->qt_stock);  // quantidade
    printf("\n");
    cadastro->id = id;
    cadastro->next = NULL;
    cadastro->prev = NULL;

    if (head == NULL) // verifica se ele é o primeiro
    {
        head = cadastro;
        tail = head;

        // se for, head é igual o novo produto e tail = head
    }
    // encadeamento
    else
    {
        Product *aux = aloc(id);
        if (aux == NULL)
        {
            head->prev = cadastro;
            cadastro->next = head;
            cadastro->prev = NULL;
            head = cadastro;
        }
        else if (aux == tail)
        // tail
        {
            aux->next = cadastro;
            cadastro->prev = aux;
            cadastro->next = NULL;
            tail = cadastro;
        }
        else // meio
        {
            Product *auxiliar = aux->next;
            aux->next = cadastro;
            cadastro->prev = aux;
            cadastro->next = auxiliar;
            auxiliar->prev = cadastro;
        }
    }
}

// conta quantos produtos há cadastrado
int qtd_produtos(int id)
{
    Product *aux;
    int c = 0;
    for (aux = head; aux != NULL; aux = aux->next)
    {
        c++;
    }
    return c;
}

// faz uma busca na lista de produtos por meio do id
int search_(int id)
{
    Product *aux;
    printf("Digite o código do produto: ");

    scanf("%d", &id);
    for (aux = head; aux != NULL; aux = aux->next)
    {
        if (aux->id == id)
        {

            printf("\n%d, %s, %.2f, %d\n", aux->id, aux->name, aux->price, aux->qt_stock);
            return TRUE;
        }
    }

    printf("Produto não encontrado!\n");
    return FALSE;
}

// listar produtos
void list_prod()
{
    Product *aux;
    for (aux = head; aux != NULL; aux = aux->next)
    {
        printf("\n%d, %s, %.2f, %d\n", aux->id, aux->name, aux->price, aux->qt_stock);
    }
}

// verifica se a lista é vazia
// Se produto != lista -> produto não existe
// se lprod == NULL -> lista vazia

int empty_()
{
    if (head != NULL)
        return TRUE;
    printf("Não há produtos cadastrados!\n");
    return FALSE;
}

// deleta o elemento
Product *delete_(int id)
{
    Product *newaux;
    printf("Digite o código do produto para excluir: ");
    scanf("%d", &id);
    for (int i = qtd_produtos(id); i > 0; i--)
    {
        for (newaux = head; newaux != NULL; newaux = newaux->next)
        {
            if (id == newaux->id)
            {
                if (newaux == head)
                {
                    head = newaux->next;
                    if (head != NULL)
                        head->prev = NULL;
                }
                else if (newaux == tail)
                {
                    tail = newaux->prev;
                    tail->next = NULL;
                }
                else
                {
                    newaux->prev->next = newaux->next;
                    newaux->next->prev = newaux->prev;
                }
                free(newaux);
                break;
            }
        }
    }
}
// Sai do sistema e limpa a memória
void saida()
{
    Product *aux;
    aux = head;
    while (aux != NULL)
    {
        Product *prox = aux->next;
        free(aux);
        printf("*\n");
        aux = prox;
    }
}

// menu de opções
void menu()
{
    printf("1 - Cadastrar Produto\n2 - Listar\n3 - Buscar\n4 - Excluir Produto \n5 - Comprar Produto\n6 - Quantidade de Produtos\n0 - Sair\n ");
}

/* int id_equal(Product *head, int id)
{
    Product *aux;
    if (head != NULL)
    {
        for (aux = head; aux != NULL; aux = aux->next)
        {
            if (aux->id == id)
            {
                printf("Produto ou código do produto existente!, por favor, tente outro\n");
                return TRUE;
            }
        }

        return FALSE;
    }
} */

#endif