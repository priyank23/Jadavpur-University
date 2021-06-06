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
static const char *ng0 = "/home/lp2917/14.7/ISE_DS/ass4/bcd_adder.vhd";
extern char *WORK_P_0833183191;

void work_p_0833183191_sub_6416717178906620129_902013405(char *, char *, char *, char *, char *, char *, char *, char *);


static void work_a_2649315539_3212880686_p_0(char *t0)
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

LAB0:    xsi_set_current_line(18, ng0);
    t1 = (t0 + 2432);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    memcpy(t4, t3, 4U);
    t2 = (t0 + 4600U);
    t5 = (t0 + 1192U);
    t6 = *((char **)t5);
    memcpy(t7, t6, 4U);
    t5 = (t0 + 4616U);
    t8 = (t0 + 1648U);
    t9 = *((char **)t8);
    t8 = (t0 + 4648U);
    work_p_0833183191_sub_6416717178906620129_902013405(WORK_P_0833183191, t1, t4, t2, t7, t5, t9, t8);
    xsi_set_current_line(19, ng0);
    t1 = (t0 + 1648U);
    t2 = *((char **)t1);
    t1 = (t0 + 3040);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    memcpy(t8, t2, 5U);
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 2944);
    *((int *)t1) = 1;

LAB1:    return;
}


extern void work_a_2649315539_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2649315539_3212880686_p_0};
	xsi_register_didat("work_a_2649315539_3212880686", "isim/bcd_adder_test_bench_isim_beh.exe.sim/work/a_2649315539_3212880686.didat");
	xsi_register_executes(pe);
}
