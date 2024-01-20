#ifndef queue_arr
#define queue_arr
typedef struct{
    int *array;
    int size;
    int scount;
    int count;
} arr;
arr *create(void);
void print(arr *);
int deque(arr *);
void enque(int ,arr *);
#endif

