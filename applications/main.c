#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#include <board.h>
#include <rtdevice.h>
#define APP_VERSION "7.0"
#define LED0 GET_PIN(C,3)

int main(void)
{
    int count = 1;

    rt_pin_mode(LED0, PIN_MODE_OUTPUT);
    rt_kprintf("APP_VERSION is %s\n",APP_VERSION);
    rt_kprintf("THE second commit\n");
    while (count++)
    {

        //LOG_D("Hello RT-Thread!");
        rt_pin_write(LED0, !(rt_pin_read(LED0)));
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}
