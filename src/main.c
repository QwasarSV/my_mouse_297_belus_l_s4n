#include <main_header.h>


int main(int argc, char** argv)
{
    if (welcome_error(argc))
    {
        return EXIT_FAILURE;
    }
    
    char* buff = NULL;
    buff = read_map(argv[1]);
    printf("file buff :\n%s", buff);
    // printf("max: %s \n", buff[9]);
    grid_t* grid_attr = get_grid_attr(buff);

    printf("size of grid    : |%i| \n", grid_attr->size);
    printf("entrance coord  : [%i][%i]\n", grid_attr->entrance[0], grid_attr->entrance[1]);
    printf("exit_ coord     : [%i][%i]\n", grid_attr->exit_[0], grid_attr->exit_[1]);
    bfs(grid_attr, grid_attr->entrance, grid_attr->exit_);
    // golden_path(grid_attr);
    printf("\n\nPrinting the grid:\n");
    print_grid(grid_attr->tokens);
    
    free(buff);
    free(grid_attr->tokens);
    free(grid_attr);
    return EXIT_SUCCESS;
}
