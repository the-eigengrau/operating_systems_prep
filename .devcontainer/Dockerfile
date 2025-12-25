# 1. Force x86 emulation (Crucial for GIOS on M-series chips)
FROM --platform=linux/amd64 ubuntu:20.04

# 2. Prevent interactive prompts during install
ENV DEBIAN_FRONTEND=noninteractive

# 3. Install the "GIOS Toolchain"
# These are the exact tools you need for the course
RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    valgrind \
    git \
    man-db \
    vim \
    net-tools \
    curl \
    python3 \
    && rm -rf /var/lib/apt/lists/*

# 4. Set the default shell to bash
ENV SHELL /bin/bash
