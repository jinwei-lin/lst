# Linked List

A doubly linked list is implemented.

## Data Structure

### Linked-list node

```
struct lst_node {
        void *data;
        struct lst_node *prev,
                        *nxt;
};
```

- `data`: element stored in the linked-list node
- `prev`: pointer to the previous node
- `nxt`: pointer to the next node

### Element destructor

Destructor for the element in a linked-list node should be declared in accordance with the following function prototype.

```
typedef void (*dtor_t)(void*);
```

### Linked list

```
struct lst {
        size_t cnt;
        struct lst_node *head,
	                *tail;
        dtor_t dtor;
};
```

- `cnt`: number of nodes in the linked list
- `head`: pointer to the first node
- `tail`: pointer to the last node
- `dtor`: destructor for the element in a node

## Functions

```
void lst_init(struct lst *lst, dtor_t dtor);
```

Initialize a linked list.

```
void lst_psh_bk(struct lst *lst, void *data);
```

Add an element at the end of a linked list.

Memory space of the element to be added should be dynamically allocated.

```
void lst_insr(struct lst *lst, struct lst_node *pos, void *data);
```

Insert an element before the one pointed to by argument `pos` in a linked list.

```
struct lst_node* lst_del(struct lst *lst, struct lst_node *pos);
```

Delete an element from a linked list.

Pointer to the linked-list node following the deleted one is returned. If the last node is deleted, `NULL` is returned.

```
void lst_fnl(struct lst *lst);
```

Thoroughly clear a linked list, including all its elements.
