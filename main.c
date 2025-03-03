#include <stdio.h>
#include <string.h>
#include "book_mngr.c"


int main()
{
    char input[10];
    int choice;
    book_t new_book;
    book_mngr_err_t result;

    while(1)
    {
        printf("---MENU---\n");
        printf("1. Dodaj ksiazke\n");
        printf("2. Wyswietl ksiazki\n");
        printf("3. Usun ostatnio dodana ksiazke\n");
        printf("4. Wyjdz\n");
        printf("Wybierze opcje: ");
    

        if (!fgets(input, sizeof(input), stdin)) 
        {
            printf("Błąd odczytu!\n");
            continue;
        }

        // Zamiana inputu na liczbe
        if (sscanf(input, "%d", &choice) != 1) 
        {
            printf("Nieprawidłowy wybór, spróbuj ponownie.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Podaj autora:");
            fgets(new_book.author, sizeof(new_book.author), stdin);
            new_book.author[strcspn(new_book.author, "\n")] = 0;

            printf("Podaj tytul:");
            fgets(new_book.book_name, sizeof(new_book.book_name), stdin);
            new_book.book_name[strcspn(new_book.book_name, "\n")] = 0;

            printf("Podaj rok wydania: ");
                if (scanf("%d", &new_book.year) != 1) {
                    printf("Badd: Niepoprawny format roku!\n");
                    while (getchar() != '\n');  // Czyści błędne wejście
                    break;
                }
            getchar(); 

            result = add_book(new_book);
            if (result == BOOK_SUCCESS) 
            {
                printf("Ksiazka dodana poprawnie\n");
            }
            else
            {
                printf("Blad");
            }

            break;

        case 2:
            display_books(books, book_cnt);
            break;
            
        case 3:
            result = delete_last_book();
            if (result == BOOK_SUCCESS) {
                printf("Ostatnia książka została usunięta.\n");
            }
            else 
            {
                printf("Brak książek do usunięcia!\n");
            }
            break;

            case 4:
                printf("Zamykanie programu...\n");
                return 0;

            default:
                printf("Nieprawidłowy wybór, spróbuj ponownie.\n");
        };
    };
    return 0;
}