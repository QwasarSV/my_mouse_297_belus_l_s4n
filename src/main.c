#include <main_header.h>

    queue_t queue = {
        .s1 = {.top = -1},
        .s2 = {.top = -1},
        .front = NULL,
        .is_empty = is_empty,
        .push = push,
        .pop = pop
    };


int main(int argc, char** argv)
{
    if (welcome_error(argc))
    {
        return EXIT_FAILURE;
    }

    printf("gorlami\n");

    printf("buenjourno?\n");

    char val_a[] = "aasdad";
    char val_b[] = "basdasd";
    char val_c[] = "casdad";

    char* ptr_a = malloc(sizeof(char*));
    char* ptr_b = malloc(sizeof(char*));
    char* ptr_c = malloc(sizeof(char*));
    ptr_a = val_a;
    ptr_b = val_b;
    ptr_c = val_c;
    enqueue(&queue, ptr_a);
    enqueue(&queue, ptr_b);
    enqueue(&queue, ptr_c);

    printf("the front is element: %s\n", queue.front);

    printf("Dequeued element: %s\n", dequeue(&queue));
    printf("Dequeued element: %s\n", dequeue(&queue));
    printf("come?\n");
    return EXIT_SUCCESS;
}