package main

import (
	"bufio"
	"fmt"
	"os"
	"os/exec"
)

func main() {
	cmd := exec.Command(os.Args[1], os.Args[2:]...)
	stdout, _ := cmd.StdoutPipe()

	cmd.Start()

	buf := bufio.NewReader(stdout)
	k := 0

	for {
		symbol, size, _ := buf.ReadRune()
		if size == 0 {
			break
		}

		switch symbol {
		case '0':
			k++
		}
	}

	fmt.Println(k)
}
