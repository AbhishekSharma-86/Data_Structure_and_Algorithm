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
void printlevelwise(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left != NULL){
        cout<<"L"<<root->left->data<<", ";
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data<<endl;
    }
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);

    while(pending.size()){
        BinaryTreeNode<int>* front = pending.front();
        pending.pop();
        if(front->left){
            cout<<front->left->data<<":";
            if(front->left->left != NULL){
                cout<<"L"<<front->left->left->data<<", ";

            }
            if(front->left->right != NULL){
                cout<<"R"<<front->left->right->data<<endl;
            }
            pending.push(front->left);
        }
        if(front->right){
            cout<<front->right->data<<":";
            if(front->right->left != NULL){
                cout<<"L"<<front->right->left->data<<", ";
            }
            if(front->right->right != NULL){
                cout<<"R"<<front->right->right->data<<endl;

            }
            pending.push(front->right);
        }
    }
}


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

void inorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
BinaryTreeNode<int>* helpbuildTree(int* in, int* pre, int InS, int InE, int preS, int preE ){
    if(InS > InE){
        return NULL;
    }
    int rootData = pre[preS];
    int rootindex = -1;
    for(int i = InS ;i<=InE; i++){
        if(in[i] == rootData){
            rootindex=i;
            break;
        }
    }
    int lInS = InS;
    int lInE = rootindex-1;
    int lpreS = preS + 1;
    int lpreE = lInE-lInS+lpreS;
    int rInS = rootindex+1;
    int rInE = InE;
    int rpreS = lpreE+1;
    int rpreE = preE;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = helpbuildTree(in, pre, lInS, lInE, lpreS, lpreE);
    root->right = helpbuildTree(in, pre, rInS, rInE, rpreS, rpreE);
    return root;

}
BinaryTreeNode<int>* buildTree(int* in, int* pre, int size){
    return helpbuildTree(in, pre, 0, size-1, 0, size-1);
} 

int numNode(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1+numNode(root->left)+numNode(root->right);
}
int main(){
    int in[] = {4,2,5,1,8,6,9,3,7};
    int pre[] = {1,2,4,5,3,6,8,9,7};

    BinaryTreeNode<int>* root = buildTree(in, pre, 9);
    printlevelwise(root);
    delete root;

    /*
    BinaryTreeNode<int>* root = TakeInputLevelwise();
    printlevelwise(root);
    cout<<"The Number of Nodes: "<<numNode(root)<<endl;
    inorder(root);
    delete root;
    */
}