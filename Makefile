CONFIG_STACK_VALIDATION=

ccflags-y  := -I.

obj-m += hello.o
obj-m += who-connect-me.o
obj-m += add-arp-records.o
obj-m += excited_virus.o
obj-m += check-tcp-syncookies.o
obj-m += custom-netlink.o
obj-m += kprobe_tcp_conn_request.o
obj-m += run-bpf-prog.o
obj-m += percpu-ptr.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
