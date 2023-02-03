#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    write(1, "dummy1\n", 7);

    return 0;
}