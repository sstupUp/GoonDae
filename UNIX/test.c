#include "apue.h"

int main()
{
  sigset_t set;

  sigemptyset(&set);
  sigaddset(&set, SIGINT);

  pr_mask("Hi");

  exit(0);
}
