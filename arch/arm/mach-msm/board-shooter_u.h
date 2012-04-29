/* linux/arch/arm/mach-msm/board-shooter_u.h
 *
 * Copyright (C) 2010-2011 HTC Corporation.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ARCH_ARM_MACH_MSM_BOARD_SHOOTER_U_H
#define __ARCH_ARM_MACH_MSM_BOARD_SHOOTER_U_H

#include <mach/board.h>

#define SHOOTER_U_PROJECT_NAME	"shooter_u"

#define MSM_RAM_CONSOLE_BASE	MSM_HTC_RAM_CONSOLE_PHYS
#define MSM_RAM_CONSOLE_SIZE	MSM_HTC_RAM_CONSOLE_SIZE

extern int panel_type;

/* GPIO definition */

/* Direct Keys */
#define SHOOTER_U_GPIO_SW_LCM_3D       (64)
#define SHOOTER_U_GPIO_SW_LCM_2D       (68)
#define SHOOTER_U_GPIO_KEY_VOL_DOWN    (103)
#define SHOOTER_U_GPIO_KEY_VOL_UP      (104)
#define SHOOTER_U_GPIO_KEY_CAM_STEP2   (115)
#define SHOOTER_U_GPIO_KEY_CAM_STEP1   (123)
#define SHOOTER_U_GPIO_KEY_POWER       (125)

/* Battery */
#define SHOOTER_U_GPIO_MBAT_IN		   (61)
#define SHOOTER_U_GPIO_CHG_INT		   (126)

/* Wifi */
#define SHOOTER_U_GPIO_WIFI_IRQ              (46)
#define SHOOTER_U_GPIO_WIFI_SHUTDOWN_N       (96)

/* Sensors */
#define SHOOTER_U_SENSOR_I2C_SDA		(72)
#define SHOOTER_U_SENSOR_I2C_SCL		(73)
#define SHOOTER_U_GYRO_INT            (127)

/* General */
#define SHOOTER_U_GENERAL_I2C_SDA		(59)
#define SHOOTER_U_GENERAL_I2C_SCL		(60)

/* Microp */

/* TP */
#define SHOOTER_U_TP_I2C_SDA           (51)
#define SHOOTER_U_TP_I2C_SCL           (52)
#define SHOOTER_U_TP_ATT_N          (57)

/* LCD */

/* Audio */
#define SHOOTER_U_AUD_CODEC_RST        (67)
#define SHOOTER_U_AUD_CDC_LDO_SEL      (116)
/* BT */
#define SHOOTER_U_GPIO_BT_HOST_WAKE      (45)
#define SHOOTER_U_GPIO_BT_UART1_TX       (53)
#define SHOOTER_U_GPIO_BT_UART1_RX       (54)
#define SHOOTER_U_GPIO_BT_UART1_CTS      (55)
#define SHOOTER_U_GPIO_BT_UART1_RTS      (56)
#define SHOOTER_U_GPIO_BT_SHUTDOWN_N     (100)
#define SHOOTER_U_GPIO_BT_CHIP_WAKE      (130)
#define SHOOTER_U_GPIO_BT_RESET_N        (142)

/* USB */
#define SHOOTER_U_GPIO_USB_ID        (63)
#define SHOOTER_U_GPIO_MHL_RESET        (70)
#define SHOOTER_U_GPIO_MHL_INT        (71)
#define SHOOTER_U_GPIO_MHL_USB_EN         (139)
#define SHOOTER_U_GPIO_MHL_USB_SWITCH      (99)

/* Camera */

/* Flashlight */
#define SHOOTER_U_FLASH_EN             (29)
#define SHOOTER_U_TORCH_EN             (30)

/* Accessory */
#define SHOOTER_U_GPIO_AUD_HP_DET        (31)

/* SPI */
#define SHOOTER_U_SPI_DO                 (33)
#define SHOOTER_U_SPI_DI                 (34)
#define SHOOTER_U_SPI_CS                 (35)
#define SHOOTER_U_SPI_CLK                (36)

/* CAMERA SPI */
#define SHOOTER_U_SP3D_SPI_DO                 (41)
#define SHOOTER_U_SP3D_SPI_DI                 (42)
#define SHOOTER_U_SP3D_SPI_CS                 (43)
#define SHOOTER_U_SP3D_SPI_CLK                (44)

/* CAMERA GPIO */
#define SHOOTER_U_CAM_I2C_SDA           (47)
#define SHOOTER_U_CAM_I2C_SCL           (48)
#define SHOOTER_U_SP3D_GATE              (107)
#define SHOOTER_U_SP3D_CORE_GATE         (58)
#define SHOOTER_U_SP3D_SYS_RST           (102)
#define SHOOTER_U_SP3D_PDX               (137)
#define SHOOTER_U_S5K4E1_PD				(137)
#define SHOOTER_U_S5K4E1_INTB				(102)
#define SHOOTER_U_S5K4E1_VCM_PD			(58)
#define SHOOTER_U_SP3D_MCLK           (32)
#define SHOOTER_U_WEBCAM_STB          (140)
#define SHOOTER_U_WEBCAM_RST           (138)
#define SHOOTER_U_CAM_SEL           (141)
#define SHOOTER_U_SP3D_INT	(106)

/* LCM */
#define SHOOTER_U_CTL_3D_1		(131)
#define SHOOTER_U_CTL_3D_2		(132)
#define SHOOTER_U_CTL_3D_3		(133)
#define SHOOTER_U_CTL_3D_4		(134)

#define GPIO_LCM_ID	50
#define GPIO_LCM_RST_N	66

/* PMIC */

/* PMIC GPIO definition */
#define PMGPIO(x) (x-1)
#define SHOOTER_U_VOL_UP             (104)
#define SHOOTER_U_VOL_DN             (103)
#define SHOOTER_U_AUD_HP_EN          PMGPIO(18)
#define SHOOTER_U_AUD_SPK_ENO        PMGPIO(19)
#define SHOOTER_U_3DLCM_PD           PMGPIO(20)
#define SHOOTER_U_PS_VOUT            PMGPIO(22)
#define SHOOTER_U_GREEN_LED          PMGPIO(24)
#define SHOOTER_U_AMBER_LED          PMGPIO(25)
#define SHOOTER_U_3DCLK              PMGPIO(26)
#define SHOOTER_U_AUD_MIC_SEL        PMGPIO(14)
#define SHOOTER_U_CHG_STAT	     PMGPIO(33)
#define SHOOTER_U_SDC3_DET	     PMGPIO(34)
#define SHOOTER_U_PLS_INT            PMGPIO(35)
#define SHOOTER_U_WIFI_BT_SLEEP_CLK  PMGPIO(38)
#define SHOOTER_U_TP_RST             PMGPIO(23)
#define SHOOTER_U_TORCH_SET1         PMGPIO(40)
#define SHOOTER_U_TORCH_SET2         PMGPIO(31)
#define SHOOTER_U_AUD_REMO_EN        PMGPIO(15)
#define SHOOTER_U_AUD_REMO_PRES      PMGPIO(37)

int __init shooter_u_init_mmc(void);
void __init shooter_u_audio_init(void);
int __init shooter_u_init_keypad(void);
int __init shooter_u_wifi_init(void);
int __init shooter_u_init_panel(struct resource *res, size_t size);

#endif /* __ARCH_ARM_MACH_MSM_BOARD_SHOOTER_U_H */
