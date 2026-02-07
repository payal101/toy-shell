# Mini Shell (C++) — Experimental Learning Project

This repository contains an early experimental attempt at building a minimal Unix-like shell in C++.
The goal of this project was **learning**, not completeness — specifically to understand how shells
parse commands, execute programs, and handle simple piping.

## ✨ What This Project Does

- Provides a simple interactive shell prompt (`myshell>`)
- Executes single system commands using `system()`
- Supports **one pipe between two commands** (e.g. `ls | grep cpp`)
- Demonstrates basic command parsing using string streams
- Handles piping by redirecting output through a temporary file

## Limitations (By Design)

This project is intentionally minimal and incomplete:

- Only supports **one pipe (two commands max)**
- Uses temporary files instead of real UNIX pipes
- No support for:
  - Background processes
  - Environment variables
  - Quoting or escaping
  - Redirection operators (`>`, `>>`)
  - Signal handling

These limitations reflect the early learning stage at which this was built.

##  What I Learned

- How shells tokenize and parse input
- How commands are executed at a system level
- The complexity hidden behind everyday shell features
- Why real shells rely on `fork()`, `exec()`, and `pipe()` instead of `system()`

##  Build & Run

```bash
g++ myshell.cpp -o myshell
./myshell
