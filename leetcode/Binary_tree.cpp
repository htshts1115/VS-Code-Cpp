#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

// 144. Binary Tree Preorder Traversal
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if (root!=NULL){
            preorder(root);
        }
        return printpreorder;
    }
    void preorder(TreeNode* root){
        if (!root) return;
        printpreorder.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        if (root!=NULL){
            inorder(root);
        }
        return printinorder;
    }
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        printinorder.push_back(root->val);
        inorder(root->right);
    }

    std::vector<int> postorderTraversal(TreeNode* root) {
        if (root!=NULL){
            postorder(root);
        }
        return printpostorder;
    }
    void postorder(TreeNode* root){
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        printpostorder.push_back(root->val);
    }

private:
    std::vector<int> printpreorder;
    std::vector<int> printinorder;
    std::vector<int> printpostorder; 
};

class IterativeSolution{
public:
    std::vector<int> preorderTraversal(TreeNode* root){
        std::stack<TreeNode*> S;
        std::vector<int> V;
        TreeNode* p = root;
        while (p || S.size()) {
            while (p) {
                V.push_back(p->val);    //visit root node
                S.push(p->right);       //stack right
                p = p->left;            //point to left
            }
            p = S.top();                //left is over, turn to right
            S.pop();
        }
        return V;
    }
    
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> S;
        std::vector<int> V;
        TreeNode* p = root;
        while (p || S.size()) {
            while (p) {
                S.push(p);
                p = p->left;
            }
            p = S.top();
            V.push_back(p->val);
            S.pop();
            p = p->right;
        }
        return V;
    }

    std::vector<int> postorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> S;
        std::vector<int> V;
        TreeNode* p = root;
        TreeNode* last = NULL;
        while (p || S.size()) {
            while (p) {
                S.push(p);
                p = p->left;
            }
            p = S.top();
            if (p->right == NULL || p->right == last){
                V.push_back(p->val);
                last = p;
                S.pop();
                p = NULL;
            }
            else {
                p = p->right;
            }
        }
        return V;
    }
};