/*
Implementation of regex to NFA matcher from https://swtch.com/%7Ersc/regexp/regexp1.html
source code -> https://swtch.com/~rsc/regexp/nfa.c.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Convert infix regexp re to postfix notation.
 * Insert . as explicit concatenation operator.
 * Cheesy parser, return static buffer.
 */
char *re2post(char *re)
{
    int nalt, natom;
    static char buf[8000];
    char *dst;
    struct
    {
        int nalt;
        int natom;
    } paren[100], *p;

    p = paren;
    dst = buf;
    nalt = 0;
    natom = 0;
    if (strlen(re) >= sizeof buf / 2)
        return NULL;
    for (; *re; re++)
    {
        switch (*re)
        {
        case '(':
            if (natom > 1)
            {
                --natom;
                *dst++ = '.';
            }
            if (p >= paren + 100)
                return NULL;
            p->nalt = nalt;
            p->natom = natom;
            p++;
            nalt = 0;
            natom = 0;
            break;
        case '|':
            if (natom == 0)
                return NULL;
            while (--natom > 0)
                *dst++ = '.';
            nalt++;
            break;
        case ')':
            if (p == paren)
                return NULL;
            if (natom == 0)
                return NULL;
            while (--natom > 0)
                *dst++ = '.';
            for (; nalt > 0; nalt--)
                *dst++ = '|';
            --p;
            nalt = p->nalt;
            natom = p->natom;
            natom++;
            break;
        case '*':
        case '+':
        case '?':
            if (natom == 0)
                return NULL;
            *dst++ = *re;
            break;
        default:
            if (natom > 1)
            {
                --natom;
                *dst++ = '.';
            }
            *dst++ = *re;
            natom++;
            break;
        }
    }
    if (p != paren)
        return NULL;
    while (--natom > 0)
        *dst++ = '.';
    for (; nalt > 0; nalt--)
        *dst++ = '|';
    *dst = 0;
    return buf;
}


int main(int argc, char *argv[])
{
    int i;
    char *post;

    if (argc < 3)
    {
        fprintf(stderr, "usage: nfa regexp string...\n");
        return 1;
    }

    post = re2post(argv[1]);
    if (post == NULL)
    {
        fprintf(stderr, "bad regexp %s\n", argv[1]);
        return 1;
    }
    fprintf(stdout, "post: [%s]\n", post);

    return 0;
}
