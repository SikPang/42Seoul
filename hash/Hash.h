#ifndef HASH_H
#define HASH_H

#define MAX_LOAD_FACTOR 0.5

#include <stdlib.h>
#include <string.h>

typedef enum state
{
	EMPTY,
	DELETED,
	USED
} state;

typedef struct data
{
	char*			key;
	int				value;
	state			state;
	unsigned long	hash_result;
} data;

typedef struct hash
{
	data*			bucket;
	unsigned long   size;
	unsigned long   capacity;
} hash;

hash* init_hash(void);
void resize_hash(hash* hash);
int find_hash(hash* hash, char* key, int* return_ref);
void erase_hash(hash* hash, char* key);
void insert_hash(hash* hash, char* key, int value);
void clear_hash(hash* hash);

#endif