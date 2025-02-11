#include <bits/stdc++.h>
using namespace std;

// below is the structure of a binary tree and then we will define functions based ont this structure

struct TreeNode{
int value;
struct TreeNode* left;
struct TreeNode* right;

// below is the constructor of the structure to initialize the node with a value

TreeNode(int val){
    value=val;
    right=nullptr;
    left=nullptr;
    }
};

// printing the binary tree using inorder traversal

void printBinaryTree_inorder(struct TreeNode* root){
    if(root==nullptr) return;
    printBinaryTree_inorder(root->left);
    cout<<" "<<root->value<<" ";
    printBinaryTree_inorder(root->right);
}
void printBinaryTree_preorder(struct TreeNode* root){
    if(root==nullptr) return;
    cout<<" "<<root->value<<" ";
    printBinaryTree_preorder(root->left);
    printBinaryTree_preorder(root->right);
}
void printBinaryTree_postorder(struct TreeNode* root){
    if(root==nullptr) return;
    printBinaryTree_postorder(root->left);
    printBinaryTree_postorder(root->right);
    cout<<" "<<root->value<<" ";
}

//below is the code for non recursive preorder traversal.You can do the same for inorder and postorder traversals. This code uses stacks.

void preorder_nonrecursive(TreeNode* root){
    if(root==nullptr) return;
    stack<TreeNode*> s;
    s.push(root);
    
    while(!s.empty()){
        TreeNode* curr=s.top();
        s.pop();
        cout<<" "<< curr->value <<" ";
        if(curr->right!=nullptr){
            s.push(curr->right);
        }
        if(curr->left!=nullptr){
            s.push(curr->left);
        }

    }
}

    void levelOrderTraversal(TreeNode* root){
        if(root==nullptr) return;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            cout<<" "<<curr->value<<" ";

            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }
        }
    }

    void insert_key_level_order(TreeNode* root, int key){
        if(root==nullptr){
            cout<<"empty tree!!";
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr=q.front();

        while(curr->left!=nullptr and curr->right!=nullptr){
            q.pop();
            q.push(curr->left);
            q.push(curr->right);
            curr=q.front();
        }
        if(curr->left==nullptr) curr->left=new TreeNode(key);
        else if(curr->right==nullptr) curr->right=new TreeNode(key);
    }


int main(){
    struct  TreeNode* root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    
    // printBinaryTree_inorder(root);
    // cout<<endl;
    // printBinaryTree_preorder(root);
    // cout<<endl;
    // printBinaryTree_postorder(root);
    // cout<<endl;
    // preorder_nonrecursive(root);
    // cout<<endl;
    // levelOrderTraversal(root);

    // insert_key_level_order(root,8);
    // insert_key_level_order(root,9);
    // insert_key_level_order(root,10);
    // levelOrderTraversal(root);
    
}
