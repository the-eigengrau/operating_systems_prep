# Operating Systems Prep

A structured 18-project roadmap designed to bridge the gap between high-level languages and low-level systems programming. 

Designed as preparation for **CS 6200: Graduate Introduction to Operating Systems (GIOS)** at Georgia Tech.

---

## 📚 Contents

**Phase 1: C Fundamentals (The "Unlearning Python" Phase)**
* [1_manual_string](#01_manual_string): Pointers, Arrays & Arithmetic
* [2_leaky_bucket](#02_leaky_bucket): Malloc, Free & Valgrind Hygiene
* [3_syscall_file_copy](#03_syscall_file_copy): `open`, `read`, `write` System Calls

**Phase 2: OS Primitives**
* [4_socket_dance](#04_tcp_echo_server): Socket Lifecycle (`bind`/`listen`/`accept`)
* [4.5_multi_socket_dance](#04_tcp_echo_server): Socket Lifecycle (`bind`/`listen`/`accept`)
* [5_race_condition](#05_race_condition): Threading Risks & Mutexes
* [6_boss_worker_queue](#06_boss_worker_queue): Producer-Consumer & Condition Variables
* [7_shared_memory](#07_shared_memory): `mmap` & Semaphores

**Phase 3: Advanced Tooling (Debugging Phase)**
* [8_segfault_hunt](#08_segfault_hunt): GDB & Stack Traces
* [9_generic_map](#09_generic_map): Void Pointers & Function Callbacks
* [10_binary_packer](#10_binary_packer): Network Serialization & Endianness

**Phase 4: Systems Deep Dive**
* [11_http_parser](#11_http_parser): State Machines & Protocol Parsing
* [12_lru_cache](#12_lru_cache): Thread-Safe Data Structures
* [13_signal_handler](#13_signal_handler): Graceful Shutdowns (`SIGINT`)
* [14_mini_shell](#14_mini_shell): `fork`, `exec`, & Process Management
* [15_shm_ring_buffer](#15_shm_ring_buffer): High-Performance IPC
* [16_simple_proxy](#16_simple_proxy): Managing Multiple Sockets

**Phase 5: Distributed Basics**
* [17_simple_rpc](#17_simple_rpc): Remote Procedure Calls & Marshalling

---

## 🛠 Environment

This repository uses a **Dev Container** configuration to ensure code behaves exactly as it would on a course grading server (x86 Linux), even if you are developing on an Apple Silicon (M1/M2/M3) Mac.

### 1. Install Tools
1.  **[OrbStack](https://orbstack.dev/)** (Recommended for macOS) or Docker Desktop.
2.  **[VS Code](https://code.visualstudio.com/)**.
3.  **Dev Containers Extension** for VS Code (ms-vscode-remote.remote-containers).

### 2. How to Start
1.  Clone this repository.
2.  Open the folder in VS Code.
3.  You should see a pop-up: *"Folder contains a Dev Container configuration file. Reopen to develop in a container."* Click **Reopen in Container**.
    * *If you miss it: Press `Cmd+Shift+P` -> "Dev Containers: Reopen in Container".*
4.  Wait for the build. Once finished, opening a terminal in VS Code (`Ctrl + ~`) will give you an **x86 Ubuntu 20.04** shell with `gcc`, `gdb`, `valgrind`, and `make` pre-installed.

---

## 📂 Structure

Each project is self-contained in its own directory with a dedicated `Makefile`.

```text
gios-prep/
├── .devcontainer/           # Docker config for the portable x86 environment
├── .gitignore               # Ignores binaries (*.o, *.out) and core dumps
├── README.md
├── 01_manual_string/        # Project 1: Pointers & Arrays
├── 02_leaky_bucket/         # Project 2: Malloc/Free & Valgrind
├── ...
└── 17_simple_rpc/           # Project 17: Distributed Systems