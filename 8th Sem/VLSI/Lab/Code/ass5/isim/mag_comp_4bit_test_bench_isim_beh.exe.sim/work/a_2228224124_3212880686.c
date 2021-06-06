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
static const char *ng0 = "/home/lp2917/14.7/ISE_DS/ass5/mag_comp_4bit.vhd";
extern char *WORK_P_3306708044;

void work_p_3306708044_sub_14104941192144296382_368113534(char *, char *, char *, char *, char *, char *, char *, char *, char *);


static void work_a_2228224124_3212880686_p_0(char *t0)
{
    char t4[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned char t14;

LAB0:    xsi_set_current_line(19, ng0);
    t1 = (t0 + 2992);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    memcpy(t4, t3, 4U);
    t2 = (t0 + 5536U);
    t5 = (t0 + 1192U);
    t6 = *((char **)t5);
    memcpy(t7, t6, 4U);
    t5 = (t0 + 5552U);
    t8 = (t0 + 1968U);
    t9 = *((char **)t8);
    t8 = (t9 + 0);
    t10 = (t0 + 2088U);
    t11 = *((char **)t10);
    t10 = (t11 + 0);
    t12 = (t0 + 2208U);
    t13 = *((char **)t12);
    t12 = (t13 + 0);
    work_p_3306708044_sub_14104941192144296382_368113534(WORK_P_3306708044, t1, t4, t2, t7, t5, t8, t10, t12);
    xsi_set_current_line(20, ng0);
    t1 = (t0 + 1968U);
    t2 = *((char **)t1);
    t14 = *((unsigned char *)t2);
    t1 = (t0 + 3600);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    *((unsigned char *)t8) = t14;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(21, ng0);
    t1 = (t0 + 2088U);
    t2 = *((char **)t1);
    t14 = *((unsigned char *)t2);
    t1 = (t0 + 3664);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    *((unsigned char *)t8) = t14;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(22, ng0);
    t1 = (t0 + 2208U);
    t2 = *((char **)t1);
    t14 = *((unsigned char *)t2);
    t1 = (t0 + 3728);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    *((unsigned char *)t8) = t14;
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 3504);
    *((int *)t1) = 1;

LAB1:    return;
}


extern void work_a_2228224124_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2228224124_3212880686_p_0};
	xsi_register_didat("work_a_2228224124_3212880686", "isim/mag_comp_4bit_test_bench_isim_beh.exe.sim/work/a_2228224124_3212880686.didat");
	xsi_register_executes(pe);
}
