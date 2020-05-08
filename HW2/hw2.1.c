#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char model[20];
    char memory[10];
    char screen[10];
    char price[15];
}phone;

void intob(FILE *writep)
{   FILE *ptr;
    phone arrtmp[100];
    ptr=fopen("mytext.txt","r");
    int num=0;
    while(!feof(ptr))
    {
        num=fread(arrtmp,sizeof(phone),100,ptr);
        printf("%d\n",num);
    }
    fwrite(arrtmp,sizeof(phone),num,writep);  
    printf("num:%d\n",num);
    fclose(ptr);
}

void readb(phone *arr,FILE *read,int *num)
{   char arrtmp[100];
    while(!feof(read))
    {
        *num=fread(arr,sizeof(phone),100,read);
    }
    printf("num:%d\n",*num);
}

void search(phone arr[],int num)
{
    char name[20];
    printf("What model are u looking for?\n");
    fflush(stdin);
    gets(name);
    printf("\nYour product:\n");
    printf("%-20s%-10s%-10s%-10s\n","Model","Memory","Screen","Price");
    for(int i=0;i<num;i++)
    {   
        if(strcmp(name,arr[i].model)==0)
        {  
            printf("%-20s%-10s%-10s%-10s\n",arr[i].model,arr[i].memory,arr[i].screen,arr[i].price); 
        }        
    }
}

void insert()
{   phone arr[100];
    int number=0;
    printf("how many data do you want to insert?(max 100):\n");
    scanf("%d",&number);
    FILE *ptr;
    ptr=fopen("mytext.txt","w+");
    for(int i=0;i<number;i++)
    {
        printf("Pls insert data %d by the form(model memory screen price):\n",i+1);
        fflush(stdin);
        gets(arr[i].model);
        gets(arr[i].memory);
        gets(arr[i].screen);
        gets(arr[i].price);
    }
    fwrite(arr,number,sizeof(phone),ptr);
    fclose(ptr);
}
int main()
{   int choice=0;
    int datanum=0;
    phone arrorg[100];
    FILE *input,*output;
    output=fopen("mytextb.dat","w+b");
    input=fopen("mytextb.txt","rb");
    do
    {   printf("\n---------------------------MENU---------------------------");
        printf("\n1.Import DB from text:");
        printf("\n2.Import from DB:");
        printf("\n3.Print all Iphone Database:");
        printf("\n4.Search by model:");
        printf("\n5.Insert file text:");
        printf("\n6.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: intob(output);
                    printf("File mytext.txt is tranferred into file binary(textb.txt)\n");
                    rewind(output);
                    break;
            case 2: readb(arrorg,input,&datanum);
                    rewind(input);
                    break;
            case 3: printf("%-20s%-10s%-10s%-10s\n","Model","Memory","Screen","Price");
                    for(int i=0;i<datanum;i++)
                    {
                        printf("%-20s%-10s%-10s%-10s\n",arrorg[i].model,arrorg[i].memory,arrorg[i].screen,arrorg[i].price);                       
                    }
                    break;
            case 4: search(arrorg,datanum);
                    break;
            case 5: insert();
                    break;
            case 6: printf("Gut pai\n");
                    break;          
            default: printf("Wrong Choice. Enter again\n");
                    break;              
        }
    } while (choice!=6);
    fclose(input);
    fclose(output);
    return 0;
}