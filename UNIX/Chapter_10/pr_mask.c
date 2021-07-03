#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define TOTNUM_SIG 31

void pr_mask(const char*str)
{
  sigset_t sigset;
  int errno_save;
  int i;
  char *signame;
  
  errno_save = errno;

  if(sigprocmask(0, NULL, &sigset) < 0)
    {
      printf("sigprocmask erro\n");

      return;
    }
  else
    {
      printf("%s", str);

      for(i = 1; i <= TOTNUM_SIG; ++i)
	if(sigismember(&sigset, i))
	  {
	    signame = strsignal(i);
	    
	    printf("\t\t%s\n", signame);
	  }
      
    }

  return;
}


int main(void)
{
  sigset_t maskset, oldset;
  int i;

  printf("-----------------------------------------\n");  
  printf("masking SIGINT\n");
  
  sigemptyset(&maskset);
  sigaddset(&maskset, SIGINT);
  sigprocmask(0, NULL, &oldset);

  sigprocmask(SIG_SETMASK, &maskset, NULL);

  printf("done!\n-----------------------------------------\n\n");
  pr_mask("masked signals:\n");

  printf("\n-----------------------------------------\nunmasking SIGINT\n");
  
  sigprocmask(SIG_SETMASK, &oldset, NULL);

  printf("done!\n");

  printf("-----------------------------------------\n");
  printf("masking EVERY signal\n");

  sigemptyset(&maskset);
  for(i = 1; i <= TOTNUM_SIG; ++i)
    sigaddset(&maskset, i);
  sigprocmask(0,NULL, &oldset);

  sigprocmask(SIG_SETMASK, &maskset, NULL);

  printf("done!\n-----------------------------------------\n\n");

  pr_mask("masked signals:\n");
  printf("\n-----------------------------------------\nunmasking EVERY signal\n");
  
  sigprocmask(SIG_SETMASK, &oldset, NULL);

  printf("done!\n");
  printf("-----------------------------------------\n");
  
  
  return 0;
}
