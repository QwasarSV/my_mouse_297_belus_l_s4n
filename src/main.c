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
    golden_path(grid_attr);
    printf("\n\nPrinting the grid:\n");
    print_grid(grid_attr->tokens);
    
    free(buff);
    free(grid_attr->tokens);
    free(grid_attr);
    return EXIT_SUCCESS;
}






// int main(int argc, char** argv)
// {
//     if (welcome_error(argc))
//     {
//         return EXIT_FAILURE;
//     }

//     set_t* visited  = new_set();
//     queue_t queue = new_queue();
//     // int val_a[1] = {1};
//     // int val_b[1] = {3};
//     // int val_c[1] = {2};
//     // char val_a[] = "[2][1]";
//     char val_b[] = "basdasd";
//     char val_c[] = "casdad";

//     char* ptr_a = NULL;
//     char* ptr_b = NULL;
//     char* ptr_c = NULL;

//     // ptr_a = val_a;
//     ptr_b = val_b;
//     ptr_c = val_c;

//     // add(visited, val_a);
//     add(visited, val_b);
//     add(visited, val_c);

//     // int result = include(visited, val_a);
//     printf("Set already exist %i: \n", include(visited, val_c));
//     // enqueue(&queue, val_a);
//     enqueue(&queue, val_b);
//     enqueue(&queue, val_c);

//     printf("end of test\n\n");
//     // printf("The front is element: %s\n", (char*)queue.front);
//     // printf("Dequeued element: %s\n", dequeue(&queue));
//     // printf("Dequeued element: %s\n", dequeue(&queue));
//     // free(ptr_a);
//     // free(ptr_b);
//     // free(ptr_c);

//     return EXIT_SUCCESS;
// }