#include <stdlib.h>
#include <stdio.h>

int char_count[256];
void init_char_count()
{
    for (int i = 0; i < 256; i++)
    {
        char_count[i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    init_char_count();
    FILE *fp;
    char *filename = "test.txt";

    fp = fopen(filename, "r");

    if (!fp)
    {
        perror("Error opening ");
        printf("%s", filename);
        exit(1);
    }
    char c;
    int size = 0;
    while ((c = fgetc(fp)) != EOF)
    {
        char_count[c]++;
        size++;
    }
    printf("ASCII\tCHARACTER\tFREQ\n");
    for (int i = 0; i < 256; i++)
    {
        if (i == '\t')
        {
            printf("%d\t'\\t'\t\t%d\n", i, char_count[i]);
        }
        else if (i == '\n')
        {
            printf("%d\t'\\n'\t\t%d\n", i, char_count[i]);
        }
        else if (i == '\b')
        {
            printf("%d\t'\\b'\t\t%d\n", i, char_count[i]);
        }
        else
            printf("%d\t%c\t\t%d\n", i, i, char_count[i]);
    }

    return 0;
}
