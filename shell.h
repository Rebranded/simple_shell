#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND 30
#define MAX_INPUT 1024
#include <unistd.h>
#include <errno.h>

/* list of function prototype */
int prompt(char **env, int is_pipe);
size_t ak_strl(const char *str);
int ak_strncmp(const char *s1, const char *s2, size_t z);
char *ak_strdup(const char *str);
int exe_code(char *code, char **envr);
void ak_strcpy(char *to, const char *from_str);
char *scat(char *to, const char *from);
void perform_env(char **env);
int ak_strcmp(const char *s1, const char *s2);

#endif
