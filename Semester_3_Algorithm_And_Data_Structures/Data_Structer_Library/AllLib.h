#ifndef AllLib
#define AllLib
typedef struct s{
	struct s *left,*right;
	int x;
}tree;
tree *create(int );
tree *input(tree *,int );
void traversal(tree *);
int max(tree *);
int min(tree *);
bool find(tree *,int);
tree *delete(tree *,int );
typedef struct n{
	int data;
	struct n *next;
}que;
void printq(que *);
que * enque(que *, int );
int deque(que **);
typedef struct m{
	int data;
	struct m *next;
}node;
void print(node *);
node * push(node *,int );
int pop(node **);
#endif
