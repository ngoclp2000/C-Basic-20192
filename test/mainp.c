#include<stdio.h>
#include<stdlib.h>
#include "tuyenxep.h"
#include<string.h>
diemdodb ddlist;
tuyenxedb txlist;
diemdodb adddd()
{   char idin[10];
    int xin=0,yin=0;
    printf("nhap ID: ");
    fflush(stdin);
    gets(idin);
    while((finddd_by_id(ddlist,idin))!=NULL)
    {
        printf("ID ton tai,nhap lai id khac: ");
        gets(idin);
    }
    printf("nhap toa do theo dang x y: ");
    scanf("%d %d",&xin,&yin);
    // int flag=0;
    // for(diemdodb cur=ddlist;cur!=NULL;cur=cur->next)
    // {   
    //     if(cur->id==idin)
    //         flag=1;
    // }
    // if(flag==0)
    // {
    //     printf("diem den khong nam trong danh sach,xin nhap lai tu dau\n ");
    //     exit(0);
    // }
    diemdodb tmp=make_dd(idin,xin,yin);
    ddlist=addtail(ddlist,tmp);
    return ddlist;
}

int main()
{   
    ddlist=create_diemdodb();
    txlist=create_tuyenxedb();
    int choice=0;
    do
    {   printf("\n--------------------MENU--------------------\n");
        printf("1.Import from FILE\n");
        printf("2.ADDING STATION\n");
        printf("3.ADDING BUS\n");
        printf("4.PASSING BY BUS\n");
        printf("5.QUICKEST PATH\n");
        printf("6.SAVE\n");
        printf("7.QUIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: ddlist=read_dddb("diemdo.txt");
                //printdd(ddlist);
                txlist=read_txdb("tuyenxe.txt",ddlist);
                //printtx(txlist);
               // printf("read succesfully\n");
                break;
        case 2: ddlist=adddd();
                printdd(ddlist);
                break;
        case 5: 
        break;
        case 7: printf("Gud Pai\n"); 
                break;                                                        
        default:printf("Invalid\n");
                break;
        }
    }while(choice!=7);
}