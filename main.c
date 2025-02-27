#include <stdio.h>
#include <string.h>
#include "book_mngr.c"



int main()
{
    book_t book1 =
    {
        .author = "tomek",
        .book_name = "hary poter kontra hipopotam",
    .year = 111
    };
    
    books[book_size] = book1;
    book_size++;

    display_books(books, book_size);




    return 0;
}