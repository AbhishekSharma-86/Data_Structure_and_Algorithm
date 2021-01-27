#include<iostream>
using namespace std;
void merge(int A[],int l, int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];  ///temporary array 
    int b[n2];  ///temporary array 
    for(int i=0;i<n1;i++){
        a[i]=A[i+l];
    }
    for(int i=0;i<n2;i++){
        b[i]=A[i+mid+1];
    }
    int i=0;
    int j=0;
    int k;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            A[k]=a[i];
            k++;
            i++;

        }
        else{
            A[k]=b[j];
            k++;
            i++;
        }

    }
    while(i<n1){
        A[k]=a[i];
        k++;
        i++;
    }
    while(j<n2){
        A[k]=b[j];
        k++;
        j++;
    }
}
void mergeSort(int A[], int l, int r){
    if(l<r){
        int mid= (l+r)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,r);
        merge(A,l,mid,r);
    }
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
    mergeSort(A,0,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
    
}