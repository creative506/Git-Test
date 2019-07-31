#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define _XOPEN_SOURCE


int main(int argc, char **argv)
{
    /*
     Assume that each password has been hashed with C’s DES-based (not MD5-based) crypt function.
     
     Assume that each password is no longer than five (5) characters. Gasp!
     
     Assume that each password is composed entirely of alphabetical characters (uppercase and/or lowercase).
     
     i need to iterate over all possible values of the password , it can be 1-5 character long
     
     1- we start by trying one letter 56 possiblities and compare each hashed value with the one provided
     by the user
     
     2- then we leverage the plain length to be 2 characters long 56^2 possible values.
     
     */
    
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char salt[3] ;
    char *hash = argv[1];
    
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    salt[2] = '\0';
    
    int one, two, three, four, five, length = strlen(alphabet) ;
    char str1[2], str2[3], str3[4], str4[5], str5[6];
    for(one = 0 ; one < length ; one++)
    {
        str1[0] = alphabet[one];
        str1[1] = '\0';
        char *testHash = crypt(str1, salt);
        if(strcmp(testHash, hash) == 0)
        {
            printf("%s\n", str1);
            exit(0);
        }
        else
        {
            str2[0] = alphabet[one];
            for(two = 0 ; two < length ; two++)
            {
                str2[1] = alphabet[two];
                str2[2] = '\0';
                testHash = crypt(str2, salt);
                if(strcmp(testHash, hash) == 0)
                {
                    printf("%s\n", str2);
                    exit(0);
                }
                else
                {
                    str3[0] = alphabet[one];
                    str3[1] = alphabet[two];
                    for(three = 0 ; three < length ; three++)
                    {
                        str3[2] = alphabet[three];
                        str3[3] = '\0';
                        testHash = crypt(str3, salt);
                        if(strcmp(testHash, hash) == 0)
                        {
                            printf("%s\n", str3);
                            exit(0);
                        }
                        else
                        {
                            str4[0] = alphabet[one];
                            str4[1] = alphabet[two];
                            str4[2] = alphabet[three];
                            for(four = 0 ; four < length; four++)
                            {
                                str4[3] = alphabet[four];
                                str4[4] = '\0';
                                testHash = crypt(str4, salt);
                                if(strcmp(testHash, hash) == 0)
                                {
                                    printf("%s\n", str4);
                                    exit(0);
                                }
                                else
                                {
                                    str5[0] = alphabet[one] ;
                                    str5[1] = alphabet[two] ;
                                    str5[2] = alphabet[three] ;
                                    str5[3] = alphabet[four] ;
                                    for(five = 0 ; five < length ; five++)
                                    {
                                        str5[4] = alphabet[five];
                                        str5[5] = '\0';
                                        testHash = crypt(str5, salt);
                                        
                                        if(strcmp(testHash, hash) == 0)
                                        {
                                            printf("%s\n", str5);
                                            exit(0);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("could not found that!\n");
}
