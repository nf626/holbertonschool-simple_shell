#include "shell.h"

extern char **environ;

char *get_env_value(const char *name)
{
    size_t name_len = _strlen(name);
    for (int i = 0; environ[i] != NULL; i++)
    {
        if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            return (_strdup(&environ[i][name_len + 1]));
        }
    }
    return (NULL);
}
