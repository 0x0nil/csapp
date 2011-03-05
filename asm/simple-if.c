void cond(int a, int *p)
{
    if (p && a > 0)
        *p += a;
}
