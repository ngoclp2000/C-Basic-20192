#ifndef __BOOK__
#define __BOOK__

#include "main.h"
BookDB read_db(char filename[]);
BookDB write_db(char filename[]);
struct BookNode* make_node(char id[],char title[],char author[],int published_years);
BookDB append(BookDB db,struct BookNode*b);
struct BookNode* find_by_id(BookDB db,char id[]);
BookDB removeBook(BookDB db,char id[]);
BookDB swap(BookDB db, struct BookNode* b1, struct BookNode* b2);
void print_book(struct BookNode* b);
void print_db(BookDB db);
#endif