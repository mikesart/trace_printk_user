obj-m += trace_user_mod.o

KDIR ?= /lib/modules/$(shell uname -r)/build
$(info kdir is $(KDIR))

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
