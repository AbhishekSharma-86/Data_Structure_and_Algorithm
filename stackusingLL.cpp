#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
    }
};
class Stack{
    Node* head;
    int count=0;

    public:
    void push(int element){
        if(head==NULL){
            Node* n = new Node(element);
            head=n;
            count++;
        }
        else{
            Node* n = new Node(element);
            
            n->next=head;
            head=n;
            count++;
        }
    }
    int pop(){
        int a;
        Node* temp=NULL;
        if(head==NULL){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        else{
            a = head->data;
            temp=head;
            head = head->next;
            delete temp;
            count--;
            return a;
           
        }
    }
    int top(){
        if(head==NULL){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        else{
            return head->data;
        }
    }
    int size(){
        return count;
    }
    bool IsEmpty(){
        return !count;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.IsEmpty()<<endl;
    cout<<s.size()<<endl;

}