#ifndef tuyenxe_H
#define tuyenxe_H

struct diemdonode
{
  char id[10];
  int x;
  int y;
  struct diemdonode *next;
};
typedef struct diemdonode* diemdodb;

struct tuyenxenode
{
  char id[10];
  int sodiemdo;
  diemdodb dsdiemdo;
  struct tuyenxenode *next;
};
typedef struct tuyenxenode *tuyenxedb;

diemdodb make_dd(char id[],int x,int y);

diemdodb create_diemdodb();

tuyenxedb create_tuyenxedb();

int is_empty(diemdodb l);

diemdodb reverse(diemdodb l);

diemdodb addtail(diemdodb head,diemdodb x);

diemdodb InsertAtPosition(diemdodb head,diemdodb x,int position);

diemdodb DeleteAtPosition(diemdodb head,int position);

void free_diemdodb(diemdodb l);

void printout(diemdodb l);

diemdodb read_db(char filename[]);

diemdodb finddd_by_id(diemdodb db, char id[]);

diemdodb remove_by_id(diemdodb db, char id[]);

void write_db(char filename[],diemdodb list);

diemdodb swap(diemdodb db,diemdodb b1,diemdodb b2);

void print_book(diemdodb b);

void print_db(diemdodb db);
//
diemdodb read_dddb(char filename[]);

tuyenxedb read_txdb(char filename[],diemdodb ddlist);

void write_dddb(char filename[],diemdodb dddb);

void write_txdb(char filname[],tuyenxedb txdb);

diemdodb append_dd(diemdodb db,char id[],int x,int y);

tuyenxedb append_tx(tuyenxedb db,char id[],int sodiemdo,diemdodb dsdiemdo);

diemdodb nearest(diemdodb db,int x,int y);

tuyenxedb findtx_by_id(tuyenxedb db,char id[]);

void printtx(tuyenxedb txlist);

void printdd(diemdodb ddlist);



#endif