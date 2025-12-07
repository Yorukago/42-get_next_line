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

## Project Structure
├── get_next_line.c
├── get_next_line.h
├── get_next_line_utils.c
+
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
