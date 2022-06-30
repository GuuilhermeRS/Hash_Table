#pragma once

#include <stdio.h>
#include <stdlib.h>

#define TAM 17

typedef struct hash {
	int table[TAM];
	int size;
} s_hash;


s_hash* createTable();
int hashTransform(int key, int size);
void insert(s_hash* hash, int value);
int findElements(s_hash* hash, int wanted_value);
