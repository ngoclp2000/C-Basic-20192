#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "main.h"
#include "dangky.h"
#include<stdio_ext.h>
int main(){
    MonHocDB db = NULL;
    DangKyDB dkdb = NULL;
    int choice;
    do{
        printf("1.Import Data\n2.Import Dangky Database\n3.Create Subject\n4.Register Subject for Student \n5.Find all by Id Subject\n6.Dem So tin chi\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                db = read_mh("monhoc.txt");
                print_mh(db);
                break;
            case 2:
                dkdb = read_dk("dangky.txt",db);
                print_dk(dkdb);
                break;
            case 3:
                printf("Enter the information of new subject\n");
                char id[10];
                int so_tin_chi,hoc_ky;
                do{
                    printf("ID: ");
                    scanf("%s",id);
                    printf("So tin chi: ");
                    scanf("%d",&so_tin_chi);
                    printf("Hoc ky: ");
                    scanf("%d",&hoc_ky);
                }while(find_mh_by_id(db,id) != NULL);
                monhoc_node_t new_node = make_node_mh(id,so_tin_chi,hoc_ky);
                db = append_mh(db,new_node);
                print_mh(db);
            break;
            case 4: 
                printf("Enter the information for register\n");
                char id_c[10];
                char id_mh[10];
                MonHocDB temp1 = db;
                DangKyDB temp2 = dkdb;
                do{
                    printf("ID: ");
                    scanf("%s",id_c);
                    printf("ID Subject: ");
                    scanf("%s",id_mh);
                }while(find_mh_by_id(temp1,id_mh) == NULL || find_dk_by_id(temp2,id_c) == NULL);
                DangKyDB current = find_dk_by_id(temp2,id_c);
                MonHocDB mh = find_mh_by_id(temp1,id_mh);
                monhoc_node_t new_node1 = make_node_mh(mh->id,mh->so_tin_chi,mh->hoc_ky);
                current->dsmh = append_mh(current->dsmh,new_node1);
                print_dk(dkdb);
            break;
            case 5:
                printf("Enter the ID of subject\n");
                char id_mh1[10];
                scanf("%s",id_mh1); 
                print_all_mh(dkdb,id_mh1);
            break;
            case 6:
                printf("Enter the id of student\n");
                char id_student[10];
                scanf("%s",id_student);
                DangKyDB current_student = find_dk_by_id(dkdb,id_student);
                int count1=0;
                int count2=0;
                MonHocDB temp_student = current_student->dsmh;
                while(current_student->dsmh != NULL){
                    if(current_student->dsmh->hoc_ky == 1) count1+= current_student->dsmh->so_tin_chi;
                    else count2+= current_student->dsmh->so_tin_chi;
                    current_student->dsmh = current_student->dsmh->next;
                }
                printf("So tin chi trong ky 1: %d\n",count1);
                printf("So tin chi trong ky 2: %d\n",count2);
            break;
        }
    }while(choice != 7);
}