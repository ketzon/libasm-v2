#include "libasm.h"

void printStrlen(){
    printf("TEST AVEC SIMPLE STRING\n");
    char *str = "hello";
    int len = ft_strlen(str);
    printf("le mot est %s\n", str);
    printf("le nombre de character est %d\n", len);
    printf("\n");

    printf("TEST AVEC EMPTY STRING\n");
    char *str2 = "";
    int len2 = ft_strlen(str2);
    printf("le mot est %s\n", str2);
    printf("le nombre de character est %d\n", len2);
    printf("\n");

    printf("TEST AVEC NOMBRE\n");
    char *str3 = "123";
    int len3 = ft_strlen(str3);
    printf("le mot est %s\n", str3);
    printf("le nombre de character est %d\n", len3);
    printf("\n");

    printf("TEST AVEC BIG CHAINE\n");
    int len4 = ft_strlen(HUGE_STRING);
    printf("le mot est %s\n", HUGE_STRING);
    printf("le nombre de character est %d\n", len4);
    printf("\n");
}

void printStrcpy(){
    printf("====TEST WITH BIG STRING====\n");
    char *dest = malloc(sizeof(char) * strlen(HUGE_STRING));
    char *res = ft_strcpy(dest, HUGE_STRING);
    printf("le resultat de la copy est: %s\n", res);
    printf("====TEST WITH EMPTY STRING====\n");
    char *res2 = ft_strcpy(dest, "");
    printf("le resultat de la copy est: %s\n", res2);
    free(dest);
}

void printStrcmp() {
    const char *s1 = "hello";
    const char *s2 = "hello";
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

int errno;
void printWrite(){
    int fd = open("text.txt", O_WRONLY | O_TRUNC);
    char *str = HUGE_STRING;
    printf("test 1 - ecriture normale:\n");
    int res = ft_write(1, str, ft_strlen(str));
    printf("\nresultat: %d caracteres ecrits\n", res);
    printf("errno: %s\n", strerror(errno));
    printf("\ntest 2 - erreur fd invalide:\n");
    errno = 0;
    res = ft_write(-1, str, ft_strlen(str));
    printf("resultat: %d\n", res);
    printf("errno: %s\n", strerror(errno));
    printf("\ntest 3 - erreur Test open fd:\n");
    errno = 0;  
    res = ft_write(fd, str, ft_strlen(HUGE_STRING));
    printf("resultat: %d\n", res);
    printf("errno: %s\n", strerror(errno));
    close(fd);
    printf("\ntest 4 - NULL buffer:\n");
    errno = 0;  
    res = ft_write(1, NULL, 5);
    printf("resultat: %d\n", res);
    printf("errno: %s\n", strerror(errno));
}

void printRead() {
    int fd = open("text.txt", O_RDONLY);
    if (fd == -1) {
        printf("Erreur ouverture fichier: %s\n", strerror(errno));
        return;
    }
    char buf[500];
    memset(buf, 0, sizeof(buf));  
    printf("\n====TEST WITH A SIMPLE TEXT====\n");
    int res = ft_read(fd, buf, sizeof(buf) - 1);  
    if (res == -1) {
        printf("Erreur ft_read: %s\n", strerror(errno));
    } else {
        buf[res] = '\0';  
        printf("number of character read %d\n", res);
        printf("here is the content of text.txt read: %s\n", buf);
    }
    printf("====END OF TEST====\n");
    printf("\n====TEST WITH A BAD FILE DESCRIPTOR====\n");
    int res2 = ft_read(-1, buf, sizeof(buf) - 1);  
    if (res2 == -1) {
        printf("Erreur ft_read: %s\n", strerror(errno));
    } else {
        buf[res2] = '\0';  
        printf("number of character read %d\n", res2);
        printf("here is the content of text.txt read: %s\n", buf);
    }
    printf("====END OF TEST====\n");
    printf("\n====TEST WITH STDIN====\n");
    int res3 = ft_read(0, buf, sizeof(buf) - 1);  
    if (res3 == -1) {
        printf("Erreur ft_read: %s\n", strerror(errno));
    } else {
        buf[res3] = '\0';  
        printf("number of character read %d\n", res3);
    }
    printf("====END OF TEST====\n");
    close(fd);  
}

void printStrdup() {
    const char *src = "";
    char *copy = ft_strdup(HUGE_STRING);
    char *empty = ft_strdup(src);
    printf("TEST WITH BIG STRING\n");
    printf("la valeur de copy: %s\n", copy);
    printf("TEST WITH EMPTY STRING\n");
    printf("la valeur de empty: %s\n", empty);
}

int main() {
    printStrlen();
    /* printStrcpy(); */
    /* printStrcmp(); */
    /* printWrite(); */
    /* printRead(); */
    /* printStrdup(); */
    return 0;
}

