// #include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
}*first=NULL;

void create(int A[], int n){
    struct Node *t, *last;
    int i;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for (i=1;i=n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next=NULL;
        last->next;
        last=t;
    }
}
void Display(struct Node *p){
    while(p){
        printf("%d", p->data);
        p=p->next;
    }
}
int main(){
    int A[]={13,23,43,32,12};
    create(A,5);
    Display(first);

}

