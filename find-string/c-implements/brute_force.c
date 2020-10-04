
#include <string.h>
#include <stdio.h>


int brute_find(char *pattern, char *stirng) {

    int count;

    int pattern_length = strlen(pattern);
    int string_length = strlen(stirng);

    if (pattern_length > string_length)
        return -1;
    
    for (int i = 0; i <= string_length - pattern_length; i++) {
        count = 0;
        for (int j = 0; j < pattern_length; j++) {
            if (stirng[i + j] != pattern[j])
                break;
            count++;
        }

        if (count == pattern_length)
            return i;
    }

    return -1;
}


int main() {
    char *s = "aaaaaaaaaaaaaaaaaaa";
    char *sub = "aab";

    int res = brute_find(sub, s);

    printf("%d \n", res);
}