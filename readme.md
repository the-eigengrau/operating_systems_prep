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
* [4b_multi_socket_dance](#04_tcp_echo_server): Socket Lifecycle (`bind`/`listen`/`accept`)
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