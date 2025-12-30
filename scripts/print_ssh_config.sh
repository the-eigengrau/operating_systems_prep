#!/usr/bin/env bash
set -euo pipefail
IP="${1:-}"
USER="${2:-root}"
KEY="${3:-~/.ssh/id_ed25519}"

if [[ -z "$IP" ]]; then
  echo "Usage: $0 <VM_IP> [user] [keypath]"
  exit 1
fi

cat <<EOF
Host gios-vm
  HostName $IP
  User $USER
  IdentityFile $KEY
  IdentitiesOnly yes
  ServerAliveInterval 30
  StrictHostKeyChecking accept-new
EOF
