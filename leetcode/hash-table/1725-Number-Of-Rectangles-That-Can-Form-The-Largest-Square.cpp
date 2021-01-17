
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int largest = 0;
        unordered_map<int, int> squares;
        for (int i = 0; i < rectangles.size(); i++) {
            int square = min(rectangles[i][0], rectangles[i][1]);
            squares[square] ++;
            largest = max(largest, square);
        }
        return squares[largest];
    }
};
