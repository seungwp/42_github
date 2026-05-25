*This project has been created as part of the 42 curriculum by sekim.*

## Description

`get_next_line` is a C function that reads a line from a file descriptor, one line at a time. Each successive call returns the next line from the file. The function returns the line including the terminating `\n` character (except at end of file if the file does not end with `\n`). It returns `NULL` when there is nothing left to read or when an error occurs.

The project introduces the concept of **static variables** in C, which persist their value across multiple function calls without being global.

## Instructions

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

The `BUFFER_SIZE` macro controls how many bytes are read per `read()` call. It can be set at compile time or will default to `42` if not provided.

### Usage

```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm

The implementation uses a **static buffer accumulation** strategy:

1. **`read_to_leftover`** — Reads `BUFFER_SIZE` bytes at a time from the file descriptor and appends them to a persistent `leftover` string (stored in a static variable). Reading stops as soon as a newline character is found or EOF is reached.

2. **`extract_line`** — Scans `leftover` up to (and including) the first `\n` and returns a copy of that segment as the line to return to the caller.

3. **`update_leftover`** — Removes the extracted line from the front of `leftover`, keeping only the bytes after the `\n` for the next call. If nothing remains, it frees the buffer and sets the static pointer to `NULL`.

**Why this approach?**
- It reads as little as possible per call (stops at the first `\n`), satisfying the requirement not to read the whole file at once.
- The `leftover` static variable bridges calls, preserving bytes read beyond the current line without re-reading them.
- Memory is always freed: `ft_strjoin` frees its first argument (`s1`) on each join, ensuring there are no accumulation leaks.
- Works correctly for any `BUFFER_SIZE` (1, 42, 9999, or 10000000).

## Resources

- `man 2 read` — POSIX read system call documentation
- `man 3 malloc` / `man 3 free` — memory management
- *The C Programming Language*, Kernighan & Ritchie — foundational C reference
- 42 Norm documentation (norminette v3)

### AI Usage

Claude Code (claude-sonnet-4-6) was used to generate the implementation files (`get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`) and this README based on the project subject PDF.
