#include <stdio.h>
#include <stdbool.h>

// int lengthOfLongestSubstring(char* s) {
//     return 0;
// }
int getSizeOfString(char* string)
{
    int size = 0;
    while (true) {
        if (string[size] == '\0') break;
        size += 1;
    }
    return size;
}


int main(void)
{
    int i, j, j_pos, subs_l;
    int result, size;


    char* s = "auauk";
    result = 0;
    size = getSizeOfString(s);
    subs_l = 0;
    j_pos = 0;

    printf("size is -> %d\n", size);

    for (i = 0; i < size; i++) {
        j = j_pos;
        while (j < i) {
            if (s[j] == s[i]) {
                subs_l = i - j_pos;
                j_pos = i;
                break;
            }
            j += 1;
        }
        if (result < subs_l) {
            result = subs_l;
        }
    }

    
    printf("\nresult: %d\n", result);
    
    return 0;
}






// int main(void)
// {
//     int i, j, j_pos, subs_l;
//     int result, size;

//     // char* s = "abcabcbbb";
//     // char* s = " ";
//     char* s = "auauk";
//     result = 0;
//     size = getSizeOfString(s);
//     subs_l = 0;
//     j_pos = 0;

//     printf("size is -> %d\n", size);


//     for (i = 0; i < size; i++) {
//         printf("%d---: elem %d: %c\n", i, i, s[i]);

//         j = j_pos;
        
//         while (j < i) {
//             if (s[i] == s[j]) {
//                 printf("%d---: i=%d;j=%d;j_pos=%d\n", i, i, j, j_pos);
//                 subs_l = i - j_pos;
//                 j_pos = i;
//                 break;
//             }
//             j += 1;
//         }

//         printf("%d---:\t\t subs_l : %d\n", i, subs_l);
//         if (subs_l >= result) {
//             result = subs_l;
//         }
//     }

//     printf("\nresult: %d\n", result);
    
//     return 0;
// }