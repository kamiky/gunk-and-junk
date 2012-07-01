/*
** tp-strace-ex2.c for tp-strace-ex2.c in /home/krik/work/tp/strace/
**
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
**
** Started on  Thu May 19 11:08:13 2011 patrick rabier
** Last update Thu May 19 12:15:31 2011 Patrick Rabier
*/

#include "my.h"

static char *(syscall_names[256]) = {
  "exit", "fork", "read", "write", "open", "close", "waitpid", "creat",
  "link", "unlink", "execve", "chdir", "time", "mknod", "chmod",
  "lchown", "break", "oldstat", "lseek", "getpid", "mount", "umount",
  "setuid", "getuid", "stime", "ptrace", "alarm", "oldfstat", "pause",
  "utime", "stty", "gtty", "access", "nice", "ftime", "sync", "kill",
  "rename", "mkdir", "rmdir", "dup", "pipe", "times", "prof", "brk",
  "setgid", "getgid", "signal", "geteuid", "getegid", "acct", "umount2",
  "lock", "ioctl", "fcntl", "mpx", "setpgid", "ulimit", "oldolduname",
  "umask", "chroot", "ustat", "dup2", "getppid", "getpgrp", "setsid",
  "sigaction", "sgetmask", "ssetmask", "setreuid", "setregid",
  "sigsuspend", "sigpending", "sethostname", "setrlimit", "getrlimit",
  "getrusage", "gettimeofday", "settimeofday", "getgroups", "setgroups",
  "select", "symlink", "oldlstat", "readlink", "uselib", "swapon",
  "reboot", "readdir", "mmap", "munmap", "truncate", "ftruncate",
  "fchmod", "fchown", "getpriority", "setpriority", "profil", "statfs",
  "fstatfs", "ioperm", "socketcall", "syslog", "setitimer", "getitimer",
  "stat", "lstat", "fstat", "olduname", "iopl", "vhangup", "idle",
  "vm86old", "wait4", "swapoff", "sysinfo", "ipc", "fsync", "sigreturn",
  "clone", "setdomainname", "uname", "modify_ldt", "adjtimex",
  "mprotect", "sigprocmask", "create_module", "init_module",
  "delete_module", "get_kernel_syms", "quotactl", "getpgid", "fchdir",
  "bdflush", "sysfs", "personality", "afs_syscall", "setfsuid",
  "setfsgid", "_llseek", "getdents", "_newselect", "flock", "msync",
  "readv", "writev", "getsid", "fdatasync", "_sysctl", "mlock",
  "munlock", "mlockall", "munlockall", "sched_setparam",
  "sched_getparam", "sched_setscheduler", "sched_getscheduler",
  "sched_yield", "sched_get_priority_max", "sched_get_priority_min",
  "sched_rr_get_interval", "nanosleep", "mremap", "setresuid",
  "getresuid", "vm86", "query_module", "poll", "nfsservctl",
  "setresgid", "getresgid", "prctl","rt_sigreturn","rt_sigaction",
  "rt_sigprocmask", "rt_sigpending", "rt_sigtimedwait",
  "rt_sigqueueinfo", "rt_sigsuspend", "pread", "pwrite", "chown",
  "getcwd", "capget", "capset", "sigaltstack", "sendfile", "getpmsg",
  "putpmsg", "vfork", "ugetrlimit", "mmap2", "truncate64",
  "ftruncate64", "stat64", "lstat64", "fstat64", "lchown32", "getuid32",
  "getgid32", "geteuid32", "getegid32", "setreuid32", "setregid32",
  "getgroups32", "setgroups32", "fchown32", "setresuid32",
  "getresuid32", "setresgid32", "getresgid32", "chown32", "setuid32",
  "setgid32", "setfsuid32", "setfsgid32", "pivot_root", "mincore",
  "madvise", "getdents64", "fcntl64", 0, "security", "gettid",
  "readahead", "setxattr", "lsetxattr", "fsetxattr", "getxattr",
  "lgetxattr", "fgetxattr", "listxattr", "llistxattr", "flistxattr",
  "removexattr", "lremovexattr", "fremovexattr", "tkill", "sendfile64",
  "futex", "sched_setaffinity", "sched_getaffinity", "set_thread_area",
  "get_thread_area", "io_setup", "io_destroy", "io_getevents", "io_submit",
  "io_cancel", "fadvise64", 0, "exit_group", "lookup_dcookie"
};

pid_t		xfork()
{
  pid_t		p;

  p = fork();
  if (p == -1)
    {
      perror("fork");
      exit(EXIT_FAILURE);
    }
  return (p);
}

long		xptrace(enum __ptrace_request req, pid_t pid,
			void *addr, void *data)
{
  long		ret;
  
  ret = ptrace(req, pid, addr, data);  
  if (ret == -1 && errno)
    {
      perror("ptrace");
      exit(EXIT_FAILURE);
    }
  return (ret);
}


void				trace(int p)
{
  int				status;
  struct user_regs_struct	data;
  unsigned int			eip_content;
  int				is_running;
  
  is_running = 1;
  while (is_running)
    {
      waitpid(p, &status, 0);
      if (WIFEXITED(status) || WIFSIGNALED(status))
	is_running = 0;
      else if (WIFSTOPPED(status))
	{
	  xptrace(PTRACE_GETREGS, p, NULL, &data);
	  eip_content = xptrace(PTRACE_PEEKTEXT, p, (void *)data.eip, NULL);
	  if ((eip_content & 0xffff0000) == 0x80cd
	      || (eip_content & 0xffff) == 0x80cd)
	    printf("Syscall %li : %s\n", data.eax, syscall_names[data.eax -1]);
	}
      if (is_running)
	xptrace(PTRACE_SINGLESTEP, p, NULL, NULL);
    }
}

void		launch(char ** argv)
{
  pid_t		p;

  p = xfork();
  if (p)
    trace(p);
  else
    {
      if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
	perror("ptrace");
      else
	{
	  if (execve(argv[1], argv + 1, NULL) == -1)
	    perror("exec");
	  exit(1);
	}
    }
}

int		main(int argc, char **argv)
{
  if (argc < 2)
    printf("[USAGE] ./strace binary\n");
  else
    {
      if (strcmp(argv[1], "-p"))
	launch(argv);
      else
	{
	  if (argc == 2 || !is_numeric(argv[2]))
	    fprintf(stderr, "bad usage : [-p pid]\n");
	  else {
	    xptrace(PTRACE_ATTACH, atoi(argv[2]), NULL, NULL);
	    trace(atoi(argv[2]));
	  }
	}
    }
  return (EXIT_SUCCESS);
}
