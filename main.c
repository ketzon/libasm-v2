#include "libasm.h"

void printStrlen(){
    printf(WHT "TEST AVEC SIMPLE STRING\n" END);
    char *str = "hello";
    int len = ft_strlen(str);
    printf("le mot est %s\n", str);
    printf("le nombre de character est %d\n", len);
    printf("\n");

    printf(WHT "TEST AVEC EMPTY STRING\n" END);
    char *str2 = "";
    int len2 = ft_strlen(str2);
    printf("le mot est %s\n", str2);
    printf("le nombre de character est %d\n", len2);
    printf("\n");

    printf(WHT "TEST AVEC NOMBRE\n" END);
    char *str3 = "123";
    int len3 = ft_strlen(str3);
    printf("le mot est %s\n", str3);
    printf("le nombre de character est %d\n", len3);
    printf("\n");

    printf(WHT "TEST AVEC BIG CHAINE\n" END);
    int len4 = ft_strlen(HUGE_STRING);
    printf("le mot est %s\n", HUGE_STRING);
    printf("le nombre de character est %d\n", len4);
}

void printStrcpy(){
    printf(WHT "====TEST WITH BIG STRING====\n" END);
    char *dest = malloc(sizeof(char) * strlen(HUGE_STRING));
    char *res = ft_strcpy(dest, HUGE_STRING);
    printf("le resultat de la copy est: %s\n", res);
    printf(WHT "====TEST WITH EMPTY STRING====\n" END);
    char *res2 = ft_strcpy(dest, "");
    printf("le resultat de la copy est: %s\n", res2);
    free(dest);
}

void printStrcmp() {
    const char *s1 = "hello";
    const char *s2 = "hello";
    printf(WHT "====TEST WITH IDENTICAL STRING====\n" END);
    int res = ft_strcmp(s1, s2);
    if ( res == 0) {
        printf("les chaines sont identique: %d\n", res);
    }
    printf(WHT "====TEST WITH FIRST STRING LOWER THAN S2====\n" END);
    s1 = "hell";
    s2 = "hello";
    res = ft_strcmp(s1, s2);
    if ( res < 0) { 
        printf("la chaine 1 est plus petite que la 2: %d\n", res);
    }
    printf(WHT "====TEST WITH FIRST STRING BIGGER THAN S2====\n" END);
    s1 = "hello";
    s2 = "hell";
    res = ft_strcmp(s1, s2);
    if ( res > 0) {
        printf("la chaine 1 est plus grande que la 2: %d\n", res);
    }
    printf(WHT "====TEST WITH TWO ENPTY STRING ====\n" END);
    s1 = "";
    s2 = "";
    res = ft_strcmp(s1, s2);
    if ( res == 0) {
        printf("les chaines sont vide: %d\n", res);
    }
}

int errno;
void printWrite(){
    int fd = open("text.txt", O_WRONLY | O_TRUNC);
    char *str = HUGE_STRING;
    printf(WHT "====TEST 1 - ecriture normale====\n" END);
    int res = ft_write(1, str, ft_strlen(str));
    printf("\nresultat: %d caracteres ecrits\n", res);
    printf("errno: %s\n", strerror(errno));
    printf(WHT "\nTEST 2 - erreur fd invalide:\n" END);
    errno = 0;
    res = ft_write(-1, str, ft_strlen(str));
    printf("resultat: %d\n", res);
    printf("errno: %s\n", strerror(errno));
    printf(WHT "\nTEST 3 - erreur Test open fd:\n" END);
    errno = 0;  
    res = ft_write(fd, str, ft_strlen(HUGE_STRING));
    printf("resultat: %d\n", res);
    printf("errno: %s\n", strerror(errno));
    close(fd);
    printf(WHT "\nTEST 4 - NULL buffer:\n" END);
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
    printf(WHT "====TEST WITH A SIMPLE TEXT====\n" END);
    int res = ft_read(fd, buf, sizeof(buf) - 1);  
    if (res == -1) {
        printf("Erreur ft_read: %s\n", strerror(errno));
    } else {
        buf[res] = '\0';  
        printf("number of character read %d\n", res);
        printf("here is the content of text.txt read: %s\n", buf);
    }
    printf(WHT "\n====TEST WITH A BAD FILE DESCRIPTOR====\n" END);
    int res2 = ft_read(-1, buf, sizeof(buf) - 1);  
    if (res2 == -1) {
        printf("resultat: %d\n", res2);
        printf("Erreur ft_read: %s\n", strerror(errno));
    } else {
        buf[res2] = '\0';  
        printf("number of character read %d\n", res2);
        printf("here is the content of text.txt read: %s\n", buf);
    }
    /* printf(WHT "\n====TEST WITH STDIN====\n" END); */
    /* int res3 = ft_read(0, buf, sizeof(buf) - 1); */  
    /* if (res3 == -1) { */
        /* printf("resultat: %d\n", res3); */
    /*     printf("Erreur ft_read: %s\n", strerror(errno)); */
    /* } else { */
    /*     buf[res3] = '\0'; */  
    /*     printf("number of character read %d\n", res3); */
    /* } */
    close(fd);  
}

void printStrdup() {
    const char *src = "";
    char *copy = ft_strdup(HUGE_STRING);
    char *empty = ft_strdup(src);
    printf(WHT "TEST WITH BIG STRING\n" END);
    printf("la valeur de copy: %s\n", copy);
    printf(WHT "TEST WITH EMPTY STRING\n" END);
    printf("la valeur de empty: %s\n", empty);
}

int main() {
    printf(BLU "====FT_STRLEN====\n");
    printStrlen();
    printf(BLU "====END====\n\n" END);
    printf(RED "====FT_STRCPY====\n");
    printStrcpy();
    printf(RED "====END====\n\n" END);
    printf(CYN "====FT_STRCMP====\n");
    printStrcmp();
    printf(CYN "====END====\n\n" END);
    printf(GRN "====FT_WRITE====\n");
    printWrite();
    printf(GRN "====END====\n\n" END);
    printf(MAG "====FT_READ====\n");
    printRead();
    printf(MAG "====END====\n\n" END);
    printf(YEL "====FT_STRDUP====\n");
    printStrdup();
    printf(YEL "====END====\n\n" END);
    return 0;
}

