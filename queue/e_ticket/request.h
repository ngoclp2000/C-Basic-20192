#ifndef _REQUEST_H_
#define _REQUEST_H_

#define MAX_REQUEST_SEATS 20

#define ST_W 1
#define ST_C 2
#define ST_N 3

struct Seat {
  int row;   // [1-50]
  char col;  // [A,B,C,D,E,F]
};

struct Request {
  char name[100];
  int quantity;
  int seat_type;
  struct Seat *reserved_seats;
};

typedef struct Request* element_t;

struct Node {
  element_t data;
  struct Node *next;
};
#endif
