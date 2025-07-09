#include "../header.h"

char *ft_strdup(const char *src){
    if (src == NULL){
        return NULL;
    }
    char *copy = malloc(sizeof(src));
    if (copy == NULL) {
        return NULL;
    }
    int i = 0;
    while (src[i]){
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}
