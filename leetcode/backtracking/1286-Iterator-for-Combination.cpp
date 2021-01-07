
#include <vector>
#include <string>

using namespace std;


class CombinationIterator {
private:
    
    vector<string> combinations;
    vector<string>::iterator iter;

    void backtracking(string& characters, int combinationLength, int index, string& path) {
        if (path.size() == combinationLength) {
            combinations.push_back(path);
            return ;
        }
        for (int i = index; i < characters.size(); i++) {
            path += characters[i];
            backtracking(characters, combinationLength, i + 1, path);
            path.pop_back();
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        string path = "";
        backtracking(characters, combinationLength, 0, path);
        iter = combinations.begin();
    }
    
    string next() {
        return *iter++;
    }
    
    bool hasNext() {
        return iter != combinations.end();
    }
};
