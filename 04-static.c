#include<stdio.h>
int runner() {
    static int count = 0;
    count++;
    return count;
}

int main()
{
    printf("%d ", runner());
    printf("%d ", runner());
    return 0;
}

/* Output: 1 2 */

// No Static variable
// #include<stdio.h>
// int runner() {
//     static int count = 0;
//     count++;
//     return count;
// }

// int main()
// {
//     printf("%d ", runner());
//     printf("%d ", runner());
//     return 0;
// }

/* Output: 1 1 */