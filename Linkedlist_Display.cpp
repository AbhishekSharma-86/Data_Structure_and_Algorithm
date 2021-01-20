#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next=NULL;
    Node(int data){
        this->data=data;
    }
};
Node* input(){
    int data;
    cin>>data;
    Node* head=NULL;
    while(data != -1){
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
    cin>>data;
    }
    return head;
}

void print(Node *head){
    Node* temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main(){
    Node* head=input();
    print(head);
}