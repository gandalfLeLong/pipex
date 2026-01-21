# pipex

This project is a simplified re-implementation of the UNIX pipe `|` operator. It explores the management of multiple processes, file descriptors, and inter-process communication (IPC).

---

### 💡 Key Features
* **Process Redirection:** Orchestrates data flow between two commands using `pipe()`, `fork()`, and `dup2()`.
* **Path Resolution:** Programmatically locates executable binaries by parsing the `PATH` environment variable.
* **Error Handling:** Robust management of file access permissions, non-existent commands, and memory cleanup.
* **Execution:** Handles command execution via `execve`, ensuring proper environment passing.

---

### 🛠️ Compilation & Usage

This project uses a **Makefile** that also manages the internal **Libft**.

| Rule | Description |
| :--- | :--- |
| `make` | Compiles the `pipex` executable. |
| `make debug` | Compiles with AddressSanitizer and debug symbols. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the `pipex` binary. |
| `make re` | Performs a clean re-compilation. |
| `make gotham` | Displays custom ASCII art in the terminal. |

**To run the program:**
The program mimics the shell command `< file1 cmd1 | cmd2 > file2`.
```bash
./pipex infile "ls -l" "wc -l" outfile
