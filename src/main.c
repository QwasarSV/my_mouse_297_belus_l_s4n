#include <main_header.h>

int main(int argc, char** argv)
{
    if (welcome_error(argc))
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}