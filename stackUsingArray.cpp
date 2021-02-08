#include<iostream>
#include<climits>

using namespace std;
class Stack{
    int* data;
    int currentIndex;
    int capacity;

    public:
    Stack(){
        data= new int[4];
        currentIndex=0;
        capacity=4;
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
            int* newdata = new int[capacity*2];
            capacity *= 2;
            delete []data;
            data = newdata;
        }
    }
};


int main(){
    Stack s;
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
    cout<<s.pop()<<endl;
    
    cout<<s.size()<<endl;
    cout<<s.IsEmpty()<<endl;
    


}