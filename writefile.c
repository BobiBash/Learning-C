#include <stdio.h>

int main () {

    FILE *oFile = fopen("/home/hoppa/Downloads/input.txt", "r");

    char contents[256];

    if(oFile == NULL) {
        printf("Erorr reading file.");
        return 1;
    }

    while(fgets(contents, sizeof(contents), oFile)) {
        printf("%s", contents);
    }

    fclose(oFile);

    return 0;
}