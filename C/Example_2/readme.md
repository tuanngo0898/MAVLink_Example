# MAVLink with UART

```bash
sudo apt install socat
sudo socat PTY,link=/dev/ttyS0 PTY,link=/dev/ttyS1
```

```shell
gcc -I ../mavlink/include/common -o program1 program1.c
gcc -I ../mavlink/include/common -o program2 program2.c
sudo ./program1
```

```shell
sudo ./program2
```