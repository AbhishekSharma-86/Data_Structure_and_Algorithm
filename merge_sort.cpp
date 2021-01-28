#include<iostream>
using namespace std;
void merge(int A[], int l, int r){
    int mid=(l+r)/2;
    int i=l;
    int j=mid+1;
    int k=l;
    int temp[50];
    while (i<=mid && j<=r)
    {
        if(A[i]<A[j]){
            temp[k]=A[i];
            k++;
            i++;
        }
        else{
            temp[k]=A[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k]=A[i];
        k++;
        i++;
    }
    while(j<=r){
        temp[k]=A[j];
        k++;
        j++;
    }
    for(int n=l;n<=r;n++){
        A[n]=temp[n];
    }
    
    

}
void mergeSort(int A[], int l, int r){
    int mid;
    if (l<r){
        mid=(l+r)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,r);
        merge(A,l,r);
    }
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    mergeSort(A,0,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" , ";
    }
}