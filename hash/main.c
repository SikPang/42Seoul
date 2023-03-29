#include "Hash.h"
#include "stdio.h"

void print_hash(hash* hash)
{
	printf("size: %lu, cap: %lu\n", hash->size, hash->capacity);
	for (unsigned long i = 0 ; i < hash->capacity; ++i)
	{
		switch (hash->bucket[i].state)
		{
		case 0:
			printf("[%lu] %s : %d, %lu (EMPTY)\n", i, hash->bucket[i].key, hash->bucket[i].value, hash->bucket[i].hash_result % hash->capacity);
			break;
		case 1:
			printf("[%lu] %s : %d, %lu (DELETED)\n", i, hash->bucket[i].key, hash->bucket[i].value, hash->bucket[i].hash_result % hash->capacity);
			break;
		case 2:
			printf("[%lu] %s : %d, %lu (USED)\n", i, hash->bucket[i].key, hash->bucket[i].value, hash->bucket[i].hash_result % hash->capacity);
			break;
		}
	}
	printf("\n");
}

int main()
{
	hash* hash = init_hash();

	printf("----- insert -----\n");
	insert_hash(hash, "hello world", 9);
	print_hash(hash);

	insert_hash(hash, "tyrret world", 2);
	print_hash(hash);

	insert_hash(hash, "aaaaa", 2);
	print_hash(hash);

	insert_hash(hash, "bbbbb", 2);
	print_hash(hash);

	insert_hash(hash, "ccccc", 3);
	print_hash(hash);

	insert_hash(hash, "ddddd", 4);
	print_hash(hash);

	insert_hash(hash, "---", 5);
	print_hash(hash);

	printf("\n----- find -----\n");
	int val;
	if (find_hash(hash, "ccccc", &val) != -1)
		printf("%d\n", val);
	else
		printf("not_found\n");

	if (find_hash(hash, "bbbbb", &val) != -1)
		printf("%d\n", val);
	else
		printf("not_found\n");

	if (find_hash(hash, "aaaaa", &val) != -1)
		printf("%d\n", val);
	else
		printf("not_found\n");

	if (find_hash(hash, "mmm", &val) != -1)
		printf("%d\n", val);
	else
		printf("not_found\n\n");

	printf("\n----- erase -----\n");
	erase_hash(hash, "mmm");
	print_hash(hash);

	erase_hash(hash, "aaaaa");
	print_hash(hash);

	erase_hash(hash, "ddddd");
	print_hash(hash);

	erase_hash(hash, "hello");
	print_hash(hash);

	erase_hash(hash, "ccccc");
	print_hash(hash);

	insert_hash(hash, "ccccc", 3);
	print_hash(hash);

	erase_hash(hash, "ccccc");
	print_hash(hash);

	erase_hash(hash, "tyrret world");
	print_hash(hash);

	erase_hash(hash, "bbbbb");
	print_hash(hash);

	erase_hash(hash, "hello world");
	print_hash(hash);

	erase_hash(hash, "---");
	print_hash(hash);

	printf("\n----- clear -----\n");
	clear_hash(hash);
	print_hash(hash);

	free(hash->bucket);
	free(hash);
}