#ifndef __MY_QUEUE_HEADER_
#define __MY_QUEUE_HEADER_

#include <main_header.h>

#ifndef __MY_QUEUE__
#define __MY_QUEUE__
struct queue
{
    stack_t s1;
    stack_t s2;
    char*   front;
    bool    (*is_empty)(stack_t*);
    int     (*push)(stack_t*, char*);
    char*   (*pop)(stack_t*);
};
typedef struct queue queue_t;
#endif

extern queue_t queue;

int     enqueue(queue_t* queue, char* token);
char*   dequeue(queue_t* queue);

#endif