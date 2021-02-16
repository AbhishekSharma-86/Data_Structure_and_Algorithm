#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
    
};
class Queue{
    Node* head;
    Node* tail;
    int size;


    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void enQueue(int element){
        if(head == NULL){
            Node * que = new Node(element);
            head = que;
            tail = que;
            size++;
        }
        else{
            Node * que = new Node(element);
            tail->next = que;
            tail = que;
            size++;
        }
    }
    int deQueue(){
        if(size == 0){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        else{
            int ans = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return ans;
        }
    }
    int Size(){
        return size;
    }
    bool isEmpty(){
        return !size;
    }
    int front(){
        if(size == 0){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        else{
            return head->data;
        }
    }
};
int main(){
    Queue q1;
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);
    cout<<q1.front()<<endl;
    cout<<q1.deQueue()<<endl;
    cout<<q1.deQueue()<<endl;
    cout<<q1.Size()<<endl;
    cout<<q1.isEmpty()<<endl;

    

}