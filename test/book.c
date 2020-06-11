#include "main.h"
#include "book.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
BookDB read_db(char filename[]){
    FILE *fin = fopen(filename,"r+");
    BookDB db = NULL;
    int num;
    fscanf(fin, "%d\n", &num);
    for(int i = 0 ; i <  num ; i++){
        char id[10],title[50],author[20];
        int published_years;
        fscanf(fin, "%s\n",id);
        fgets(title, sizeof(title), fin);
        title[strlen(title)-1] = '\0';
        fgets(author, sizeof(author), fin);
        author[strlen(author)-1] = '\0';
        fscanf(fin, "%d\n",&published_years);
        node_t new_node = make_node(id,title,author,published_years);
        db = append(db, new_node);
        if(db != NULL) printf("%s\n",db->title);
    }
    
}
BookDB write_db(char filename[]){}
struct BookNode* make_node(char id[],char title[],char author[],int published_years){
    node_t new_node = (node_t) malloc(sizeof(struct BookNode));
    strcpy(new_node->id,id);
    strcpy(new_node->title,title);
    strcpy(new_node->author,author);
    new_node->published_years = published_years;
    new_node->next = NULL;
    return new_node;
}
BookDB append(BookDB db,struct BookNode*b){
    if(db == NULL) return b;
    while(db->next != NULL)
        db = db->next;
    db->next = b;
    return db;
}
struct BookNode* find_by_id(BookDB db,char id[]){}
BookDB removeBook(BookDB db,char id[]){}
BookDB swap(BookDB db, struct BookNode* b1, struct BookNode* b2){}
void print_book(struct BookNode* b){}
void print_db(BookDB db){
    printf("%-5s%-20s%-10s%s\n","ID","TITLE","AUTHOR","PUBLISHED_YEARS");
    while(db != NULL){
        printf("%-5s%-20s%-10s%d\n",db->id,db->title,db->author,db->published_years);
        db = db->next;
    }
}