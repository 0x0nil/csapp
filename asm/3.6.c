int test(int n)
{
    int i;
    int v = 0;
    for (i = 0; i < n; i++)
        v +=i;

    return v;
}

/* 1 这个函数使用gcc -S 3.6.c 得到的汇编代码没有看到有
 * xorl指令。
 * 
 * 2 使用gcc -S -O2 3.6.c 得到的汇编代码有xorl指令。
 * test:
 *         pushl   %ebp
 *         movl    %esp, %ebp
 *         movl    8(%ebp), %ecx
 *         testl   %ecx, %ecx
 *         jle     .L9
 *         xorl    %edx, %edx
 *         xorl    %eax, %eax
 *         .p2align 2,,3
 * .L5:
 *         addl    %edx, %eax
 *         incl    %edx
 *         cmpl    %edx, %ecx
 *         jne     .L5
 *         leave
 *         ret
 * .L9:
 *         xorl    %eax, %eax
 *         leave
 *         ret
 * 这里面的xorl的作用是对返回值%eax进行清零操作。
 * 
 * 3 使用gcc -c 3.6.c 然后再使用objdump 3.6.o 没看到有xorl指令
 *
 * 4 使用gcc -c 3.6.c -O2 然后在使用objdump 3.6.o 得到的汇编代码
 * 有xorl指令
 *  0:   55                      push   %ebp
 *  1:   89 e5                   mov    %esp,%ebp
 *  3:   8b 4d 08                mov    0x8(%ebp),%ecx
 *  6:   85 c9                   test   %ecx,%ecx
 *  8:   7e 0f                   jle    19 <test+0x19>
 *  a:   31 d2                   xor    %edx,%edx
 *  c:   31 c0                   xor    %eax,%eax
 *  e:   89 f6                   mov    %esi,%esi
 * 10:   01 d0                   add    %edx,%eax
 * 12:   42                      inc    %edx
 * 13:   39 d1                   cmp    %edx,%ecx
 * 15:   75 f9                   jne    10 <test+0x10>
 * 17:   c9                      leave
 * 18:   c3                      ret
 * 19:   31 c0                   xor    %eax,%eax
 * 1b:   c9                      leave
 * 1c:   c3                      ret
 * 这里面xorl出现了好几次，但他们的作用都是用来清零。如清零i的值。
 * 当n等于0的时候清零返回值。清零v的值。
 *
 * */
 
