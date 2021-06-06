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
static const char *ng0 = "/home/lp2917/14.7/ISE_DS/ass4/half_adder.vhd";
extern char *WORK_P_0833183191;

void work_p_0833183191_sub_1454475833253765710_902013405(char *, char *, unsigned char , unsigned char , char *, char *);


static void work_a_2735068677_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    xsi_set_current_line(18, ng0);
    t1 = (t0 + 2712);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t2 = (t0 + 1192U);
    t5 = *((char **)t2);
    t6 = *((unsigned char *)t5);
    t2 = (t0 + 1808U);
    t7 = *((char **)t2);
    t2 = (t7 + 0);
    t8 = (t0 + 1928U);
    t9 = *((char **)t8);
    t8 = (t9 + 0);
    work_p_0833183191_sub_1454475833253765710_902013405(WORK_P_0833183191, t1, t4, t6, t2, t8);
    xsi_set_current_line(19, ng0);
    t1 = (t0 + 1808U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t1 = (t0 + 3320);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t4;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(20, ng0);
    t1 = (t0 + 1928U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t1 = (t0 + 3384);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t4;
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 3224);
    *((int *)t1) = 1;

LAB1:    return;
}


extern void work_a_2735068677_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2735068677_3212880686_p_0};
	xsi_register_didat("work_a_2735068677_3212880686", "isim/half_adder_test_bench_isim_beh.exe.sim/work/a_2735068677_3212880686.didat");
	xsi_register_executes(pe);
}
