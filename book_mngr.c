
typedef struct 
{
    char author[50];
    char book_name[50];
    int year;
} Book;


// display book

Book books[10];
int book_count = 0;

void display(Book books[], int book_count)
{
    if (book_count == 0)
    {
        printf("No Books");
        return;
    }

    for(int i = 0; i < book_count; i++)
    {
        printf("%s\n", books[i].author);
        printf("%s\n", books[i].book_name);
        printf("%d\n", books[i].year);
    }
}

