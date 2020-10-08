# proc_io: Utils for measure process IO traffic

## Build:

```
$ make
```

## Usage:

```
proc_io [-o <log output path>] <your program> <your argument>
```

Default output path is: `/tmp/proc_io.log`

Example:

```
proc_io -o io.log gcc ~/hello.c
```

Example output:
```
/usr/lib/gcc/x86_64-linux-gnu/7/cc1
rchar: 145150
wchar: 454
syscr: 38
syscw: 1
read_bytes: 0
write_bytes: 0
cancelled_write_bytes: 0
/usr/bin/x86_64-linux-gnu-as
rchar: 10150
wchar: 1521
syscr: 20
syscw: 8
read_bytes: 0
write_bytes: 0
cancelled_write_bytes: 0
...
```

# Reference

https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/Documentation/filesystems/proc.rst
