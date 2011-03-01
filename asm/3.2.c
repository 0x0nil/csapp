/* 题设信息如下，将一个原型为
 * void decode1 (int *xp, int *yp, int *zp);
 * 的函数编译成汇编代码。代码如下:
 *
 * 1 movl 8(%ebp), %edi
 * 2 movl 12(%ebp), %ebx
 * 3 movl 16(%ebp), %esi
 * 4 movl (%edi), %eax
 * 5 movl (%ebx), %edx
 * 6 movl (%esi), %ecx
 * 7 movl %eax, (%ebx)
 * 8 movl %edx, (%esi)
 * 9 movl %ecx,(%edi)
 *
 * 参数xp,yp和zp存储在相对于寄存器%ebp中地址的偏移8，12和16的地方。
 * 请写出等效于上面汇编代码的decode1的c代码。可以用-S选项编译你的
 * 代码，检验你的答案。你的编译器生成的代码在寄存器的使用或是存储器
 * 的引用上的顺序上可能会有所不同，但是功能应该是等效的。
 */

void decode1 (int *xp, int *yp, int *zp)
{
    int temp = *xp;
    *xp = *zp;
    *zp = *yp;
    *yp = temp;
}
/* 这里面的关键是理解内存的访问方式和推导出中间变量。
 * (基址+偏移量)寻址 Imm(E) M[Imm + R[E]]
 * */

/* 使用gcc -S 3.2.c 编译出来的代码是
 *  pushl   %ebp
 *  movl    %esp, %ebp
 *  subl    $16, %esp
 *  movl    8(%ebp), %eax
 *  movl    (%eax), %eax
 *  movl    %eax, -4(%ebp)
 *  movl    16(%ebp), %eax
 *  movl    (%eax), %edx
 *  movl    8(%ebp), %eax
 *  movl    %edx, (%eax)
 *  movl    12(%ebp), %eax
 *  movl    (%eax), %edx
 *  movl    16(%ebp), %eax
 *  movl    %edx, (%eax)
 *  movl    12(%ebp), %edx
 *  movl    -4(%ebp), %eax
 *  movl    %eax, (%edx)
 *  
 *  和题目中的相差有点远。但是完成的功能是等效的
 *  而使用gcc -S -O2 3.2.c 编译出来的代码就和题目的比较相近
 *	movl	8(%ebp), %edx
 *	movl	12(%ebp), %ebx
 *	movl	16(%ebp), %ecx
 *	movl	(%edx), %esi
 *	movl	(%ecx), %eax
 *	movl	%eax, (%edx)
 *	movl	(%ebx), %eax
 *	movl	%eax, (%ecx)
 *	movl	%esi, (%ebx)
 *	*/
