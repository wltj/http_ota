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
#include <dfs_fs.h>
#define DBG_TAG "user_dfs_port"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#define FS_PARTITION_NAME "fatFS"
int dfs_mount_init(void)
{
    struct rt_device *flash_dev = fal_blk_device_create(FS_PARTITION_NAME);
    if (flash_dev == NULL)
    {
        LOG_E("Can't create a block device on '%s' partition.", FS_PARTITION_NAME);
    }
    else
    {
        LOG_D("Create a block device on the %s partition of flash successful.", FS_PARTITION_NAME);
    }

    dfs_mkfs("elm", flash_dev->parent.name);

    if (dfs_mount(flash_dev->parent.name, "/", "elm", 0, 0) == 0)
    {
        LOG_I("Filesystem initialized!");
    }
    else
    {
        LOG_E("Failed to initialize filesystem!");
        LOG_D("You should create a filesystem on the block device first!");
    }

    return 0;
}

INIT_ENV_EXPORT(dfs_mount_init);
