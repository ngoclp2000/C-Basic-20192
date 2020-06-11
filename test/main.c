#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "main.h"
#include "book.h"
#include<stdio_ext.h>
int main(){
    BookDB db = NULL;
    int choice;
    do{
        printf("1.Import Data\n2.Append new Book\n3.Remove Book\n4.Swap\n5.Find by year\n6.Export Data\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                //printf("ENter the filename\n");
                //char filename[15];
                //scanf("%s",filename);
                db = read_db("book.txt");
                print_db(db);
                break;
            case 2:
                printf("Enter the new book information\n");
                char id[10],title[50],author[20];
                int published_years;
                do{
                    printf("ID: ");
                    scanf("%s",id);
                    printf("Title: ");
                    scanf("%s",title);
                    printf("Author: ");
                    scanf("%s",author);
                    printf("published_years: ");
                    scanf("%d",&published_years);
                }while(find_by_id(db,id) != NULL);
                node_t new_node = make_node(id,title,author,published_years);
                db = append(db,new_node);
                print_db(db);
                break;
            case 3:
                printf("Enter the id: ");
                //char id[10];
                scanf("%s",id);
                while(find_by_id(db,id) == NULL){
                    printf("Enter another id: ");
                    scanf("%s",id);
                }
                db = removeBook(db,id);
                print_db(db);
                break;
            case 4:
                printf("Enter two id: ");
                char id1[10],id2[10];
                scanf("%s %s",id1,id2);
                while(find_by_id(db,id1) == NULL || find_by_id(db,id2) == NULL){
                    printf("Enter other two id: ");
                    scanf("%s %s",id1,id2);
                }
                db = swap(db,find_by_id(db,id1),find_by_id(db,id2));
                print_db(db);
                break;
            case 5:
                printf("Enter the published_years: ");
                scanf("%d",&published_years);
                node_t temp = db;
                int count = 0;
                while(temp != NULL){
                    if(temp->published_years == published_years) count++;
                }
                printf("There are %d books in that published_years\n",count);
                break;
            case 6:
                write_db("book_out.txt",db);
                break;
        }
    }while(choice != 7);
}