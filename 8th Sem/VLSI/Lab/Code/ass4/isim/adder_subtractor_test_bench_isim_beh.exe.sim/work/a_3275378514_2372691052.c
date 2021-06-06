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
static const char *ng0 = "/home/lp2917/14.7/ISE_DS/ass4/adder_subtractor_test_bench.vhd";
extern char *WORK_P_0833183191;

void work_p_0833183191_sub_17772734202513611019_902013405(char *, char *, int , int , char *, char *);


static void work_a_3275378514_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    int t10;
    int t11;
    int64 t12;
    int t13;

LAB0:    t1 = (t0 + 2904U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 5510);
    *((int *)t2) = 0;
    t3 = (t0 + 5514);
    *((int *)t3) = 15;
    t4 = 0;
    t5 = 15;

LAB4:    if (t4 <= t5)
        goto LAB5;

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(44, ng0);
    t6 = (t0 + 2712);
    t7 = (t0 + 5510);
    t8 = (t0 + 1808U);
    t9 = *((char **)t8);
    t8 = (t0 + 5464U);
    work_p_0833183191_sub_17772734202513611019_902013405(WORK_P_0833183191, t6, *((int *)t7), 4, t9, t8);
    xsi_set_current_line(45, ng0);
    t2 = (t0 + 1808U);
    t3 = *((char **)t2);
    t2 = (t0 + 3288);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 4U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(46, ng0);
    t2 = (t0 + 5518);
    *((int *)t2) = 0;
    t3 = (t0 + 5522);
    *((int *)t3) = 15;
    t10 = 0;
    t11 = 15;

LAB8:    if (t10 <= t11)
        goto LAB9;

LAB11:
LAB6:    t2 = (t0 + 5510);
    t4 = *((int *)t2);
    t3 = (t0 + 5514);
    t5 = *((int *)t3);
    if (t4 == t5)
        goto LAB7;

LAB21:    t10 = (t4 + 1);
    t4 = t10;
    t6 = (t0 + 5510);
    *((int *)t6) = t4;
    goto LAB4;

LAB9:    xsi_set_current_line(47, ng0);
    t6 = (t0 + 2712);
    t7 = (t0 + 5518);
    t8 = (t0 + 1928U);
    t9 = *((char **)t8);
    t8 = (t0 + 5464U);
    work_p_0833183191_sub_17772734202513611019_902013405(WORK_P_0833183191, t6, *((int *)t7), 4, t9, t8);
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 1928U);
    t3 = *((char **)t2);
    t2 = (t0 + 3352);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 4U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(49, ng0);
    t2 = (t0 + 3416);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(50, ng0);
    t12 = (1 * 1LL);
    t2 = (t0 + 2712);
    xsi_process_wait(t2, t12);

LAB14:    *((char **)t1) = &&LAB15;

LAB1:    return;
LAB10:    t2 = (t0 + 5518);
    t10 = *((int *)t2);
    t3 = (t0 + 5522);
    t11 = *((int *)t3);
    if (t10 == t11)
        goto LAB11;

LAB20:    t13 = (t10 + 1);
    t10 = t13;
    t6 = (t0 + 5518);
    *((int *)t6) = t10;
    goto LAB8;

LAB12:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 3416);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(52, ng0);
    t12 = (1 * 1LL);
    t2 = (t0 + 2712);
    xsi_process_wait(t2, t12);

LAB18:    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB16:    goto LAB10;

LAB17:    goto LAB16;

LAB19:    goto LAB17;

}


extern void work_a_3275378514_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3275378514_2372691052_p_0};
	xsi_register_didat("work_a_3275378514_2372691052", "isim/adder_subtractor_test_bench_isim_beh.exe.sim/work/a_3275378514_2372691052.didat");
	xsi_register_executes(pe);
}
