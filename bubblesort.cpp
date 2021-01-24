#include<iostream>
using namespace std;

int BubbleSort(int a[], int n){
    int c=0;            //to count the swapping
    for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < n - 1; j++) {
        // Swap adjacent elements if they are in decreasing order
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            c++;
        }
    }
    
}
return c;

}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n ; i++){
        cin>>A[i];
    }
    int count=BubbleSort(A, n);
    cout<<"Array is sorted in "<<count<<" swaps."<<endl;
    cout<<"First Element: "<<A[0]<<endl;
    cout<<"Last Element: "<<A[n-1]<<endl;
    return 0;
}