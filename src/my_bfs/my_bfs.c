#include <main_header.h>

set_t*  visited;
queue_t q;

cell_t* set_cell(int x, int y, cell_t* next)
{
    cell_t cell = {
        x, y, {x, y}, next
    }; 
    cell_t* cell_ptr = (cell_t*)malloc(sizeof(cell_t));
    *cell_ptr = cell;
    return cell_ptr;
}

bool is_valid(int x, int y, grid_t* grid_attr)
{
    if (x >= 0 &&
        x < grid_attr->size &&
        y >= 0 &&
        y < grid_attr->size &&
        grid_attr->tokens[x][y] != grid_attr->obstacle)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

void add_valid_cell(int new_x, int new_y, grid_t* grid_attr, cell_t* next)
{
    int cell[2] = {0};
    cell[0] = new_x;
    cell[1] = new_y;
    if (is_valid(new_x, new_y, grid_attr) && !include(visited, cell))
    {
        cell_t* new_path = set_cell(new_x, new_y, next);
        enqueue(&q, new_path);
        add(visited, cell);
    }
}

void explore_grid(int x, int y, grid_t* grid_attr, cell_t* next)
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int index = 0;
    int new_x = 0;
    int new_y = 0;
    while (index < MAX_DIRECTION)
    {
        new_x = x + dx[index];
        new_y = y + dy[index];
        add_valid_cell(new_x, new_y, grid_attr, next);
        index += 1;
    }
}

int bfs(grid_t* grid_attr, int* entrance, int* exit_)
{
    int     exit_x      = exit_[0];
    int     exit_y      = exit_[1];
    visited             = new_set();
    q                   = new_queue();
    cell_t* cell        = set_cell(entrance[0], entrance[1], NULL);
    add(visited, entrance);

    printf("cell        : [%i][%i]\n",cell->x, cell->y); 
    enqueue(&q, cell);
    while (!is_q_empty(&q))
    {
        cell = dequeue(&q);
        // printf("cell        : [%i][%i]\n",cell->x, cell->y);    
        if (cell->x == exit_x && cell->y == exit_y )
        {
            golden_path(grid_attr, cell);
            flush_path();
            return 1;
        }
        explore_grid(cell->x, cell->y, grid_attr, cell);
    }
    return -1;
}

void golden_path(grid_t* grid_attr, cell_t* exit_cell)
{
    cell_t* current = exit_cell;
    while (current != NULL)
    {

        grid_attr->tokens[current->x][current->y] = 'o';
        current = current->next;
    }
}

void flush_path()
{
    cell_t* cell;
    int index = 0;
    while (!is_q_empty(&q))
    {
        cell = dequeue(&q);
        index += 1;
        free(cell);
    }
    printf("freed %i elements", index);
}