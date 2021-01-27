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
        int minIndex=i;     //assume min index is ith 
        for(int j=i+1;j<n;j++){
            if(A[j]<A[i]){
                minIndex=j;
            }
        }
        swap(A[i],A[minIndex]);
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
}