 #include <stdio.h>
#include <string.h>
#include "book_mngr.c"


int main()
{
    char input[10] = {0};
    int choice = 0;
    book_mngr_err_t result = BOOK_SUCCESS;

    while(1)
    {
        printf("---MENU---\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Delete last added book\n");
        printf("4. Save lib\n");
        printf("5. Load lib\n");
        printf("6. Exit\n");
        printf("Choose option: ");
    
        if (!fgets(input, sizeof(input), stdin)) 
        {
            printf("Błąd odczytu!\n");
            continue;
        }

        // change input to number
        if (sscanf(input, "%d", &choice) != 1) 
        {
            printf("Wrong choice, try again.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            book_t new_book = {0};
            printf("Author:");
            fgets(new_book.author, sizeof(new_book.author), stdin);
            new_book.author[strcspn(new_book.author, "\n")] = 0;

            printf("Title:");
            fgets(new_book.book_name, sizeof(new_book.book_name), stdin);
            new_book.book_name[strcspn(new_book.book_name, "\n")] = 0;

            printf("Year of release: ");
                if (scanf("%d", &new_book.year) != 1) {
                    printf("Error: wrong year format!\n");
                    while (getchar() != '\n');  
                    break;
                }
            getchar(); 

            result = add_book(new_book);
            if (result == BOOK_SUCCESS) 
            {
                printf("Book added correctly\n");
            }
            else
            {
                printf("Error: Book not added\n");
            }

            break;

        case 2:
            display_books(books, book_cnt);
            break;
            
        case 3:
            result = delete_last_book();
            if (result == BOOK_SUCCESS) {
                printf("Last book deleted.\n");
            }
            else 
            {
                printf("No book to delete!\n");
            }
            break;

        case 4:
            save_lib();
            printf("Saving...\n");
            break;

        case 5:
            load_lib();
            printf("Loading...\n");
            break;
            
        case 6:
            printf("Closing the program...\n");
            return 0;

        default:
            printf("Wrong choice, try again.\n");
        };
    };
    return 0;
}