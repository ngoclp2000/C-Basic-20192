#ifndef _MAIN_H_
#define _MAIN_H_
struct DiemDoNode{
    char id[10];
    int x;
    int y;
    struct DiemDoNode *next;
};
typedef int element_t;
typedef struct DiemDoNode *DiemDoDB;
struct TuyenXeNode{
    char id[10];
    int soDiemDo;
    DiemDoDB dsDiemDo;
    struct TuyenXeNode *next;
};
typedef struct TuyenXeNode *TuyenXeDb;
#endif