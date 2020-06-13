#ifndef _MAIN_H_
#define _MAIN_H_
struct MonHocNode{
    char id[10];
    int so_tin_chi;
    int hoc_ky;
    struct MonHocNode *next;
};
typedef int element_t;
typedef struct MonHocNode *monhoc_node_t;
typedef struct MonHocNode *MonHocDB;
struct DangKyNode{
    char id[10];
    int so_mon;
    MonHocDB dsmh;
    struct DangKyNode *next;
};
typedef struct DangKyNode *DangKyDB;
#endif