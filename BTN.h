#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode * left;
    BinaryTreeNode * right;

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

BinaryTreeNode<int> * takeInput(){
    int rootData;
    cout << "Enter root data" <<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data <<endl;
        int leftchildData;
        cin >> leftchildData;
        if(leftchildData != -1){
            BinaryTreeNode<int> * child = new BinaryTreeNode<int>(leftchildData);
            front->left = child;
            pendingNodes.push(child);
        } 

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int> * child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }

    }
    return root;

}

void printBinaryTree(BinaryTreeNode<int> * root){
    if(root == NULL){
        return;
    }

    cout << root->data << ":";

    if(root->left != NULL){
        cout << "L" << root->left->data;
    }

    if(root->right != NULL){
        cout << "R" << root->right->data;
    }
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

void printTreeLevelWise(BinaryTreeNode<int> * root){
    if(root == NULL){
        return;
    }
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){

        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << ":";
        
        if(front->left != NULL){
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }

        if(front->right != NULL){
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}
