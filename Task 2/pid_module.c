#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>


#define BUFFER_SIZE 128
#define PROC_NAME "pid"


static int current_pid = 0;


static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);
static ssize_t proc_write(struct file *file, const char __user *usr_buf, size_t count, loff_t *pos);


static struct proc_ops proc_fops = {
    .proc_read = proc_read,
    .proc_write = proc_write,
};


static int proc_init(void) {
    proc_create(PROC_NAME, 0666, NULL, &proc_fops);
    printk(KERN_INFO "/proc/%s created\n", PROC_NAME);
    return 0;
}


static void proc_exit(void) {
    remove_proc_entry(PROC_NAME, NULL);
    printk(KERN_INFO "/proc/%s removed\n", PROC_NAME);
}


static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos) {
    int rv = 0;
    char buffer[BUFFER_SIZE];
    static int completed = 0;
    struct task_struct *tsk = NULL;

   if (completed) {
        completed = 0;
        return 0;
    }


    tsk = pid_task(find_vpid(current_pid), PIDTYPE_PID);
    if (tsk) {
        // Version specific "current state" variable syntax, modify "__state" in "tsk->__state" as per your VM linux kernel version header before making the file.
        rv = snprintf(buffer, BUFFER_SIZE, "command = [%s]\npid = [%d]\nstate = [%ld]\n", tsk->comm, current_pid, tsk->__state);
    } else {
        printk(KERN_INFO "Invalid PID %d\n", current_pid);
        return 0;
    }


    completed = 1;


    if (rv > count) {
        rv = count;
    }


    if (copy_to_user(usr_buf, buffer, rv)) {
        rv = -EFAULT;
    }


    return rv;
}

static ssize_t proc_write(struct file *file, const char __user *usr_buf, size_t count, loff_t *pos) {
    char *k_mem;


    k_mem = kmalloc(count + 1, GFP_KERNEL);
    if (!k_mem) {
        return -ENOMEM;
    }


    if (copy_from_user(k_mem, usr_buf, count)) {
        kfree(k_mem);
        return -EFAULT;
    }


    k_mem[count] = '\0';


    if (kstrtoint(k_mem, 10, &current_pid)) {
        printk(KERN_INFO "Error converting pid\n");
        kfree(k_mem);
        return -EFAULT;
    }


    printk(KERN_INFO "PID set to %d\n", current_pid);
    kfree(k_mem);


    return count;
}


module_init(proc_init);
module_exit(proc_exit);


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module for displaying task information based on PID.");
MODULE_AUTHOR("SGG");
