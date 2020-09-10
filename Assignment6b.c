#include<pthread.h>
#include <stdio.h>
#define NUM_TICKETS 35
#define NUM_SELLERS 4

static int numTickets = NUM_TICKETS;
static Semaphore ticketsLock;

void main(int argc, char **argv)
{
int i;
char name[32];
bool verbose = (argc == 2 && (strcmp(argv[1], "-v") == 0));
InitThreadPackage(verbose);
ticketsLock = SemaphoreNew("Tickets Lock", 1);
for (i = 0; i < NUM_SELLERS; i++) {
sprintf(name, "Seller #%d", i); 
ThreadNew(name, SellTickets, 0);
}
RunAllThreads();
SemaphoreFree(ticketsLock);
printf("All done!\n");
}

static void SellTickets(void)
{
bool done = false;
int numSoldByThisThread = 0; 
while (!done) {
RandomDelay(500000, 2000000);
SemaphoreWait(ticketsLock); 
if (numTickets == 0) { 
done = true; 
} else {
numTickets--;
numSoldByThisThread++;
printf("%s sold one (%d left)\n", ThreadName(), numTickets);
}
SemaphoreSignal(ticketsLock); 
}
printf("%s noticed all tickets sold! (I sold %d myself) \n",
ThreadName(), numSoldByThisThread);
}
static void RandomDelay(int atLeastMicrosecs, int atMostMicrosecs)
{
long choice;
int range = atMostMicrosecs - atLeastMicrosecs;
PROTECT(choice = random()); 
ThreadSleep(atLeastMicrosecs + choice % range); 
}



/*OUTPUT

epic18:/usr/class/cs107/other/thread_examples>ticketSeller
Seller #1 sold one (34 left)
Seller #0 sold one (33 left)
Seller #1 sold one (32 left)
Seller #1 sold one (31 left)
Seller #1 sold one (30 left)
Seller #1 sold one (29 left)
Seller #1 sold one (28 left)
Seller #2 sold one (27 left)
Seller #3 sold one (26 left)
Seller #2 sold one (25 left)
Seller #3 sold one (24 left)
Seller #2 sold one (23 left)
Seller #0 sold one (22 left)
Seller #1 sold one (21 left)
Seller #2 sold one (20 left)
Seller #0 sold one (19 left)
Seller #1 sold one (18 left)
Seller #1 sold one (17 left)
Seller #3 sold one (16 left)
Seller #2 sold one (15 left)
Seller #0 sold one (14 left)
Seller #0 sold one (13 left)
Seller #1 sold one (12 left)
Seller #3 sold one (11 left)
Seller #2 sold one (10 left)
Seller #0 sold one (9 left)
Seller #0 sold one (8 left)
Seller #1 sold one (7 left)
Seller #3 sold one (6 left)
Seller #2 sold one (5 left)
Seller #0 sold one (4 left)
Seller #1 sold one (3 left)
Seller #1 sold one (2 left)
Seller #1 sold one (1 left)
Seller #1 sold one (0 left)
Seller #3 noticed all tickets sold! (I sold 5 myself)
Seller #2 noticed all tickets sold! (I sold 7 myself)
Seller #1 noticed all tickets sold! (I sold 15 myself)
Seller #0 noticed all tickets sold! (I sold 8 myself)
All done!*/
