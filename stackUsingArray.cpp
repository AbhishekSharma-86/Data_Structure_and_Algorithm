#include<iostream>
#include<climits>

using namespace std;
class Stack{
    int* data;
    int currentIndex;
    int capacity;

    public:
    Stack(int size){
        data= new int[size];
        currentIndex=0;
        capacity=size;
    }

    int top(){
        if(currentIndex==0){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        return data[currentIndex-1];
    }

    int size(){
        return currentIndex;
    }

    bool IsEmpty(){
        return currentIndex == 0;
    }

    int pop(){
        if(currentIndex==0){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        currentIndex--;
        return data[currentIndex];
    }
    void push(int entry){
        if(currentIndex < capacity){
            data[currentIndex]=entry;
            currentIndex++;
            }
        else{
            cout<<"stack is full"<<endl;
            return;
        }
    }
};


int main(){
    int size;
    cin>>size;
    Stack s(size);
    int element;
    char a='y';
    while(a == 'y'){
        cin>>element;
        s.push(element);
        cout<<"Do you want to insert more data y or n: ";
        cin>>a;
    }
    
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    
    cout<<s.size()<<endl;
    cout<<s.IsEmpty()<<endl;
    


}