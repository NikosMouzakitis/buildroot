#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

void dummy_func(void)
{
	int i;
	i++;
}

int main(int argc, char *argv[])
{
	unsigned ch1,cl1;
	unsigned ch2,cl2;
	uint64_t st, e;

	asm volatile(
		"CPUID\n\t"
	        "RDTSC\n\t"
		"mov	%%edx, %0\n\t"
		"mov %%eax, %1\n\t": "=r" (ch1), "=r" (cl1)::"%rax", "%rbx", "%rcx", "rdx");

	//function to measure
	dummy_func();

	asm volatile(
		"CPUID\n\t"
	        "RDTSC\n\t"
		"mov	%%edx, %0\n\t"
		"mov %%eax, %1\n\t": "=r" (ch2), "=r" (cl2)::"%rax", "%rbx", "%rcx", "rdx");
		
	st = (( (uint64_t) ch1<<32 )  | cl1);
	e  = (( (uint64_t) ch2<<32)   | cl2);

	printf("Counted cycles: %llu \n", (e-st));
	return(0);
}
