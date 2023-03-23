#include <main_header.h>

int get_size(char** tokens)
{
    int size = 0;
    while (tokens[size][0] != '\0')
    {
        size += 1;
    }
    return size;
}

void print_grid(char** grid)
{
    int index = 0;
    while (grid[index][0] != '\0')
    {
        printf("row N %i: |%s|\n", index, grid[index]);
        index +=1;
    }
}

int index_of(char* str, char ch)
{
    int index = 0; 
    while (str[index] != ch)
    {
        index +=1;
    }
    return index;
}

int* get_coord(grid_t* grid_attr, int row, char ch)
{
    int col = index_of(grid_attr->tokens[row], ch);
    if (row == 1)
    {
        grid_attr->entrance[0] = 1;
        grid_attr->entrance[1] = col;
    }
    else
    {
        grid_attr->exit_[0] = row;
        grid_attr->exit_[1] = col;
    }   
}

grid_t* get_grid_attr(char* grid)
{
    grid_t *grid_attr   = malloc(sizeof(grid_t));
    grid_attr->tokens   = dirty_split(grid, '\n');
    printf("\n\nPrinting the grid:\n");
    print_grid(grid_attr->tokens);
    grid_attr->size     = get_size(grid_attr->tokens);
    printf("\n\nPrinting the attr:\n");
    printf("val 1 is %c: \n", grid_attr->tokens[0][grid_attr->size -3]);
    get_coord(grid_attr, 1, grid_attr->tokens[0][grid_attr->size -3]);
    get_coord(grid_attr, grid_attr->size - 1, grid_attr->tokens[0][grid_attr->size-2]);
    return grid_attr;
}