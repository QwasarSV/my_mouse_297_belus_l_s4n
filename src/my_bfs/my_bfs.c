#include <main_header.h>

int bfs(char** tokens, int* entrance, int* exit_)
{
    int entrance_x = entrance[0];
    int entrance_y = entrance[1];
    int exit_x     = exit_[0];
    int exit_y     = exit_[1];    
    set_t* visited  = new_set();
    queue_t q = new_queue();
    
    //
    node_t* node = malloc(sizeof(node_t));
    node->x = entrance_x;
    node->y = entrance_y;
    node->xy[0] = entrance_x;
    node->xy[1] = entrance_y;
    //
    
    add(visited, entrance);
    enqueue(&q, node);
    while (!is_q_empty(&q))
    {
        node = dequeue(&q);
        if (node->x == exit_x && node->y == exit_y )
        { 
            return 1;
        }
    }
    return -1;
}
