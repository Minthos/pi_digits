#include <stdio.h>
#include <error.h>
#include <string.h>


FILE *f = 0;

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "r");
    __uint64_t i = 0;
    size_t nmemb = 1;
    size_t divisor = 1;
    const size_t bufsiz = 100;
    char i_str[bufsiz];
    char str[bufsiz];
    bzero(i_str, bufsiz);
    bzero(str, bufsiz);
    do{
        if(i/divisor == 10){
            divisor *= 10;
            nmemb++;
        }

        int status = snprintf(i_str, nmemb+1, "%ld", i);
        status = fseek(f, i+1, SEEK_SET);
        if(status != 0){
            perror(0);
            return(status);
        }

        size_t num_read = fread(str, sizeof(char), nmemb, f);
        if(num_read != nmemb){
            return(0);
        }

        int diff = strncmp(i_str, str, nmemb);
        if(diff == 0){
            printf("%ld\n", i);
        }

        i++;
    } while(nmemb + 1 < bufsiz);

    return(-1);
}

