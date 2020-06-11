#ifndef _MAIN_H_
#define _MAIN_H_
struct BookNode{
    char id[10];
    char title[50];
    char author[20];
    int published_years;
    struct BookNode *next;
};
typedef int element_t;
typedef struct BookNode *node_t;
typedef struct BookNode *BookDB;
#endif