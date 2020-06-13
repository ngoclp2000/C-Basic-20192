#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "dangky.h"
MonHocDB read_mh(char filename[]){
    FILE *fin = fopen(filename,"r");
    MonHocDB db = NULL;
    int num;
    fscanf(fin,"%d\n",&num);
    for(int i = 0 ; i < num ; i++){
        char id[10];
        int so_tin_chi,hoc_ky;
        fscanf(fin,"%s %d %d\n",id,&so_tin_chi,&hoc_ky);
        monhoc_node_t new_node = make_node_mh(id,so_tin_chi,hoc_ky);
        db = append_mh(db,new_node);
    }
    return db;
}
DangKyDB read_dk(char filename[],MonHocDB db){
    FILE *fin = fopen(filename,"r");
    DangKyDB dkdb = NULL;
    int num;
    fscanf(fin,"%d\n",&num);
    for(int i = 0 ; i < num ; i++){
        DangKyDB new_node_dk = (DangKyDB) malloc(sizeof(struct DangKyNode));
        new_node_dk->dsmh = NULL;
        new_node_dk->next = NULL;
        int so_mon;
        char id[10];
        fscanf(fin,"%s ",id);
        fscanf(fin,"%d ",&so_mon);
        new_node_dk->so_mon = so_mon;
        strcpy(new_node_dk->id,id);
        for(int i = 0 ; i < so_mon ; i++){
            char id_mh[10];
            if(i != 2) fscanf(fin,"%s ",id_mh);
            else fscanf(fin,"%s\n",id_mh);
            monhoc_node_t new_node = find_mh_by_id(db,id_mh);
            new_node_dk->dsmh = append_mh(new_node_dk->dsmh,make_node_mh(new_node->id,new_node->so_tin_chi,new_node->hoc_ky));
        }
        dkdb = append_dd(dkdb,new_node_dk);
    }
    return dkdb;
}
MonHocDB make_node_mh(char id[],int so_tin_chi,int hoc_ky){
    MonHocDB new_node = (struct MonHocNode *) malloc(sizeof(struct MonHocNode));
    strcpy(new_node->id,id);
    new_node->so_tin_chi = so_tin_chi;
    new_node->hoc_ky = hoc_ky;
    new_node->next = NULL;
    return new_node;
}
MonHocDB append_mh(MonHocDB db,monhoc_node_t new_node){
    monhoc_node_t original = db;
    if (db == NULL) return new_node;
    for(db;db->next != NULL;db = db->next);
    db->next = new_node;
    return original;
}
DangKyDB append_dd(DangKyDB dkdb,DangKyDB new_node){
    if(dkdb == NULL) return new_node;
    DangKyDB original = dkdb;
    for(dkdb;dkdb->next != NULL;dkdb=dkdb->next);
    dkdb->next = new_node;
    return original;
}
void print_mh(MonHocDB db){
    printf("%-5s%-11s%s\n","ID","So_Tin_Chi","Hoc_Ky");
    while(db != NULL){
        printf("%-5s%-11d%d\n",db->id,db->so_tin_chi,db->hoc_ky);
        db = db->next;
    }
}
void print_dk(DangKyDB dkdb){
    printf("%-5s%-11s%s\n","ID","So_Tin_Chi","Danh_Sach_Dang_Ky");
    while(dkdb != NULL){
        printf("%-5s%-11d",dkdb->id,dkdb->so_mon);
        MonHocDB temp = dkdb->dsmh;
        while(dkdb->dsmh != NULL){
            printf("%s",dkdb->dsmh->id);
            if(dkdb->dsmh->next != NULL) printf(" ");
            dkdb->dsmh = dkdb->dsmh->next;
        }
        printf("\n");
        dkdb->dsmh = temp;
        dkdb = dkdb->next;
    }
}
struct MonHocNode *find_mh_by_id(MonHocDB db,char id[]){
    while(db != NULL && strcmp(id,db->id) != 0) db = db->next;
    return db;
}
struct DangKyNode *find_dk_by_id(DangKyDB dkdb,char id[]){
    while(dkdb != NULL && strcmp(id,dkdb->id) != 0) dkdb = dkdb->next;
    return dkdb;
}
int isExists(MonHocDB db,char id[]){
    MonHocDB temp = db;
    while(db != NULL && strcmp(id,db->id) != 0)
        db = db->next;
    if(db == NULL) return 0;
    db = temp;
    return 1;
}
void print_all_mh(DangKyDB dkdb,char id[]){
    int count = 0;
    while(dkdb != NULL){
        if( isExists(dkdb->dsmh,id) == 1 ){
            count++;
            printf("%s ",dkdb->id);
        }
        dkdb = dkdb->next;
    }
    printf("\n");
    if( count == 0 ) printf("Khong tim thay\n");
}