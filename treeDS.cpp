#include<iostream>
#include<vector>
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
    int rootData;
    cout<<"Enter the data: ";
    cin>>rootData;
    treeNode* root = new treeNode(rootData);
    cout<<"Enter the number of children of "<<rootData<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        treeNode* child =  takeInput();
        root->children.push_back(child);

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


