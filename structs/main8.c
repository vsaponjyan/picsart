#include <stdio.h>
#include <string.h>
#include "struct.h"

int main()
{
    srand(time(NULL));

    struct StudentData s1, s2, s3;
    size_t size = 3;
    addStudent(&s1, "John", "Doe");
    addStudent(&s2, "Jane", "Smith");
    addStudent(&s3, "Bob", "Johnson");
    struct StudentData arr[3] = {s1, s2, s3};
    max_grade(arr, size);
    return 0;
}
