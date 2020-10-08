#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>

static char buf[PATH_MAX];

static
void dump_proc_io()
{
  /* TODO: Check return value?  */
  readlink("/proc/self/exe", buf, sizeof(buf));

  FILE *cmdline = fopen(buf, "r");

  FILE *iostat = fopen("/proc/self/io", "r");

  const char *output = NULL;
  output = getenv("PROC_IO_OUTPUT");

  if (output == NULL)
    output = "/tmp/proc_io.log";

  /* TODO: Maybe need a lock for output file?  */
  FILE *f = fopen(output, "a");

  fprintf (f, "%s\n", buf);

  while (fgets(buf, sizeof(buf), iostat) != NULL){
    fprintf (f, "%s", buf);
  }

  fclose(cmdline);
  fclose(iostat);
  fclose(f);
}

void __attribute__((constructor))
hook_atexit() {
  atexit(dump_proc_io);
}
