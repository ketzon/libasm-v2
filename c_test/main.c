#include "header.h"

void test_strcpy(){
    char *src = "simple copy test";
    char *dest = malloc(sizeof(char) * strlen(src)); 
    char *res = ft_strcpy(dest, src);
    printf("le resultat de strcpy est %s\n", res);
    free(dest);
}

void test_strcmp() {
    const char *s1 = "";
    const char *s2 = "";
    int res = ft_strcmp(s1, s2);
    if ( res == 0) {
        printf("les chaines sont identique: %d\n", res);
        return ;
    }
    if ( res < 0) { 
        printf("la chaine 1 est plus petite que la 2: %d\n", res);
        return ;
    }
    if ( res > 0) {
        printf("la chaine 1 est plus grande que la 2: %d\n", res);
        return ;
    }
}

void test_strdup() {
    char *val = "hello world";
    char *copy = strdup(val);
    printf("voici le copy de strdup: %s\n", copy);
    free(copy);
}
int errno;
int main(void){
    /* printf("====FT_STRCPY===\n"); */
    /* test_strcpy(); */ 
    /* printf("====END===\n"); */
    /* printf("====FT_STRCMP===\n"); */
    test_strcmp(); 
    /* printf("====END===\n"); */
    /* printf("====FT_WRITE===\n"); */
    /* int res = write(1, "hello\n", 6); */
    /* printf("la valeur de write est: %d et le code d'erreur est: %s\n ",res, strerror(errno)); */
    /* printf("====END===\n"); */
    /* printf("====FT_STRDUP===\n"); */
    test_strdup();
    /* printf("====END===\n"); */
}
