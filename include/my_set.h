#ifndef __MY_SET_HEADER_
#define __MY_SET_HEADER_

#include <main_header.h>

#ifndef __MY_SET__
#define __MY_SET__
struct set
{
    hash_t  hash_v;
    void    (*clear_hash)(hash_t*);
    int     (*hash_string)(char*);
};
typedef struct set set_t;
#endif


bool    include(set_t* set, char* str);
void    add(set_t* set, char* str);
void    remove_data(set_t* set, char* str);
set_t*   new_set();
#endif