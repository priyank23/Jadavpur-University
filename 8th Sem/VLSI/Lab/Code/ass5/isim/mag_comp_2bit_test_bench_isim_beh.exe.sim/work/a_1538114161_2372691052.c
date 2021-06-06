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
static const char *ng0 = "/home/lp2917/14.7/ISE_DS/ass5/mag_comp_2bit_test_bench.vhd";
extern char *WORK_P_2944585553;

void work_p_2944585553_sub_18019450254920267640_3755968336(char *, char *, int , int , char *, char *);


static void work_a_1538114161_2372691052_p_0(char *t0)
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

LAB0:    t1 = (t0 + 3064U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 5611);
    *((int *)t2) = 0;
    t3 = (t0 + 5615);
    *((int *)t3) = 3;
    t4 = 0;
    t5 = 3;

LAB4:    if (t4 <= t5)
        goto LAB5;

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(49, ng0);
    t6 = (t0 + 2872);
    t7 = (t0 + 5611);
    t8 = (t0 + 1968U);
    t9 = *((char **)t8);
    t8 = (t0 + 5576U);
    work_p_2944585553_sub_18019450254920267640_3755968336(WORK_P_2944585553, t6, *((int *)t7), 2, t9, t8);
    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1968U);
    t3 = *((char **)t2);
    t2 = (t0 + 3448);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 2U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 5619);
    *((int *)t2) = 0;
    t3 = (t0 + 5623);
    *((int *)t3) = 3;
    t10 = 0;
    t11 = 3;

LAB8:    if (t10 <= t11)
        goto LAB9;

LAB11:
LAB6:    t2 = (t0 + 5611);
    t4 = *((int *)t2);
    t3 = (t0 + 5615);
    t5 = *((int *)t3);
    if (t4 == t5)
        goto LAB7;

LAB17:    t10 = (t4 + 1);
    t4 = t10;
    t6 = (t0 + 5611);
    *((int *)t6) = t4;
    goto LAB4;

LAB9:    xsi_set_current_line(52, ng0);
    t6 = (t0 + 2872);
    t7 = (t0 + 5619);
    t8 = (t0 + 2088U);
    t9 = *((char **)t8);
    t8 = (t0 + 5576U);
    work_p_2944585553_sub_18019450254920267640_3755968336(WORK_P_2944585553, t6, *((int *)t7), 2, t9, t8);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 2088U);
    t3 = *((char **)t2);
    t2 = (t0 + 3512);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 2U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(54, ng0);
    t12 = (1 * 1LL);
    t2 = (t0 + 2872);
    xsi_process_wait(t2, t12);

LAB14:    *((char **)t1) = &&LAB15;

LAB1:    return;
LAB10:    t2 = (t0 + 5619);
    t10 = *((int *)t2);
    t3 = (t0 + 5623);
    t11 = *((int *)t3);
    if (t10 == t11)
        goto LAB11;

LAB16:    t13 = (t10 + 1);
    t10 = t13;
    t6 = (t0 + 5619);
    *((int *)t6) = t10;
    goto LAB8;

LAB12:    goto LAB10;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

}


extern void work_a_1538114161_2372691052_init()
{
	static char *pe[] = {(void *)work_a_1538114161_2372691052_p_0};
	xsi_register_didat("work_a_1538114161_2372691052", "isim/mag_comp_2bit_test_bench_isim_beh.exe.sim/work/a_1538114161_2372691052.didat");
	xsi_register_executes(pe);
}
