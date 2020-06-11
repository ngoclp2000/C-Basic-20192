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
        printf("1.Import Data\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("ENter the filename\n");
                char filename[15];
                scanf("%s",filename);
                db = read_db(filename);
                //print_db(db);
                //printf("%s\n",db->title);
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                    
                break;
        }
    }while(choice != 7);
}