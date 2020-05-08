#include<stdio.h>
#define _GNU_SOURCE
#include<string.h>
#include<stdlib.h>
#include<ctype.h> 
typedef struct Infor{
    char model[35];
    char memory[35];
    char displaySize[35];
    char price[35];
}Infor_t;
int size;
Infor_t *importData;
int ChangeBinaryFile(FILE *input,FILE *output){
    int count = 0;
    while(!feof(input)){
        Infor_t *new_infor = (Infor_t *) calloc(sizeof(Infor_t),1);
        fscanf(input,"%s %s %s %s\n",new_infor->model,new_infor->memory,new_infor->displaySize,new_infor->price);
        //printf("%-30s%-20s%-20s%s\n",new_infor->model,new_infor->memory,new_infor->displaySize,new_infor->price);
        fwrite(new_infor,sizeof(Infor_t),1,output);
        free(new_infor);
        count++;
    }
    fclose(input);
    fclose(output);
    return count;
}
void importDataF(FILE *fin){
    int i = 0;
    while(!feof(fin)){
        fread((importData + i++),sizeof(Infor_t),1,fin);
    }
}
void PrintDB(){
    printf("%-35s%-35s%-35s%s\n","Model","Memory","DisplaySize","Price");
    for(int i = 0 ; i  < size ; i++){
        printf("%-35s%-35s%-35s%-35s\n",(importData+i)->model,(importData+i)->memory,(importData+i)->displaySize,(importData+i)->price);
    }
}

char *lowerWord(char word[]){
    char *lower = (char * ) malloc(sizeof(char) * (strlen(word)+1));
    for(int i = 0 ; i < strlen(word) ; i++){
        lower[i] = tolower(word[i]);
    }
    return lower;
}

int SearchingModel(char model[]){
    printf("%-35s%-35s%-35s%s\n","Model","Memory","DisplaySize","Price");
    int count = 0;
    // for(int i = 0 ; i < size ;i++){
    //     //Sequential search
    //     // if(strcmp((importData + i)->model,model) == 0){
    //     //     printf("%-35s%-35s%-35s%s\n",(importData+i)->model,(importData+i)->memory,(importData+i)->displaySize,(importData+i)->price);
    //     //     count++;
    //     //     break;
    //     // }
    //     //if(strstr(lowerWord((importData+i)->model),lowerWord(model)) == NULL) continue;
    // }
    //Sentinel search
    strcpy((importData + size)->model,model);
    int i = 0;
    while(strcmp((importData + size)->model,(importData + i)->model) != 0) i++;
    if ( i < size) return i;
    else printf("Not Found!!!!");
    printf("Found %d result(s) for '%s'\n",count,model);
    return -1;
}

int main(){
    //SetConsoleOutputCP(CP_UTF8); // Display Vietnamese
    importData = (Infor_t *) malloc(sizeof(Infor_t) *10000);
    int choice;
    do{
        printf("1.Convert Phone.txt into Phone.dat\n2.Import DB\n3.Print All DB\n4.Search by Model\n5.Exit\n");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            /* code */
            printf("\n");
            FILE *input1 = fopen("Phone.txt","r");
            FILE *output1 = fopen("Phone.dat","w+b");
            if(input1 == NULL){
                printf("Cann't open input file\n");
                return 0;
            }else if(output1 == NULL){
                printf("Cann't open output file\n");
                return 1;   
            }
            size = ChangeBinaryFile(input1,output1);
            break;
        case 2:
            if(importData != NULL) importData = (Infor_t*) malloc(sizeof(Infor_t)*size);
            FILE *fin = fopen("Phone.dat","rb");
            if(fin == NULL){
                printf("Cann't open the file\n");
                break;
            }
            importDataF(fin);
            break;
        case 3:
            PrintDB();
            break;
        case 4:
            printf("Enter the model you want to search\n");
            // FILE *input3 = fopen("Phone.dat","rb");
            // if(input3 == NULL){
            //     printf("Cann't open input file\n");
            //     return 0;
            // }
            // printf("Enter the model you want search\n");
            // char model[20];
            char model[20];
            do{
                scanf("%s",model);
            }while(strlen(model) > 20);
            int i = SearchingModel(model);
            printf("%-35s%-35s%-35s%s\n",(importData+i)->model,(importData+i)->memory,(importData+i)->displaySize,(importData+i)->price);
            break;
        default:
            break;
        }
    }while(choice != 5);
}


