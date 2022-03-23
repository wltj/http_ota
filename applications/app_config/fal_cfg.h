
/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-09     YPD       the first version
 */
#ifndef APPLICATIONS_APP_CONFIG_FAL_CFG_H_
#define APPLICATIONS_APP_CONFIG_FAL_CFG_H_


#include <rtthread.h>
#include "board.h"

#define FLASH_SIZE_GRANULARITY_16K   (4 * 16 * 1024)
#define FLASH_SIZE_GRANULARITY_64K   (64 * 1024)
#define FLASH_SIZE_GRANULARITY_128K  (7 * 128 * 1024)

#define STM32_FLASH_START_ADRESS_16K  STM32_FLASH_START_ADRESS
#define STM32_FLASH_START_ADRESS_64K  (STM32_FLASH_START_ADRESS_16K + FLASH_SIZE_GRANULARITY_16K)
#define STM32_FLASH_START_ADRESS_128K (STM32_FLASH_START_ADRESS_64K + FLASH_SIZE_GRANULARITY_64K)

extern const struct fal_flash_dev stm32_onchip_flash_16k;
extern const struct fal_flash_dev stm32_onchip_flash_64k;
extern const struct fal_flash_dev stm32_onchip_flash_128k;

extern struct fal_flash_dev nor_flash0;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &stm32_onchip_flash_16k,                                        \
    &stm32_onchip_flash_128k,                                        \
    &nor_flash0,                                                      \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG

/* partition table */                                                                                                    \
#define FAL_PART_TABLE                                                                                                     \
{                                                                                                                          \
    {FAL_PART_MAGIC_WROD, "bootloard", "onchip_flash_16k",  0 ,           (4*16*1024),   0}, \
    {FAL_PART_MAGIC_WROD, "app",       "onchip_flash_128k", 0 ,           (7*128*1024),  0}, \
    {FAL_PART_MAGIC_WROD, "download",  "norflash0",         0,            (1*1024*1024), 0}, \
    {FAL_PART_MAGIC_WROD, "easyflash", "norflash0",         (1*1024*1024),(2*1024*1024), 0}, \
    {FAL_PART_MAGIC_WROD, "fatFS",     "norflash0",         (3*1024*1024),(5*1024*1024), 0}, \
}


#endif /* FAL_PART_HAS_TABLE_CFG */

#endif /* APPLICATIONS_APP_CONFIG_FAL_CFG_H_ */
