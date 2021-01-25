#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for (int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(A[j]<A[i]){
                int a;
                a=A[j];
                A[j]=A[i];
                A[i]=a;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
}