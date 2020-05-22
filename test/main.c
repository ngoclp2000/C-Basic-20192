#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "main.h"
#include "tuyenxe.h"
#include<stdio_ext.h>
int main(){
    DiemDoDB dbhead = NULL;
    TuyenXeDb txhead =NULL;
    int choice;
    do{
        printf("1.ImportData\n2.Them tuyen xe\n3.Them diemdo\n4.Tim kiem\n5.Tim kiem diem do thich hop\n6.Export data\n7.Exit");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                dbhead = read_dddb("diemdo.txt");
                txhead = read_txdb("tuyenxe.txt",dbhead);
                break;
            case 2:
                printf("Enter the information\n");
                TuyenXeDb new = (struct TuyenXeNode *) malloc(sizeof(struct TuyenXeNode));
                Again2:
                printf("Enter the ID\n");
                __fpurge(stdin);
                scanf("%s",new->id);
                printf("Enter the num of parking place\n");
                scanf("%d",&(new->soDiemDo));
                printf("Enter the parking places\n");
                for(int i = 0 ; i < new->soDiemDo ; i++){
                    char id[10];
                    __fpurge(stdin);
                    scanf("%s",id);
                    DiemDoDB x = find_dd_by_id(dbhead,id);
                    if(x == NULL) goto Again2;
                    new->dsDiemDo = append_dd(new->dsDiemDo,x->id,x->x,x->y);
                }
                if(isExisttx(txhead,new->id)) goto Again2;
                txhead = append_tx(txhead,new->id,new->soDiemDo,new->dsDiemDo);
                printTuyenXe(txhead);
                break;
            case 3:
                printf("\n");
                char id_new_parking[10];
                do{
                    printf("Enter the new id parking place\n");
                    scanf("%s",id_new_parking);
                }while(isExistdd(dbhead,id_new_parking));
                DiemDoDB newdd = (struct DiemDoNode *) malloc(sizeof(struct DiemDoNode));
                strcpy(newdd->id,id_new_parking);
                do{
                    printf("Enter the coordinate\n");
                    scanf("%d %d",&(newdd->x),&(newdd->y));
                }while(isConflict(dbhead,newdd->x,newdd->y));
                dbhead = append_dd(dbhead,id_new_parking,newdd->x,newdd->y);
                printDiemDo(dbhead);
                break;
            case 4:
                    printf("All the buses pass that parking place\n");
                    char id_parking[10];
                    scanf("%s",id_parking);
                    TuyenXeDb temp = txhead;
                    while(temp != NULL){
                        if(isExistdd(temp->dsDiemDo,id_parking)){
                            printf("%s\n",temp->id);
                        }
                        temp = temp->next;
                    }
                break;
            case 5:
                    printf("Enter the coordinate\n");
                    int x,y;
                    scanf("%d %d",&x,&y);
                    int min = 9999999;
                    char id_min_parking[10];
                    DiemDoDB tempdb = dbhead;
                    while(tempdb != NULL){
                        int dis_x,dis_y;
                        dis_x = (x - tempdb->x);
                        dis_y = (y - tempdb->y);
                        int distance = dis_x*dis_x + dis_y*dis_y;
                        if(distance < min) {
                            min = distance;
                            strcpy(id_min_parking,tempdb->id);
                        }
                        tempdb = tempdb->next;
                    }
                    printf("The minimum distance parking place is at: %s\n",id_min_parking);
                    break;
            case 6:
                printf("Export Data.....\n");
                FILE *fout1 = fopen("diemdo2.txt","w+");
                FILE *fout2 = fopen("tuyenxe2.txt","w+");
                DiemDoDB out_dd = dbhead;
                TuyenXeDb out_tx = txhead;
                while(out_dd != NULL){
                    fprintf(fout1,"%s %d %d",out_dd->id,out_dd->x,out_dd->y);
                    if(out_dd->next !=NULL) fputs("\n",fout1);
                    out_dd = out_dd->next;
                }
                fclose(fout1);
                while(out_tx != NULL){
                    fprintf(fout2,"%s %d ",out_tx->id,out_tx->soDiemDo);
                    DiemDoDB t = out_tx->dsDiemDo;
                    while(t != NULL){
                        fprintf(fout2,"%s",t->id);
                        if(t->next != NULL) fputs(" ",fout2);
                        t = t->next;
                    }
                    if(out_tx->next != NULL){
                        fputs("\n",fout2);
                    }
                    out_tx = out_tx->next;
                }
                fclose(fout2);
                break;
        }
    }while(choice != 7);
}