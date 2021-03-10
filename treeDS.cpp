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

void print(treeNode* root){
    cout<<root->data<<endl;
    for(int i=0;i < root->children.size(); i++){
        print(root->children[i]);
    }
}


int main(){
    treeNode* root = new treeNode(10);
    treeNode* Node1 = new treeNode(20);
    treeNode* Node2 = new treeNode(30);
    root->children.push_back(Node1);
    root->children.push_back(Node2);
    print(root);

}


