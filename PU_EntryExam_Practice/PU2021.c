#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char product_name[20];
    double product_price;
    int product_availability;
    int product_type;
}Product;

int compare(const void *a, const void *b) {
    Product *s1 = (Product *) a;
    Product *s2 = (Product *) b;

    int name_cmp = strcmp(s1->product_name, s2->product_name);
    if(name_cmp != 0) {
        return name_cmp;
    }

    return s1->id - s2->id;
}

int total_price_compare(const void *a, const void *b) {
    Product *s1 = (Product *) a;
    Product *s2 = (Product *) b;

    double s1_total = s1->product_availability * s1->product_price;
    double s2_total = s2->product_availability * s2->product_price;

    return (s1_total > s2_total) - (s2_total > s1_total);
}

int main () {

    int user_input;
    while(1) {
        printf("Number of products: ");
        scanf("%d", &user_input);
        if(user_input > 0 && user_input < 2000) {
            break;
        }
    }

    Product *products = malloc(user_input * sizeof(Product));

    for (int i = 0; i < user_input; i++) {
        Product *p = &products[i];

        p->id = i + 1;
        while(getchar() != '\n');

        while(1) {
            printf("Product name: ");
            fgets(p->product_name, sizeof(p->product_name), stdin);
            p->product_name[strcspn(p->product_name, "\n")] = 0;
            if(strlen(p->product_name) > 2 && strlen(p->product_name) < 20){
                break;
            }
        }

        while(1) {
            printf("Product price: ");
            scanf("%lf", &p->product_price);
            if(p->product_price > 0.10) {
                break;
            }
        }

        while(1) {
            printf("Product amount: ");
            scanf("%d", &p->product_availability);
            if (p->product_availability > 0) {
                break;
            }
        }

        while(1) {
            printf("Product type: ");
            scanf("%d", &p->product_type);
            if(p->product_type >= 1 && p->product_type <= 5) {
                break;
            }
        }
    }

    qsort(products, user_input, sizeof(Product), compare);

    printf("\n");
    for(int i = 0; i < user_input; i++) {
        Product *p = &products[i];
        char unique_code[50];
        sprintf(unique_code, "%d%c%c%d", p->id, p->product_name[0], p->product_name[1], p->product_type);
        printf("ID: %d|Product name: %s|Product price: %.2lf|Product Availability: %d|Product type: %d|Unique code: %s\n", 
        p->id, p->product_name, p->product_price, p->product_availability, p->product_type, unique_code);
    }

    int specified_type;
    printf("Specified product type: \n");
    scanf("%d", &specified_type);

    qsort(products, user_input, sizeof(Product), total_price_compare);

    for (int i = 0; i < user_input; i++) {
        Product *p = &products[i];
        if(p->product_type == specified_type) {
            printf("ID: %d|Product name: %s|Product price: %.2lf|Product Availability: %d|Product type: %d\n",
            p->id, p->product_name, p->product_price, p->product_availability, p->product_type);
        }
    }

    double total_value = 0;
    double price_combined_type_4 = 0;
    int product_count = 0;

    for(int i = 0; i < user_input; i++) {
        Product *p = &products[i];
        if(p->product_type == 4) {
            product_count ++;
            total_value += p->product_availability * p->product_price;
            price_combined_type_4 += p->product_price;
        }
    }

    printf("Task 4*****\n");

    if(product_count > 0) {
        printf("Average price: %.2lf|Total value: %.2lf\n", price_combined_type_4 / product_count, total_value);
    }
    else {
        printf("No products of this type");
    }





    free(products);
    return 0;
}