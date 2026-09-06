#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 자식이 계산한 값을 부모가 받아 사용하는 대표적인 Tree DFS 패턴이다.
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);

    cout << maxDepth(root) << '\n';

    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
}
