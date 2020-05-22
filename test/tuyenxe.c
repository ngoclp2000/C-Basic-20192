#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "tuyenxe.h"
#include "main.h"
DiemDoDB read_dddb(char *filename){
    FILE *fin = fopen(filename,"r+");
    int n = (int)fgetc(fin) - 48;
    fgetc(fin);
    char id[10];
    int x,y;
    DiemDoDB head = NULL;
    while(n != 0){
        fscanf(fin,"%s %d %d\n",id,&x,&y);
        head = append_dd(head,id,x,y);
        n--;
    }
    printDiemDo(head);
    return head;
}
TuyenXeDb read_txdb(char *filename,DiemDoDB diemdoDB){
    FILE *fin = fopen(filename,"r+");
    TuyenXeDb head = NULL;
    int n = (int)fgetc(fin) - 48;
    fgetc(fin);
    char id[10];
    int sodiemDo;
    while(n != 0){
        DiemDoDB dsDiemDo = NULL;
        char *input = (char *) malloc(sizeof(char) *100);
        fgets(input,100,fin);
        input = strtok(input," ");
        strcpy(id,input);
        input = strtok(NULL," ");
        sodiemDo = atoi(input);
        for(int i = 0 ; i < sodiemDo ; i++){
            input = strtok(NULL," ");
            if(strlen(input) != 4)
                input[strlen(input) - 1] = '\0';
            DiemDoDB new = find_dd_by_id(diemdoDB,input);
            dsDiemDo = append_dd(dsDiemDo,input,new->x,new->y);
        }
        head = append_tx(head,id,sodiemDo,dsDiemDo);
        n--;
    }
    printTuyenXe(head);
    return head;
}
DiemDoDB append_dd(DiemDoDB db,char id[],int x,int y){
    DiemDoDB n = (struct DiemDoNode *) malloc(sizeof(struct DiemDoNode));
    DiemDoDB origin = db;
    n->next = NULL;
    strcpy(n->id,id);
    n->x = x;
    n->y = y;
    if(db == NULL) return n;
    while(db->next != NULL)
        db = db->next;
    db->next = n;
    return origin;
}
TuyenXeDb append_tx(TuyenXeDb tx,char id[],int soDiemDo,DiemDoDB dsDiemdo){
    TuyenXeDb n = (struct TuyenXeNode *) malloc(sizeof(struct TuyenXeNode));
    TuyenXeDb origin = tx;
    n->next = NULL;
    strcpy(n->id,id);
    n->soDiemDo = soDiemDo;
    n->dsDiemDo = dsDiemdo;
    if(tx == NULL) return n;
    while(tx->next != NULL)
        tx= tx->next;
    tx->next = n;
    return origin;
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
struct DiemDoNode *find_dd_by_id(DiemDoDB db,char id[]){
    while(db != NULL && strcmp(id,db->id) != 0)
        db = db->next;
    return db;
}
void printDiemDo(DiemDoDB db){
    printf("%-10s%s\n","Diem Do","Toa Do");
    while(db != NULL){
        printf("%-10s(%d,%d)\n",db->id,db->x,db->y);
        db = db->next;
    }
}
void printTuyenXe(TuyenXeDb tx){
    printf("%-10s%s\n","Tuyen Xe","Lo Trinh");
    while(tx != NULL){
        printf("%-10s",tx->id);
        DiemDoDB t = tx->dsDiemDo;
        printf("[");
        while(t != NULL){
            printf("%s",t->id);
            if(t->next != NULL) printf(",");
            t = t->next;
        }
        printf("]\n");
        tx = tx->next;
    }
}
int isExisttx(TuyenXeDb tx,char id[]){
    while(tx != NULL && strcmp(id,tx->id) != 0)
        tx = tx->next;
    if(tx == NULL) return 0;
    return 1;
}
int isExistdd(DiemDoDB db,char id[]){
    while(db != NULL && strcmp(id,db->id) != 0)
        db = db->next;
    if(db == NULL) return 0;
    return 1;
}
int isConflict(DiemDoDB db,int x,int y){
    while(db != NULL){
        if(db->x == x && db->y == y)
            return 1;
        db = db->next;
    }
    return 0;
}