#include "lst.h"

void lst_init(struct lst *lst, dtor_t dtor) {
	lst->head = NULL;
	lst->tail = NULL;
	lst->cnt = 0;
	lst->dtor = dtor;
}

void lst_psh_bk(struct lst *lst, void *data) {
	struct lst_node *node = malloc(sizeof(struct lst_node)),
			*tail = lst->tail;

	node->data = data;
	node->nxt = NULL;
	if(tail == NULL) { // List is empty.
		node->prev = NULL;
		lst->head = node;
		lst->tail = node;
	} else {
		node->prev = tail;
		tail->nxt = node;
		lst->tail = node;
	}
	lst->cnt += 1;
}

void lst_insr(struct lst *lst, struct lst_node *pos, void *data) {
	struct lst_node *node = malloc(sizeof(struct lst_node)),
			*prev = pos->prev;

	node->data = data;
	node->prev = prev;
	node->nxt = pos;
	pos->prev = node;
	if(prev != NULL)
		prev->nxt = node;
	else // Element is inserted at the head.
		lst->head = node;
	lst->cnt += 1;
}

struct lst_node* lst_del(struct lst *lst, struct lst_node *pos) {
	struct lst_node *prev = pos->prev,
			*nxt = pos->nxt;

	if(prev != NULL)
		prev->nxt = nxt;
	else // Head element is deleted.
		lst->head = nxt;
	if(nxt != NULL)
		nxt->prev = prev;
	else // Tail element is deleted.
		lst->tail = prev;
	lst->dtor(pos->data);
	free(pos);
	lst->cnt -= 1;
	return nxt;
}

void lst_fnl(struct lst *lst) {
	struct lst_node *cur, *nxt;
	dtor_t dtor = lst->dtor;

	for(cur = lst->head; cur != NULL; cur = nxt) {
		nxt = cur->nxt;
		dtor(cur->data);
		free(cur);
	}
	memset(lst, 0, sizeof(struct lst));
}
