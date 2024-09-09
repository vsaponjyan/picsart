#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_string.h"

// char* my_strcpy(char *dest, const char *src);
char *my_strcpy(char *dest, const char *src)
{
    size_t src_len = strlen(src);
    dest = (char *)realloc(dest, src_len + 1);

    if (dest == NULL)
    {
        perror("Failed to allocate memory for src");
        exit(1);
    }
    strcpy(dest, src);

    return dest;
}
char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    dest = (char *)realloc(dest, n);
    if (dest == NULL)
    {
        perror("Failed to allocate memory for src");
        exit(1);
    }

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    dest[i] = '\0';

    return dest;
}

char *my_strcat(char *dest, const char *src)
{

    int full_len = strlen(dest) + strlen(src) + 1;
    int initial_dest_len = strlen(dest);

    dest = (char *)realloc(dest, full_len);
    for (int i = 0; i < strlen(src) + 1; i++)
    {
        dest[initial_dest_len + i] = src[i];
    }

    return dest;
}

char *my_strncat(char *dest, const char *src, size_t n)
{
    size_t dest_len = strlen(dest);
    size_t total_len = dest_len + n + 1;

    dest = (char *)realloc(dest, total_len);
    if (dest == NULL)
    {
        perror("Failed to allocate memory for src");
        exit(1);
    }

    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }

    dest[total_len] = '\0';

    return dest;
}

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    if ((*str1 - *str2) == 0)
    {
        return 0;
    }
    if ((*str1 - *str2) > 0)
    {
        return 1;
    }
    return -1;
}

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {

        if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0')
        {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
    }

    return 0;
}

size_t my_strlen(const char *str)
{
    size_t count = 0;
    while (*str)
    {
        count++;
        str++;
    }
    return count;
}
