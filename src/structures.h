#ifndef STRUCTURES_H //diretivas
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
    int qt_buy;
    struct product *next, *prev;
};
typedef struct cart Cart;   

#endif