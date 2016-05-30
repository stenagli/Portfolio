#include <stdio.h>
#include <limits.h>

/* function prototype */
int add(int i, int j);


int main(){
printf("%d\n",add(INT_MAX,1));
return 0;
}


int add(int i, int j){
return i+j;
}
