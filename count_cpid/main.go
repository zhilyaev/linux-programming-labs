package main

import (
	"fmt"
	"os"
	"path/filepath"
	"strconv"
)

func main() {
	pid, _ := strconv.Atoi(os.Args[1])

	// Also count first pid
	k := 1
	Children(pid, &k)

	fmt.Println(k)
}

func Children(pid int, counter *int) {
	path := fmt.Sprintf("/proc/%d/tasks/*/stat", pid)
	children, _ := filepath.Glob(path)
	// fmt.Println("len of children=", len(children))
	// *counter += len(children) - 1
	// fmt.Println("k=", *counter)

	for _, child := range children {
		cpid, _ := Stat(child)
		if cpid == pid {
			continue
		}
		*counter++
		// fmt.Println("cpid=", cpid)
		Children(cpid, counter)
	}
}

func Stat(filename string) (pid int, name string) {
	f, _ := os.Open(filename)
	_, _ = fmt.Fscanf(f, "%d %s", &pid, &name)
	return pid, name
}
