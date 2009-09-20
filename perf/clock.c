/*
 * 2009年 02月 12日 星期四 11:14:01 CST
 * */
#include<stdio.h>
#include<unistd.h>
/* initialize the cycle counter */
static unsigned cyc_hi = 0;
static unsigned cyc_lo = 0;

/* set hi an lo to the high an low order bits of the cycle counter.
 * implementation requires assembly code to use the rdstsc instruction
 * */
void access_counter(unsigned *hi, unsigned *lo)
{
	/*asm 的扩展格式，%1表示输出值表中的第一个参数，在%eax
	 * 这样的寄存器名字必须要多加一个%符号。
	 * */
	asm("rdtsc; movl %%edx,%0; movl %%eax,%1"
			:	"=r" (*hi), "=r" (*lo)	/* 输入值 */
			:							/* 输出值 */
			:	"%edx","%eax");			/* 覆盖值 */
}
/* record the current value of the cycle counter.*/
void start_counter()
{
	access_counter(&cyc_hi, &cyc_lo);
}
/* return the number of cycles since the last call to start_counter.*/
double get_counter()
{
	unsigned ncyc_hi, ncyc_lo;
	unsigned hi, lo, borrow;
	double result;

	access_counter(&ncyc_hi, &ncyc_lo);

	lo = ncyc_lo - cyc_lo;
	borrow = lo > ncyc_lo;
	hi = ncyc_hi - cyc_hi -borrow;
	result = (double)hi * (1 << 30) *4 +lo;
	if(result < 0 )
	{
		fprintf(stderr,"error: counter returns neg vaule: %.0f\n",result);
	}
	return result;
}

double mhz(int verbose, int sleeptime)
{
	double rate;

	start_counter();
	sleep(sleeptime);
	rate = get_counter();
	if(verbose)
		printf("processor clock rate ~= %.1f MHz\n",rate);
	return rate;
}
int main()
{
	mhz(1,1);
	return 0;
}
