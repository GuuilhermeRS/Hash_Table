#include "Header.h"

int main() {
	s_hash* hash = createTable();
	int i, find, value = 34;

	insert(hash, 5);
	insert(hash, 32);
	insert(hash, 34);
	insert(hash, 35);

	for (int i = 0; i < TAM; i++) {
		printf("%d: %d\n", i, hash->table[i]);
	}

	find = findElements(hash, value);
	if (find != -1) printf("Valor: %d encontrado na tabela hash na posicao: %d\n", value, find);
	else printf("Valor: %d nao encontrado na tabela hash!\n", value);


	return 0;
}


s_hash* createTable() {
	s_hash* hash_table = (s_hash*)malloc(sizeof(s_hash));
	if (!hash_table) {
		printf("Error: Could not allocate memory!\n");
		exit(1);
	}

	hash_table->size = TAM;

	for (int i = 0; i < TAM; i++) {
		hash_table->table[i] = 0;
	}

	return hash_table;
}

int hashTransform(int key, int size) {
	int hash = key % size;

	return hash;
}

void insert(s_hash* hash, int value) {
	int hash_position = hashTransform(value, hash->size);
	hash->table[hash_position] = value;
}

int findElements(s_hash* hash, int wanted_value) {
	int hash_position = hashTransform(wanted_value, hash->size);

	if (wanted_value == hash->table[hash_position]) return hash_position;
	else return -1;
}

