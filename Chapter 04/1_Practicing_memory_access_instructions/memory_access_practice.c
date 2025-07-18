#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct task_struct {
        int flags;
        int state;
        char task_name[15];
};

void init_task_state(void)
{
        struct task_struct * ptr;
        ptr = (struct task_struct *)malloc(sizeof(*ptr));
        ptr->state = 1;

        printf("state:%d \n", ptr->state);
        free(ptr);
}

int main(void)
{
        init_task_state();

        return 0;
}
