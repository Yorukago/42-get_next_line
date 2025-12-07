# get_next_line
A minimal implementation of the classic 42 function that returns a single line from a file descriptor on each call.  
Designed to be efficient, safe, and easy to integrate into other projects.

## Overview
This version uses:
- A static buffer to minimize allocations  
- Custom helper functions for string handling  
- A simple, predictable control flow  
- Support for any `BUFFER_SIZE` > 0  

Each call to `get_next_line(fd)` returns:  
- The next line including the trailing newline (if present)  
- `NULL` when there’s nothing left to read or on error

## How It Works

### 1. Static buffer  
A persistent buffer keeps leftover data between calls, so the function only reads from the file when necessary.

### 2. Line construction  
`ft_strjoin` dynamically builds the line by joining previously collected data with new data from the buffer.

### 3. Buffer advancement  
`ft_advance` trims the buffer after a newline is found, shifting remaining characters to the front.

### 4. Stop conditions  
- Newline found  
- EOF  
- `read()` error  
- Memory allocation failure  

## Helper Functions
| Function | Purpose |
|---------|---------|
| `ft_strlen` | Basic string length |
| `ft_strlen_nl` | Length until newline (including it) |
| `ft_memcpy` | Custom memory copy, used on ft_strjoin |
| `ft_strjoin` | Concatenate and free previous buffer |
| `ft_advance` | Move buffer past the first newline |

## Example Usage
```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return 1;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## Bonus (Multiple File Descriptors)

The bonus version extends `get_next_line` so it can handle multiple file descriptors at the same time.  
This means you can read from several files (or pipes, or stdin + a file, etc.) without losing state between calls.

### How It Works

#### 1. Per-FD Buffers  
Instead of using a single static buffer, the bonus version uses something like:

```
static char buffer[MAX_FDS][BUFFER_SIZE + 1];
```
Each file descriptor gets its own buffer, so the function can keep track of leftover data separately.

#### 2. Same Logic, Independent States
Every FD follows the same read/append/advance flow as the mandatory part, but fully isolated:
Reading from fd1 doesn’t affect the stored data for fd2
Each FD remembers its own progress between calls
Switching between FDs is safe and seamless

#### 3. MAX_FDS
MAX_FDS defines how many file descriptors you want to support at once.

Typically it’s set to something like:
```
#ifndef MAX_FDS
# define MAX_FDS 1024
#endif
```
This avoids out-of-bounds access when indexing the buffer array.

That's about it :D (i hated it btw)
