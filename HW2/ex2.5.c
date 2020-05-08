#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct phoneaddress_t{
    char name[100];
    char tel[10];
    char email[100];
}tel_add;

void inputPhone(tel_add arr[],int n){
    int i=0;
    printf("%d",n);
    for(i=0;i<n;i++){
        printf("No %d.\n",i+1);
        printf("Name: ");
        fflush(stdin);
        gets(arr[i].name);
        printf("Tel Number: ");
        fflush(stdin);
        do{
            gets(arr[i].tel);
            if(strlen(arr[i].tel)>10){
                printf("Invalid phone number. Please input again.\n");
            }
        }while(strlen(arr[i].tel)>10);
        printf("Email: ");
        fflush(stdin);
        gets(arr[i].email);
    }
    
}

void WriteFile(FILE* input,tel_add arr[],int n){
    int num;
    num=fwrite(arr,sizeof(tel_add),n,input);
    printf("fwrite returns code %d.\n",num);
}

int main(){
    FILE* input=fopen("tringu.txt","wb");
    int n;
    printf("How many contacts do you want to enter? ");
    scanf("%d",&n);
    tel_add arr[n];
    int num,num1,num2,num3,num4;
    inputPhone(arr,n);
    //printf("%s%s%s\n",(arr+0)->name,(arr+0)->tel,(arr+0)->email);
    WriteFile(input,arr,n);
    for(int i=0;i<n;i++){
        printf("%-5d%-20s%-10s%-20s",i+1,arr[i].name,arr[i].tel,arr[i].email);
        printf("\n");
    }
    // num1=fread(arr,sizeof(tel_add),n,input);
    // printf("fread returns code %d.\n",num1);
    // printf("How many contacts do you want to load? ");
    // scanf("%d",&num2);
    // tel_add *tel_arr=(tel_add*)malloc(num2*sizeof(tel_add));
    // if(tel_arr==NULL){
    //     printf("Memory allocated failed.\n");
    // }
    // if(fseek(input,1*sizeof(tel_add),SEEK_SET)!=0){
    //     printf("fseek failed.\n");
    // }
    // num3=fread(tel_arr,sizeof(tel_add),num2,input);
    // for(int i=0;i<num2;i++){
    //     printf("Name: %s\n",tel_arr[i].name);
    //     printf("Tel: %s\n",tel_arr[i].tel);
    //     printf("Email: %s\n",tel_arr[i].email);
    // }
    // strcpy(tel_arr[0].name,"Hoang Minh Tri");
    // strcpy(tel_arr[0].tel,"0916286767");
    // strcpy(tel_arr[0].email,"tridlfc2000@gmail.com");  
    // num4=fwrite(tel_arr,sizeof(tel_add),num2,input);
    // free(tel_arr);
    fclose(input);
}
