/**
 * Copyright 2025 Leon Hwang.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/percpu-defs.h>  // included for percpu macros and functions

DEFINE_PER_CPU(int, my_percpu_var) = 0;

int target_cpu;
module_param(target_cpu, int, 0);
MODULE_PARM_DESC(target_cpu, "Target CPU for percpu variable");

int percpu_read(int cpu);
int thiscpu_read(void);
int percpu_currcpu_read(int cpu);

int percpu_read(int cpu)
{
    return *(int *)(void *)per_cpu_ptr(&my_percpu_var, cpu);
}
EXPORT_SYMBOL(percpu_read);

int thiscpu_read(void)
{
    return *(int *)(void *)this_cpu_ptr(&my_percpu_var);
}
EXPORT_SYMBOL(thiscpu_read);

int percpu_currcpu_read(int cpu)
{
    if (cpu == raw_smp_processor_id())
        return *(int *)(void *)this_cpu_ptr(&my_percpu_var);
    else
        return *(int *)(void *)per_cpu_ptr(&my_percpu_var, cpu);
}
EXPORT_SYMBOL(percpu_currcpu_read);

static int __init percpu_ptr_init(void)
{
    int myvar;

    myvar = percpu_read(target_cpu);
    printk(KERN_INFO "percpu_ptr: percpu_read %d\n", myvar);
    myvar = thiscpu_read();
    printk(KERN_INFO "percpu_ptr: thiscpu_read %d\n", myvar);
    myvar = percpu_currcpu_read(target_cpu);
    printk(KERN_INFO "percpu_ptr: percpu_currcpu_read %d\n", myvar);
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit percpu_ptr_cleanup(void)
{
    printk(KERN_INFO "Goodbye, percpu_ptr.\n");
}

module_init(percpu_ptr_init);
module_exit(percpu_ptr_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Leon Hwang");
MODULE_DESCRIPTION("A simple example for percpu and thiscpu ptr");
