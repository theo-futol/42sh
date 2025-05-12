# 42sh - Epitech Shell Project

42sh is a custom Unix shell developed as part of the Epitech curriculum. It aims to mimic and extend the behavior of standard shells like `tcsh`, offering advanced features such as line editing, globbing, and built-in commands.

## Features

- 🔤 **Ncurses-based line editing**
- 📜 **Command history**
- 🧩 **Globbing support** (e.g., `ls *.c`)
- 🔁 **Alias management**
- 🧠 **Local variable handling**
- 🗨️ **Quote parsing** (single and double)
- 🔗 **Pipe handling** (`|`)
- ✅ **Logical AND (`&&`)**
- ❌ **Logical OR (`||`)**
- 🧬 **Command separators (`;`)**
- ⚙️ **Built-in commands**:
  - `which`
  - `where`
  - `setenv`
  - `unsetenv`
  - `cd`
- 🔁 **repeat command** (e.g., `repeat 3 echo 'hello'`)
- 🚫 **Inhibitor support** (e.g., escaping special characters)

---

## 📦 Dependencies

Before building, make sure the following dependencies are installed:

### Linux (Debian-based):
```bash
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev
```

### macOS (with Homebrew):
```bash
brew install ncurses
```

## 🔧 Build Instructions

### Clone the repository
```bash
git clone git@github.com:theo-futol/42sh.git
cd 42sh
```

### Compile the shell
```bash
make
```

### Clean object files
```bash
make clean
```

### Clean all (object files + binary)
```bash
make fclean
```

## 🚀 Running the Shell
```bash
./42sh
```
## 🛠 Makefile Rules
```bash
make - Build the 42sh binary.
make clean - Remove all .o object files.
make fclean - Clean object files and delete the final executable.
make re - Equivalent to make fclean followed by make.
```

## 📣 Credits
- Lucien Rivière
- Arthur Girardin--Calbe
- Aurélien Loyer
- Joachim Ismael
- Théo Futol