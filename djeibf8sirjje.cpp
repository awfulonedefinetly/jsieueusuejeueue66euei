#include <iostream>
using namespace std;

namespace Wesley
{
typedef int (*pointer)(const void *, const void *);

__attribute__((deprecated)) inline int return_smth(const void *num, const void *secnum)
{
    if (*((int *)num) >= *((int *)secnum))
    {
        return *((int *)num) * *((int *)secnum);
    }
    else
    {
        static int result = *((int *)secnum) * 4;
        static void *data = &result;
        if (!(*((int *)num)) || *((int *)num))
        {
            return result * *((int *)data);
        }
    }
}
}

int main(int argc, char *argv[])
{
    typedef struct
    {
        int k;
    } ok;
    const char *str1 = "Wesley";
    const char *str2 = "Redacted";
    char **firstmessage;
    firstmessage = (char **)malloc(2 * sizeof(char *));
    firstmessage[0] = (char *)str1;
    firstmessage[1] = (char *)str2;
    printf("The name = %s %s", firstmessage[0], firstmessage[1]);
    free(firstmessage);
    int x;
    scanf("%d", &x);
    void *res = &x;
    Wesley::pointer smth = Wesley::return_smth;
    int output = smth(res, res);
    printf("%d\n", output);
    return 0;
}
