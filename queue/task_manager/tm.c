#include<stdio.h>
#include<stdlib.h>
#include "program.h"
#include "process-list.h"
#include "process-queue.h"
int memory_capacity,num_p_process;
list programs;
queue pendingProcess;
void inicialize();
void createNewProgram();
void killProgram();
void printProcess();
void printPending();
void cleanUp();
int main(){
    inicialize();
    int selection;
    do{
        printf("1.Create new program\n2.Kill the program\n3.Show the running programs\n4.Show the pending process\n5.Exit\n");
        scanf("%d",&selection);
        switch(selection){
            case 1:
                createNewProgram();
            break;
            case 2:
                killProgram();
            break;
            case 3:
                printProcess();
            break;
            case 4:
                printPending();
            break;
        }
    }while(selection != 5);

    cleanUp();
}

void inicialize(){
    // Input the number of parallel process and the memory of the system
    printf("Enter the number of parallel proccess which the system can run\n");
    scanf("%d",&num_p_process);
    printf("Enter the memory capacity\n");
    scanf("%d",&memory_capacity);
    programs = create_list();
    pendingProcess = createQueue();
}
void createNewProgram(){
    node_t n = (struct Node *) malloc(sizeof(struct Node));
    n->data = (struct Program *) malloc(sizeof(struct Program));
    printf("Enter the name of the process\n");
    fflush(stdin);
    gets(n->data->name);
    printf("Enter the needed memory of new process\n");
    scanf("%d",&(n->data->memory_capacity));
    // Consider the system has enough memory for the new process or not, or overload the process
    if (n->data->memory_capacity <= memory_capacity && length(programs) <= num_p_process){
        // If yes   
        // Minus the memory 
        memory_capacity -= n->data->memory_capacity;
        n->data->id = length(programs) + 1;
        // Insert after the last process 
        list l = programs;
        while( l != NULL && l->next != NULL) l = l->next;
        programs = insert_after(programs,l,n->data);
    }else{
        // If not, enqueue into the process pending queue
        printf("The system does not have enough memory for this new process\nIt will be added into pending processes\n");
        pendingProcess = enqueue(pendingProcess,n->data);
    }
}
void killProgram(){
    printProcess();
    printf("Enter the ID of your process to kill\n");
    int id;
    scanf("%d",&id);
    node_t found_node = find(programs,id);
    // Increse the memory and 
    memory_capacity += found_node->data->memory_capacity;
    programs = remove_at(programs,found_node);
    // Peek from the process queue list
    queue temp = peek(pendingProcess);
    while( temp != NULL && temp->data->memory_capacity <= memory_capacity && length(programs) < num_p_process){
        // If yes insert it after the last and dequeue the pending process queue
        list p = programs;
        while(p->next != NULL) p = p->next;
        programs = insert_after(programs,p,temp->data);
        pendingProcess = dequeue(pendingProcess);
        printf("The proccess %s was added into system \n",temp->data->name);
        temp = peek(pendingProcess);
    }
    list l = programs;
    int i = 1;
    while(l != NULL){
        l->data->id = i++;
        l = l->next;
    }
    printf("The process was killed\n");
}
void printProcess(){
    printlist(programs);
}
void printPending(){
    printQueue(pendingProcess);
}
void cleanUp(){
    programs = free_list(&programs);
    pendingProcess = freeQueue(&pendingProcess);
}