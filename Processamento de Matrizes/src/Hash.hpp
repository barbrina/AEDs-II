#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Matriz.hpp"

#define hash(v, M) (v % M)

typedef struct DataTable DataTable;
typedef struct HashTable HasTable;

struct DataTable
{
    int *key;
    bool data;
    int LIN;
    Data **m;
};

struct HashTable
{
    DataTable *table;
    int M;
};

void initialize(HashTable *h, int M);
void imprime(HashTable *h);
void insert(HashTable *h, int key[4], int idx, Data **matriz, int LIN);
bool search(HashTable *h, int *key);
int primo(int x);
int proxprimo(int x);

#endif