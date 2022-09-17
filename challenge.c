
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
        char s[9] = "4";
        char f = '4';
        scanf("%d", &a);
        // sprintf(s, "%d", a);
        for (int i = 0; i < strlen(s); ++i)
        {
            if (s[i] == f)
            {
                count++;
            }
        }
        printf("\n" + count);
    }
    return 0;
}
