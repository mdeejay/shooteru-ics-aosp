/* arch/arm/mach-msm/board-shooter_u-keypad.c
 *
 * Copyright (C) 2008 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/gpio_event.h>
#include <linux/keyreset.h>
#include <asm/mach-types.h>
#include <linux/gpio.h>
#include <mach/gpio.h>

#include "board-shooter_u.h"
/*#include "proc_comm.h"*/

#include <linux/mfd/pmic8058.h>
#include <linux/input/pmic8xxx-keypad.h>

static char *keycaps = "--qwerty";
#undef MODULE_PARAM_PREFIX
#define MODULE_PARAM_PREFIX "board_shooter_u."
module_param_named(keycaps, keycaps, charp, 0);

static void config_gpio_table(uint32_t *table, int len)
{
	int n, rc;
	for (n = 0; n < len; n++) {
		rc = gpio_tlmm_config(table[n], GPIO_CFG_ENABLE);
		if (rc) {
			pr_err("[keypad]%s: gpio_tlmm_config(%#x)=%d\n",
				__func__, table[n], rc);
			break;
		}
	}
}

static struct gpio_event_direct_entry shooter_u_keypad_input_map[] = {
	{
		.gpio = SHOOTER_U_GPIO_KEY_POWER,
		.code = KEY_POWER,
	},
	{
		.gpio = SHOOTER_U_GPIO_KEY_VOL_UP,
		.code = KEY_VOLUMEUP,
	},
	{
		.gpio = SHOOTER_U_GPIO_KEY_VOL_DOWN,
		.code = KEY_VOLUMEDOWN,
	},
	{
		.gpio = SHOOTER_U_GPIO_KEY_CAM_STEP1,
		.code = KEY_HP,
	},
	{
		.gpio = SHOOTER_U_GPIO_KEY_CAM_STEP2,
		.code = KEY_CAMERA,
	},
};

static void shooter_u_gpio_event_input_init(void)
{
	uint32_t inputs_gpio_table[] = {
		GPIO_CFG(SHOOTER_U_GPIO_KEY_POWER, 0, GPIO_CFG_INPUT,
			GPIO_CFG_PULL_UP, GPIO_CFG_2MA),
		GPIO_CFG(SHOOTER_U_GPIO_KEY_VOL_UP, 0, GPIO_CFG_INPUT,
			GPIO_CFG_PULL_UP, GPIO_CFG_2MA),
		GPIO_CFG(SHOOTER_U_GPIO_KEY_VOL_DOWN, 0, GPIO_CFG_INPUT,
			GPIO_CFG_PULL_UP, GPIO_CFG_2MA),
		GPIO_CFG(SHOOTER_U_GPIO_KEY_CAM_STEP1, 0, GPIO_CFG_INPUT,
			GPIO_CFG_PULL_UP, GPIO_CFG_2MA),
		GPIO_CFG(SHOOTER_U_GPIO_KEY_CAM_STEP2, 0, GPIO_CFG_INPUT,
			GPIO_CFG_PULL_UP, GPIO_CFG_2MA),
	};

	config_gpio_table(inputs_gpio_table, ARRAY_SIZE(inputs_gpio_table));

	enable_irq_wake(MSM_GPIO_TO_INT(SHOOTER_U_GPIO_KEY_POWER));
}

static struct gpio_event_input_info shooter_u_keypad_input_info = {
	.info.func = gpio_event_input_func,
	.flags = GPIOEDF_PRINT_KEYS,
	.type = EV_KEY,
#if BITS_PER_LONG != 64 && !defined(CONFIG_KTIME_SCALAR)
	.debounce_time.tv.nsec = 5 * NSEC_PER_MSEC,
#else
	.debounce_time.tv64 = 5 * NSEC_PER_MSEC,
#endif
	.keymap = shooter_u_keypad_input_map,
	.keymap_size = ARRAY_SIZE(shooter_u_keypad_input_map),
};

static struct gpio_event_info *shooter_u_keypad_info[] = {
	&shooter_u_keypad_input_info.info,
};

static int shooter_u_gpio_keypad_power(
    const struct gpio_event_platform_data *pdata, bool on)
{
  return 0;
}

static struct gpio_event_platform_data shooter_u_keypad_data = {
	.name = "shooteru-keypad",
	.info = shooter_u_keypad_info,
	.info_count = ARRAY_SIZE(shooter_u_keypad_info),
	.power = shooter_u_gpio_keypad_power,
};

static struct platform_device shooter_u_keypad_input_device = {
	.name = GPIO_EVENT_DEV_NAME,
	.id = 0,
	.dev		= {
		.platform_data	= &shooter_u_keypad_data,
	},
};

static struct keyreset_platform_data shooter_u_reset_keys_pdata = {
	.keys_down = {
		KEY_POWER,
		KEY_VOLUMEDOWN,
		KEY_VOLUMEUP,
		0
	},
};

struct platform_device shooter_u_reset_keys_device = {
	.name = KEYRESET_NAME,
	.dev.platform_data = &shooter_u_reset_keys_pdata,
};

void __init shooter_u_init_keypad(void)
{

	if (platform_device_register(&shooter_u_reset_keys_device))
     		printk(KERN_WARNING "%s: register reset key fail\n", __func__);

	shooter_u_gpio_event_input_init();
	platform_device_register(&shooter_u_keypad_input_device);
}
