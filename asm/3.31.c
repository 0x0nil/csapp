/* 家庭作业 3.31 */

int decode2(int x, int y, int z);

int decode2(int x, int y, int z)
{
    int a = y - z;
    int b = a * x;
    b = b << 31;
    b = b >> 31;
    return a ^ b;
}
