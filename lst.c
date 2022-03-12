#include "lst.h"

void lst_init(struct lst *lst, dtor_t dtor) {
	lst->head = NULL;
	lst->cnt = 0;
	lst->dtor = dtor;
}

void lst_psh_bk(struct lst *lst, void *data) {
	struct lst_node *node = malloc(sizeof(struct lst_node)),
			*head = lst->head;

	node->data = data;
	if(head == NULL) {
		node->prev = node;
		node->nxt = node;
		lst->head = node;
	} else {
		node->prev = head->prev;
		node->nxt = head;
		head->prev->nxt = node;
		head->prev = node;
	}
	lst->cnt += 1;
}

void lst_insr(struct lst *lst, struct lst_node *pos, void *data) {
	struct lst_node *node = malloc(sizeof(struct lst_node));

	node->data = data;
	node->prev = pos->prev;
	node->nxt = pos;
	pos->prev->nxt = node;
	pos->prev = node;
	lst->cnt += 1;
	if(lst->head == pos)
		lst->head = node;
}
