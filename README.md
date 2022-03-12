# Linked List

A doubly circular linked list is implemented.

## Data Structure

### Element destructor

Destructor for the element in a linked-list node should be declared in accordance with the following function prototype.

```
typedef void (*dtor_t)(void*);
```

### Linked list

```
struct lst {
        size_t cnt;
        struct lst_node *head;
        dtor_t dtor;
};
```

- `cnt`: number of nodes in the linked list
- `head`: pointer to the first node
- `dtor`: destructor for the element in a node
