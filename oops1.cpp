#include<iostream>
using namespace std;
class Student{
    private:
    int RollNo;
    int StudentID;
    
    public:
    Student(int RollNo, int StudentID){
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
    void Display(){
        cout<<"Roll No.: "<<getRollNo()<<endl;
        cout<<"Student ID : "<<getStudentID()<<endl;
    }
};


int main(){
    Student s1(12,11);
    s1.Display();
    Student * s2 = new Student(121, 113);
    s2 -> Display();
    s2 -> setRollNo(112);
    s2 -> setStudentID(123);
    s2 -> Display();
    delete s2;
    return 0;
}