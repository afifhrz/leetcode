#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//TreeNode* buildTree(vector<string>& nodes) {
//    if (nodes.empty() || nodes[0] == "null") {
//        return nullptr;
//    }
//    
//	TreeNode* root = new TreeNode(stoi(nodes[0]));
//    queue<TreeNode*> q;
//	q.push(root);
//	int i = 1;
//
//    while (!q.empty() && i < nodes.size())
//    {
//        TreeNode* current = q.front();
//        q.pop();
//        if (nodes[i] != "null") {
//            current->left = new TreeNode(stoi(nodes[i]));
//            q.push(current->left);
//        }
//        i++;
//        if (i < nodes.size() && nodes[i] != "null") {
//            current->right = new TreeNode(stoi(nodes[i]));
//            q.push(current->right);
//        }
//		i++;
//    }
//	return root;
//}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		if (!root) { return result; }
		queue<TreeNode*> q;
		q.push(root);
        
        while (!q.empty())
        {
			int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i)
            {
				TreeNode* current = q.front();
                q.pop();
                if (i == levelSize - 1)
                {
                    result.push_back(current->val);
                }
                if (current->left)
                {
                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
				}
            }
        }
		return result;
    }
};
