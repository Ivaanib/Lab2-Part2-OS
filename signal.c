/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// void handler(int signum)
// { //signal handler
//   printf("Hello World!\n");
//   exit(1); //exit after printing
// }
// void sigint_handler(int signum) {
//     // Signal handler for SIGINT
//     printf("Received SIGINT: Exiting program...\n");
//     exit(0);
//   }
// int main(int argc, char * argv[])
// {
//   signal(SIGALRM,handler); //register handler to handle SIGALRM
//   signal(SIGINT, sigint_handler); // Register handler to handle SIGINT
//   alarm(5); //Schedule a SIGALRM for 5 seconds
//   while(1) { // Busy wait for signals to be delivered
//         pause(); // Sleep until a signal is received
//     } 
//   return 0; //never reached
// }



// volatile sig_atomic_t alarm_count = 0;  // Global variable to count alarms


// void handler(int signum)
//  { //signal handler
//    printf("Hello World!\n");
//    alarm_count++;  // Increment the alarm count
//  }
// void sigint_handler(int signum) {
//     // Signal handler for SIGINT
//     printf("Received SIGINT: Exiting program...\n");
//     exit(0);
// }

// int main(int argc, char *argv[]) {
//     // Register the handler for SIGALRM
//     signal(SIGALRM, handler); // Register handler to handle SIGALRM
//     // Register the handler for SIGINT
//     signal(SIGINT, sigint_handler); // Register handler to handle SIGINT

//     alarm(5); // Schedule a SIGALRM for 5 seconds
    
//     while (1) { // Busy wait for signals to be delivered
//         pause(); // Sleep until a signal is received
//         printf("Turing was right!\n");  // Print after each SIGALRM
//         alarm(5); // Reschedule the SIGALRM
//     }
    
//     return 0; // Never reached
// }
volatile sig_atomic_t signal_received = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  signal_received = 1; //exit after printing
  alarm(5);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 seconds
  while (1){
    if (signal_received){
      printf("Turing was right!\n");
      signal_received = 0; 
    }
    usleep(100000);
  };//busy wait for signal to be delivered
  
  return 0; //never reached
}