#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int64_t maxofthree(int64_t, int64_t, int64_t);
size_t  ft_strlen(const char *str);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s);

int main()
{
    char str[10] = "HOLAAs";
    char dst[10];
    char dst2[10];
    printf("%ld\n", maxofthree(2, 3, 1));
    printf("%zu\n", strlen("holaa"));
    printf("%zu\n", ft_strlen("holaa"));
    printf("%i\n", strcmp("", "a"));
    printf("%i\n", ft_strcmp("", "a"));
    printf("%s\n", strcpy(dst, str));
    printf("dst %s\n", dst);
    printf("%s\n", ft_strcpy(dst2, str));
    printf("dst2 %s\n", dst2);
    printf("%s\n", ft_strdup(str));

}