char ctest(int a, int b, int c)
{
    char t1 = a > b;
    char t2 = b < (unsigned)a;
    char t3 = (short)c >= (short)a;
    char t4 = (char)a != (char)c;
    char t5 = c > b;
    char t6 = a > 0;

    return t1 + t2 + t3 + t4 + t5 + t6;
}

/* 很就之前我第一次看这本书的时候没搞懂set指令，现在
 * 再做一次这个题目就搞懂了。就是把测试的值放到一个地方
 * 保存以来
 * */
