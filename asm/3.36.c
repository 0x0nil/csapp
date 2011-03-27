/* homework 3.36 */

typedef struct {
    int idx;
    int x[4];
} a_struct;

#define CNT  9

typedef struct {
    int left;
    a_struct a[CNT];
    int right;
} b_struct;

void test(int i, b_struct *bp)
{
    int n = bp->left + bp->right;
    a_struct *ap = &bp->a[i];
    ap->x[ap->idx] = n;
}

/* 观察反汇编代码可得：
 * ap = 20×i+bp+4
 * 又有题目已知可知bp+4是a的地址，那么说明a的大小如果是20.
 * 由反汇编代码可查到right的地址为bp+0xb8,而a的开始地址为0x4，
 * 那么CNT = (0xb8-0x4)/20 = 9.
 * 因为idx类型为int，如果a中没有因为内存对齐而填充的字节的话，
 * a_struct的完整声明如上面所示。
 * */
