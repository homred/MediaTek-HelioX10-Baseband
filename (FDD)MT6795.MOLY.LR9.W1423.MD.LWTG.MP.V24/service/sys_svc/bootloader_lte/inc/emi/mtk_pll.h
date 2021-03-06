/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   mtk_pll.h
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file is used for mempll related
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * 1. Add compile flag for sync to FlashTool and HVT
 *
 * removed!
 * removed!
 * update dram init for different frequency
 *
 * removed!
 * removed!
 * Rollback auto-k changelist 173182
 *
 * removed!
 * removed!
 * 1. add MR4 refresh rate update and derating ac timing
 * 2. add to set ap offset
 * 3. add dramc ssc
 *
 * removed!
 * removed!
 * 1. update mempll init 
 * a. multi-pll mode
 * b. mempll1
 * c. seal-ring mode
 * d. auto detection to  distinguish between MT6290 and MT6290M.
 * 2. update dram ac timing for tRPab
 *
 * removed!
 * removed!
 * add mempll calib code
 *
 * removed!
 * removed!
 * update auto calibration code for MT6290M and MT6290
 *
 * removed!
 * removed!
 * fix mempll setting
 *
 * removed!
 * removed!
 * 1. add custom folder for MT6290M
 * 2. update custom_EMI.h and custom_EMI_release.h with emigen
 * 3. update custom_EMI_INFO.h with manual check in
 * 4. update cfggen
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 ****************************************************************************/

#ifndef __MTK_PLL_H__
#define __MTK_PLL_H__

#include "reg_base.h"

#if defined(MT6290)
#define REG_MDCLKCTL_R_MDCLKCTL_CODA_VERSION    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x0))
#define REG_MDCLKCTL_CLKONCTL   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x4))
#define REG_MDCLKCTL_CLKSRCSEL0 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x8))
#define REG_MDCLKCTL_CLKSRCSEL1 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0xC))
#define REG_MDCLKCTL_CLKSPDCTL  ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x14))
#define REG_MDCLKCTL_MDCLKONCTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x18))
#define REG_MDCLKCTL_APCLKONCTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x1C))
#define REG_MDCLKCTL_CLKSWCCTL  ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x20))
#define REG_MDCLKCTL_SRCLKEN_CTL    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x24))
#define REG_MDCLKCTL_SRCLKEN_CTL2   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x28))
#define REG_MDCLKCTL_SLEEP_CNT  ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x2C))
#define REG_MDCLKCTL_RING_OSC_CTL   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x100))
#define REG_MDCLKCTL_RAND_NUM   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x104))
#define REG_MDCLKCTL_FREQ_METER_CTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x108))
#define REG_MDCLKCTL_FREQ_XTAL_CNT  ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x10C))
#define REG_MDCLKCTL_CKMON_CNT  ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x110))
#define REG_MDCLKCTL_FREQ_METER_H   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x114))
#define REG_MDCLKCTL_FREQ_METER_L   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x118))
#define REG_MDCLKCTL_CKMON_CTL  ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x11C))
#define REG_MDCLKCTL_PLLGP_MONCTL   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x300))
#define REG_MDCLKCTL_ARM7PLL_CTL    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x308))
#define REG_MDCLKCTL_CR4PLL_CTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x30C))
#define REG_MDCLKCTL_UNIVPLL_CTL    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x310))
#define REG_MDCLKCTL_ISPPLL_CTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x314))
#define REG_MDCLKCTL_EMIDDS_CTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x31C))
#define REG_MDCLKCTL_DSPPLL_CTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x320))
#define REG_MDCLKCTL_LTEWHPLL_CTL   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x324))
#define REG_MDCLKCTL_LTEWPLL_CTL    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x328))
#define REG_MDCLKCTL_OGTWPLL_CTL    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x32C))
#define REG_MDCLKCTL_LTEPLL_CTL0    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x330))
#define REG_MDCLKCTL_LTEPLL_CTL1    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x334))
#define REG_MDCLKCTL_LTEPLL_CTL2    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x338))
#define REG_MDCLKCTL_LTEPLL_CTL3    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x33C))
#define REG_MDCLKCTL_TDPLL_CTL0 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x340))
#define REG_MDCLKCTL_TDPLL_CTL1 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x344))
#define REG_MDCLKCTL_MEMPLL_CTL0    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x350))
#define REG_MDCLKCTL_MEMPLL_CTL1    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x354))
#define REG_MDCLKCTL_MEMPLL_CTL2    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x358))
#define REG_MDCLKCTL_MEMPLL2_CTL0   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x35C))
#define REG_MDCLKCTL_MEMPLL2_CTL1   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x360))
    #define MEMPLL2_CTL1_REF_DL_MASK    (0x1F << 8)
    #define MEMPLL2_CTL1_REF_DL(n)      (((n) << 8) & MEMPLL2_CTL1_REF_DL_MASK)
    #define MEMPLL2_CTL1_FB_DL_MASK     (0x1F << 0)
    #define MEMPLL2_CTL1_FB_DL(n)       (((n) << 0) & MEMPLL2_CTL1_FB_DL_MASK)
#define REG_MDCLKCTL_MEMPLL2_CTL2   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x364))
#define REG_MDCLKCTL_MEMPLL3_CTL0   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x368))
#define REG_MDCLKCTL_MEMPLL3_CTL1   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x36C))
    #define MEMPLL3_CTL1_REF_DL_MASK    (0x1F << 8)
    #define MEMPLL3_CTL1_REF_DL(n)      (((n) << 8) & MEMPLL3_CTL1_REF_DL_MASK)
    #define MEMPLL3_CTL1_FB_DL_MASK     (0x1F << 0)
    #define MEMPLL3_CTL1_FB_DL(n)       (((n) << 0) & MEMPLL3_CTL1_FB_DL_MASK)
#define REG_MDCLKCTL_MEMPLL3_CTL2   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x370))
#define REG_MDCLKCTL_MEMPLL4_CTL0   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x374))
#define REG_MDCLKCTL_MEMPLL4_CTL1   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x378))
    #define MEMPLL4_CTL1_REF_DL_MASK    (0x1F << 8)
    #define MEMPLL4_CTL1_REF_DL(n)      (((n) << 8) & MEMPLL4_CTL1_REF_DL_MASK)
    #define MEMPLL4_CTL1_FB_DL_MASK     (0x1F << 0)
    #define MEMPLL4_CTL1_FB_DL(n)       (((n) << 0) & MEMPLL4_CTL1_FB_DL_MASK)
#define REG_MDCLKCTL_MEMPLL4_CTL2   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x37C))
#define REG_MDCLKCTL_POP_MEMPLL_CTL0    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x380))
#define REG_MDCLKCTL_POP_MEMPLL_CTL1    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x384))
#define REG_MDCLKCTL_POP_MEMPLL_CTL2    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x388))
#define REG_MDCLKCTL_POP_MEMPLL3_CTL0   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x38C))
#define REG_MDCLKCTL_POP_MEMPLL3_CTL1   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x390))
    #define POP_MEMPLL3_CTL1_REF_DL_MASK    (0x1F << 8)
    #define POP_MEMPLL3_CTL1_REF_DL(n)      (((n) << 8) & POP_MEMPLL3_CTL1_REF_DL_MASK)
    #define POP_MEMPLL3_CTL1_FB_DL_MASK     (0x1F << 0)
    #define POP_MEMPLL3_CTL1_FB_DL(n)       (((n) << 0) & POP_MEMPLL3_CTL1_FB_DL_MASK)
#define REG_MDCLKCTL_POP_MEMPLL3_CTL2   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x394))
#define REG_MDCLKCTL_MEMPLL_JMETER_CTL  ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x398))
    #define MEMPLL_JMETER_CTL_CNT_MASK      (0xFFFF << 16)
    #define MEMPLL_JMETER_CTL_CNT(n)        (((n) << 16) & MEMPLL_JMETER_CTL_CNT_MASK)
    #define MEMPLL_JMETER_CTL_EN(n)         (1 << (n))
    #define MEMPLL_JMETER_CTL_DONE(n)       (1 << ((n)+4))
#define REG_MDCLKCTL_MEMPLL0_JMETER_STS ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x3A0))
#define REG_MDCLKCTL_MEMPLL1_JMETER_STS ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x3A4))
#define REG_MDCLKCTL_MEMPLL2_JMETER_STS ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x3A8))
#define REG_MDCLKCTL_MEMPLL3_JMETER_STS ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x3AC))
    #define MEMPLLn_JMETER_STS_ZEROS_CNT_VAL(n)    (((DRV_Reg32(((unsigned int)REG_MDCLKCTL_MEMPLL0_JMETER_STS)+((n)<<2))) >> 16) & 0xFFFF)
    #define MEMPLLn_JMETER_STS_ONES_CNT_VAL(n)     (((DRV_Reg32(((unsigned int)REG_MDCLKCTL_MEMPLL0_JMETER_STS)+((n)<<2))) >> 0) & 0xFFFF)
#define REG_MDCLKCTL_MEMPLL_PCW ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x3B0))
#define REG_MDCLKCTL_POP_MEMPLL_PCW ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x3B4))
#define REG_MDCLKCTL_MEMPLL_CTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x3B8))
    #define MEMPLL_CTL_MEMPLL_SW_POP_MEMPLL_ISO_EN      (0x1 << 17)
    #define MEMPLL_CTL_MEMPLL_POP_MEMPLL_HW_CTL_MODE    (0x1 << 16)
    #define MEMPLL_CTL_MEMPLL_RDY_GATING                (0x1 << 2)
    #define MEMPLL_CTL_MEMPLL_SW_MEMPLL_ISO_EN          (0x1 << 1)
    #define MEMPLL_CTL_MEMPLL_MEMPLL_HW_CTL_MODE        (0x1 << 0)
#define REG_MDCLKCTL_PLL_FORCE_ON   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x400))
#define REG_MDCLKCTL_MDTOPSM_SW_CTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x404))
#define REG_MDCLKCTL_APTOPSM_SW_CTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x408))
#define REG_MDCLKCTL_LTEL1_TOPSM_SW_CTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x40C))
#define REG_MDCLKCTL_MODEM_TOPSM_SW_CTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x410))
#define REG_MDCLKCTL_PLL_DLY_CTL0   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x420))
#define REG_MDCLKCTL_PLL_DLY_CTL1   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x424))
#define REG_MDCLKCTL_PLL_DLY_CTL2   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x428))
#define REG_MDCLKCTL_PLL_DLY_CTL3   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x42C))
#define REG_MDCLKCTL_PLL_DLY_CTL4   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x430))
#define REG_MDCLKCTL_PLL_DLY_CTL5   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x434))
#define REG_MDCLKCTL_PLL_ON_CTL0    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x438))
#define REG_MDCLKCTL_PLL_ON_CTL1    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x43C))
    #define PLL_ON_CTL1_REFto_MEMPLL_OUT_EN         (0x1 << 27)
    #define PLL_ON_CTL1_EMIDDS_INT_REF_CG_EN        (0x1 << 26)
    #define PLL_ON_CTL1_SW_MEMPLL_EN_SEL            (0x1 << 25)
    #define PLL_ON_CTL1_SW_EMIDDS_EN_SEL            (0x1 << 24)
    #define PLL_ON_CTL1_SW_EMIDDS_ISO_EN_SEL        (0x1 << 23)
    #define PLL_ON_CTL1_SW_EMIDDS_PWR_ON_SEL        (0x1 << 22)
    #define PLL_ON_CTL1_SW_EMIDDS_ON_SEL            (0x1 << 21)
    #define PLL_ON_CTL1_SW_MEMPLL_EN                (0x1 << 20)
    #define PLL_ON_CTL1_SW_EMIDDS_EN                (0x1 << 19)
    #define PLL_ON_CTL1_SW_EMIDDS_ISO_EN            (0x1 << 18)
    #define PLL_ON_CTL1_SW_EMIDDS_PWR_ON            (0x1 << 17)
    #define PLL_ON_CTL1_SW_EMIDDS_ON                (0x1 << 16)
    #define PLL_ON_CTL1_SW_ISPPLL_EN_SEL            (0x1 << 15)
    #define PLL_ON_CTL1_SW_ISPPLL_ISO_EN_SEL        (0x1 << 14)
    #define PLL_ON_CTL1_SW_ISPPLL_PWR_ON_SEL        (0x1 << 13)
    #define PLL_ON_CTL1_SW_ISPPLL_ON_SEL            (0x1 << 12)
    #define PLL_ON_CTL1_SW_ISPPLL_EN                (0x1 << 11)
    #define PLL_ON_CTL1_SW_ISPPLL_ISO_EN            (0x1 << 10)
    #define PLL_ON_CTL1_SW_ISPPLL_PWR_ON            (0x1 << 9)
    #define PLL_ON_CTL1_SW_ISPPLL_ON                (0x1 << 8)
#define REG_MDCLKCTL_PLL_ON_CTL2    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x440))
#define REG_MDCLKCTL_PLL_ON_CTL3    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x444))
#define REG_MDCLKCTL_DCXO_ON_CTL    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x448))
#define REG_MDCLKCTL_PLLFH_CTL  ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x500))
#define REG_MDCLKCTL_CR4PLL_FH_CTL1 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x524))
#define REG_MDCLKCTL_CR4PLL_FH_CTL2 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x528))
#define REG_MDCLKCTL_CR4PLL_FH_CTL3 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x52C))
#define REG_MDCLKCTL_CR4PLL_FH_CTL4 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x530))
#define REG_MDCLKCTL_CR4PLL_FH_CTL5 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x534))
#define REG_MDCLKCTL_ARM7PLL_FH_CTL1    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x544))
#define REG_MDCLKCTL_ARM7PLL_FH_CTL2    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x548))
#define REG_MDCLKCTL_ARM7PLL_FH_CTL3    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x54C))
#define REG_MDCLKCTL_ARM7PLL_FH_CTL4    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x550))
#define REG_MDCLKCTL_ARM7PLL_FH_CTL5    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x554))
#define REG_MDCLKCTL_DSPPLL_FH_CTL1 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x564))
#define REG_MDCLKCTL_DSPPLL_FH_CTL2 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x568))
#define REG_MDCLKCTL_DSPPLL_FH_CTL3 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x56C))
#define REG_MDCLKCTL_DSPPLL_FH_CTL4 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x570))
#define REG_MDCLKCTL_DSPPLL_FH_CTL5 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x574))
#define REG_MDCLKCTL_ISPPLL_FH_CTL1 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x5A4))
#define REG_MDCLKCTL_ISPPLL_FH_CTL2 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x5A8))
#define REG_MDCLKCTL_ISPPLL_FH_CTL3 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x5AC))
#define REG_MDCLKCTL_ISPPLL_FH_CTL4 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x5B0))
#define REG_MDCLKCTL_ISPPLL_FH_CTL5 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x5B4))
#define REG_MDCLKCTL_EMIDDS_FH_CTL1 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x5C0))
    #define EMIDDS_FH_CTL1_EMIDDS_FSM_EN            (1 << 20)
    #define EMIDDS_FH_CTL1_EMIDDS_BP_CHG_CTRL       (1 << 19)
    #define EMIDDS_FH_CTL1_EMIDDS_FHCTL_EN          (1 << 18)
    #define EMIDDS_FH_CTL1_EMIDDS_SFSTR_EN          (1 << 17)
    #define EMIDDS_FH_CTL1_EMIDDS_FRDDS_EN          (1 << 16)
    #define EMIDDS_FH_CTL1_EMIDDS_SFSTR_DTS_MASK    (0x7 << 12)
    #define EMIDDS_FH_CTL1_EMIDDS_SFSTR_DTS(n)      (((n) << 12) & EMIDDS_FH_CTL1_EMIDDS_SFSTR_DTS_MASK)
    #define EMIDDS_FH_CTL1_EMIDDS_SFSTR_DYS_MASK    (0x7 << 8)
    #define EMIDDS_FH_CTL1_EMIDDS_SFSTR_DYS(n)      (((n) << 8) & EMIDDS_FH_CTL1_EMIDDS_SFSTR_DYS_MASK)
    #define EMIDDS_FH_CTL1_EMIDDS_FRDDS_DTS_MASK    (0x7 << 4)
    #define EMIDDS_FH_CTL1_EMIDDS_FRDDS_DTS(n)      (((n) << 4) & EMIDDS_FH_CTL1_EMIDDS_FRDDS_DTS_MASK)
    #define EMIDDS_FH_CTL1_EMIDDS_FRDDS_DYS_MASK    (0x7 << 0)
    #define EMIDDS_FH_CTL1_EMIDDS_FRDDS_DYS(n)      (((n) << 0) & EMIDDS_FH_CTL1_EMIDDS_FRDDS_DYS_MASK)
#define REG_MDCLKCTL_EMIDDS_FH_CTL2 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x5C4))
    #define EMIDDS_FH_CTL2_FRDDS_DNLMT_MASK     (0x0FFF << 16)
    #define EMIDDS_FH_CTL2_FRDDS_DNLMT(n)       (((n) << 16) & EMIDDS_FH_CTL2_FRDDS_DNLMT_MASK)
    #define EMIDDS_FH_CTL2_FRDDS_UPLMT_MASK     (0x0FFF << 0)
    #define EMIDDS_FH_CTL2_FRDDS_UPLMT(n)       (((n) << 0) & EMIDDS_FH_CTL2_FRDDS_UPLMT_MASK)
#define REG_MDCLKCTL_EMIDDS_FH_CTL3 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x5C8))
#define REG_MDCLKCTL_EMIDDS_FH_CTL4 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x5CC))
#define REG_MDCLKCTL_EMIDDS_FH_CTL5 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x5D0))
#define REG_MDCLKCTL_STATUS_0   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x800))
#define REG_MDCLKCTL_STATUS_1   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x804))
#define REG_MDCLKCTL_STATUS_2   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x808))
#define REG_MDCLKCTL_STATUS_3   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x80C))
#define REG_MDCLKCTL_STATUS_4   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x810))
#define REG_MDCLKCTL_STATUS_5   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x814))
#define REG_MDCLKCTL_STATUS_6   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x818))
#define REG_MDCLKCTL_STATUS_7   ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x81C))
#define REG_MDCLKCTL_DUMMY  ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x1000))
#define REG_MDCLKCTL_DUMMY2 ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x1004))
#define REG_MDCLKCTL_TOP_DUMMY  ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x1008))
#define REG_MDCLKCTL_TOP_STATUS ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x100C))
#define REG_MDCLKCTL_FPGA_EMICTL    ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x4000))
#define REG_MDCLKCTL_FPGA_CLKSPDCTL ((volatile UINT32P)(BASE_ADDR_MDCLKCTL+0x4004))
#endif // end if defind(MT6290)

int mt_pll_init(void);
void mt_mempll_ssc(void);

#endif // end if __MTK_PLL_H__
