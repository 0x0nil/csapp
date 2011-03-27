int absdiff(int x, int y)
{
    if (x < y)
        return y - x;
    else
        return x - y;
}

int gotodiff(int x, int y)
{
    int rval;
    
    if (x < y)
        goto less;
    rval = x - y;
    goto done;

less:
    rval = y - x;
done:
    return rval;
}
