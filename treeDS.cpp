#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class treeNode{
    public:
    int data;
    vector<treeNode*> children;

    treeNode(int data){
        this->data = data;
    }

};

treeNode* takeInput(){
    int data;
    cout<<"Enter the root data: ";
    cin>>data;
    treeNode* root  = new treeNode(data);
    queue<treeNode*> panding;
    panding.push(root);
    while(panding.size() != 0){
        treeNode* front = panding.front();
        panding.pop();
        int n;
        cout<<"Enter the number of childrens of "<<front->data<<": ";
        cin>>n;
        for(int i=0; i<n; i++){
            int a;
            cout<<"Enter the "<<i<<"th child of "<<front->data<<": ";
            cin>>a;
            treeNode* child = new treeNode(a);
            front->children.push_back(child);
            panding.push(child);
        }
    }
    return root;
}


void print(treeNode* root){
    cout<<root->data<<":";
    for(int i=0;i < root->children.size(); i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0 ; i<root->children.size() ; i++){
        print(root->children[i]);
    }
}


int main(){
    treeNode* root = takeInput();
    print(root);

}


