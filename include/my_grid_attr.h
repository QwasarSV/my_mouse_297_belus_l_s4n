#ifndef __MY_GRID_ATTR_HEADER_
#define __MY_GRID_ATTR_HEADER_

#include <main_header.h>



#ifndef GRID_STRUCT
#define GRID_STRUCT
struct data_struct
{
    char**  tokens;
    int     size;
    int     entrance[1];
    int     exit_[1];
};
typedef struct data_struct grid_t;
#endif

grid_t* get_grid_attr(char* grid);
int     get_size(char** tokens);
int     index_of(char* str, char c);
int*    get_coord(grid_t* grid_attr, int row, char ch);
void    print_grid(char** grid);


#endif