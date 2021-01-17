#include<iostream>
#include <cstring>
using namespace std;
class Student{
    private:
    int RollNo;
    int StudentID;
    char *name;
    
    public:
    Student(int RollNo, int StudentID,char *name){
        //Deep copy
        this -> name = new char[strlen(name) + 1];
        strcpy(this->name,name);
        this -> RollNo = RollNo;
        this -> StudentID = StudentID;
    }
    void setRollNo(int r){
        RollNo= r;
    }
    void setStudentID(int id){
        StudentID = id;
    }
    int getRollNo(){
        return RollNo;
    }
    int getStudentID(){
        return StudentID;
    }
    string getName(){
        return name;
    }
    void Display(){
        cout<<"Roll No.: "<<getRollNo()<<endl;
        cout<<"Student ID : "<<getStudentID()<<endl;
        cout<<"Student name: "<<getName()<<endl;
    }
};


int main(){
    char name[]= "abhi";
    Student s1(12,11,name);
    s1.Display();
    name[3]= 'c';
    
    Student s2(122 , 111 , name);
    s2.Display();

    // Student * s2 = new Student(121, 113,a);
    // s2 -> Display();
    // s2 -> setRollNo(112);
    // s2 -> setStudentID(123);
    // s2 -> Display();
    // delete s2;
    return 0;
}