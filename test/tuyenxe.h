#ifndef _Book_
#define _Book_
#include "main.h"
    DiemDoDB read_dddb(char *filename);
    TuyenXeDb read_txdb(char *filename,DiemDoDB diemdoDB);
    void write_dddb(char *filename,DiemDoDB dddb);
    void write_txdb(char *filename,TuyenXeDb txdb);
    DiemDoDB append_dd(DiemDoDB db,char id[],int x,int y);
    TuyenXeDb append_tx(TuyenXeDb tx,char id[],int soDiemDo,DiemDoDB dsDiemDo);
    struct DiemDoNode *find_dd_by_id(DiemDoDB db,char id[]);
    struct TuyenXeNode *find_tx_by_id(TuyenXeDb tx,char id[]);
    void printDiemDo(DiemDoDB db);
    void printTuyenXe(TuyenXeDb tx);
    int isExisttx(TuyenXeDb tx,char id[]);
    int isExistdd(DiemDoDB db,char id[]);
    int isConflict(DiemDoDB db,int x,int y);
#endif