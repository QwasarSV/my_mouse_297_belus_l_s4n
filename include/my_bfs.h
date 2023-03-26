#ifndef __MY_BFS_HEADER_
#define __MY_BFS_HEADER_

#define MAX_DIRECTION 4

#ifndef __CELL_
#define __CELL_
struct cell
{
    int x;
    int y;
    int xy[2];
};
typedef struct cell cell_t;
#endif

extern set_t*  visited;
extern queue_t q;

cell_t* set_node(int x, int y);
bool    is_valid(int x, int y, grid_t* grid_attr);
void    add_valid_node(int new_x, int new_y, grid_t* grid_attr);
void    explore_grid(int x, int y, grid_t* grid_attr);
int     bfs(grid_t* grid_attr, int* entrance, int* exit_);
void    golden_path(grid_t* grid_attr);

#endif