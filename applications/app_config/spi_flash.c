/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-18     1       the first version
 */
#include <rtthread.h>
#include <board.h>
#include <rtdevice.h>
#include "drv_spi.h"
#include "spi_flash_sfud.h"

//挂载W25Q64到SPI1总线上
static int rt_hw_spi_flash_init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
    rt_hw_spi_device_attach("spi1", "spi10", GPIOB, GPIO_PIN_6);// spi10 表示挂载在 spi1 总线上的 0 号设备,PB6是片选，这一步就可以将从设备挂在到总线中。

    if (RT_NULL == rt_sfud_flash_probe("norflash0", "spi10"))  //注册块设备，这一步可以将外部flash抽象为系统的块设备
    {
        return -RT_ERROR;
    };

    return RT_EOK;
}
/* 导出到自动初始化 */
//INIT_COMPONENT_EXPORT(rt_hw_spi_flash_init);
INIT_DEVICE_EXPORT(rt_hw_spi_flash_init);//建议用这个宏，上面那个在移植文件系统时出问题了
