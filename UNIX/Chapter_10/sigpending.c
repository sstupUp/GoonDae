#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void sig_int(int);

static void sig_int(int signo)
{
  printf("\ncaught SIGINT\n");

  if(signal(SIGINT, SIG_DFL) == SIG_ERR)
    {
      printf("can't reset SIGQUIT");

      return;
    }
}

int main(void)
{
  sigset_t newmask, oldmask, pendmask;

  if(signal(SIGINT, sig_int) == SIG_ERR)
    {
      printf("signal() error\n");

      return -1;
    }

  sigemptyset(&newmask);
  sigaddset(&newmask, SIGINT);

  printf("blocking sig_int\n");
  
  if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    {
      printf("SIG_BLOCK error");

      return -1;
    }

  sleep(5);
  
  if(sigpending(&pendmask) < 0)
    {
      printf("sigpending error\n");

      return -1;
    }
  
  if(sigismember(&pendmask, SIGINT))
    printf("\nSIGINT pending\n");
  
  if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    {
      printf("SIG_SETMASK error");

      return -1;
    }

  printf("SIGINT unblocked\n");

  sleep(5);

  return 0;
}
  
