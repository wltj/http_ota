/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-18     1       the first version
 */
#include <board.h>
#include <rtdevice.h>

#define RESET_IO GET_PIN(D,10)

void phy_reset(void)
{
    rt_pin_write(RESET_IO, PIN_LOW);
    rt_thread_mdelay(50);
    rt_pin_write(RESET_IO, PIN_HIGH);
}
void phy_init(void){
    rt_pin_mode(RESET_IO, PIN_MODE_OUTPUT);
    rt_pin_write(RESET_IO, PIN_HIGH);
    return RT_EOK;
}
INIT_APP_EXPORT(phy_init);
