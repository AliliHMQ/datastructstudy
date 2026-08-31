//二叉搜索树
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insertRec(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) node->left = insertRec(node->left, val);
        else if (val > node->val) node->right = insertRec(node->right, val);
        return node;
    }

    bool searchRec(TreeNode* node, int val) {
        if (!node) return false;
        if (val == node->val) return true;
        if (val < node->val) return searchRec(node->left, val);
        return searchRec(node->right, val);
    }

    void inorderRec(TreeNode* node) {
        if (!node) return;
        inorderRec(node->left);
        cout << node->val << " ";
        inorderRec(node->right);
    }

    void destroy(TreeNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroy(root); }

    void insert(int val) { root = insertRec(root, val); }
    bool search(int val) { return searchRec(root, val); }
    void printInorder() {
        inorderRec(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) bst.insert(x);

    cout << "中序遍历(升序): ";
    bst.printInorder(); // 20 30 40 50 60 70 80

    cout << "查找 40: " << (bst.search(40) ? "找到" : "未找到") << endl;
    cout << "查找 90: " << (bst.search(90) ? "找到" : "未找到") << endl;
    return 0;
}