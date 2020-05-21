#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "main.h"
#include "book.h"
<<<<<<< HEAD
#include<stdio_ext.h>
int main(){
    BookDB head = NULL;
    int choice;
    do{
        printf("1.ImportDB\n2.Add record\n3.Delete record\n4.Swap records\n5.Count by PulishedYear\n6.WriteToFile\n7.Print DB\n8.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case /* constant-expression */ 1:
            /* code */
            if(head == NULL) head = read_db("book.txt");
            else printf("The data has been read\n");
            break;
        case 2:
            printf("Enter the data\n");
            char id[10],title[50],author[20];
            int p_year;
            BookDB b;
            do{
                printf("ID:");
                __fpurge(stdin);
                scanf("%s",id);
                printf("Title: ");
                __fpurge(stdin);
                scanf("%[^\n]s",title);
                printf("Author: ");
                __fpurge(stdin);
                scanf("%[^\n]s",author);
                printf("PulishedYear : ");
                scanf("%d",&p_year);
                b = make_node(id,title,author,p_year);
            }while(isExist(head,b));
            head = append(head,b);
            printf("Adding successfully\n");
            print_db(head);
            break;
        case 3:
            printf("Enter the data you want to delete\n");
            do{
                printf("ID:");
                __fpurge(stdin);
                scanf("%s",id);
                b = make_node(id,title,author,p_year);
            }while(!isExist(head,b));
            head = removeBook(head,id);
            printf("Remove successfully\n");
            print_db(head);
            break;
        case 4:
            printf("Enter the id\n");
            char id1[10],id2[10];
            BookDB b1 = NULL;
            BookDB b2 = NULL;
            do{
                scanf("%s",id1);
                __fpurge(stdin);
                scanf("%s",id2);
                b1 = find_by_id(head,id1);
                printf("%s\n",b1->title);
                b2 = find_by_id(head,id2);
                printf("%s\n",b2->title);
            }while(b1 == NULL || b2 == NULL);
            head = swap(head,&b1,&b2);
            printf("Swap successfully\n");
            print_db(head);
            break;
        case 5:
            printf("Enter the year\n");
            int y;
            scanf("%d",&y);
            printf("Total: %d\n",count(head,y));
            break;
        case 6:
            write_db("book-out.txt",head);
            break;
        case 7:
            print_db(head);
            break;
        default:
            break;
        }
    }while(choice != 8);
=======
int main(){
    read_db("bookdb.txt");
>>>>>>> 8b12faed52230b00dee6eeddb515cda524b301ca
}