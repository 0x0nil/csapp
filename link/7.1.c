/* 练习题7.1
 *
 * 符号    swap.o.symtab表目   符号类型   在哪个模块中定义  节
 * buf     有                  extern     main.o            .data
 * bufp0   有                  global     swap.o            .data
 * bufp1   有                  global     swap.o            .bss
 * swap    有                  global     swap.o            .text
 * temp    没                  ----       ----               ---
 * */

/* 这里只要熟悉.symtab里面的内容
 * 它存放在程序中被定义和引用的函数和全局变量的信息
 * */
