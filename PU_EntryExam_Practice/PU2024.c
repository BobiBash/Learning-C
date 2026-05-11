#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct to store the books information
typedef struct {
    // id from 1 to N
    int id;
    // author name - shorter than 40 symbols
    char author_name[40];
    // title - shorter than 60 symbols
    char title[60];
    // year of publication
    int publication_year;
    // pages count
    int pages;
    // genre - either "Artistic" or "Scientific"
    char genre[256];
}Book;

int compare(const void* a, const void* b) {
    Book* book1 = (Book*) a;
    Book* book2 = (Book*) b;

    int result = strcmp(book1->author_name, book2->author_name);

    if(result == 0){
        return book1->pages > book2->pages;
    }

    return result;
}

int main () {

    // take user input for amount of books
    int user_input = 0;
    // check if amount of books is between 5 and 300
    while(1) {
        printf("Amount of books: ");
        scanf("%d", &user_input);
        if (user_input >= 2 && user_input <= 300) break;
    }
    while(getchar() != '\n');

    // create space for the books we'll store on the heap
    Book* books = malloc(user_input * sizeof(Book));

    // loop to add a record for each book from user_input
    for(int i = 0; i < user_input; i++) {
        books[i].id = i + 1;

        do {
            printf("Enter Author name:");
            fgets(books[i].author_name, sizeof(books[i].author_name), stdin);
            books[i].author_name[strcspn(books[i].author_name, "\n")] = '\0';
        } while (strlen(books[i].author_name) == 0 || strlen(books[i].author_name) > 40);

        do {
            printf("Enter Title: ");
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = '\0';
        } while (strlen(books[i].title) == 0 || strlen(books[i].title) > 60);

        do {
            printf("Enter Publication year: ");
            scanf("%d", &books[i].publication_year);
        } while (books[i].publication_year == 0);

        do {
            printf("Enter Page count: ");
            scanf("%d", &books[i].pages);
            while(getchar() != '\n');
        } while (books[i].pages == 0);

        do {
            printf("Enter Genre: ");
            scanf("%s", books[i].genre);
        } while (strcmp(books[i].genre, "Artistic") != 0 && strcmp(books[i].genre, "Scientific") != 0);
    }

    printf("\n");
    // another loop to print out all the books
    for(int i = 0; i < user_input; i++) {
        printf("ID: %d|| Author: %s|| Title: %s|| Publication year: %d|| Pages count: %d|| Genre: %s\n",
            books[i].id, books[i].author_name, books[i].title, books[i].publication_year, books[i].pages, books[i].genre);
    }


    // print out all books with less than user inputted pages
    int user_pages_input = 0;
    printf("Books shorter than: \n");
    scanf("%d", &user_pages_input);


    for(int i = 0; i < user_input; i++) {
        if(books[i].pages < user_pages_input) {
            printf("ID: %d|| Author: %s|| Title: %s|| Publication year: %d|| Pages count: %d|| Genre: %s\n",
                books[i].id, books[i].author_name, books[i].title, books[i].publication_year, books[i].pages, books[i].genre);
        }
    }

    printf("\n");
    int scifi_book_count = 0;
    int total_pages = 0;
    for(int i = 0; i < user_input; i++) {
        if(strcmp(books[i].genre, "Scientific") == 0) {
            scifi_book_count += 1;
            total_pages += books[i].pages;
        }
    }

    printf("Average pages for scifi books: %d\n", total_pages / scifi_book_count);

    // output all the Artistic books published after 1990 with pages less than 200
    printf("Artistic books published after 1990 with less than 200 pages\n");
    for(int i = 0; i<user_input; i++) {
        if(strcmp(books[i].genre, "Artistic") == 0){
            if(books[i].publication_year > 1990) {
                if(books[i].pages < 200) {
                    printf("ID: %d|| Author: %s|| Title: %s|| Publication year: %d|| Pages count: %d|| Genre: %s\n",
                        books[i].id, books[i].author_name, books[i].title, books[i].publication_year, books[i].pages, books[i].genre);
                }
            }
        }
    }

    // sort by name first and if names are the same then sort by book pages
    qsort(books, user_input, sizeof(Book), compare);
    printf("Sorted books\n");

    // print out sorted books
    for(int i = 0; i < user_input; i++) {
        printf("ID: %d|| Author: %s|| Title: %s|| Publication year: %d|| Pages count: %d|| Genre: %s\n",
            books[i].id, books[i].author_name, books[i].title, books[i].publication_year, books[i].pages, books[i].genre);
    }

    // free the memory that was used by books
    free(books);
    return 0;
}
