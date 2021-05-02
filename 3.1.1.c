#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void)
{

 void sigint_handler(int sig);
 void sigtstp_handler(int tstp);
 void sigquit_handler(int quit);
 char s[200];

 if(signal(SIGINT,sigint_handler)==SIG_ERR)
 {
  perror("signal");
  exit(1);
 }
 else if(signal(SIGTSTP,sigtstp_handler)==SIG_ERR)
 {
  perror("signal");
  exit(1);
 }
 else if(signal(SIGQUIT,sigquit_handler)==SIG_ERR)
 { 
  perror("signal");
  exit(1);
 }


 printf("Enter a signal:\n");
 
 if(fgets(s,200,stdin)==NULL)
 perror("gets");
 else 
 printf("you entered: %s\n", s);

return 0;
}

void sigint_handler(int sig)
{
 printf("This is a speacial signal handler for <ctrl+C>\n");
}
void sigtstp_handler(int tstp)
{
 printf("This is a special signal handler for <CTRL + Z>\n");
}
void sigquit_handler(int quit)
{
 printf("This is a special signal handler for <CTRL + />\n");
}
