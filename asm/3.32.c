/* homework 3.32 */

int absdiff2(int x, int y)
{
    int result;

    if (x < y)
        result = y - x;
    else
        result = x - y;
    return result;
}

/* A 当x<y是，执行y-x这个减法，当x>=y时，执行x-y这个减法。
 * B 这段代码和前面讲过的if-else的标准实现有2个不同的地方
 *   1 在这段代码里先判断else的情况。
 *   2 在这段代码里在判断前就先计算了x - y的情况然后在比较。
 *   通过上面的两点综合起来，减少了一次标号。
 * C goto版如下
 * */

int gotodiff2(int x, int y)
{
    int result;

    result = x - y;
    if (x >= y)
        goto done;
    result = y - x;
done:
    return result;
}

/* D 为了保证这个翻译具有c代码指定的行为，要在编译的时候加上-O0的选项，
 * 限制编译器优化
 * */
