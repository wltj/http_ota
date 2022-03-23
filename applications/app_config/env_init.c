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

#include <rtdevice.h>
#include <board.h>
#include <easyflash.h>

int user_easy_flash(void)
{
    easyflash_init();
    return 0;
}


INIT_APP_EXPORT(user_easy_flash);
