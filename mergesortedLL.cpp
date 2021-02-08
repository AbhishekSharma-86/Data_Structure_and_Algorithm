#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next=NULL;
    Node(int data){
        this->data=data;
    }
};



Node* insert(){
    Node* head=NULL;
    int data;
    char a='y';
    while(a=='y'){
        cin>>data;
        Node* n=new Node(data);
        if(head==NULL){
            head=n;
        }
        else{
            Node* t=head;
            while(t->next !=NULL){
                t=t->next;
            }
            t->next=n;
            
        }
        cout<<"Enter y to insert more node otherwise enter n: ";
        cin>>a;
    }
    return head;

}
Node* merge(Node* head1, Node* head2){
    Node* ft=NULL;
    Node* fh=NULL;
    Node* t=NULL;

    if(head1->data < head2->data){
        fh=head1;
        t=head1;
    }
    else{
        fh=head2;
        t=head2;
    }
    while(head1->next !=NULL && head2->next != NULL){
        if(head1->data < head2->data){
            ft=head1;
        }
    }

}


void Display(Node* head){

    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<", ";
        temp=temp->next;
    }
}
int main(){
    Node* head1= insert();
    Display(head1);
    cout<<endl;
    Node* head2=insert();
    Display(head2);
    Node* head = merge(head1,head2);
    Display(head);
    return 0;
}
