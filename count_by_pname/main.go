package main

import (
	"fmt"
	"os"
	"path/filepath"
)

func main() {
	matches, _ := filepath.Glob("/proc/*/stat")

	i := 0

	for _, file := range matches {
		var pid int
		var name string
		f, _ := os.Open(file)

		_, _ = fmt.Fscanf(f, "%d %s", &pid, &name)
		fmt.Println(name)

		if name == "genenv" {
			i++
		}
	}

	fmt.Println(i)
}
