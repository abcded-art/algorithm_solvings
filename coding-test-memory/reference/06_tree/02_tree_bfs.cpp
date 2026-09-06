#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};

    vector<vector<int>> levels;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // 현재 레벨의 노드 수를 먼저 고정한다.
        vector<int> level;

        while (levelSize--) {
            TreeNode* cur = q.front();
            q.pop();
            level.push_back(cur->val);

            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        levels.push_back(level);
    }
    return levels;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    for (const auto& level : levelOrder(root)) {
        for (int value : level) cout << value << ' ';
        cout << '\n';
    }

    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
}
