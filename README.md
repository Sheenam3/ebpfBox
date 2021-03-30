# ebpfBox
For better understanding of bcc, ebpf tools in a simplest way, with the simplest program. Get thread ids, latencies, syscalls, file reads and relations among members and much more we can do with ebpf.



#bpftrace

1. Build the sample-code using:
```
#for multithread program
gcc usimex.c -pthread -o usimex
#for normal program
gcc usimex.c -o usimex
```
2.  Check if the function you are looking for exists in the program. 
```
root@bpftrace:/# objdump -Tt ./usimex | grep get
00000000000008da g     F .text  0000000000000039              getNum
```

Make sure you hit this command in your program's directory otherwise you will see the following:
```
objdump: './usimex': No such file
```

3. Execute bpftrace command:

```
root@bpftrace:~# bpftrace -e 'uretprobe:/usimex:getNum {printf("TID:%d Retval:%d\n", tid,retval);}'
Attaching 1 probe...
TID:22413 Retval:6
TID:22411 Retval:5
TID:22408 Retval:2
TID:22412 Retval:1
TID:22409 Retval:8
TID:22405 Retval:1
TID:22407 Retval:0
TID:22410 Retval:0
TID:22406 Retval:2
TID:22404 Retval:0
TID:22413 Retval:0
TID:22411 Retval:7
TID:22408 Retval:4

```
We can see thread_ids and their return values.

