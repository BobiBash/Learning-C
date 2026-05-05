#include <stdio.h>

int strlength(char *str);
void strcopy(char *str1, char *str2);
void my_strcat(char *str1, char *str2);

int main () {

    char src[20] = "hello";
    char dest[] = " world";
    my_strcat(src, dest);
    printf("%s\n", src);
    return 0;
}

int strlength(char *str) {
    int len = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        len += 1;
    }

    return len;
}

void strcopy(char *str1, char *str2) {
    for (int i = 0; i < strlength(str1); i++) {
        str2[i] = str1[i];
    }

    str2[strlength(str1)] = '\0';

}

void my_strcat(char *str1, char *str2) {

    int start = strlength(str1);

    for(int i = 0; i < strlength(str2); i++) {
        str1[start] = str2[i];
    }

    str1[strlength(str1)] = '\0';
}