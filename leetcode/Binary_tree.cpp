#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 144. Binary Tree Preorder Traversal
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class RecursiveSolution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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

    vector<int> inorderTraversal(TreeNode* root) {
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

    vector<int> postorderTraversal(TreeNode* root) {
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

//104. Maximum Depth of Binary Tree
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        else
            return (1+ max(maxDepth(root->left), maxDepth(root->right)));
    } 
    int maxDepth_iterative(TreeNode* root){
        queue<TreeNode *> qlist;
        int h = 0;
        if (!root)
            return 0;
        else {
            qlist.push(root);
        }
        while (!qlist.empty()){
            int count = qlist.size();
            for (int i = 0; i < count; i++){
                TreeNode *temp = qlist.front();
                if (temp->left)
                    qlist.push(temp->left);
                if (temp->right)
                    qlist.push(temp->right);
                qlist.pop();
            }
            h++;
        }
        return h;
    }

private:
    vector<int> printpreorder;
    vector<int> printinorder;
    vector<int> printpostorder; 

};

class IterativeSolution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*> S;
        vector<int> V;
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
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> V;
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

    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> V;
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


class Binary_Search_tree_Solution {
public:
//98. Validate Binary Search Tree
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return BSTcheck(root, LONG_MIN, LONG_MAX);
    }
    
    bool BSTcheck(TreeNode* p, long minv, long maxv){
        if (!p) return true;
        if (p->val > minv && p->val < maxv)
            return (BSTcheck(p->left, minv, p->val) && BSTcheck(p->right, p->val, maxv));
        else return false;
    }
};