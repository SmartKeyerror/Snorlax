
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
 * 打开一个 4 位数的密码锁，每次操作只能将每一位往前拨或者是往后拨，并且存在“死亡组合”，一旦我们将密码锁拨到了“死亡数字”，那么密码锁将再也无法打开。
 * 
 * 对于初始值 "0000" 而言，一次操作以后将会产生 8 中不同的可能: 
 * 1000, 0100, 0010, 0001, 9000, 0900, 0090, 0009
 * 
 * 因此，我们只需要在这些状态所组成的图中来一次 BFS 即可得到答案。 
 */
class Solution {
private:
    vector<string> getNextStatuses(string current) {
        vector<string> result;
        for (int i = 0; i < current.size(); i++) {
            string temp = current;
            
            if (temp[i] == '9') temp[i] = '0';
            else temp[i] ++;
            result.push_back(temp);

            temp = current;
            if (temp[i] == '0') temp[i] = '9';
            else temp[i] --;
            result.push_back(temp);
        }
        return result;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> deadPool;
        for (string deadend: deadends)
            deadPool.insert(deadend);
        
        if (deadPool.count(target) != 0 || deadPool.count("0000") != 0) return -1;
        if (target == "0000") return 0;

        queue<string> levelQueue;
        unordered_map<string, int> record;

        levelQueue.push("0000");
        record.insert({"0000", 0});

        while (!levelQueue.empty()) {
            string current = levelQueue.front();
            levelQueue.pop();

            for (string status: getNextStatuses(current)) {

                if (record.count(status) != 0 || deadPool.count(status) != 0) continue;

                levelQueue.push(status);
                record.insert({status, record[current] + 1});
                if (status == target) return record[status];
            }
        }
        return -1;
    }
};
