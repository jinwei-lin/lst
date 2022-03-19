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
	struct lst_node *head,
			*tail;
	dtor_t dtor;
};

void lst_init(struct lst *lst, dtor_t dtor);
void lst_psh_bk(struct lst *lst, void *data);
void lst_insr(struct lst *lst, struct lst_node *pos, void *data);
struct lst_node* lst_del(struct lst *lst, struct lst_node *pos);

#endif
