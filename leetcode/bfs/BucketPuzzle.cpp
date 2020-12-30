
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;


class BucketPuzzle {
private:
    int endStatus = -1;

    // 使用 hashmap 判定是否访问过, value 表示当前状态是从哪个状态转移而来的。
    unordered_map<int, int> visited; 

    vector<int> nextStatuses(int x, int y) {
        vector<int> nexts;

        nexts.push_back(a * 10 + y);
        nexts.push_back(x * 10 + b);

        nexts.push_back(0 * 10 + y);
        nexts.push_back(x * 10 + 0);

        nexts.push_back(10 * (a - min(x, b - y)) + (y + min(x, b - y)));
        nexts.push_back(10 * (x + min(y, a - x)) + (y - min(y, a - x)));

        return nexts;
    }

    void bfs() {
        queue<int> levelQueue;

        levelQueue.push(0);
        visited[0] = 0;

        while (!levelQueue.empty()) {
            int current = levelQueue.front();
            levelQueue.pop();

            int x = current / 10, y = current % 10;

            for (int next: nextStatuses(x, y)) {
                if (!visited.count(next)) {
                    levelQueue.push(next);
                    visited[next] = current;

                    if (next / 10 == dst || next % 10 == dst) {
                        endStatus = next;
                        return ;
                    }
                }
            }
        }
    }

public:

    int a, b, dst;

    BucketPuzzle(int bucketA, int bucketB, int target) {
        a = bucketA, b = bucketB, dst = target;
    }

    void slove() {
        
        bfs();
        
        if (endStatus == -1) {
            cout<<"There has no solution for input"<<endl;
            return;
        }

        int current = endStatus;
        vector<int> path;

        while (current != 0) {
            path.push_back(current);
            current = visited[current];
        }
        path.push_back(0);
        reverse(path.begin(), path.end());

        for (int status: path)
            cout<<status<<' ';        
    }

};


int main() {
    BucketPuzzle(9, 4, 6).slove();
    return 0;
}
