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
extern char *IEEE_P_2592010699;
static const char *ng1 = "/home/lp2917/14.7/ISE_DS/ASS3/ass3_annex2b.vhd";



void work_a_1623475649_3212880686_sub_9950378674781759149_3057020925(char *t0, char *t1, char *t2, char *t3, char *t4, char *t5)
{
    char t6[128];
    char t7[40];
    char t8[16];
    char t15[8];
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned char t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned char t27;
    unsigned int t28;
    char *t29;
    char *t30;
    char *t31;
    char *t33;

LAB0:    t9 = (t8 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 3;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t11 = (0 - 3);
    t12 = (t11 * -1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    t10 = (t6 + 4U);
    t13 = ((IEEE_P_2592010699) + 4000);
    t14 = (t10 + 88U);
    *((char **)t14) = t13;
    t16 = (t10 + 56U);
    *((char **)t16) = t15;
    xsi_type_set_default_value(t13, t15, t8);
    t17 = (t10 + 64U);
    *((char **)t17) = t8;
    t18 = (t10 + 80U);
    *((unsigned int *)t18) = 4U;
    t19 = (t7 + 4U);
    t20 = (t2 != 0);
    if (t20 == 1)
        goto LAB3;

LAB2:    t21 = (t7 + 12U);
    *((char **)t21) = t3;
    t22 = (t7 + 20U);
    *((char **)t22) = t4;
    t23 = (t7 + 28U);
    *((char **)t23) = t5;
    t24 = (t3 + 12U);
    t12 = *((unsigned int *)t24);
    t12 = (t12 * 1U);
    t25 = (t0 + 4684);
    t27 = 1;
    if (t12 == 2U)
        goto LAB7;

LAB8:    t27 = 0;

LAB9:    if (t27 != 0)
        goto LAB4;

LAB6:    t9 = (t3 + 12U);
    t12 = *((unsigned int *)t9);
    t12 = (t12 * 1U);
    t13 = (t0 + 4690);
    t20 = 1;
    if (t12 == 2U)
        goto LAB15;

LAB16:    t20 = 0;

LAB17:    if (t20 != 0)
        goto LAB13;

LAB14:    t9 = (t3 + 12U);
    t12 = *((unsigned int *)t9);
    t12 = (t12 * 1U);
    t13 = (t0 + 4696);
    t20 = 1;
    if (t12 == 2U)
        goto LAB23;

LAB24:    t20 = 0;

LAB25:    if (t20 != 0)
        goto LAB21;

LAB22:    t9 = (t3 + 12U);
    t12 = *((unsigned int *)t9);
    t12 = (t12 * 1U);
    t13 = (t0 + 4702);
    t20 = 1;
    if (t12 == 2U)
        goto LAB31;

LAB32:    t20 = 0;

LAB33:    if (t20 != 0)
        goto LAB29;

LAB30:    t9 = (t0 + 4708);
    t14 = (t4 + 0);
    memcpy(t14, t9, 4U);

LAB5:
LAB1:    return;
LAB3:    *((char **)t19) = t2;
    goto LAB2;

LAB4:    t31 = (t0 + 4686);
    t33 = (t4 + 0);
    memcpy(t33, t31, 4U);
    goto LAB5;

LAB7:    t28 = 0;

LAB10:    if (t28 < t12)
        goto LAB11;
    else
        goto LAB9;

LAB11:    t29 = (t2 + t28);
    t30 = (t25 + t28);
    if (*((unsigned char *)t29) != *((unsigned char *)t30))
        goto LAB8;

LAB12:    t28 = (t28 + 1);
    goto LAB10;

LAB13:    t18 = (t0 + 4692);
    t25 = (t4 + 0);
    memcpy(t25, t18, 4U);
    goto LAB5;

LAB15:    t28 = 0;

LAB18:    if (t28 < t12)
        goto LAB19;
    else
        goto LAB17;

LAB19:    t16 = (t2 + t28);
    t17 = (t13 + t28);
    if (*((unsigned char *)t16) != *((unsigned char *)t17))
        goto LAB16;

LAB20:    t28 = (t28 + 1);
    goto LAB18;

LAB21:    t18 = (t0 + 4698);
    t25 = (t4 + 0);
    memcpy(t25, t18, 4U);
    goto LAB5;

LAB23:    t28 = 0;

LAB26:    if (t28 < t12)
        goto LAB27;
    else
        goto LAB25;

LAB27:    t16 = (t2 + t28);
    t17 = (t13 + t28);
    if (*((unsigned char *)t16) != *((unsigned char *)t17))
        goto LAB24;

LAB28:    t28 = (t28 + 1);
    goto LAB26;

LAB29:    t18 = (t0 + 4704);
    t25 = (t4 + 0);
    memcpy(t25, t18, 4U);
    goto LAB5;

LAB31:    t28 = 0;

LAB34:    if (t28 < t12)
        goto LAB35;
    else
        goto LAB33;

LAB35:    t16 = (t2 + t28);
    t17 = (t13 + t28);
    if (*((unsigned char *)t16) != *((unsigned char *)t17))
        goto LAB32;

LAB36:    t28 = (t28 + 1);
    goto LAB34;

}

static void work_a_1623475649_3212880686_p_0(char *t0)
{
    char t7[8];
    char t8[16];
    char t14[8];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    char *t13;
    int t15;
    int t16;
    int t17;
    unsigned char t18;
    unsigned char t19;
    char *t20;
    int t21;
    int t22;
    int t23;
    char *t24;
    int t25;
    int t26;
    int t27;
    unsigned int t28;
    unsigned char t29;
    char *t30;
    int t31;
    int t32;
    int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    int t43;
    int t44;
    int t45;
    char *t46;
    int t47;
    int t48;
    int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    int t53;
    int t54;
    int t55;
    char *t56;
    int t57;
    int t58;
    int t59;
    unsigned int t60;
    unsigned int t61;

LAB0:    xsi_set_current_line(31, ng1);
    t1 = (t0 + 2392);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = (3 - 3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t2 = (t3 + t6);
    memcpy(t7, t2, 2U);
    t9 = (t8 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 3;
    t10 = (t9 + 4U);
    *((int *)t10) = 2;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t11 = (2 - 3);
    t12 = (t11 * -1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    t10 = (t0 + 1488U);
    t13 = *((char **)t10);
    t10 = (t0 + 4632U);
    work_a_1623475649_3212880686_sub_9950378674781759149_3057020925(t0, t1, t7, t8, t13, t10);
    xsi_set_current_line(32, ng1);
    t1 = (t0 + 2392);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = (3 - 1);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t2 = (t3 + t6);
    memcpy(t14, t2, 2U);
    t9 = (t8 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 1;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t11 = (0 - 1);
    t12 = (t11 * -1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    t10 = (t0 + 1608U);
    t13 = *((char **)t10);
    t10 = (t0 + 4648U);
    work_a_1623475649_3212880686_sub_9950378674781759149_3057020925(t0, t1, t14, t8, t13, t10);
    xsi_set_current_line(33, ng1);
    t1 = (t0 + 4712);
    *((int *)t1) = 0;
    t2 = (t0 + 4716);
    *((int *)t2) = 3;
    t11 = 0;
    t15 = 3;

LAB2:    if (t11 <= t15)
        goto LAB3;

LAB5:    t1 = (t0 + 2904);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(34, ng1);
    t3 = (t0 + 1488U);
    t9 = *((char **)t3);
    t3 = (t0 + 4712);
    t16 = *((int *)t3);
    t17 = (t16 - 3);
    t4 = (t17 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, *((int *)t3));
    t5 = (1U * t4);
    t6 = (0 + t5);
    t10 = (t9 + t6);
    t18 = *((unsigned char *)t10);
    t19 = (t18 == (unsigned char)3);
    if (t19 != 0)
        goto LAB6;

LAB8:    xsi_set_current_line(37, ng1);
    t1 = (t0 + 4720);
    t3 = (t0 + 4712);
    t16 = *((int *)t3);
    t17 = (4 * t16);
    t21 = (t17 + 3);
    t9 = (t0 + 4712);
    t22 = *((int *)t9);
    t23 = (4 * t22);
    t25 = (t23 - t21);
    t4 = (t25 * -1);
    t4 = (t4 + 1);
    t5 = (1U * t4);
    t18 = (t5 != 4U);
    if (t18 == 1)
        goto LAB11;

LAB12:    t10 = (t0 + 4712);
    t26 = *((int *)t10);
    t27 = (4 * t26);
    t31 = (t27 + 3);
    t6 = (15 - t31);
    t12 = (1U * t6);
    t28 = (0U + t12);
    t13 = (t0 + 3016);
    t20 = (t13 + 56U);
    t24 = *((char **)t20);
    t30 = (t24 + 56U);
    t37 = *((char **)t30);
    t38 = (t0 + 4712);
    t32 = *((int *)t38);
    t33 = (4 * t32);
    t43 = (t33 + 3);
    t39 = (t0 + 4712);
    t44 = *((int *)t39);
    t45 = (4 * t44);
    t47 = (t45 - t43);
    t34 = (t47 * -1);
    t34 = (t34 + 1);
    t35 = (1U * t34);
    memcpy(t37, t1, t35);
    t40 = (t0 + 4712);
    t48 = *((int *)t40);
    t49 = (4 * t48);
    t53 = (t49 + 3);
    t41 = (t0 + 4712);
    t54 = *((int *)t41);
    t55 = (4 * t54);
    t57 = (t55 - t53);
    t36 = (t57 * -1);
    t36 = (t36 + 1);
    t50 = (1U * t36);
    xsi_driver_first_trans_delta(t13, t28, t50, 0LL);

LAB7:
LAB4:    t1 = (t0 + 4712);
    t11 = *((int *)t1);
    t2 = (t0 + 4716);
    t15 = *((int *)t2);
    if (t11 == t15)
        goto LAB5;

LAB13:    t16 = (t11 + 1);
    t11 = t16;
    t3 = (t0 + 4712);
    *((int *)t3) = t11;
    goto LAB2;

LAB6:    xsi_set_current_line(35, ng1);
    t13 = (t0 + 1608U);
    t20 = *((char **)t13);
    t13 = (t0 + 4712);
    t21 = *((int *)t13);
    t22 = (4 * t21);
    t23 = (t22 + 3);
    t24 = (t0 + 4712);
    t25 = *((int *)t24);
    t26 = (4 * t25);
    t27 = (t26 - t23);
    t12 = (t27 * -1);
    t12 = (t12 + 1);
    t28 = (1U * t12);
    t29 = (t28 != 4U);
    if (t29 == 1)
        goto LAB9;

LAB10:    t30 = (t0 + 4712);
    t31 = *((int *)t30);
    t32 = (4 * t31);
    t33 = (t32 + 3);
    t34 = (15 - t33);
    t35 = (1U * t34);
    t36 = (0U + t35);
    t37 = (t0 + 3016);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    t42 = (t0 + 4712);
    t43 = *((int *)t42);
    t44 = (4 * t43);
    t45 = (t44 + 3);
    t46 = (t0 + 4712);
    t47 = *((int *)t46);
    t48 = (4 * t47);
    t49 = (t48 - t45);
    t50 = (t49 * -1);
    t50 = (t50 + 1);
    t51 = (1U * t50);
    memcpy(t41, t20, t51);
    t52 = (t0 + 4712);
    t53 = *((int *)t52);
    t54 = (4 * t53);
    t55 = (t54 + 3);
    t56 = (t0 + 4712);
    t57 = *((int *)t56);
    t58 = (4 * t57);
    t59 = (t58 - t55);
    t60 = (t59 * -1);
    t60 = (t60 + 1);
    t61 = (1U * t60);
    xsi_driver_first_trans_delta(t37, t36, t61, 0LL);
    goto LAB7;

LAB9:    xsi_size_not_matching(t28, 4U, 0);
    goto LAB10;

LAB11:    xsi_size_not_matching(t5, 4U, 0);
    goto LAB12;

}


extern void work_a_1623475649_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1623475649_3212880686_p_0};
	static char *se[] = {(void *)work_a_1623475649_3212880686_sub_9950378674781759149_3057020925};
	xsi_register_didat("work_a_1623475649_3212880686", "isim/ass3_annex2b_test_bench_isim_beh.exe.sim/work/a_1623475649_3212880686.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
