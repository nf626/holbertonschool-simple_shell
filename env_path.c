#include "shell.h"

/** Structure Linked list for path */
typedef struct path_name {
  char *dir;
  struct path_name *next;
}path_t;
/** Linked list for path */
path_t *create_path_list(char *path)
{
  path_t *head = NULL;
  path_t *tail = NULL;

  char *dir = strtok(path, ":");

  while (dir != NULL)
    {
      path_t *new_node = malloc(sizeof(path_t));
      new_node->dir = strdup(dir);
      new_node->next = NULL;

      if (head == NULL)
	{
	  head = new_node;
	  tail = new_node;
	}
      else
	{
	  tail->next = new_node;
	  tail = new_node;
	}
      dir = strtok(NULL, ":");
    }
  return (head);
}
/** free memory in linked list */
void free_list(path_t *path)
{
  path_t *temp = NULL;

  while (path != NULL)
    {
      temp = path;
      path = path->next;
      free(temp->dir);
      free(temp);
    }
  free(path);
}
/** Get environment */
char *_getenv(const char *name)
{
  int i, j;
  int status;

  i = 0;
  while (environ[i] != NULL)
    {
      status = 1;
      j = 0;
      while (environ[i][j] != '=')
	{
	  if (name[j] != environ[i][j])
	    {
	      status = 0;
	      break;
	    }
	  j = j + 1;
	}
      if (status)
	{
	  return (&environ[i][j + 1]);
	}
      i = i + 1;
    }
  return (NULL);
}

