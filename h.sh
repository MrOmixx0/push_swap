while true; do
  ARG=$(bash << 'EOF'
  declare -A seen
  count=0
  while [ $count -lt 5 ]; do
    num=$(( (RANDOM << 16) | RANDOM ))
    sign=$(( RANDOM % 2 ))
    if [ $sign -eq 0 ]; then
      num=$(( -1 * num ))
    fi
    if [ $num -lt -2147483648 ] || [ $num -gt 2147483647 ]; then
      continue
    fi
    if [ -z "${seen[$num]}" ]; then
      seen[$num]=1
      printf "%d " "$num"
      ((count++))
    fi
  done
  echo
EOF
)
  ./push_swap $ARG | ./checker_linux $ARG
  ./push_swap $ARG | wc -l
  sleep 1
done
