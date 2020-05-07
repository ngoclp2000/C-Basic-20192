#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
enum{FAIL,SUCCESS};

typedef struct PHONE_INFO{
    char model[30];
    char memory[30];
    char displaySize[30];
    char price[30];
}phone_t;

typedef struct LinkedList{
    phone_t *info;
    struct LinkedList *next;
}node;

node* head=NULL;
node* cur=NULL;

void FreeData(){
    node *tmp;
    cur=head;
    while(cur!=NULL){
        tmp=cur;
        cur=cur->next;
        free(tmp);
    }
    head=NULL;
    cur=NULL;
}

void Convert_Linkedlist(node **head){
    FILE* fin=fopen("Phone.txt","r");
    FILE* fout=fopen("Phone.dat","wb");
    if(fin==NULL){
        printf("Cannot open file\n");
        return;
    }else if(fout==NULL){
        printf("Cannot open file\n");
        return;
    }else{
        while(!feof(fin)){
            node* ptr=(node *)malloc(1*sizeof(node));
            ptr->info=(phone_t *)malloc(1*sizeof(phone_t));
            fscanf(fin,"%s%s%s%s\n",ptr->info->model,ptr->info->memory,ptr->info->displaySize,ptr->info->price);
            fwrite(ptr->info,sizeof(phone_t),1,fout);
            ptr->next=NULL;
            //scan to linked list
            if((*head)==NULL){
                (*head)=ptr;
            }else{
                node* tmp=(*head);
                //traversing the list
                while(tmp->next!=NULL){
                    tmp=tmp->next;
                }
                tmp->next=ptr;
            }
        }
    }
    fclose(fin);
    fclose(fout);
}

void PrintList(node *head){
    printf("%-30s%-30s%-30s%-30s\n","Model","Memory","Display Size","Price");
    while(head!=NULL){
        printf("%-30s%-30s%-30s%-30s\n",head->info->model,head->info->memory,head->info->displaySize,head->info->price);
        head=head->next;
    }
}

void Insert_Update(node *head){
    int n;
    printf("How many models do you want to add more? ");
    do{
        do{
            scanf("%d",&n);
            if(n<0){
                printf("Invalid. Enter again.\n");
            }
        }while(n<0);
        node *add=(node *)malloc(1*sizeof(node));
        add->info=(phone_t*)malloc(1*sizeof(phone_t));
        add->next=NULL;
        printf("Model: ");
        fflush(stdin);
        gets(add->info->model);
        printf("Memory: ");
        fflush(stdin);
        gets(add->info->memory);
        printf("Display Size: ");
        fflush(stdin);
        gets(add->info->displaySize);
        printf("Price: ");
        fflush(stdin);
        gets(add->info->price);
        // Upgrading to the list
        if(head==NULL){
            head=add;
        }else{
            node* tmp=head;
            while(tmp->next!=NULL){
                tmp=tmp->next;
            }
            tmp->next=add;
        }
        n--;
    }while(n>0);
}

char *lowerChar(char word[]){
    char *lower=(char*)malloc((strlen(word)+1)*sizeof(char));
    for(int i=0;i<strlen(word);i++){
        lower[i]=tolower(word[i]);
    }
    return lower;
}

void Search(node *head){
    char model[30];
    node *tmp;
    int n=0;
    printf("Search model: ");
    fflush(stdin);
    gets(model);
    printf("%-30s%-30s%-30s%-30s\n","Model","Memory","Display Size","Price");
    for(tmp=head;tmp!=NULL;tmp=tmp->next){
        if(strstr(lowerChar(tmp->info->model),lowerChar(model))!=NULL){
            printf("%-30s%-30s%-30s%-30s\n",tmp->info->model,tmp->info->memory,tmp->info->displaySize,tmp->info->price);
            n++;
        }else if(tmp==NULL){
            printf("Cannot find.\n");
        }
    }
    printf("Find %d result(s) for '%s'.\n",n,model);
}

node* insert_pos(node *head, phone_t *add, int *n){
    int position;
    printf("At which position do you want to add? ");
    do{
        scanf("%d",&position);
        if(position<0){
            printf("Invalid.Please input again.\n");
        }
    }while(position<0);
    add=(phone_t*)malloc(1*sizeof(phone_t));
    printf("Model: ");
    scanf("%s",add->model);
    printf("Memory: ");
    scanf("%s",add->memory);
    printf("Display size: ");
    scanf("%s",add->displaySize);
    printf("Price: ");
    scanf("%s",add->price);
    node *tmp=(node*)malloc(1*sizeof(node));
    node *p=(node*)malloc(1*sizeof(node));
    tmp->info=add;
    tmp->next=NULL;
    p=head;
    if(position==0){
        tmp->next=head->next;
        head->next=tmp;
    }else{
        for(int j=0;j<position;j++){
            p=p->next;
        }
        tmp->next=p->next;
        p->next=tmp;
        printf("\nData at position %d is %s %s %s %s.\n",position,p->next->info->model,p->next->info->memory,p->next->info->displaySize,p->next->info->price);
    }
    (*n)=(*n)+1;
    return head;
}

node* Delete_pos(node *head,int *n){
    int pos;
    printf("At which position do you want to delete? ");
    do{
        scanf("%d",&pos);
        if(pos<0){
            printf("Invalid.Please input again.\n");
        }
    }while(pos<0);
    node *tmp,*p;
    tmp=(node*)malloc(1*sizeof(node));
    p=(node*)malloc(1*sizeof(node));
    p=head;
    if(pos==0){
        tmp=p->next;
        (*n)-=1;
        return tmp;
    }else{
        for(int k=0;k<pos;k++){
            tmp=p;
            p=p->next;
        }
        tmp->next=p->next;
        printf("Deleted node: %s %s %s %s\n",p->info->model,p->info->memory,p->info->displaySize,p->info->price);
        (*n)-=1;
        return head;
    }
}

node* ReverseList(node* head){
    node *pre,*cur,*next;
    cur=head;
    pre=NULL;
    next=NULL;
    while(cur!=NULL){
        next=cur->next; // store the next node value
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}

node* insertfirst(node* head,phone_t *add){
    add=(phone_t*)malloc(1*sizeof(phone_t));
    printf("Model: ");
    scanf("%s",add->model);
    printf("Memory: ");
    scanf("%s",add->memory);
    printf("Display size: ");
    scanf("%s",add->displaySize);
    printf("Price: ");
    scanf("%s",add->price);
    node *tmp;
    tmp->info=(phone_t*)malloc(1*sizeof(phone_t));
    tmp->info=add;
    tmp->next=NULL;

    tmp->next=head;
    //head=tmp;

    return tmp;
}
void InsertToLast(node **headnode,node *newNode){
    node *runNode = (*headnode);
    newNode->next = NULL;
    if(runNode == NULL){
        (*headnode) = newNode;
        return;
    }
    while(runNode->next != NULL){
        runNode = runNode->next;
    }
    runNode->next = newNode;
}
node *Remove(node *p){
    node *prev = NULL;
    node *temp = head;
    while(temp ->next != NULL && p->next != temp){
        prev = temp;
        temp = temp->next;
    }
    prev->next = p->next;
    return p;
}
node* Split(node* head){
    int n1,n2;
    printf("At which position do you want to split? ");
    scanf("%d",&n1);
    printf("The length of list: ");
    scanf("%d",&n2);
    node *p=(node*)malloc(sizeof(node));
    node *arr=NULL;
    p=head;
    int i = 0;
    for(;p != NULL && i<n1; i++ , p = p->next);
    int limit = n1+n2;
    while(n1 < limit && p!= NULL){
        node *temp = p->next;
        InsertToLast(&arr,Remove(p));
        n1++;
        p = temp;
    }
    return arr;
}

// void Save(node* head,phone_t *arr,FILE *output){
//     node *p=head;
//     while(p!=NULL){
//         arr=p->info;
//         fwrite(arr,sizeof(phone_t),1,output);
//         p=p->next;
//     }
//}

int main(){
    int choice;
    do{
        printf("1.Convert file to linked list and binary file.\n2.Print linked list.\n3.Insert and update linked list(addtail).\n4.Search model.\n5.Insert at positon.\n6.Delete at position.\n7.Reverse List.\n8.Split list.\n9.Insert First.\n10.Save.\n11.Exit.\n");
        printf("Choice: ");
        do{
            scanf("%d",&choice);
            if(choice<=0){
                printf("Invalid choice. Choose again.\n");
            }
        }while(choice<=0);
        switch(choice){
            case 1:
                Convert_Linkedlist(&head);
                break;
            case 2:
                PrintList(head);
                break;
            case 3:
                Insert_Update(head);
                break;
            case 4:
                Search(head);
                break;
            case 5:;
                int n;
                phone_t *add;
                head=insert_pos(head,add,&n);
                PrintList(head);
                break;
            case 6:;
                int n1;
                head=Delete_pos(head,&n1);
                PrintList(head);
                break;
            case 7:
                head=ReverseList(head);
                printf("\n");
                PrintList(head);
                break;
            case 8:;
                node *a;
                a=Split(head);
                PrintList(a);
                break;
            case 9:;
                phone_t *in;
                head=insertfirst(head,in);
                PrintList(head);
                break;
            // case 10:;
            //     FILE* fin=fopen("Phone.txt","r");
            //     FILE* fout=fopen("PhoneOutput.txt","w");
            //     int num;
            //     int reval=SUCCESS;
            //     phone_t *arr;
            //     if(fin==NULL){
            //         printf("Cannot open file to read.\n");
            //         reval=FAIL;
            //         return reval;
            //     }else if(fout==NULL){
            //         printf("Cannot open file to save.\n");
            //         reval=FAIL;
            //         return reval;
            //     }else{
            //         while(!feof(fin)){
            //             num=fread(arr,sizeof(phone_t),1,fin);
            //             Save(head,arr,fout);
            //         }
            //     }
            //     fclose(fin);
            //     fclose(fout);
            //     break;
            case 11:
                break;
            default:
                break;
        }
        printf("\n");
   }while(choice!=11);

   FreeData();

   return 0;
}