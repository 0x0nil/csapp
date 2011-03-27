/* homework */

typedef enum {
    MODE_A,
    MODE_B,
    MODE_C,
    MODE_D,
    MODE_E
} mode_t;

int switch3(int *p1, int *p2, mode_t action)
{
    int result = 0;
    switch(action) {
    case MODE_A:
        result = *p2;
        *p2 = *p1;
        break;
    case MODE_B:
        *p1 = *p2 + *p1;
        result = *p1;
        break;
    case MODE_C:
            *p1 = 15;
            result = *p2;
    case MODE_D:
            *p1 = *p2;
    case MODE_E:
            result = 17;
            break;
    default:
            result = -1;
    }
    return result;
}

/* A 观察题目中给出的汇编代码可得程序变量result对应的寄存器是%edx
 * B 填写C代码中缺失的部分，填写后的代码如上
 * */
