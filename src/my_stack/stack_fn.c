#include <main_header.h>


int push(stack_t stack, char* token)
{
    if (stack.top > _SIZE_STACK_) 
    {
        write(STDERR_FILENO, OVERFLOW, SIZE_OVERF);
        return EXIT_FAILURE;
    }
    free(stack.data[stack.top + 1]);
    stack.data[++stack.top] = strdup(token);
    return EXIT_SUCCESS;
}

char* pop(stack_t stack)
{
    if (stack.top > _SIZE_STACK_) 
    {
        write(STDERR_FILENO, UNDERFLOW, SIZE_UNDERFLOW);
        return NULL;
    }
    return stack.data[stack.top--];
}

bool is_empty(stack_t stack)
{
    if (stack.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int print_stack(stack_t stack)
{
    printf("printing stack top is %i:", stack.top);
    int index = 0; 
    while (index <= stack.top)
    {
        printf("|%s|",stack.data[index]);
        index += 1;
    }
    printf("\n");
}