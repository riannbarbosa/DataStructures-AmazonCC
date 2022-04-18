#ifndef STRUCTURES_H // diretivas
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>

struct product // Produtos
{
    int id;
    char name[61];
    float price;
    int qt_stock;
    struct product *next, *prev;
};

struct product *head = NULL;
struct product *tail = NULL;
struct product *cadastro;

typedef struct product Product;

struct cart // Carrinho
{
    int id_prod;
    char name[61];
    float price_cart;
    int stockid;
    struct cart *next, *prev;
};
// printf("\n%d, %s, %.2f, %d\n", aux_c->id_prod,aux_c->name, aux_c->price_cart, aux_c->stockid);
struct cart *head2 = NULL;
struct cart *tail2 = NULL;
struct cart *cart2;

typedef struct cart Cart;

#endif