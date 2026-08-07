/*
 * Shared data-structure library (tree/queue/stack).
 * Algorithms and data structures (Data Structures).
 */
#ifndef queu_ll
#define queu_ll
typedef struct n{
	int data;
	struct n *next;
}node;
void print(node *);
int deque(node **);
node *enque(int,node*);
#endif