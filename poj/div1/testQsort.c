#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INTSIZE 6
#define TREESIZE 4
#define DICTSIZE 4
//the forth parameter in qsort is compar, and the parameters of
//compar is void pointer, we should change the type of the void
//pointer to the type of data that we want to compare with.
int cmpstr(const void *a, const void *b){
     return strcmp((char*)a,(char*)b) ;
}
int cmpint(const void *pa, const void *pb){
    int *p1 = (int*)pa;
    int *p2 = (int*)pb;
    return *p1 - *p2;
}
typedef struct Node{
    int iter;
    int parent;
    int lchild;
}Node;
int cmpnode(const void *pa, const void *pb){
    Node *p1 = (Node*)pa;
    Node *p2 = (Node*)pb;
    return p1->parent - p2->parent;
}
int main(){
    char chDict[DICTSIZE][7];
    int intArr[INTSIZE] = {5,4,3,2,1,0};
    Node tree[TREESIZE] = {{1,1,2}, {2,2,3}, {3,6,5},{4,0,3}};
    int iter;
    for(iter = 0; iter < DICTSIZE; ++iter){
        scanf("%6s",chDict[iter]);
    }
	//qsort(chArr,sizeof(chArr)/sizeof(chArr[0]),sizeof(chArr[0]),cmpstr);
    qsort(&chDict[0], sizeof(chDict)/sizeof(chDict[0]), sizeof(chDict[0]), cmpstr);
    qsort(&intArr[0], sizeof(intArr)/sizeof(intArr[0]),sizeof(intArr[0]),cmpint);
    qsort(&tree[0], sizeof(tree)/sizeof(tree[0]), sizeof(tree[0]), cmpnode);
    for(iter = 0; iter < TREESIZE; ++iter)
        printf("%d:%d\n",tree[iter].iter,tree[iter].parent);
    return 0;
}
