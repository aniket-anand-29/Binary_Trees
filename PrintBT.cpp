#include "BTN.h"

void printTree(BinaryTreeNode<int> * root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(q.size() != 0){
        BinaryTreeNode<int> * front = q.front();
        q.pop();
        
        cout << front->data << ":";

        if(front->left != NULL){
            cout << "L" << front->left->data;
            q.push(front->left);
        }

        if(front->right != NULL){
            cout << "R" << front->right->data;
            q.push(front->right);
        }
        cout << endl;
    }
}

int main(){
    BinaryTreeNode<int> * root = takeInput();
    printTree(root);
}