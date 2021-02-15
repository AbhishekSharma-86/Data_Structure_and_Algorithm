#include<iostream>
using namespace std;

class Queue{
    int * que;
    int capacity;
    int currentIndex;
    
    public:
    Queue(){
        capacity = 4;
        que = new int[capacity];
        currentIndex = 0;
    }

    void enQueue(int element){
        if(currentIndex == capacity){
            int * newQue = new int[capacity*2];
            for(int i=0; i<capacity; i++){
                newQue[i] = que[i];
            }
            capacity *= 2;
            delete que;
            que = newQue;
            que[currentIndex] = element;
            currentIndex++; 
        }
        else{
            que[currentIndex] = element;
            currentIndex++;
        }
    }
    int deQueue(){
        if(currentIndex == 0){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        else{
            int ans = que[0];
            for(int i=0; i<currentIndex; i++){
                que[i] = que[i+1];
            }
            currentIndex--;
            return ans;
        }
    }
    bool isEmpty(){
        return !currentIndex;
    }
    int size(){
        return currentIndex;
    }
};


int main(){
    Queue q1;
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);
    q1.enQueue(50);
    cout<<q1.deQueue()<<endl;
    cout<<q1.deQueue()<<endl;
    cout<<q1.deQueue()<<endl;
    cout<<q1.deQueue()<<endl;
    cout<<q1.deQueue()<<endl;
    cout<<q1.isEmpty()<<endl;
    cout<<q1.size()<<endl;


}