class Solution {
public:
    bool isValid(string s) {
        int balance = 0;

        for (char ch : s) {
            if (ch == '(') {
                balance++;
            } else if (ch == ')') {
                balance--;

                if (balance < 0) {
                    return false;
                }
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int size = q.size();

            // Process one complete BFS level.
            while (size--) {
                string current = q.front();
                q.pop();

                // If valid, this is the minimum-removal level.
                if (isValid(current)) {
                    result.push_back(current);
                    found = true;
                }

                // If we already found valid strings at this level,
                // don't generate strings with more removals.
                if (found) {
                    continue;
                }

                // Remove one parenthesis from every possible position.
                for (int i = 0; i < current.size(); i++) {

                    // Letters don't need to be removed.
                    if (current[i] != '(' && current[i] != ')') {
                        continue;
                    }

                    string next = current.substr(0, i) + current.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // Valid strings were found, so this is the
            // minimum number of removals.
            if (found) {
                break;
            }
        }

        return result;
    }
};
