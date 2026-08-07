/*
 * Shared data-structure library (tree/queue/stack).
 * Algorithms and data structures (Data Structures).
 */
#ifndef stack_ll
#define stack_ll
typedef struct n{
	int data;
	struct n *next;

}node;
int pop(node **);
node * push(node *,int);
void print();
#endif