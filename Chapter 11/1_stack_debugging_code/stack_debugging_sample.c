#define GET_SP_REGISTER_DEBUG() \  
	debug_sp_register()
	
unsigned long sp_value;  
unsigned long lr_value;  

static inline void debug_sp_register(void)  
{  
	asm volatile ("mov %0, sp\n" \  
		      "mov %1, x30" \  
		      :"=r" (sp_value), "=r" (lr_value));  

	printf("sp: 0x%lx, x30: 0x%lx \n", sp_value, lr_value);  

	printf("[0x%lx]: 0x%lx \n", (unsigned long)sp_value, *((unsigned long*)(sp_value + 0x0)));  
	printf("[0x%lx]: 0x%lx \n", (unsigned long)(sp_value + 0x8), *((unsigned long*)(sp_value + 0x8)));  
	printf("[0x%lx]: 0x%lx \n", (unsigned long)(sp_value + 0x10), *((unsigned long*)(sp_value + 0x10)));  
}

int add_func(int x, int y)  
{  
	int result = x + y;
  
	GET_SP_REGISTER_DEBUG();
	suspicious_stack_corruption();  
	printf("x: %d, y: %d \n", x, y);  

	return result;  
}  

  
