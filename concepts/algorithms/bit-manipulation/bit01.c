/**
 * (c) https://stackoverflow.com/questions/28937523/how-to-do-a-bit-representation-in-a-c-standard-way
 * 
 *   */ 

#include <stdio.h>
#include <stdint.h>
#define TYPE_PUN(to, from, x) ( *(to *)&(from){(x)} )
// Source - https://stackoverflow.com/a
// Posted by mafso, modified by community. See post 'Timeline' for change history
// Retrieved 2025-12-07, License - CC BY-SA 3.0


unsigned sign_bit = 1u << sizeof sign_bit * __CHAR_BIT__ - 1;

int main(int argc, char *argv[])
{
    int a = 12;
    int c = 34;
    int b = 3;
    
    printf("check: %d\n", (c & (c - 1)));
    printf("%d\n", a >> 1);
    printf("%d\n", a >> 2);
    printf("%d\n", (a >> 1) + (a >> 2));
    printf("%d\n", a >> b);
    printf("%u\n", sign_bit);
    return 0;
}