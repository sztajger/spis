#ifndef BOOK_MNGR_H
#define BOOK_MNGR_H

#define MAX_BOOKS 100

typedef struct 
{
    char author[50];
    char book_name[50];
    int year;
} book_t;

extern book_t books[MAX_BOOKS];
extern int book_size;

void display_books(book_t *p_book, int book_size);

#endif