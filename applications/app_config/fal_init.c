/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-18     1       the first version
 */
#include <fal.h>
int user_fal_init(void)
{
    fal_init();
    return 0;
}

INIT_COMPONENT_EXPORT(user_fal_init);
