
#ifndef __MY_H_HEADER_
#define __MY_H_HEADER_


// hash strings
int     hash_string(char** arr, int arr_size, int arr_max_range);
int     my_pow(int val, int exp);
bool    check_hash(int hash);


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


#endif