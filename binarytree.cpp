#include<iostream>
#include<queue>
using namespace std;
template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
BinaryTreeNode<int>* TakeInputLevelwise(){
    // input -1 if you dont want to input data
    int NodeData;
    cout<<"Enter the root data: ";
    cin>>NodeData;
    if(NodeData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(NodeData);
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    while(pending.size()){
        int leftChild;
        BinaryTreeNode<int>* frontNode = pending.front();
        pending.pop();
        cout<<"Enter the left child of "<<frontNode->data<<": ";
        cin>>leftChild;
        BinaryTreeNode<int>* left = new BinaryTreeNode<int>(leftChild);

        if(leftChild != -1){
            frontNode->left = left;
            pending.push(left);
        }
        int rightChild;
        cout<<"Enter the right child of "<<frontNode->data<<": ";
        cin>>rightChild;
        BinaryTreeNode<int>* right = new BinaryTreeNode<int>(rightChild);
        if(rightChild != -1){
            frontNode->right = right;
            pending.push(right);
        } 
    }
    return root;
}
/* BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout<<"Enter the data: ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftchild = takeInput();
    BinaryTreeNode<int>* rightchild = takeInput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}
*/

void printData(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L"<<root->left->data<<", ";
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printData(root->left);
    printData(root->right);
}
int main(){
    BinaryTreeNode<int>* root = TakeInputLevelwise();
    printData(root);
}