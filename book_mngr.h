#ifndef BOOK_MNGR_H
#define BOOK_MNGR_H

#define MAX_BOOKS 100

typedef struct 
{
    char author[50];
    char book_name[50];
    int year;
} book_t;

typedef enum 
{
    BOOK_SUCCESS = 0,
    BOOK_MNGR_ERR_SIZE = -1,
    BOOK_MNGR_ERR_EMPTY = 2
}book_mngr_err_t;



void display_books(book_t *p_book, int book_cnt);
book_mngr_err_t add_book(book_t book);

#endif