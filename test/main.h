<<<<<<< HEAD
#ifndef _MAIN_H_
#define _MAIN_H_
struct BookNode{
    char id[10];
    char title[50];
    char author[20];
    int published_year;
    struct BookNode *next;
};
typedef int element_t;
typedef struct BookNode *BookDB;
typedef struct BookNode *node_t;
=======
#ifndef _MAIN_H_
#define _MAIN_H_
struct BookNode{
    char id[10];
    char title[50];
    char author[20];
    int published_year;
    struct BookNode *next;
};
typedef struct BookNode *BookDB;
typedef struct BookNode *node_t;
>>>>>>> 8b12faed52230b00dee6eeddb515cda524b301ca
#endif