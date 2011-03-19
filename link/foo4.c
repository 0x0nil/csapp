/* foo4.c */
#include <stdio.h>

void f(void);

int x;

int main()
{
    x = 15213;
    f();
    printf("x = %d\n", x);
    return 0;
}

/* 符号的强弱只是针对那些全局符号来说的，
 * 和那些局部的变量没有关系，因为局部的变量
 * 编译器不会输出给汇编器
 * */
