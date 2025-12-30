#!/usr/bin/env bash
set -euo pipefail

IMAGE="gtomscs6200/spr26-environment"

docker run --rm -it \
  --cap-add=SYS_PTRACE \
  --security-opt=seccomp=unconfined \
  -v "$(pwd)":/work -w /work \
  "$IMAGE" bash
