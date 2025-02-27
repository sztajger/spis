#include <stdio.h>
#include <string.h>
#include "book_mngr.c"



int main()
{
    Book book1;
    strcpy(book1.author, "tomek");
    strcpy(book1.book_name, "hary poter kontra hipopotam");
    book1.year = 1000;
    
    books[book_count] = book1;
    book_count++;

    display(books, book_count);




    return 0;
}