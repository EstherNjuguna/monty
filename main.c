#include "monty.h"
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return (EXIT_FAILURE);
    }

    execute(argv[1]);

    return (EXIT_SUCCESS);
}
