#!/bin/bash

# Run the hsh shell with the updated test command
./hsh << 'EOF'
echo "/bin/false"
exit
EOF