all: libproc_io.so

libproc_io.so: libproc_io.c
	$(CC) $< -fPIC -shared -O -o $@
