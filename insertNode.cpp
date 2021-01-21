#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next=NULL;
    Node(int data){
        this-> data= data;
    }
};
Node* input(){
    int data;
    Node * head=NULL;
    char a='y';
    
    while(a=='y'){
    cin>>data;
    Node* n=new Node(data);
    if(head==NULL){
        head=n;
    }
    else{
        Node* temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
    
    cout<<"Enter your choice, You wanna insert more data y/n:";
    cin>>a;
    }
    return head;
}
Node* insert(Node * head, int i, int value){
    int count;
    Node *n1=new Node(value);
    if (i==0)
    {
        n1->next=head;
        head=n1;
        return head;    
    }
    
    else{
        Node* t=head;
        Node*a;
        for (count=0;count<=i-1;count++){
        a=t;
        t=t->next;
        }
        a->next=n1;
        n1->next=t;

    }
    return head;
}

void Display(Node * head){
    Node * p=head;
    while(p!= NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    
}
int main(){
    Node* head=input();
    Display(head);
    int data;
    int i;
    cout<<endl;
    cout<<"Enter the data and the position :"<<endl;
    cin>>data;
    cin>>i;
    head=insert(head,i,data);
    Display(head);


}