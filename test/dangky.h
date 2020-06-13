#ifndef __dangky__
#define __dangky__
#include "main.h"
MonHocDB read_mh(char filename[]);
DangKyDB read_dk(char filename[],MonHocDB db);
MonHocDB append_mh(MonHocDB db,monhoc_node_t new_node);
DangKyDB append_dd(DangKyDB dkdb,DangKyDB new_node);
struct MonHocNode *find_mh_by_id(MonHocDB db,char id[]);
struct DangKyNode *find_dk_by_id(DangKyDB dkdb,char id[]);
MonHocDB make_node_mh(char id[],int so_tin_chi,int hoc_ky);
void print_mh(MonHocDB db);
void print_dk(DangKyDB dkdb);
int isExists(MonHocDB db,char id[]);
void print_all_mh(DangKyDB dkdb,char id[]);
#endif