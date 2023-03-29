/*
1. 키 : 문자열
2. Open addressing - linear probing
3. 해싱 함수 + 배열 크기 소수 (처음 크기, resizing 기준, resizing 크기)
*/

#include "Hash.h"

static long is_prime(int nb)
{
	long i = 2;

	while (i * i <= nb) 
	{
		if (nb % i == 0)
			return (0);
		++i;
	}
	
	return (i);
}

static unsigned long find_next_prime(int nb)
{
	while (1)
	{
		if (is_prime(nb))
			return (nb);
		++nb;
	}
}

static unsigned long get_hash(unsigned char *str)
{
    unsigned long hash = 5381;

    while (*str != '\0')
	{
        hash = ((hash << 5) + hash) + *str;	/* hash * 33 + c */
		++str;
	}
    return hash;
}

// initialize
hash* init_hash(void)
{
	hash* new;

	new = (hash*)malloc(sizeof(hash));
	if (new == NULL)
		return (NULL);
	new->capacity = 7;
	new->bucket = (data*)calloc(new->capacity, sizeof(data));
	new->size = 0;
	return new;
}

// resize
void resize_hash(hash* hash)
{
	unsigned long new_capacity = find_next_prime(hash->capacity * 2);
	data*         new_bucket = calloc(new_capacity, sizeof(data));

	for (unsigned long i = 0; i < hash->capacity; ++i)
	{
		if (hash->bucket[i].state != USED)
			continue;
		unsigned long idx = hash->bucket[i].hash_result;

		while (new_bucket[idx % new_capacity].state == USED)
		{
			if (strcmp(new_bucket[idx % new_capacity].key, hash->bucket[i].key) == 0)
				return;
			++idx;
		}

		new_bucket[idx % new_capacity] =
			(data){hash->bucket[i].key, hash->bucket[i].value, USED, hash->bucket[i].hash_result};
	}
	free(hash->bucket);
	hash->bucket = new_bucket;
	hash->capacity = new_capacity;
}

// insert
void insert_hash(hash* hash, char* key, int value)
{
	if ((double)hash->size / (double)hash->capacity > MAX_LOAD_FACTOR)
		resize_hash(hash);
	unsigned long result = get_hash((unsigned char*)key);
	unsigned long idx = result;

	while (hash->bucket[idx % hash->capacity].state == USED)
	{
		if (strcmp(hash->bucket[idx % hash->capacity].key, key) == 0)
			return;
		++idx;
	}

	hash->bucket[idx % hash->capacity] =
		(data){key, value, USED, result};
	++hash->size;
}

// erase
void erase_hash(hash* hash, char* key)
{
	int idx = find_hash(hash, key, NULL);
	if (idx < 0)
		return ;
	//free(hash->bucket[idx].key);
	hash->bucket[idx] = (data){NULL, 0, DELETED, 0};
	--hash->size;
}

// find
int find_hash(hash* hash, char* key, int* return_ref)
{
	unsigned long result = get_hash((unsigned char*)key);
	unsigned long idx = result;
	
	while (hash->bucket[idx % hash->capacity].state != EMPTY)
	{
		if (hash->bucket[idx % hash->capacity].state == USED
			&& strcmp(hash->bucket[idx % hash->capacity].key, key) == 0)
			break ;
		++idx;
		if (idx % hash->capacity == result % hash->capacity)
			return -1;
	}
	if (hash->bucket[idx % hash->capacity].state == EMPTY)
		return -1;
	if (return_ref != NULL)
		*return_ref = hash->bucket[idx % hash->capacity].value;
	return idx % hash->capacity;
}

void clear_hash(hash* hash)
{
	free(hash->bucket);
	
	hash->capacity = 7;
	hash->bucket = (data*)calloc(hash->capacity, sizeof(data));
	hash->size = 0;
}