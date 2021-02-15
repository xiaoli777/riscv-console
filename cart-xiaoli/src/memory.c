#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

#define die(...)                    \
do {                                \
	fprintf(stderr, ##__VA_ARGS__); \
	fprintf(stderr, "\n");          \
	exit(1);                        \
} while (0)

static inline void *xmalloc(int size)
{
	void *p = malloc(size);

	if (!p)
		die_perror("malloc");
	return p;
}