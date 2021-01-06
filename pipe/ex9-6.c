#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    if(mknod("One-FIFO",S_IFIFO | 0644, 0) == -1)
    {
        perror("mknod");
        exit(1);
    }

    if(mkfifo("Two-FIFO", 0644) == -1)
    {
        perror("mkfifo");
        exit(1);
    }

    return 0;
}
