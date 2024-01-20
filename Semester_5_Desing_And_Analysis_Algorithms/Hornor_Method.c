#include<stdio.h>
int horner(int A[], int n, int x) 
{ 
    int result = A[0],i; 
    for (i=1; i<n; -++i) 
        result = result*x + A[i]; 
    return result; 
} 
int main(){
    int A[] = {2, -6, 2, -1},x = 3; 
    printf("%d ",horner(A,4,3));
}