#include <stdio.h>
#include <stdlib.h>
#include "my_dynamicStrings.c"

int main()
{
    char *dest = malloc(10 * sizeof(char));
    if (dest == NULL)
    {
        perror("Failed to allocate memory for dest");
        exit(1);
    }

    char *src = malloc(14 * sizeof(char));
    if (src == NULL)
    {
        perror("Failed to allocate memory for src");
        free(dest);
        exit(1);
    }
    strcpy(src, "world");
    strcpy(dest, "hello ");

    // char *result = my_strcpy(dest, src);
    // char *result = my_strncpy(dest, src, 5);

    // char *result = my_strcat(dest, src);
    char *result = my_strncat(dest, src, 3);
    if (result != NULL)
    {
        printf("your result is %s\n", result);
    }
    else
    {
        printf("Error occurred during dynamic string copy.\n");
    }

    free(dest);
    free(src);

    return 0;
}
