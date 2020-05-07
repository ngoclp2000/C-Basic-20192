#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Phone{
    char model[35];
    char memory[35];
    char displaySize[35];
    char price[35];
}Phone_t;

typedef struct Node{
    Phone_t *phoneInfo;
    struct Node *nextNode;
}Node_t;
void insertNodeToLast(Node_t **headNode,Node_t **lastNode,Node_t *newNode){
    if((*headNode) == NULL) {
        (*headNode) = newNode;
        (*lastNode) = newNode;
    }else{
        (*lastNode)->nextNode = newNode;
        (*lastNode) = newNode;
    }
    return; 
}
void insertNodeToHead(Node_t **headNode,Node_t **lastNode,Node_t *newNode){
    if((*headNode) == NULL){
        (*headNode) = newNode;
        (*lastNode) = newNode;
    }else{
        newNode->nextNode = (*headNode);
        (*headNode) = newNode;
    }
    return;
}
void insertNodeAfterCur(int pos,Node_t **headNode,Node_t *newNode){
    // Count from 0 index
    if((*headNode) == NULL) return;
    Node_t *runNode = (*headNode);
    while(pos >= 0 && runNode->nextNode != NULL){
        runNode = runNode->nextNode;
        pos--;
    }
    if(pos >= 0){
        return;
    }
    newNode->nextNode = runNode->nextNode;
    runNode->nextNode = newNode;
}
void insertNodeBeforeCur(int pos,Node_t **headNode,Node_t *newNode){
    // Count from 0 index
    Node_t *runNode = (*headNode);
    Node_t *preNode = NULL;
    while(runNode->nextNode != NULL && pos > 0){
         preNode = runNode;
         runNode = runNode->nextNode;
         pos--;
    }
    if(preNode == NULL){
        newNode->nextNode = (*headNode);
        (*headNode) = newNode;
    }else{
        preNode->nextNode = newNode;
        newNode->nextNode = runNode;
    }
}
int ChangeBinaryFile(FILE *input,FILE *output){
    int count = 0;
    while(!feof(input)){
        Phone_t *new_infor = (Phone_t *) calloc(sizeof(Phone_t),1);
        fscanf(input,"%s %s %s %s\n",new_infor->model,new_infor->memory,new_infor->displaySize,new_infor->price);
        //printf("%-30s%-20s%-20s%s\n",new_infor->model,new_infor->memory,new_infor->displaySize,new_infor->price);
        fwrite(new_infor,sizeof(Phone_t),1,output);
        free(new_infor);
        count++;
    }
    fclose(input);
    fclose(output);
    return count;
}
void updateTextFile(FILE *output,Node_t *headNode){
    if (headNode == NULL) return;
    while(headNode->nextNode != NULL){
        fprintf(output,"%s %s %s %s",headNode->phoneInfo->model,headNode->phoneInfo->memory,headNode->phoneInfo->displaySize,headNode->phoneInfo->price);
        if(headNode->nextNode->nextNode != NULL) fputc('\n',output);
        headNode = headNode->nextNode;
    }
    return;
}

void importDataF(FILE *fin,Node_t **headNode,Node_t **lastNode){
    while(!feof(fin)){
        Node_t *newNode = (Node_t *) malloc(sizeof(Node_t));
        newNode->nextNode = NULL;
        newNode->phoneInfo = (Phone_t *) malloc(sizeof(Phone_t));
        fread(newNode->phoneInfo,sizeof(Phone_t),1,fin);
        insertNodeToLast(headNode,lastNode,newNode);
    }
}
void printLinkedList(Node_t *headNode){
    while(headNode != NULL){
        printf("%-35s%-35s%-35s%-35s %d\n",headNode->phoneInfo->model,headNode->phoneInfo->memory,headNode->phoneInfo->displaySize,headNode->phoneInfo->price,strlen(headNode->phoneInfo->model) +strlen(headNode->phoneInfo->memory) +strlen(headNode->phoneInfo->displaySize)+strlen(headNode->phoneInfo->price));
        headNode = headNode->nextNode;
    }

    return;
}
void InputNewModel(Node_t **headNode,Node_t **lastNode,Node_t *newNode){
    insertNodeBeforeCur(1,headNode,newNode);
    FILE *fout = fopen("Phone.txt","w");
    updateTextFile(fout,(*headNode));
    fclose(fout);
    FILE *fin = fopen("Phone.txt","r");
    fout = fopen("Phone.dat","wb");
}
int main(){
    Node_t *headNode = NULL;
    Node_t *lastNode = NULL;
    int choice;
    do{
        printf("1.Change into Binary and Import to Linked List\n2.Print the Linked List\n3.Input New Phone\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\n");
            FILE *fin = fopen("Phone.txt","r");
            FILE *fout = fopen("Phone.dat","wb");
            ChangeBinaryFile(fin,fout);
            fclose(fin);
            fclose(fout);
            FILE *fin1 = fopen("Phone.dat","rb");
            importDataF(fin1,&headNode,&lastNode);
            fclose(fin1);    
            break;
            case 2:
                printLinkedList(headNode);
                printf("%-35s%-35s%-35s%-35s %d\n",lastNode->phoneInfo->model,lastNode->phoneInfo->memory,lastNode->phoneInfo->displaySize,lastNode->phoneInfo->price,strlen(headNode->phoneInfo->model) +strlen(headNode->phoneInfo->memory) +strlen(headNode->phoneInfo->displaySize)+strlen(headNode->phoneInfo->price));
                break;
            case 3:
                printf("Enter the information of new phone\n");
                Node_t *newNode = (Node_t *) malloc(sizeof(Node_t));
                newNode->phoneInfo = (Phone_t *) malloc(sizeof(Phone_t));
                newNode->nextNode = NULL;
                printf("Model: ");
                scanf("%s",newNode->phoneInfo->model);
                printf("Memory: ");
                fflush(stdin);
                scanf("%s",newNode->phoneInfo->memory);
                printf("DisplaySize: ");
                fflush(stdin);
                scanf("%s",newNode->phoneInfo->displaySize);
                printf("Price: ");
                fflush(stdin);
                scanf("%s",newNode->phoneInfo->price);
                InputNewModel(&headNode,&lastNode,newNode);
                break;
        }
    }while(choice != 5);
}