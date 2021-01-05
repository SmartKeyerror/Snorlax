
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include <unordered_map>

using namespace std;

/*
 * URL短链接设计
 */
class Solution {
private:

    unordered_map<string, string> record;

    string getRandomString(int length) {
        srand(time(NULL));
        string s = "";
        for (int i = 0; i < length; i++) {
            switch (rand() % 3) {
            case 1:
                s += 'A' + rand() % 26;
                break;
            case 2:
                s += 'a' + rand() % 26;
                break;
            case 3:
                s += '0' + rand() % 10;
                break;
            }
        }
        return s;
    }
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string randomKey = getRandomString(6);
        while (record.count(randomKey))
            randomKey = getRandomString(6);
        
        record[randomKey] = longUrl;
        return randomKey;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return record[shortUrl];
    }
};
