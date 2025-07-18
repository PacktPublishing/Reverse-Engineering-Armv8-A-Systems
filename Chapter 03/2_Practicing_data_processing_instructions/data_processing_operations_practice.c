#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define TASK_RUNNING          0x0000
#define TASK_INTERRUPTIBLE    0x0001
#define TASK_UNINTERRUPTIBLE  0x0002
#define __TASK_STOPPED	      0x0004

void compare_operation(void)
{
	unsigned int state = TASK_UNINTERRUPTIBLE | TASK_INTERRUPTIBLE;
	unsigned int count = 1;

	if (state & TASK_UNINTERRUPTIBLE) {
		count++;
		state &= ~TASK_UNINTERRUPTIBLE;
	}
	else {
		count--;
		state |= __TASK_STOPPED;
	}
	check_curr_state(state);
}
	
int main() 
{
	compare_operation();
	return 0;	
}
