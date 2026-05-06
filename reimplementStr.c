#include <stdio.h>
#include <stdbool.h>

int strlength(char *str);
void strcopy(char *str1, char *str2);
void my_strcat(char *str1, char *str2);
int my_strcmp(char *str1, char *str2);

int main () {

    char test1[] = "abc";
    char test2[] = "abd";

    char short_str[] = "cat";
    char long_str[] = "catalog";

    char src[] = "abcd";
    char dest[] = "abcd";
    int result = my_strcmp(short_str, long_str);
    int result2 = my_strcmp(test1, test2);
    int result3 = my_strcmp(src, dest);
    if (result3 > 0) {
        printf("string 1 is bigger than string 2\n");
    }
    else if (result3 < 0) {
        printf("string 2 is bigger than string 1\n");
    }
    else 
    {
        printf("Theyre equal.\n");
    }

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

int my_strcmp(char *str1, char *str2) {
    int i = 0;


    while(str1[i] != '\0' || str2[i] != '\0') {

        if(str1[i] == str2[i]) {
            i++;
            continue;
        }
        else if (str1[i] > str2[i]) {
            return 1;
        } else  {
            return -1;
        } 
    }

    return 0;

}