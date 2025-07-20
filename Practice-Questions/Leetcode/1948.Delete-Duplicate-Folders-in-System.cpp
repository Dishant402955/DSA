class Solution {
    typedef struct Node {
        string name = "";
        map<string, Node*> child;
        bool deleted = false;
        Node(string n) {
            name = n;
        }
    } Node;
    unordered_map<string, Node*> seen;
    void insert(Node *curr, vector<string> &path) {
        for(int i = 0; i < path.size(); i++) {
            if(curr -> child.count(path[i]) == 0) {
                curr -> child[path[i]] = new Node(path[i]);
            }
            curr = curr -> child[path[i]];
        }
    }
    void build(Node* root, vector<vector<string>>& paths) {
        for(int i = 0; i < paths.size(); i++) {
            insert(root, paths[i]);
        }
    }
    string traverse(Node *root) {
        string subfolder = "";
        for(auto &[name, child]: root -> child) {
            subfolder += traverse(child);
        }
        if(subfolder != "") {
            if(seen.find(subfolder) == seen.end()) {
                seen[subfolder] = root;
            } else {
                root -> deleted = true;
                seen[subfolder] -> deleted = true;
            }
        }
        return "(" + root -> name + subfolder + ")";
    }
    void getPath(Node *root, vector<string> &path, vector<vector<string>> &ans) {
        if(root -> deleted == true) return;
        path.push_back(root -> name);
        ans.push_back(path);
        for(auto &[name, child]: root -> child) {
            getPath(child, path, ans);
        }
        path.pop_back();
    }
    vector<vector<string>> solve(Node *root) {
        vector<vector<string>> ans;
        vector<string> path;
        for(auto &[name, child]: root -> child) {
            getPath(child, path, ans);
        }
        return ans;
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("");
        build(root, paths);
        traverse(root);
        return solve(root);
    }
};
