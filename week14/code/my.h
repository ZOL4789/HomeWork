#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <sys/times.h>
#include <pthread.h>
#include <limits.h>
typedef struct sendval{
	int n;
	int s;
}sv;

#define NUM 4
