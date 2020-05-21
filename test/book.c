#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "book.h"
#include "main.h"
BookDB read_db(char filename[]){
    FILE *fin = fopen(filename,"r+");
    int n = (int)fgetc(fin) -48;
    fgetc(fin);
    char id[10],title[50],author[20];
    int p_year;
    BookDB head = NULL;
    while(n != 0){
        fgets(id,10,fin);
        id[strlen(id) - 1]  = '\0';
        fgets(title,50,fin);
        title[strlen(title) - 1]  = '\0';
        fgets(author,20,fin);
        author[strlen(author) - 1]  = '\0';
        char x[50];
        fgets(x,50,fin);
        p_year = atoi(x);
        head = append(head,make_node(id,title,author,p_year));
        //printf("%s %s %s %d\n",id,title,author,p_year);
        n--;
    }
    print_db(head);
    return head;
}
 void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}  
void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
}  
BookDB write_db(char *filename,BookDB head){
    FILE *fout = fopen(filename,"w+");
    while(head != NULL){
        fputs(head->id,fout);
        fputs("\n",fout);
        fputs(head->title,fout);
        fputs("\n",fout);
        fputs(head->author,fout);
        fputs("\n",fout);
        char x[10];
        itoa(head->published_year,x);
        fputs(x,fout);
        if(head->next != NULL) fputs("\n",fout);
        head = head->next;
    }
    fclose(fout);
    return NULL;
}
BookDB make_node(char id[],char title[], char author[], int published_years){
    BookDB n = (BookDB ) malloc(sizeof(struct BookNode));
    strcpy(n->author,author);
    strcpy(n->id,id);
    strcpy(n->title,title);
    n->published_year = published_years;
    n->next = NULL;
    return n;
}
BookDB append(BookDB db,struct BookNode *b){
    BookDB origin = db;
    if(db == NULL) return b;
    while(db->next != NULL)
        db = db->next;
    db->next = b;
    return origin;
}
BookDB find_by_id(BookDB db,char id[]){
    while(db != NULL && strcmp(db->id,id) != 0)
        db = db->next;
    return db;
}
BookDB removeBook(BookDB db,char *id){
    BookDB prev = NULL;
    BookDB origin = db;
    while(db != NULL && strcmp(db->id,id) != 0){
        prev = db;
        db = db->next;
    }
    if( db == NULL) return origin;
    if(prev == NULL) return origin->next;
    prev->next = db->next;
    return origin; 
}
BookDB swap(BookDB db,BookDB *b1,BookDB *b2){
    BookDB prev1 = NULL;
    BookDB prev2 = NULL;
    BookDB temp = db;
    BookDB origin = db;
    while(strcmp((*b1)->id,temp->id) != 0){
        prev1 = temp;
        temp = temp->next;
    }
    while(strcmp((*b2)->id,db->id) != 0){
        prev2 = db;
        db = db->next;
    }

    if(prev1 == NULL){
        prev2->next = (*b1);
        temp = (*b1)->next;
        (*b1)->next = (*b2)->next;
        (*b2)->next = temp;
        return (*b2);
    }else if(prev2 == NULL){
        prev1->next = (*b2);
        temp = (*b2)->next;
        (*b2)->next = (*b1)->next;
        (*b1)->next = temp;
        return (*b1);
    }else{
        prev1->next = (*b2);
        prev2->next = (*b1);
        temp = (*b1)->next;
        (*b1)->next = (*b2)->next;
        (*b2)->next = temp;
    }
    return origin;
}
int count(BookDB db,int y){
    int i = 0;
    while(db != NULL){
        if(db->published_year == y) i++;
        db = db->next;
    }
    return i;
}
void print_book(BookDB b){
    printf("%-5s%-20s%-20s%s\n","ID","Title","Author","PulishedYear");
    printf("%-5s%-20s%-20s%d\n",b->id,b->title,b->author,b->published_year);
}
void print_db(BookDB db){
    printf("%-5s%-40s%-20s%s\n","ID","Title","Author","PulishedYear");
    while(db != NULL){
        printf("%-5s%-40s%-20s%d\n",db->id,db->title,db->author,db->published_year);
        db = db->next;
    }
}
int isExist(BookDB db,BookDB b){
    while(db != NULL && strcmp(b->id,db->id) != 0){
        db = db->next;
    }
    if ( db == NULL) return 0;
    return 1;
}