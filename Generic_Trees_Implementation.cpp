#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* firstChild;
    TreeNode* nextSibling;

    TreeNode(int val){
        value=val;
        firstChild=nullptr;
        nextSibling=nullptr;
    }
};

//This is how we can treat any generic tree as a binary tree now