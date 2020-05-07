#include<stdio.h>
#define _GNU_SOURCE
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "list-table.h"
#include "queue-wait.h"
#include "main.h"
#include<windows.h>
void initialize();
void inputGuests();
void analysis();
void printTable();
list Tables;
int num_table;

int main(){
    SetConsoleOutputCP(CP_UTF8); // Display Vietnamese
    initialize();
    int selection;
    do{
        printf("1.Set up data\n2.Show the information of table\n3.Analysis\n");
        scanf("%d",&selection);
        switch(selection){
            case 1:
                if(Tables->Guests == NULL){
                    inputGuests();
                    printf("Success\n");
                }else printf("The data has been set up\n");
            break;
            case 2:
                printTable();
            break;
            case 3:
                analysis();
            break;
        }
    }while(1);
}
void initialize(){
    printf("Enter the number of tables\n");
    scanf("%d",&num_table);
    Tables = create_list();
    for(int i = 1 ; i <= num_table ;i++){
        list t = Tables;
        while(t != NULL &&t->next != NULL) t = t->next;
        element_t n = (struct Guest *) malloc(sizeof(struct Guest));
        n->num_table = i;
        Tables = insert_after(Tables,t,n);
    }
}

int timeWaiting(element_t new_g){
    int min = 99999;
    int index = 1;
    list l = Tables;
    while(l != NULL){
        if(l->Guests == NULL){
            new_g->num_table = index;
            return 0;
        }
        queue t = last_q(l->Guests);
        int time_l = t->data->time.hour*60 + t->data->time.minute + t->data->time_wait + 15 ;
        int time_n = new_g->time.hour*60 + new_g->time.minute;
        if( time_l <= time_n){
            new_g->num_table = index;
            return 0;
        }
        // if(time_l + 15 == time_n){
        //     if(last_q(l->Guests)->data->time_wait < min){
        //         min = last_q(l->Guests)->data->time_wait;
        //         new_g->num_table = index;
        //     }
        // }
        int temp_wait = time_l - time_n ;
        if(temp_wait < min){
            new_g->num_table = index;
            min =temp_wait;
        }
        l = l->next;
        index++;
    }
    return min;    
}

void inputGuests(){
    FILE *fin = fopen("file.txt","r+");
    char *time = (char*) malloc(sizeof(char)*256);
    char *num_s = (char *) malloc(sizeof(char)*2);

    while(fscanf(fin,"%s %s\n",time,num_s) == 2){
        int num_guest = atoi(num_s);
        struct Time n;
        time = strtok(time,":");
        n.hour = atoi(time);
        time =strtok(NULL,":");
        n.minute = atoi(time);
        for(int i = 0 ; i < num_guest ; i++){
            element_t new_g = (struct Guest *) malloc(sizeof(struct Guest));
            new_g->time.hour = n.hour;
            new_g->time.minute = n.minute;
            new_g->time_wait = timeWaiting(new_g);
            //printf("%d %d\n",new_g->num_table,new_g->time_wait);
            list l = Tables;
            while(l != NULL && l->data->num_table != new_g->num_table){
                l = l->next;
            }
            l->Guests = enqueue(l->Guests,new_g);
        }
    }
}
void analysis(){
    list l = Tables;
    printf("%-6s%-15s%s\n","Table","NumberOfGuests","Avg_WaitingTime");
    while(l != NULL){
        queue t = l->Guests;
        int num_g = length_q(l->Guests);
        double sum = 0.0;
        while(t != NULL){
            sum += t->data->time_wait * 1.0;
            t = t->next;
        }
        printf("%-6d%-15d%g'(with %g minutes total)\n",l->data->num_table,num_g,sum/num_g,sum);
        l = l->next;
    }
}
char *convertTime(int time){
    char temp[5];
    int hour,minute;
    hour = time / 60;
    minute = time - hour*60;
    char *convertedTime = (char *) calloc(sizeof(char),10);
    strcat(convertedTime,"0");
    itoa(hour,temp,10);
    strcat(convertedTime,temp);
    strcat(convertedTime,"h");
    itoa(minute,temp,10);
    strcat(convertedTime,temp);
    strcat(convertedTime,"'");
    return convertedTime;
}
void printTable(){
    printf("Bank BIDV-Ha Thanh 17 Ta Quang Buu\nNumber of the service table: %d\n",num_table);
    list l = Tables;
    printf("-----------------------------------\n");
    printf("%-6s%-6s%-12s%s\n","Table","Guest","ArrivalTime","WaitingTime");
    while(l != NULL){
        queue t = l->Guests;
        int i = 1;
        while(t != NULL){
            char time[10];
            char temp[5];
            memset(time,'\0',sizeof(char)*10);
            if(t->data->time.hour < 10) strcat(time,"0");
            itoa(t->data->time.hour,temp,10);
            strcat(time,temp);
            itoa(t->data->time.minute,temp,10);
            strcat(time,":");
            if(t->data->time.minute < 10) strcat(time,"0");
            strcat(time,temp);
            char *convertedTime = convertTime(t->data->time_wait);
            printf("%-6d%-6d%-12s%s\n",t->data->num_table,i++,time,convertedTime);
            t = t->next;
        }
        printf("-----------------------------------\n");
        l = l->next;
    }
}