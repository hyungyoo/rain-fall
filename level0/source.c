#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


// 0x08048ec9 <+9>:	mov    eax,DWORD PTR [ebp+0xc]
// 0x08048ecc <+12>:	add    eax,0x4
// 0x08048ecf <+15>:	mov    eax,DWORD PTR [eax]
// 0x08048ed1 <+17>:	mov    DWORD PTR [esp],eax

int main(int argc, char **argv) {
    int number_from_atoi;
	char **cmd;
    uid_t uid;
    gid_t gid;

    // 0x08048ed4 <+20>:	call   0x8049710 <atoi>
    number_from_atoi = atoi(argv[1]);
	
    //0x08048ed9 <+25>:	cmp    eax,0x1a7
    if (number_from_atoi == 423) {

        // (gdb) x/s 0x80c5348
        // 0x08048ee7 <+39>:	call   0x8050bf0 <strdup>
        cmd[0] = strdup("/bin/sh");
		cmd[1] = 0;

		// 0x08048ef8 <+56>:	call   0x8054680 <getegid>
		gid = getegid();
        //  0x08048f01 <+65>:	call   0x8054670 <geteuid>
        uid = geteuid();
        //	0x08048f21 <+97>:	call   0x8054700 <setresgid>
        setresgid(gid, gid, gid);
        // 0x08048f3d <+125>:	call   0x8054690 <setresuid>
        setresuid(uid, uid, uid);
		
        // 0x08048f4a <+138>:	mov    DWORD PTR [esp],0x80c5348
        // 0x08048f51 <+145>:	call   0x8054640 <execv>
        execv("/bin/sh", cmd);
    }
	else {
		fwrite("No !\n", 1, 5, stderr);
    }
    return 0;
}