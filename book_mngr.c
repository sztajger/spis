#include <stdio.h>
#include <string.h>
#include "book_mngr.h"

book_t books[MAX_BOOKS];
int book_size = 0;


void display_books(book_t *p_book, int book_size)
{
    if (book_size == 0)
    {
        printf("No books");
        return;
    }

    for(int i = 0; i < book_size; i++)
    {
        printf("%s\n", books[i].author);
        printf("%s\n", books[i].book_name);
        printf("%d\n", books[i].year);
    }
}

