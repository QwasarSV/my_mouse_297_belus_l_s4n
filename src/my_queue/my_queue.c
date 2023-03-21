#include <main_header.h>

int enqueue(queue_t* queue, char* token)
{
    if (token == NULL)
    {
        return EXIT_FAILURE;
    }
    if (queue->is_empty(&queue->s1))
    {
        queue->front = my_strdup(token);
        printf("enqueue front : %s \n", queue->front);
    }
    while (!queue->is_empty(&queue->s1))
    {
        queue->push(&queue->s2, queue->pop(&queue->s1));
    }
    queue->push(&queue->s2, token);
    while (!queue->is_empty(&queue->s2))
    {
        queue->push(&queue->s1, queue->pop(&queue->s2));
    }
    return EXIT_SUCCESS;
}

char* dequeue(queue_t* queue)
{
    if (queue->is_empty(&queue->s1))
    {
        printf("End of queue->\n");
        return NULL;
    }
    char* val = my_strdup(queue->pop(&queue->s1));
    if (!queue->is_empty(&queue->s1))
    {
        queue->front = my_strdup(queue->s1.data[queue->s1.top]);
    }
    return val;
}

char* peek(queue_t* queue)
{
    return queue->front;
}

bool is_q_empty(queue_t* queue)
{
    bool s1 = queue->is_empty(&queue->s1);
    bool s2 = queue->is_empty(&queue->s2);
    if (s1 && s2)
    {
        return true;
    }
    else
    {
        return false;
    }
}