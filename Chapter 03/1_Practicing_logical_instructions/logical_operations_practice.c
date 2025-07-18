#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void logical_operation(void) 
{
	unsigned int x = 0x23, y = 0x123, z = 0x103;
	unsigned int a = 0xf, b = 0xf0; 
	unsigned int result1, result2, result3;

	result1 = x & y;
	result2 = x | z;
	result3 = a ^ b;

	printf("result1: 0x%lx, result2: 0x%lx, result3: 0x%lx \n",
				result1, result2, result3);
		
}

int main() 
{
	logical_operation();	
	return 0;	
}
