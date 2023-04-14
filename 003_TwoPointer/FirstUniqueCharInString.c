#include <stdio.h>
#include <string.h>
#include <limits.h>

int firstUniqChar(char *s) {
    int char_count[256] = {0};

    for (size_t i = 0; s[i] != '\0'; i++) {
        char_count[(unsigned char)s[i]]++;
    }

    for (size_t i = 0; s[i] != '\0'; i++) {
        if (char_count[(unsigned char)s[i]] == 1) {
            return (int)i;
        }
    }

    return -1;
}

int main(void) {
    char s[] = "loveleetcode";
    int ans = firstUniqChar(s);
    printf("The index of the first unique Character is : %d\n", ans);
}