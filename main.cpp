#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode *t = s.top();
        s.pop();
        pushAll(t->right);
        return t->val;
    }

    bool hasNext() {
        return !s.empty();
    }

private:
    void pushAll(TreeNode *node) {
        while(node != NULL) {
            s.push(node);
            node = node->left;
        }
    }
};

// Testing the BSTIterator
int main() {
    /*
            7
           / \
          3   15
              / \
             9  20
    */
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15, new TreeNode(9), new TreeNode(20));

    BSTIterator* obj = new BSTIterator(root);
    cout << "BSTIterator object address: " << obj << endl;
    
    while(obj->hasNext()) {
        cout << obj->next() << " ";
    }

    // Free memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
    delete obj;

    return 0;
}
