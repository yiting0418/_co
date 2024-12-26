#include <stdio.h>

int main() {
  int R0 = 4; 
  int R1 = 3;
  int R2 = 0; //@2, M=0

  //while (R0 > 0){
  LOOP:
    if (R0<=0) goto END; // @0, D=M, @n, D=D+M, @END, D;JGT
    R2 += R1; //@2, D=M, @1, D=D+M, @1, M=D
    R0--; //@0, M=M-1
  //}
    goto LOOP; //@LOOP, 0;JMP
  END:
    //printf("R2=%d\n", R2);
    return R2;
}