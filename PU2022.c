#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Food struct to store all the food information
typedef struct {
    char code[6];
    char name[61];
    int weight;
    int longevity;
    char group;
    char entry_date[11];
    char position[11];
    float food_temp;
} Food;

int main () {

    // accept input of N food inputs from 0 to 1000 
    int food_N;
    while(1) {
        scanf("%d", &food_N);
        if(food_N >= 1 || food_N <= 1000) break;
        printf("Invalid food_N."); 
    }

    Food* foods = malloc(food_N * sizeof(Food));
    printf("Food size: %d", sizeof(Food));
    // for loop to input the food info for(int i = 0; i < food_N; i++)
    for(int i = 0; i < food_N;i++) {
        while(1) {
            printf("Food code: ");
            scanf(" %s", &foods[i].code);

            if(strlen(foods[i].code) <= 5) {
                while(getchar() != '\n');
                break;
            } else {
                printf("Invalid code. \n");
            }
        }
        while(1) {
            printf("Food name: ");
            fgets(foods[i].name, sizeof(foods[i].name), stdin);
            foods[i].name[strcspn(foods[i].name, "\n")] = 0;
            if(strlen(foods[i].name) <= 60) {
                break;
            } else {
                printf("Invalid name.");
            }
        }
        while(1) {
            printf("Food weight: ");
            scanf(" %d", &foods[i].weight);
            if(foods[i].weight > 1) {
                break;
            } else {
                printf("Invalid weight.");
            }
        }
        while(1) {
            printf("Food longevity: ");
            scanf(" %d", &foods[i].longevity);
            if(foods[i].longevity > 1) {
                break;
            } else {
                printf("Invalid longevity.");
            }
        }
        while(1) {
            printf("Food group(S/G): ");
            scanf(" %c", &foods[i].group);
            if(foods[i].group == 'S' || foods[i].group == 'G') {
                break;
            } else {
                printf("Invalid group.");
            }
        }
        while(1) {
            printf("Food entry date: ");
            scanf(" %s", &foods[i].entry_date);
            if(strlen(foods[i].entry_date) <= 10) {
                int d, m ,y;
                char dot1, dot2;
                if (sscanf(foods[i].entry_date, "%d%c%d%c%d", &d, &dot1, &m, &dot2, &y) == 5
                && dot1 == '.' && dot2 == '.' && d >= 1 && d <= 31
                && m >= 1 && m <=12 && y > 0) {
                    break;
                }
            } else {
                printf("Invalid entry date.");
            }
        }
        while(1) {
            printf("Food position: ");
            scanf(" %s", &foods[i].position);
            if(strlen(foods[i].position) <= 10) {
                break;
            } else {
                printf("Invalid position.");
            }
        }
        if (foods[i].group == 'S') {
            while(1) {
            printf("Food temperature: ");
            scanf("%f", &foods[i].food_temp);
            if(foods[i].food_temp > 0) {
                break;
            } else {
                printf("Invalid temperature.");
            }
        }
        }
        
    }

    printf("Printing everything here\n");
    for(int i = 0; i < food_N; i++) {
        if (foods[i].group == 'G') {
        printf("%s, %s, %d, %d, %c, %s, %s, \n", foods[i].code,
            foods[i].name, foods[i].weight, foods[i].longevity,
            foods[i].group, foods[i].entry_date, foods[i].position);
        
        } else {
            printf("%s, %s, %d, %d, %c, %s, %s, %.1f \n", foods[i].code,
            foods[i].name, foods[i].weight, foods[i].longevity,
            foods[i].group, foods[i].entry_date, foods[i].position, foods[i].food_temp);
        }
    }

    // printf("Products sorted by date and name\n");
    // qsort(foods, food_N, sizeof(Food), compare);

    free(foods);

    return 0;
}

// void compare(const void *a, const void *b) {
//     Food *fa = (Food*)a;
//     Food *fb = (Food*)b;
// }