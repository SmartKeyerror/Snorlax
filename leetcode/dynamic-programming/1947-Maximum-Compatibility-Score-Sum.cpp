
#include <vector>

using namespace std;


class Solution {
public:
    int ans = 0;
    
    int calculateScore(vector<int>& student, vector<int>& mentor){
        int ans = 0;
        for(int i=0;i<student.size();i++){
            ans += student[i] == mentor[i];
        }
        return ans;
    }
    
    void permutation(vector<vector<int>>& students, vector<vector<int>>& mentors, int index, int score, vector<bool>& visited){
        if(index>=students.size()){
            ans = max(ans, score);
            return ;
        }
        
        for(int i=0;i<mentors.size();i++){
            if(!visited[i]){
                visited[i] = true;
                permutation(students, mentors, index+1, score+calculateScore(students[index], mentors[i]), visited);
                visited[i] = false;
            }
        }
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<bool> visited(students.size(), false);
        permutation(students, mentors, 0, 0, visited);
        return ans;
    }
};
