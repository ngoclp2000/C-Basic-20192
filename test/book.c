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
        //if(db != NULL) printf("%s\n",db->title);
    }
    return db;
}
BookDB write_db(char filename[],BookDB db){
    FILE *fout = fopen(filename,"w");
    while(db != NULL){
        // fputs(db->id,fout);
        // fputs("\n",fout);
        // fputs(db->title,fout);
        // fputs("\n",fout);
        // fputs(db->author,fout);
        // fputs("\n",fout);
        fprintf(fout,"%s\n%s\n%s\n%d",db->id,db->title,db->author,db->published_years);
        if(db->next != NULL) fputs("\n",fout);
        db = db->next;
    }
    fclose(fout);
    //return NULL;
}
struct BookNode* make_node(char id[],char title[],char author[],int published_years){
    node_t new_node = (BookDB) malloc(sizeof(struct BookNode));
    strcpy(new_node->id,id);
    strcpy(new_node->title,title);
    strcpy(new_node->author,author);
    new_node->published_years = published_years;
    new_node->next = NULL;
    return new_node;
}
BookDB append(BookDB db,struct BookNode*b){
    if(db == NULL) return b;
    BookDB original = db;
    while(db->next != NULL)
        db = db->next;
    db->next = b;
    return original;
}
struct BookNode* find_by_id(BookDB db,char id[]){
    while(db != NULL && strcmp(id,db->id) != 0)
        db = db->next;
    return db;
}
BookDB removeBook(BookDB db,char id[]){
    node_t prev;
    node_t original = db;
    while(db != NULL && strcmp(id,db->id) != 0){
        prev = db;
        db = db->next;
    }
    //if(db == NULL) return NULL;
    if (db == original) return db->next;
    prev->next = db->next;
    free(db);
    return original;
}
node_t find_pre_book(BookDB db,node_t b){
    node_t prev = NULL;
    while(db != NULL && strcmp(db->id,b->id)){
        prev = db;
        db = db->next;
    }
    return prev;
}
BookDB swap(BookDB db, struct BookNode* b1, struct BookNode* b2){
    node_t temp = b1;
    node_t original = db;
    node_t prev1,prev2;
    prev1 = find_pre_book(db,b1);
    prev2 = find_pre_book(db,b2);
    if(b1 == db){
        prev2->next = b1;
        node_t temp1 = b2->next;
        b2->next = b1->next;
        b1->next = temp1;
        return b2;
    }else if(b2 == db){
        prev1->next = b2;
        node_t temp1 = b2->next;
        b2->next = b1->next;
        b1->next = temp1;
        return b1;
    }
    prev1->next = b2;
    prev2->next = b1;
    node_t temp1 = b2->next;
    b2->next = b1->next;
    b1->next = temp1;
    return db;
}
void print_book(struct BookNode* b){}
void print_db(BookDB db){
    printf("%-5s%-20s%-20s%s\n","ID","TITLE","AUTHOR","PUBLISHED_YEARS");
    while(db != NULL){
        printf("%-5s%-20s%-20s%d\n",db->id,db->title,db->author,db->published_years);
        db = db->next;
    }
}
