#ifndef _MAIN1_
#define _MAIN1_
struct Time{
    int hour;
    int minute;
};
struct Guest{
    struct Time time;
    int time_wait;
    int num_table;
};
typedef struct Guest* element_t;
typedef struct TableQ* queue;

#endif