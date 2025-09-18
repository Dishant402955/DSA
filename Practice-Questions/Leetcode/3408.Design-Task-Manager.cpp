class TaskManager {
    unordered_map<int, pair<int,int>> mp; 
    // taskId -> {userId, priority}
    
    priority_queue<tuple<int,int,int>> pq; 
    // (priority, taskId, userId) : max-heap by default

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int user = t[0], task = t[1], pri = t[2];
            mp[task] = {user, pri};
            pq.emplace(pri, task, user);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.emplace(priority, taskId, userId);
    }
    
    void edit(int taskId, int newPriority) {
        auto [user, _] = mp[taskId];
        mp[taskId] = {user, newPriority};
        pq.emplace(newPriority, taskId, user);
    }
    
    void rmv(int taskId) {
        mp.erase(taskId); // lazy delete (entry stays in pq until popped)
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [pri, task, user] = pq.top();
            if (!mp.count(task)) { // removed already
                pq.pop();
                continue;
            }
            auto [curUser, curPri] = mp[task];
            if (curPri != pri) { // outdated priority
                pq.pop();
                continue;
            }
            // valid task
            pq.pop();
            mp.erase(task);
            return user;
        }
        return -1; // no tasks
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
