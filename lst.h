#ifndef LST_H
#define LST_H

#include <stdlib.h>

typedef void (*dtor_t)(void*);

struct lst_node {
	void *data;
	struct lst_node *prev,
			*nxt;
};

struct lst {
	size_t cnt;
	struct lst_node *head;
	dtor_t dtor;
};

#endif
