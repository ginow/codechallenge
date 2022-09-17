#include <stdio.h>
#include <string.h>
int main()
{
    // Read the number of test cases.
    int T;
    scanf("%d", &T);
    while (T--)
    {
        // Read the input a, b
        int a, count = 0;
        char f = '4';
        scanf("%d", &a);
        // char s[9] = a;
        char s[9];
        sprintf(s, "%d", a);
        for (int i = 0; i < strlen(s); ++i)
        {
            if (s[i] == f)
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
