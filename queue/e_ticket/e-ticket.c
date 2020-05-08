#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "request_list.h"
#include "seat_queue.h"
#include<stdio_ext.h>
#define MAX_LEN 50
queue w_seats,c_seats,n_seats,w_pending,c_pending,n_pending;
list requests;
int check_valid(queue q,int quantity){
    if (quantity <= length_q(q))
        return 1;
    return 0;
}
void initialize() {
  
  element_t seat = (struct Request *) malloc(sizeof(struct Request));
  seat->quantity  = 1;
  seat->reserved_seats = (struct Seat *) malloc(sizeof(struct Seat));
  int i;
  // Set up the memory for seat queue and request pending
  w_seats = createQueue();
  c_seats = createQueue();
  n_seats = createQueue();
  w_pending = createQueue();
  c_pending = createQueue();
  n_pending = createQueue();
  // Initialize available seats
  for (i = 1; i <= 50; i++) {
    seat->reserved_seats->row = i;
    seat->reserved_seats->col = 'A';
    w_seats = enqueue(w_seats, seat);
    seat->reserved_seats->row = i;
    seat->reserved_seats->col = 'F';
    w_seats = enqueue(w_seats, seat);
    seat->reserved_seats->row = i;
    seat->reserved_seats->col = 'B';
    n_seats = enqueue(n_seats, seat);
    seat->reserved_seats->row = i;
    seat->reserved_seats->col = 'E';
    n_seats = enqueue(n_seats, seat);
    seat->reserved_seats->row = i;
    seat->reserved_seats->col = 'C';
    c_seats = enqueue(c_seats, seat);
    seat->reserved_seats->row = i;
    seat->reserved_seats->col = 'D';
    c_seats = enqueue(c_seats, seat);
  }

  // Initialize request list
  requests = create_list();
}
void cleanUp(){
    w_seats = freeQueue(&w_seats);
    c_seats = freeQueue(&c_seats);
    n_seats = freeQueue(&n_seats);
    return;
}
void make_new_request(){
    node_t n = (node_t) malloc(sizeof(node_t));
    n->data = (struct Request *) malloc(sizeof(struct Request));
    printf("Enter the name\n");
    __fpurge(stdin);
    gets(n->data->name);
    do{
      printf("Enter the quantity(<=20)\n");
      __fpurge(stdin);
      scanf("%d",&(n->data->quantity));
    }while(n->data->quantity > 20);
    do{
      printf("Enter the ticket type(1.W,2.C,3.N)\n");
      __fpurge(stdin);
      scanf("%d",&(n->data->seat_type));
    }while(n->data->seat_type < 1 || n->data->seat_type > 3);
    queue temp;
    queue temp_pending;
    // Choosing the type of seat which users book from
    int type = n->data->seat_type;
    if(type == 1){
        temp = w_seats;
        temp_pending = w_pending;
    }
    else if(type == 2){
        temp = c_seats;
        temp_pending = c_pending;
    }
    else{
        temp = n_seats;
        temp_pending = n_pending;
    }
    // Create memory for reserved_seats
    n->data->reserved_seats = (struct Seat *) malloc(sizeof(struct Seat) * n->data->quantity);
    if(check_valid(temp,n->data->quantity)){
        // Booking successfully
        printf("Booking is success\nThank you!!\n");
        // Import the data into the list of reserved seats
        for(int i = 0 ; i < n->data->quantity ; i++){
            queue t = peek(temp);
            (n->data->reserved_seats + i)->col = t->data->reserved_seats->col;
            (n->data->reserved_seats + i)->row = t->data->reserved_seats->row;
            temp = dequeue(temp);
        }
        // Reallocate the memory of seat queue after dequeuing 
        if(type == 1) w_seats = temp;
        else if (type == 2) c_seats = temp;
        else n_seats = temp;
        list q = requests;
        // Insert the new request after the last request of the list
        while(q != NULL && q->next != NULL) q = q->next;
        requests = insert_after(requests,q, n->data);
    }else{
      // Booking fail, so the request will be added into pending request queue. When there are enough seats for 'first' position in queue pending seats, it will be added into request list
      printf("There is not enough ticket for your request, so your request will be added into pendind.\nWhen we have enough ticket, the request will be automatically added and we also inform to you\n");
      temp_pending = enqueue(temp_pending, n->data);
      if(type == 1) w_pending = temp_pending;
      else if (type == 2) c_pending = temp_pending;
      else n_pending = temp_pending;
    }
}
void cancelRequest() {
  // Input the name that the user want to cancel
    char name[100];
    list c;
    do{
        printf("Enter your name\n");
        __fpurge(stdin);
        gets(name);
        c = find(requests,name);
    }while(c == NULL);
     printf("Cancelation is success\n");
    // Choosing the type of seat which the user want to cancel
    queue temp;
    queue temp_pending;
    int type = c->data->seat_type;
    if(type == 1){
      temp = w_seats;
      temp_pending = w_pending;
    } 
    else if (type == 2){
      temp = c_seats;
      temp_pending = c_pending;
    }
    else{
      temp = n_seats;
      temp_pending = n_pending;
    }
    // Enqueue all the seats of the canceling request into its type in queue seat
    for(int i = 0 ; i < c->data->quantity;i++){
            element_t b = (struct Request *) malloc(sizeof(struct Request));
            b->quantity = 1;
            b->reserved_seats = (struct Seat *) malloc(sizeof(struct Seat));
            b->reserved_seats->col = (c->data->reserved_seats + i)->col;
            b->reserved_seats->row = (c->data->reserved_seats + i)->row;            
            temp = enqueue(temp, b);
    }
    // Remove the request
    requests = remove_at(requests,c);
    // Consider whether or not the queue seats have enough seats for the pending request in pending request queue
    if( temp_pending != NULL && length_q(temp) >= peek(temp_pending)->data->quantity){
      // If yes
      printf("The request of %s will be added to the system, because there are enough seats for his/her request\n",peek(temp_pending)->data->name);
      // Dequeue the request in the pending request queue
      queue t = peek(temp_pending);
      temp_pending = dequeue(temp_pending);
      // Reallocate the pending request queue
      if(type == 1) w_pending = temp_pending;
      else if (type == 2) c_pending = temp_pending;
      else n_pending = temp_pending;
      // Dequeue the seats for the new request,which will be added into request list
      for(int i = 0 ; i < t->data->quantity ; i++){
          (t->data->reserved_seats + i)->col = peek(temp)->data->reserved_seats->col;
          (t->data->reserved_seats + i)->row = peek(temp)->data->reserved_seats->row;
          temp = dequeue(temp);
      }
      // Reallocate the seat queue
      if(type == 1) w_seats = temp;
      else if (type == 2) c_seats = temp;
      else n_seats = temp;
      // Insert new request after the last request of the list
      list l = requests;
      while(l->next != NULL) l = l->next;
      requests = insert_after(requests,l,t->data);
    }
}
void printRequest(){
    printlist(requests);
}
void searchRequest(){
  printf("Enter your name\n");
  char name[100];
  __fpurge(stdin);
  gets(name);
  list l = find(requests, name);
  printf("%-20s%-18s%-9s%s\n","Name","Type(1.W,2.C,3.N)","Quantity","Ticket");
  printf("%-20s%-18d%-9d",l->data->name,l->data->seat_type,l->data->quantity);
  for(int i = 0 ; i < l->data->quantity ; i++){
    printf("%c%d ",(l->data->reserved_seats +i)->col,(l->data->reserved_seats + i)->row);
  }
  printf("\n");
}
void printRemainSeats(){
  printf("%-5s%-16s%s","Type","NumberAvailable","SeatList");

}
int main() {
  int running = 1;
  int selection;

  initialize();

  while (running) {
    printf("\n1. Make new request\n");
    printf("2. Cancel request\n");
    printf("3. Print all requests\n");
    printf("4. Search by name\n");
    printf("5. Quit\n");
    printf("Choose an option:");
    scanf("%d", &selection);
    switch (selection) {
    case 1:
      make_new_request();
      break;
    case 2:
      cancelRequest();
      break;
    case 3:
      printRequest();
      break;
    case 4:
      searchRequest();
      break;
    case 5:
      running = 0;
      break;
    case 6:
      break;
    }
  }

  cleanUp();
  return 0;
}


