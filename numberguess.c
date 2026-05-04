#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int r = rand() & 100;

    int user_input;

    printf("****************************\n");
    printf("Choose a number between 0 and 100.\n");
    printf("****************************\n");

    while(1) {
        scanf("%d", &user_input);

        if(user_input == r){
            printf("Good job! The number was: %d\n", r);
            break;
        }
        else {
            if(user_input > r){
                printf("The number is smaller than %d\n", user_input);
                continue;
            }
            if(user_input < r){
                printf("The number is bigger than %d\n", user_input);
                continue;
            }
        }

    }


    return 0;
}