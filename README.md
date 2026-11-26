# get_next_line

> A C function that returns **one line at a time** from any file descriptor.

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)

## About

`get_next_line` reads from a file descriptor in chunks of `BUFFER_SIZE` bytes and keeps whatever
is left over after a newline in a **static buffer**, so the next call picks up exactly where the last
one stopped. It works with files, standard input and pipes.

```c
char *get_next_line(int fd);
```

- returns the next line **including** the `\n` (if there is one)
- returns `NULL` at end of file or on error
- the caller frees each returned line

## Bonus

The bonus version keeps a separate buffer for every file descriptor, so you can read from
**several files at once**, alternating between them, without losing your place in any of them.

## Usage

There is no Makefile; compile the files together with your program and choose any buffer size:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int   fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    return 0;
}
```

```bash
cc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
# bonus (multiple fds):
cc -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl
```

---

<sub>Part of the <a href="https://www.codam.nl/">Codam</a> (42 network) curriculum.</sub>
