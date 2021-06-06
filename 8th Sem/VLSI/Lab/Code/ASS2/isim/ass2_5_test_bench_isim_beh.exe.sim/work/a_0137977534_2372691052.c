/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/lp2917/14.7/ISE_DS/ASS2/ass2_5_test_bench.vhd";



static void work_a_0137977534_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int64 t9;
    int t10;
    int t11;
    int t12;
    int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;

LAB0:    t1 = (t0 + 2344U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 4412);
    t4 = (t0 + 2728);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 16U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(30, ng0);
    t9 = (1 * 1LL);
    t2 = (t0 + 2152);
    xsi_process_wait(t2, t9);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 4428);
    *((int *)t2) = 0;
    t3 = (t0 + 4432);
    *((int *)t3) = 15;
    t10 = 0;
    t11 = 15;

LAB8:    if (t10 <= t11)
        goto LAB9;

LAB11:    goto LAB2;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB9:    xsi_set_current_line(32, ng0);
    t4 = (t0 + 4428);
    t12 = *((int *)t4);
    t13 = (t12 - 15);
    t14 = (t13 * -1);
    t15 = (1 * t14);
    t16 = (0U + t15);
    t5 = (t0 + 2728);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t17 = *((char **)t8);
    *((unsigned char *)t17) = (unsigned char)3;
    xsi_driver_first_trans_delta(t5, t16, 1, 0LL);
    xsi_set_current_line(33, ng0);
    t9 = (1 * 1LL);
    t2 = (t0 + 2152);
    xsi_process_wait(t2, t9);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB10:    t2 = (t0 + 4428);
    t10 = *((int *)t2);
    t3 = (t0 + 4432);
    t11 = *((int *)t3);
    if (t10 == t11)
        goto LAB11;

LAB16:    t12 = (t10 + 1);
    t10 = t12;
    t4 = (t0 + 4428);
    *((int *)t4) = t10;
    goto LAB8;

LAB12:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 4428);
    t12 = *((int *)t2);
    t13 = (t12 - 15);
    t14 = (t13 * -1);
    t15 = (1 * t14);
    t16 = (0U + t15);
    t3 = (t0 + 2728);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t3, t16, 1, 0LL);
    goto LAB10;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

}


extern void work_a_0137977534_2372691052_init()
{
	static char *pe[] = {(void *)work_a_0137977534_2372691052_p_0};
	xsi_register_didat("work_a_0137977534_2372691052", "isim/ass2_5_test_bench_isim_beh.exe.sim/work/a_0137977534_2372691052.didat");
	xsi_register_executes(pe);
}
