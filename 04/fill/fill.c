#include <stdint.h>
int main()
{
  FOREVER:         // (FOREVER)
    intptr_t i = 16384; //   @16384, D=A, @i, M=D

  WHILE:               // (WHILE)
    if (i >= 24576)    //   @24576, D=A, @i, D=M-D           註：(D=i-24576)
      goto WEND;       //   @WEND, D;JGE
    int color = 0;     //   @color, M=0   // 白色
    if (*(int *)(24576) == 0) //   @24576, D=M
      goto NEXT;       //   @NEXT, D;JEQ
    color = -1;        //   @color, M=-1  // 黑色
  NEXT:                // (NEXT)
    *(int *)(i) = color;      //   @color, D=M, @i, A=M, M=D // 重要，難想
    i++;               //   @i, M=M+1
    goto WHILE;        //   @WHILE, 0;JMP
  WEND:                // (WEND)

    goto FOREVER; //   @FOREVER, 0;JMP
}