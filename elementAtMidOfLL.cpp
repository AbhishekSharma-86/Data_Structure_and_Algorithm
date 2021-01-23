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
Node* input(){
    int data;
    Node* head=NULL;
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
        cout<<"Enter y if you want to insert more nodes otherwise enter n: ";
        cin>>a;
    }
    return head;
}
void display(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }

}
void midElement(Node* head){
    Node* fast=head;
    Node* slow=head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow =slow->next;
        fast =fast->next->next;
    }
    cout<<"mid element is : "<<slow->data;
}

int main(){
    Node* head=input();
    display(head);
    midElement(head);
    return 0;
}

