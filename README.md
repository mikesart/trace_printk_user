trace_printk_user_mod
=====================

```
$ make  
kdir is /lib/modules/4.8.0-2-amd64/build
make -C /lib/modules/4.8.0-2-amd64/build M=/home/mikesart/dev/amdgpu/trace_printk_user_mod modules
make[1]: Entering directory '/usr/src/linux-headers-4.8.0-2-amd64'
kdir is /lib/modules/4.8.0-2-amd64/build
  CC [M]  /home/mikesart/dev/amdgpu/trace_printk_user_mod/trace_user_mod.o
  Building modules, stage 2.
kdir is /lib/modules/4.8.0-2-amd64/build
  MODPOST 1 modules
  CC      /home/mikesart/dev/amdgpu/trace_printk_user_mod/trace_user_mod.mod.o
  LD [M]  /home/mikesart/dev/amdgpu/trace_printk_user_mod/trace_user_mod.ko
make[1]: Leaving directory '/usr/src/linux-headers-4.8.0-2-amd64'
```

```
$ sudo modinfo task06.ko
filename:       /home/mikesart/dev/amdgpu/trace_printk_user_mod/trace_user_mod.ko
description:    Userspace trace_printk module.
author:         Michael Sartain <mikesart@gmail.com>
version:        0.6
license:        Dual BSD/GPL
srcversion:     AAADE6B066D77622FE7C1C7
depends:
vermagic:       4.8.0-2-amd64 SMP mod_unload modversions
```

```
# insmod ./trace_user_mod.ko

# echo "foobar user string" > /dev/trace_user_mod
  
# rmmod trace_user_mod.ko
```
