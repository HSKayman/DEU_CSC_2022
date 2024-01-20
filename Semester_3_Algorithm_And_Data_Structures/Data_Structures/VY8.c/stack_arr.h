#ifndef stack_arr
#define stack_arr
struct s{
	int size;
	int top;
	int * array;
};
typedef s stack;
stack * def();
int pop(stack *s);
void push(int,stack *s);
void print(stack *s);

#endif