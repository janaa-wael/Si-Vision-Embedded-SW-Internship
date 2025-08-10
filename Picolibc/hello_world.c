#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
  int x = 5 , y = 10;
	printf("Hello World, from Picolibc!\nEnter a number: ");
  if(fmax(x,y) == y) printf("y is greater than x.\n");
  else printf("x is greater than y.\n");
	exit(0);
}

/**
  qemu-system-riscv32 \
  -machine virt -cpu rv32 -nographic \
  -semihosting-config enable=on \O

  -monitor none -serial mon:stdio \
  -bios none \
  -kernel hello-world-riscv.elf

 */