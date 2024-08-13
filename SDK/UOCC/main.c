#include "sys/hardware.h"

int main()
{
        int a = 5;
        int b = 8;

        int a1 = 14;
        int b1 = 1;

        FILE* f = fopen("runtime.asm", "w");

        init(f);
        add(a, b);
        add(a1, b1);

        return 0;
}
