

#include <string>

using namespace std;


class Solution {
public:
    string maximumTime(string time) {
        if(time[0]=='?')
            time[0]= (time[1]<='3' || time[1]=='?') ? '2' : '1';

        if(time[1]=='?')
            time[1]= time[0]=='2' ? '3' : '9';

        if(time[3]=='?')
            time[3]='5';

        if(time[4]=='?')
            time[4]='9';

        return time;
    }
};