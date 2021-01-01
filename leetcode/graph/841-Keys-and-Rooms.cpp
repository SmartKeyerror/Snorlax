#include <vector>

using namespace std;


class Solution {
private:
    vector<bool> visited;

    void dfs(vector<vector<int>>& rooms, int start) {
        visited[start] = true;
        for (int room: rooms[start]) {
            if (!visited[room]) {
                visited[room] = true;
                dfs(rooms, room);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited = vector<bool>(rooms.size(), false);
        dfs(rooms, 0);

        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};
