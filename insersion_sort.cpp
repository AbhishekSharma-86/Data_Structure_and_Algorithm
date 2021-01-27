#include<iostream>
using namespace std;
void insersionSort(int A[],int n){
    for(int i=1; i<n;i++){
        int no=A[i];
        int j=i-1;
        while(j>=0 && A[j]>no){
                 A[j+1]=A[j];
                 j--;
            }
            A[j+1]=no;
    }
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    insersionSort(A,n);
    
    for (int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
}