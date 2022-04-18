// para evitar que o header seja chamado duas vezes, evitando erro
#ifndef FUNCTIONS_H // diretivas
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define true e false
#define TRUE 1
#define FALSE 0
// puxa as estruturas utilizadas
#include "structures.h"

// verifica se há id na lista de Produtos
Product *search_id(int id)
{
  Product *aux;

  for (aux = head; aux != NULL; aux = aux->next)
  {
    if (aux->id == id)
    {
      return aux; // retorna o id
    }
  }

  return NULL;
}

// usado para fazer do while, verifica id igual
Product *search_id2(int id)
{
  Product *aux;
  for (aux = head; aux != NULL; aux = aux->next)
  {
    if (aux->id == id)
    {
      printf("\n---- Código já cadastrado! ----\n\n");
      return aux;
    }
  }
  return NULL;
}

// cadastro de produtos
void regist()
{
  int id, qntd;
  // leitura dos dados
  do
  {
    printf("Codigo: ");
    scanf("%d", &id);
  } while (search_id2(id));

  Product *cadastro = (Product *)malloc(sizeof(Product));

  printf("Nome: "); // codigo
  scanf("%s", cadastro->name);
  printf("Preco: "); // nome
  scanf("%f", &cadastro->price);
  if (cadastro->price < 0)
  {
    printf("\nPor favor digite um preço válido!\n");
    return;
  }
  printf("Quantidade em estoque: "); // preço de venda
  scanf("%d", &qntd);                // quantidade
  if (qntd <= 0)
  {
    printf("\nPor favor coloque um número de estoque válido!\n");
    return;
  }
  printf("\n");
  cadastro->id = id;
  cadastro->qt_stock = qntd;
  cadastro->next = NULL;
  cadastro->prev = NULL;

  if (head == NULL) // verifica se ele é o primeiro
  {
    head = cadastro;
    tail = head;

    // se for, head é igual o novo produto e tail = head
  }
  // "encadeamento"
  else
  {
    cadastro->prev = tail;
    tail->next = cadastro;
    tail = cadastro;
  }
  printf("\n--- Produto '%s' cadastrado com sucesso! ---\n", cadastro->name);
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
// realiza a busca do produto utilizando o id.
int search_(int id)
{
  Product *aux;
  printf("Digite o código do produto: ");
  scanf("%d", &id);
  for (aux = head; aux != NULL; aux = aux->next)
  {
    if (aux->id == id)
    {

      printf("\nCódigo: %d\nNome:%s\nPreço:%.2f\nEstoque:%d\n", aux->id, aux->name, aux->price, aux->qt_stock);
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
    printf("\nCódigo: %d\nNome: %s\nPreço: %.2f\nEstoque: %d\n", aux->id, aux->name, aux->price, aux->qt_stock);
  }
}

// verifica se a lista produtos é vazia
int empty_()
{
  if (head != NULL)
    return TRUE;
  printf("\n---- Não há produtos cadastrados! ---- \n");
  return FALSE;
}
// verifica a lista do carrinho
int empty_2()
{
  if (head2 != NULL)
    return TRUE;
  printf("\n---- Não há produtos cadastrados! ----\n");
  return FALSE;
}

// deleta o elemento
Product *delete_(int id)
{
  Product *aux = search_id(id);

  if (aux != NULL)
  {

    if (aux == head)
    {
      head = aux->next;

      if (head != NULL)
        head->prev = NULL;
    }
    else if (aux == tail)
    {
      aux->prev->next = NULL;
      tail = aux->prev;
    }
    else
    {
      aux->prev->next = aux->next;
      aux->next->prev = aux->prev;
    }
    printf("Produto '%s' excluído!\n", aux->name);
    free(aux);
  }
  else
  {
    for (aux = head; aux != NULL; aux = aux->next)
    {
      if (aux->id != id)
      {
        printf("Produto não existente!\n");
        return aux;
      }
      return NULL;
    }
  }
  return NULL;
}

// Sai do programa e limpa a memória
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

// realiza a busca de produtos no carrinho
Cart *search_cart(int id)
{
  Cart *aux; // printf("Digite o código do produto: ");
  // scanf("%d", &id);
  for (aux = head2; aux != NULL; aux = aux->next)
  {
    if (aux->id_prod == id)
    {
      return aux;
    }
  }

  return NULL;
}

// calcula o stock do produto
int stock_prod(int id, int qntd)
{
  Product *aux;
  for (aux = head; aux != NULL; aux = aux->next)
  {
    if (id == aux->id && aux->qt_stock >= qntd && (aux->qt_stock - qntd) >= 0)
    {
      // decrementa
      aux->qt_stock -= qntd;
      return TRUE;
    }
  }
  return FALSE;
}
// calcula o stock do carrinho
int stock_cart(int id, int qntd)
{
  Cart *aux;
  for (aux = head2; aux != NULL; aux = aux->next)
  {
    if (id == aux->id_prod && (aux->stockid + qntd) >= 0)
    {
      aux->stockid += qntd;
      return TRUE;
    }
  }
  return FALSE;
}

// realiza encadeamonto do carrinho
void Cartstructure(int id, char name[61], float price, int qntd)
{

  Cart *cart2 = malloc(sizeof(Cart));

  cart2->id_prod = id;
  strcpy(cart2->name, name);
  cart2->price_cart = price;
  cart2->stockid = qntd;
  cart2->next = NULL;
  cart2->prev = NULL;
  if (head2 == NULL) // verifica se ele é o primeiro
  {
    head2 = cart2;
    tail2 = head2;
    // se for, head é igual o novo produto e tail = head
  }
  // encadeamento
  else
  {
    cart2->prev = tail2;
    tail2->next = cart2;
    tail2 = cart2;
  }
}

// adiciona o produto da lista Produtos, na lista Carrinho
void add_cart(int id, int qntd)
{

  Product *aux;
  for (aux = head; aux != NULL; aux = aux->next)
  {
    if (aux->id == id)
    {
      if (stock_prod(id, qntd))
      {
        Cartstructure(aux->id, aux->name, aux->price, aux->qt_stock);
        printf("\nProduto '%s' adicionado ao carrinho!\n", aux->name);
        if (aux->qt_stock <= 0)
        {
          printf("\nProduto Esgotado :(\n");
        }

        if (stock_cart(id, qntd))
        {
          return;
        }
      }
    }
    else
    {
      printf("\nProduto não encontrado\n");
    }
  }
}

// deleta produto do carrinho
Cart *delete_c(int id)
{

  Cart *aux = search_cart(id);

  if (aux != NULL)
  {

    if (aux == head2)
    {
      head2 = aux->next;

      if (head2 != NULL)
        head2->prev = NULL;
    }
    else if (aux == tail2)
    {
      aux->prev->next = NULL;
      tail2 = aux->prev;
    }
    else
    {
      aux->prev->next = aux->next;
      aux->next->prev = aux->prev;
    }
    printf("\nDevolução do produto '%s' concluída!\n", aux->name);
    free(aux);
  }
  else
  {
    for (aux = head2; aux != NULL; aux = aux->next)
    {
      if (aux->id_prod != id)
      {
        printf("Produto não existente!\n");
        return aux;
      }
      return NULL;
    }
  }
  return NULL;
}
// finaliza o carrinho e reseta
void exit_cart()
{
  Cart *aux = head2;
  while (aux != NULL)
  {
    aux = aux->next;
    free(head2);
    head2 = aux;
  }
}

// lista os produtos presentes no carrinho
void list_cart(int qntd)
{
  float total = 0;
  Cart *aux;

  for (aux = head2; aux != NULL; aux = aux->next)
  {

    total += (aux->price_cart * qntd);

    printf("\nCódigo: %d\nNome: %s\nPreço: %.2f\nEstoque: %d\n", aux->id_prod, aux->name, aux->price_cart, aux->stockid);
  }
  printf("\nTotal: %.2f\n", total);
}

// verifica se o carrinho está vazio
int empty_cart()
{
  if (head2 != NULL)
    return TRUE;
  printf("Não há produtos cadastrados no carrinho!\n");
  return FALSE;
}

// seleciona o id a ser devolvido
void take(int id)
{
  Cart *aux2 = search_cart(id);

  if (aux2)
  {
    Product *stock = search_id(id);
    stock->qt_stock += aux2->stockid;
    delete_c(id);
  }
}

// retorna o menu referente a compras
int returned()
{
  return 0;
}

// chama o menu
void menu()
{
  printf("\n---- Bem Vindo(a) ----\n");
  printf("\n1 - Cadastrar Produto\n2 - Listar\n3 - Buscar\n5 - Comprar Produtos\n4 - Excluir Produto\n6 - Quantidade de Produtos\n0 - Sair\n ");
}
// do carrinho: estoque, valor total
#endif