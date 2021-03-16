
#include <vector>
#include <queue>

using namespace std;

/*
 * 既能够往左跳，也能够往右跳，那么我们可以将 arr 这个数组展开成一个图，然后用 bfs 的方式遍历。
 * 
 * 唯一的问题就是，我们不能够跳出 arr，所以说，[1, 4, 2, 2, 3, 5]，对于 4 和 5 来说，只能往右跳和往左跳
 */
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        if (arr[start] == 0) return true;

        queue<int> levelQueue;
        levelQueue.push(start);
        visited[start] = true;

        while (!levelQueue.empty()) {
            int current = levelQueue.front();
            levelQueue.pop();

            int left = current - arr[current];
            int right = current + arr[current];

            if (left >= 0 && !visited[left]) {
                if (arr[left] == 0) return true;
                visited[left] = true;
                levelQueue.push(left);
            }

            if (right < n && !visited[right]) {
                if (arr[right] == 0) return true;
                visited[right] = true;
                levelQueue.push(right);
            }
        }
        return false;
    }
};