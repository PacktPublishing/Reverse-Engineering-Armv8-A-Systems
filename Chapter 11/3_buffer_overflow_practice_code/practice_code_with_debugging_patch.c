char stream_buffer[BUFF_SIZE];  
unsigned int task_state;  

void set_task_state(unsigned int new_state) {  
    if (!(task_state == TASK_STATE_SLEEP || 
               task_state == TASK_STATE_RUN)) }  
        abort();  
    }
    task_state = new_state;  
}  
