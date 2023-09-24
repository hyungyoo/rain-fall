#include <stdio.h>

void run(void) {
    // 0x0804846d <+41>:	call   0x8048350 <fwrite@plt>
	fwrite("Good... Wait what?\n", 1, 19, stdout);
	
    // 0x08048472 <+46>:	movl   $0x8048584,(%esp)
    // 0x08048479 <+53>:	call   0x8048360 <system@plt>
    system("/bin/sh");
	// 0x0804847f <+59>:	ret 
    return;
}

int main(void) {
    // 0x08048486 <+6>:	sub    $0x50,%esp
    char str[80];

    // 0x08048489 <+9>:	lea    0x10(%esp),%eax
    // 0x0804848d <+13>:	mov    %eax,(%esp)
    // 0x08048490 <+16>:	call   0x8048340 <gets@plt>
    gets(str);

    // 0x08048496 <+22>:	ret
    return 0;
}