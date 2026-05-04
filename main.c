#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void ShoppingProgram();
void WeightConverter();
void RockPaperScissors();
void RPSChoice(int num_choice, char *rps_choice);


int main() {

    int num;
    scanf("%d", &num);

    int *input = malloc(sizeof(int) * num);

    for(int i = 0;i < num; i++) {
        printf("Input: ");
        scanf("%d", &input[i]);
    }

    for(int i = 0;i < num;i++) {
        printf("The stuff: %d\n", input[i]);
    }

    free(input);

    return 0;
}

void RockPaperScissors() {
    int player_choice;

    srand(time(NULL));

    int pc_RPS = (rand() % 3) + 1;

    char rps_player_choice[256];
    char rps_pc_choice[256];
    RPSChoice(pc_RPS, rps_pc_choice);

    while(1) {
        printf("Choose an option\n");
        printf("1. Rock\n");
        printf("2. Scissors\n");
        printf("3. Paper\n");
        printf("4. Exit\n");
        scanf("%d", &player_choice);
        if (1 > player_choice || player_choice > 4) {
            printf("Invalid choice.\n");
            continue;
        } else {
            break;
        }
    }
    if (player_choice == 4) {
        printf("Thanks for playing.\n");
        exit(EXIT_SUCCESS);
    } else {
        RPSChoice(player_choice, rps_player_choice);
    }

    printf("Computer chose: %s\n", rps_pc_choice);
    printf("Player chose: %s\n", rps_player_choice);

    if (strcmp(rps_pc_choice, rps_player_choice) == 0) {
        printf("Draw.\n");
    }
    else if ((strcmp(rps_pc_choice, "Rock") == 0 && strcmp(rps_player_choice, "Scissors") == 0) ||
             (strcmp(rps_pc_choice, "Scissors") == 0 && strcmp(rps_player_choice, "Paper") == 0)||
             (strcmp(rps_pc_choice, "Paper") == 0 && strcmp(rps_player_choice, "Rock") == 0)) {
        printf("Computer wins.\n");
    }
    else {
        printf("Player wins.\n");
    }

}

void RPSChoice(int num_choice, char *rps_choice) {


    switch(num_choice) {
        case 1:
            strcpy(rps_choice, "Rock");
            break;
        case 2:
            strcpy(rps_choice, "Scissors");
            break;
        case 3:
            strcpy(rps_choice, "Paper");
            break;
        default:
            strcpy(rps_choice, "Uknown");
            break;
    }
}

void WeightConverter() {
    int choice = 0;
    float kg;
    float lbs;

    printf("Choose an option.\n");
    printf("1.Pounds to KG\n");
    printf("2.KG to Pounds\n");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Pounds: ");
        scanf("%f", &lbs);
        kg = lbs / 2.205;
        printf("Kg: %.2f", kg);
    } else {
        printf("Kg: ");
        scanf("%f", &kg);
        lbs = kg * 2.205;
        printf("Lbs: %.2f", lbs);
    }

}

void ShoppingProgram () {
    char item[50];
    int quantity;
    float price;
    char currency[4] = "EUR";
    int menu_option_choice;
    float total = 0;

    while(1) {
        printf("1. Buy items.\n");
        printf("2. Exit\n");
        scanf("%d", &menu_option_choice);
        if (menu_option_choice == 1) {
            printf("What item would you like to buy?: \n");
            getchar();
            fgets(item, sizeof(item), stdin);
            item[strlen(item) - 1] = '\0';
            printf("What quantity of the item are you getting?: \n");
            scanf("%d", &quantity);
            printf("Whats the price of the item?: \n");
            scanf("%f", &price);
            total += price * quantity;
            printf("Current total is: %.2f%s\n", total, currency);
        } else {
            break;
        }

    }
}