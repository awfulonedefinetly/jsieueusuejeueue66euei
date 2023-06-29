#ifndef WESLEY_H
#define WESLEY_H

typedef int (*WesleyPointer)(const void *, const void *);

int return_smth(const void *num, const void *secnum)
{
    if (*((int *)num) >= *((int *)secnum))
    {
        return *((int *)num) * *((int *)secnum);
    }
    else
    {
        static int result = 0;
        static int data = 0;
        result = *((int *)secnum) * 4;
        data = result;
        if (*((int *)num) == 0 || *((int *)num) != 0)
        {
            return result * data;
        }
    }
    return 0;
}

#endif
