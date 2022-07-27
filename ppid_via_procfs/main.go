package main

import (
	"fmt"
	"os"
)

func main() {
	p := os.Getpid()

	filename := fmt.Sprintf("/proc/%d/stat", p)

	f, err := os.Open(filename)
	if err != nil {
		ERR(err)
	}

	var unused string
	var comm string
	var state string
	var ppid int
	_, err = fmt.Fscanf(f, "%s %s %s %d", &unused, &comm, &state, &ppid)
	if err != nil {
		ERR(err)
	}

	fmt.Println(ppid)

}

func ERR(err error) {
	fmt.Println(err)
	os.Exit(1)
}
