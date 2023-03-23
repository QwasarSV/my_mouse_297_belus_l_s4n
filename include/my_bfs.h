#ifndef __MY_BFS_HEADER_
#define __MY_BFS_HEADER_

#define ARG_SIZE            2
#define ERR_MSG_MAX_ARG     "bad user arg"
#define SIZE_ERR_MSG_MAX    13
#define OVERFLOW            "OVERFLOWING\n"
#define SIZE_OVERF          12
#define UNDERFLOW           "UNDERFLOWING\n"
#define SIZE_UNDERFLOW      13

int     welcome_error(int val);



#ifndef __NODE_
#define __NODE_
struct node
{
    int x;
    int y;
    int xy[1];
};
typedef struct node node_t;
#endif

int bfs(char** tokens, int* entrance, int* exit_);


#endif