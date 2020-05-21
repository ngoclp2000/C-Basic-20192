#ifndef _Book_
#define _Book_
#include "main.h"
BookDB read_db(char *filename);
BookDB write_db(char *filename,BookDB head);
BookDB make_node(char id[],char title[], char author[], int published_years);
BookDB append(BookDB db, struct BookNode *b);
BookDB find_by_id(BookDB db,char *id);
BookDB removeBook(BookDB db,char *id);
BookDB swap(BookDB db,BookDB *b1,BookDB *b2);
void print_book(BookDB b);
void print_db(BookDB db);
int isExist(BookDB db,BookDB b);
int count(BookDB db,int y);
#endif