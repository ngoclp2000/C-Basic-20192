#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tuyenxep.h"

diemdodb make_dd(char id[],int x,int y)
{
  diemdodb tmp=(diemdodb)malloc(sizeof(struct diemdonode));
  tmp->next=NULL;
  strcpy(tmp->id,id);
  tmp->x=x;
  tmp->y=y;
  return tmp;
}

tuyenxedb make_tx(char id[],int sodiemdo,diemdodb ddlist)
{
  tuyenxedb tmp=(tuyenxedb)malloc(sizeof(struct tuyenxenode));
  tmp->next=NULL;
  strcpy(tmp->id,id);
  tmp->sodiemdo=sodiemdo;
  tmp->dsdiemdo=ddlist;
  return tmp;
}

diemdodb create_diemdodb() {
  return NULL;
}
tuyenxedb create_tuyenxedb() {
  return NULL;
}

int is_empty(diemdodb l) {
  return (l == NULL);
}

void free_diemdodb(diemdodb l) {
  diemdodb p = l;

  while (p != NULL) {
    l = p->next;
    free(p);
    p = l;
  }
}

diemdodb reverse(diemdodb l)
{
  diemdodb next,pre,cur;
    cur=l;
    next=NULL;
    pre=NULL;
    while(cur!=NULL)
    {   
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}

diemdodb addtail(diemdodb ddlist,diemdodb x)
{
  diemdodb p;
  if(ddlist==NULL)
  {
     ddlist=x;
  }
  else
  {   p=ddlist;
      while(p->next!=NULL)
      {
        p=p->next;
      }
      p->next=x;
  }  
  return ddlist;
}

tuyenxedb addtailtx(tuyenxedb ddlist,tuyenxedb x)
{
  tuyenxedb p;
  if(ddlist==NULL)
  {
     ddlist=x;
  }
  else
  {   p=ddlist;
      while(p->next!=NULL)
      {
        p=p->next;
      }
      p->next=x;
  }  
  return ddlist;
}

diemdodb DeleteAtPosition(diemdodb head,int position)
{
  diemdodb pre,cur;
    cur=head;
    if(position==1)
    {
        pre=(diemdodb)malloc(sizeof(diemdodb));
        pre=cur->next;
        return pre;
    }
    else
    {
        for(int i=1;i<position;i++)
        {   
            pre=cur;
            cur=cur->next;        
        }       
        pre->next=cur->next;
        return head;
    }
}

diemdodb remove_by_id(diemdodb db, char id[])
{ 
  int k=1;
  for(diemdodb cur=db;cur!=NULL;cur=cur->next)
  {
    if(strcmp(cur->id,id)==0)
    {
      break;
    }
    k++;
  }
  db=DeleteAtPosition(db,k);
  return db;
}

diemdodb swap(diemdodb db,diemdodb b1,diemdodb b2)
{ 
  diemdodb prev1=db,prev2=db,tmp;
  if(b1==db)
    prev1=NULL;
  else
  {
    while(prev1->next!=b1)
    {
      prev1=prev1->next;
    }
  }
  if(b1->next==b2)
  { 
    if(b1==db)
    {
      tmp=b2->next;
      b2->next=b1;
      b1->next=tmp;
      return b2;
    }
    else 
    {
      tmp=b2->next;
      b2->next=b1;
      b1->next=tmp;
      prev1->next=b2;
      return db;
    }
  }
  if(b2==db)
    prev2=NULL;
  else
  {
    while(prev2->next!=b2)
    {
      prev2=prev2->next;
    }
  }
  //printf("%s // %s",prev1->id,prev2->id);
  if (b1==b2)
    return db;
  tmp=b2->next;
  b2->next=b1->next;
  b1->next=tmp;
  if(prev1==NULL)
  {
    prev2->next=b1;
    return b2;
  }
  if(prev2==NULL)
  {
    prev1->next=prev2;
    return b1;
  }
  if(prev1!=NULL && prev2 !=NULL)
  {
    prev1->next=b2;
    prev2->next=b1;
  }
  return db;
}

diemdodb read_dddb(char filename[])
{ 
  diemdodb ddlist;
  ddlist=create_diemdodb();
  FILE *input=fopen(filename,"r+");
  char idin[10];
  int xin=0,yin=0;
  if(input==NULL)
  {
    printf("open fail\n");
    exit(0);
  }
  //else printf("ok\n");
  int num=0;
  int trash=0;
  num=(int)fgetc(input)-48;
  trash=fgetc(input);
  //printf("%d",num);
  for(int i=0;i<num;i++)
  { diemdodb tmp;
    //printf("ok\n");
    fscanf(input,"%s %d %d\n",idin,&xin,&yin);
    tmp=make_dd(idin,xin,yin);
    ddlist=addtail(ddlist,tmp);
  }
  fclose(input);
  return ddlist;
}

tuyenxedb read_txdb(char filename[],diemdodb ddlist)
{ 
  FILE *fin = fopen(filename,"r+");
    tuyenxedb txlist = NULL;
    int n = (int)fgetc(fin) - 48;
    int trash=fgetc(fin);
    char id[10];
    int sodiemDo;
    for(int i=0;i<n;i++)
    {
        diemdodb dsDiemDo = NULL;
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
            diemdodb new = finddd_by_id(ddlist,id);
            printf("%s %d %d\n",new->id,new->x,new->y);
            dsDiemDo = addtail(dsDiemDo,new);
        }
        tuyenxedb tuyenxenodetmp=make_tx(id,sodiemDo,dsDiemDo);
        txlist = addtailtx(txlist,tuyenxenodetmp);
    }
    return txlist;
}

void write_dddb(char filename[],diemdodb dddb);

void write_txdb(char filname[],tuyenxedb txdb);

diemdodb append_dd(diemdodb db,char id[],int x,int y);

tuyenxedb append_tx(tuyenxedb db,char id[],int sodiemdo,diemdodb dsdiemdo);

diemdodb nearest(diemdodb db,int x,int y);

tuyenxedb findtx_by_id(tuyenxedb db,char id[])
{
  for(tuyenxedb cur=db;cur!=NULL;cur=cur->next)
  {
    if(strcmp(cur->id,id)==0)
    {
      return cur;
    }
  }
  return NULL;
}

diemdodb finddd_by_id(diemdodb db, char id[])
{
  for(diemdodb cur=db;cur!=NULL;cur=cur->next)
  {
    if(strcmp(cur->id,id)==0)
    {
      return cur;
    }
  }
  return NULL;
}

void printdd(diemdodb ddlist)
{
  printf("cac diem do:\n");
  printf("%-10s%-10s\n","DIEM DO","TOA DO");
  for(diemdodb cur=ddlist;cur!=NULL;cur=cur->next)
  {
    printf("%-10s(%5d:%-5d)\n",cur->id,cur->x,cur->y);
  }
}

void printtx(tuyenxedb txlist)
{
  printf("cac tuyen xe:\n");
  for(tuyenxedb cur=txlist;cur!=NULL;cur=cur->next)
  {
    printf("%-5s%-5d\n",cur->id,cur->sodiemdo);
    printdd(cur->dsdiemdo);
    printf("\n");
  }
}