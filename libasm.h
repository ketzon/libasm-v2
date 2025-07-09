#ifndef LIBASM_H
# define LIBASM_H

#define HUGE_STRING  "LLorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse id mattis magna. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Suspendisse potenti. Aenean ac ex sit amet augue dignissim congue. Phasellus pretium ex quis elementum viverra. Cras vel libero et nunc vulputate eleifend non ac metus. Suspendisse aliquam massa sit amet erat lobortis, nec tristique nulla lobortis. Nulla aliquet magna nec magna hendrerit, in pharetra velit bibendum. Aliquam libero ligula, ullamcorper a sollicitudin sed, faucibus eget nibh. Nulla ut magna feugiat, lacinia mauris in, vestibulum metus. Maecenas non ultrices purus, at efficitur augue. Praesent at aliquet felis. Nullam non sem elit. Morbi nec lorem eu ex pretium fermentum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse id mattis magna. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Suspendisse potenti. Aenean ac ex sit amet augue dignissim congue. Phasellus pretium ex quis elementum viverra. Cras vel libero et nunc vulputate eleifend non ac metus. Suspendisse aliquam massa sit amet erat lobortis, nec tristique nulla lobortis. Nulla aliquet magna nec magna hendrerit, in pharetra velit bibendum. Aliquam libero ligula, ullamcorper a sollicitudin sed, faucibus eget nibh. Nulla ut magna feugiat, lacinia mauris in, vestibulum metus. Maecenas non ultrices purus, at efficitur augue. Praesent at aliquet felis. Nullam non sem elit. Morbi nec lorem eu ex pretium fermentum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse id mattis magna. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Suspendisse potenti. Aenean ac ex sit amet augue dignissim congue. Phasellus pretium ex quis elementum viverra. Cras vel libero et nunc vulputate eleifend non ac metus. Suspendisse aliquam massa sit amet erat lobortis, nec tristique nulla lobortis. Nulla aliquet magna nec magna hendrerit, in pharetra velit bibendum. Aliquam libero ligula, ullamcorper a sollicitudin sed, faucibus eget nibh. Nulla ut magna feugiat, lacinia mauris in, vestibulum metus. Maecenas non ultrices purus, at efficitur augue. Praesent at aliquet felis. Nullam non sem elit. Morbi nec lorem eu ex pretium fermentum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse id mattis magna. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Suspendisse potenti. Aenean ac ex sit amet augue dignissim congue. Phasellus pretium ex quis elementum viverra. Cras vel libero et nunc vulputate eleifend non ac metus. Suspendisse aliquam massa sit amet erat lobortis, nec tristique nulla lobortis. Nulla aliquet magna nec magna hendrerit, in pharetra velit bibendum. Aliquam libero ligula, ullamcorper a sollicitudin sed, faucibus eget nibh. Nulla ut magna feugiat, lacinia mauris in, vestibulum metus. Maecenas non ultrices purus, at efficitur augue. Praesent at aliquet felis. Nullam non sem elit. Morbi nec lorem eu ex pretium fermentum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse id mattis magna. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Suspendisse potenti. Aenean ac ex sit amet augue dignissim congue. Phasellus pretium ex quis elementum viverra. Cras vel libero et nunc vulputate eleifend non ac metus. Suspendisse aliquam massa sit amet erat lobortis, nec tristique nulla lobortis. Nulla aliquet magna nec magna hendrerit, in pharetra velit bibendum. Aliquam libero ligula, ullamcorper a sollicitudin sed, faucibus eget nibh. Nulla ut magna feugiat, lacinia mauris in, vestibulum metus. Maecenas non ultrices purus, at efficitur augue. Praesent at aliquet felis. Nullam non sem elit. Morbi nec lorem eu ex pretium fermentum. orem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse id mattis magna. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Suspendisse potenti. Aenean ac ex sit amet augue dignissim congue. Phasellus pretium ex quis elementum viverra. Cras vel libero et nunc vulputate eleifend non ac metus. Suspendisse aliquam massa sit amet erat lobortis, nec tristique nulla lobortis. Nulla aliquet magna nec magna hendrerit, in pharetra velit bibendum. Aliquam libero ligula, ullamcorper a sollicitudin sed, faucibus eget nibh. Nulla ut magna feugiat, lacinia mauris in, vestibulum metus. Maecenas non ultrices purus, at efficitur augue. Praesent at aliquet felis. Nullam non sem elit. Morbi nec lorem eu ex pretium fermentum. "

# include <sys/types.h>
# include <stdlib.h>  
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>


//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define END "\e[0m"



size_t  ft_strlen(const char *s);
char   *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char   *ft_strdup(const char *src);

#endif
