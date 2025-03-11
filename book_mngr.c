#include <stdio.h>
#include <string.h>
#include "book_mngr.h"

static book_t books[MAX_BOOKS] = {0};
static int book_cnt = 0;

void display_books(book_t *p_book, int book_cnt)
{
    if (book_cnt == 0)
    {
        printf("No books");
        return;
    }

    for(int i = 0; i < book_cnt; i++)
    {
        printf("%s\n", books[i].author);
        printf("%s\n", books[i].book_name);
        printf("%d\n", books[i].year);
    }
}

book_mngr_err_t add_book(book_t book)
{
    book_mngr_err_t book_mngr_err = BOOK_SUCCESS;
    
    if (book_cnt >= MAX_BOOKS)
    {
        return BOOK_MNGR_ERR_SIZE;
    }

    strcpy(books[book_cnt].author, book.author);
    strcpy(books[book_cnt].book_name, book.book_name);
    books[book_cnt].year = book.year;

    book_cnt++;

    return BOOK_SUCCESS;
}

book_mngr_err_t delete_last_book()
{
    if (book_cnt == 0)
    {
        return BOOK_MNGR_ERR_EMPTY; // Error if ther are no books in lbrary -2
    }

    book_cnt--; //decrese the count, not sure if its correct this function work, will test this later
    return BOOK_SUCCESS;
}

void save_lib()
{
    FILE * file = fopen(FILE_NAME, "w");
    if(!file)
    {
        printf("Error, cant save!\n");
        return;
    }

    for (int i = 0; i< book_cnt; i++)
    {
        fprintf(file, "%s\n%s\n%d\n", books[i].book_name, books[i].author, books[i].year);
    }
    fclose(file);
}

void load_lib()
{
    FILE * file = fopen(FILE_NAME, "r");
    if(!file)
    {
        printf("No file!\n");
        return;
    }

    book_cnt = 0; //set actual book_cnt = 0
    while (fscanf(file, " %[^\n]\n%[^\n]\n%d", books[book_cnt].book_name, books[book_cnt].author, &books[book_cnt].year) == 3) 
    {
        book_cnt ++;
        if (book_cnt >= MAX_BOOKS) break;
    }
    {
        /* code */
    }
    
}