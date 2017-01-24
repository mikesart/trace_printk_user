/*
 *	Userspace trace_printk module.
 */
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/poll.h>
#include <linux/module.h>
#include <linux/miscdevice.h>

static ssize_t trace_printk_user_write(struct file *file,
				       char const __user *buf, size_t count,
				       loff_t *ppos)
{
	char input[1024];

	if (count <= 0 || count >= sizeof(input) - 1)
		return -EINVAL;

	if (copy_from_user(input, buf, count))
		return -EINVAL;

	trace_printk("trace_printk_user: %.*s\n", (int)count, input);

	return count;
}

static const struct file_operations trace_printk_user_fops = {
	.owner = THIS_MODULE,
	.write = trace_printk_user_write
};

static struct miscdevice trace_printk_user_dev = {
	MISC_DYNAMIC_MINOR,
	"trace_printk_user",
	&trace_printk_user_fops
};

static int __init trace_printk_user_init(void)
{
	int ret;

	pr_info("%s\n", __func__);

	ret = misc_register(&trace_printk_user_dev);
	return ret;
}

static void __exit trace_printk_user_exit(void)
{
	pr_info("%s\n", __func__);

	misc_deregister(&trace_printk_user_dev);
}

module_init(trace_printk_user_init);
module_exit(trace_printk_user_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_VERSION("0.6");
MODULE_AUTHOR("Michael Sartain <mikesart@gmail.com>");
MODULE_DESCRIPTION("Userspace trace_printk module.");
