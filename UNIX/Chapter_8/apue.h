#ifndef _APUE_H
#define _APUE_H

#define _POSIX_CSOURCE 200809L

#if defined(SOLARIS)    /* Solaris 10 */
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 700
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <termio.h>   /* for winsize */

#if defined(MACOS) || !defined(TIOCGWINSZ)
#include <sys/ioctl.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <signal.h>

#define MAXLINE 4096

/*
 * Default file access permissions for new files.
 */

#define FILE_MODE (S_ISUSR | S_IWUSR | S_IRGRP | S_IROTH)

/*
 * Default permissions for new directories.
 */

#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void Sigfunc(int);    /* for signal handlers */

#define min(a,b)   ((a) < (b) ? (a) : (b))
#define max(a,b)   ((a) > (b) ? (a) : (b))

/*
* Prototypes for our own functions.
*/

char *path_alloc(size_t *); /* Figure 2.16 */
long open_max(void); /* Figure 2.17 */

/*
* Prototypes for our own functions.
*/

char *path_alloc(size_t *);  /* Figure 2.16 */
long open_max(void);         /* Figure 2.17 */
int set_cloexec(int);        /* Figure 13.9 */
void clr_fl(int, int);
void set_fl(int, int);       /* Figure 3.12 */
void pr_exit(int);           /* Figure 8.5 */
void pr_mask(const char *);                  /* Figure 10.14 */
Sigfunc *signal_intr(int, Sigfunc *);        /* Figure 10.19 */
void daemonize(const char *);                /* Figure 13.1 */
void sleep_us(unsigned int);                 /* Exercise 14.5 */
ssize_t readn(int, void *, size_t);          /* Figure 14.24 */
ssize_t writen(int, const void *, size_t);   /* Figure 14.24 */
int fd_pipe(int *);                          /* Figure 17.2 */
int recv_fd(int, ssize_t (*func)(int, const void *, size_t));    /* Figure 17.14 */

int send_fd(int, int);                        /* Figure 17.13 */
int send_err(int, int, const char *);         /* Figure 17.12 */
int serv_listen(const char *);                /* Figure 17.8 */
int serv_accept(int, uid_t *);                /* Figure 17.9 */
int cli_conn(const char *);                   /* Figure 17.10 */
int buf_args(char *, int (*func)(int,char **));                  /* Figure 17.23 */
int tty_cbreak(int);                          /* Figure 18.20 */
int tty_raw(int);                             /* Figure 18.20 */
int tty_reset(int);                           /* Figure 18.20 */
void tty_atexit(void);                        /* Figure 18.20 */
struct termios *tty_termios(void);                               /* Figure 18.20 */
int ptym_open(char *, int);                   /* Figure 19.9 */
int ptys_open(char *);                        /* Figure 19.9 */

#ifdef TIOCGWINSZ
pid_t pty_fork(int *, char *, int, const struct termios *, const struct winsize *); /* Figure 19.10 */
#endif

int lock_reg(int, int, int, off_t, int, off_t); /* Figure 14.5 */

#define read_lock(fd, offset, whence, len) lock_reg((fd), F_SETLK, F_RDLCK, (offset), (whence), (len))
#define readw_lock(fd, offset, whence, len) lock_reg((fd), F_SETLKW, F_RDLCK, (offset), (whence), (len))
#define write_lock(fd, offset, whence, len) lock_reg((fd), F_SETLK, F_WRLCK, (offset), (whence), (len))
#define writew_lock(fd, offset, whence, len) lock_reg((fd), F_SETLKW, F_WRLCK, (offset), (whence), (len))
#define un_lock(fd, offset, whence, len) lock_reg((fd), F_SETLK, F_UNLCK, (offset), (whence), (len))

pid_t lock_test(int, int, off_t, int, off_t); /* Figure 14.6 */

#define is_read_lockable(fd, offset, whence, len) (lock_test((fd), F_RDLCK, (offset), (whence), (len)) == 0)
#define is_write_lockable(fd, offset, whence, len) (lock_test((fd), F_WRLCK, (offset), (whence), (len)) == 0)

void err_msg(const char *, ...); /* Appendix B */
void err_dump(const char *, ...) __attribute__((noreturn));
void err_quit(const char *, ...) __attribute__((noreturn));
void err_cont(int, const char *, ...);
void err_exit(int, const char *, ...) __attribute__((noreturn));
void err_ret(const char *, ...);
void err_sys(const char *, ...) __attribute__((noreturn));
void log_msg(const char *, ...); /* Appendix B */

void log_open(const char *, int, int);
void log_quit(const char *, ...) __attribute__((noreturn));
void log_ret(const char *, ...);
void log_sys(const char *, ...) __attribute__((noreturn));
void log_exit(int, const char *, ...) __attribute__((noreturn));
void TELL_WAIT(void); /* parent/child from Section 8.9 */
void log_open(const char *, int, int);
void log_quit(const char *, ...) __attribute__((noreturn));
void log_ret(const char *, ...);
void log_sys(const char *, ...) __attribute__((noreturn));
void log_exit(int, const char *, ...) __attribute__((noreturn));
void TELL_WAIT(void);       /* parent/child from Section 8.9 */
void TELL_PARENT(pid_t);
void TELL_CHILD(pid_t);
void WAIT_PARENT(void);
void WAIT_CHILD(void);

#endif /* _APUE_H */

/////////////////////////////////////////////////////////////////

/* std_error */

////////////////////////////////////////////////////////////////

#include <errno.h> /* for definition of errno */
#include <stdarg.h> /* ISO C variable aruments */
#include <string.h>

static void err_doit(int, int, const char *, va_list);

/*
 * Nonfatal error related to a system call.
 * Print a message and return.
 */

void err_ret(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(1, errno, fmt, ap);
  va_end(ap);
}

/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 */

void err_sys(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(1, errno, fmt, ap);
  va_end(ap);
  exit(1);
}

/*
 * Nonfatal error unrelated to a system call.
 * Error code passed as explict parameter.
 * Print a message and return.
 */

void err_cont(int error, const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(1, error, fmt, ap);
  va_end(ap);
}

/*
 * Fatal error unrelated to a system call.
 * Error code passed as explict parameter.
 * Print a message and terminate.
 */

void err_exit(int error, const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(1, error, fmt, ap);
  va_end(ap);
  exit(1);
}

/*
 * Fatal error related to a system call.
 * Print a message, dump core, and terminate.
 */

void err_dump(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(1, errno, fmt, ap);
  va_end(ap);
  abort(); /* dump core and terminate */
  exit(1); /* shouldn’t get here */
}

/*
 * Nonfatal error unrelated to a system call.
 * Print a message and return.
 */

void err_msg(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(0, 0, fmt, ap);
  va_end(ap);
}

/*
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */

void err_quit(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(0, 0, fmt, ap);
  va_end(ap);
  exit(1);
}

/*
 * Print a message and return to caller.
 * Caller specifies "errnoflag".
 */

static void err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
  char buf[MAXLINE];

  vsnprintf(buf, MAXLINE-1, fmt, ap);

  if (errnoflag)
    snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s", strerror(error));

  strcat(buf, "\n");

  fflush(stdout); /* in case stdout and stderr are the same */
  fputs(buf, stderr);
  fflush(NULL); /* flushes all stdio output streams */
}

//////////////////////////////////////////////////////////////////////

/* path_alloc */

///////////////////////////////////////////////////////////////////////

#include <errno.h>
#include <limits.h>

#ifdef PATH_MAX
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif

static long posix_ver = 0;
static long xsi_ver = 0;

#define PATH_MAX_GUESS 1024

char* path_alloc(size_t *sizep)
{
  char *ptr;
  size_t size;

  if(posix_ver == 0)
    posix_ver = sysconf(_SC_VERSION);

  if(xsi_ver == 0)
    xsi_ver = sysconf(_SC_XOPEN_VERSION);

  if(pathmax == 0)
    {
      errno = 0;

      if((pathmax = pathconf("/", _PC_PATH_MAX)) < 0)
        {
          if(errno == 0)
            pathmax = PATH_MAX_GUESS;
          else
            err_sys("pathconf error for _PC_PATH_MAX");
        }
      else
        pathmax++;
    }

  if((posix_ver < 200112L) && (xsi_ver < 4))
    size = pathmax + 1;
  else
    size = pathmax;

  if((ptr = malloc(size)) == NULL)
    err_sys("malloc error for pathname");

  if(sizep != NULL)
    *sizep = size;

  return(ptr);
}

////////////////////////////////////////////////////////////////////

/* pr_exit */

///////////////////////////////////////////////////////////////////

#include <sys/wait.h>

void pr_exit(int status)
{
  if(WIFEXITED(status))
    printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
  else if(WIFSIGNALED(status))
    printf("abnormal termination, signal number %d\n", WTERMSIG(status));
  else if(WIFSTOPPED(status))
    printf("child stopped, signal number = %d\n", WSTOPSIG(status));

#ifdef WCOREDUMP
  WCOREDUMP(status) ? " (core file gernerated)" : ")";
#else
  ")";
#endif

}

////////////////////////////////////////////////////////////////////

/* functions for a race condition */

////////////////////////////////////////////////////////////////////

static volatile sig_atomic_t sigflag; /* set nonzero by sig handler */
static sigset_t newmask, oldmask, zeromask;

static void sig_usr(int signo) /* one signal handler for SIGUSR1 and SIGUSR2 */
{
  sigflag = 1;
}

void TELL_WAIT(void)
{
  if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    err_sys("signal(SIGUSR1) error");
  if (signal(SIGUSR2, sig_usr) == SIG_ERR)
    err_sys("signal(SIGUSR2) error");

  sigemptyset(&zeromask);
  sigemptyset(&newmask);
  sigaddset(&newmask, SIGUSR1);

  sigaddset(&newmask, SIGUSR2);
  /* Block SIGUSR1 and SIGUSR2, and save current signal mask */

  if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    err_sys("SIG_BLOCK error");
}

void TELL_PARENT(pid_t pid)
{
  kill(pid, SIGUSR2); /* tell parent we’re done */
}

void WAIT_PARENT(void)
{
  while (sigflag == 0)
    sigsuspend(&zeromask); /* and wait for parent */

  sigflag = 0;

  /* Reset signal mask to original value */
  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    err_sys("SIG_SETMASK error");
}

void TELL_CHILD(pid_t pid)
{
  kill(pid, SIGUSR1); /* tell child we’re done */
}

void WAIT_CHILD(void)
{
    while (sigflag == 0)
      sigsuspend(&zeromask); /* and wait for child */

    sigflag = 0;

    /* Reset signal mask to original value */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
      err_sys("SIG_SETMASK error");
}
