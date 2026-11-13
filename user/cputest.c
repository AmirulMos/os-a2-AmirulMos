#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pinfo.h"
#include "user/user.h"

int
main(void)
{
  int pid = getpid();
  struct pinfo info[64];

  volatile unsigned long x = 0;

  for(unsigned long i = 0; i < 50000000UL; i++)
    x += i;

  int n = getpinfo(info, 64);

  for(int i = 0; i < n; i++){
    if(info[i].pid == pid){
      printf("PID: %d\n", info[i].pid);
      printf("Level: %d\n", info[i].level);
      printf("Runtime ticks: %d\n", info[i].runticks);
      printf("Schedules: %d\n", info[i].nsched);
    }
  }

  exit(0);
}