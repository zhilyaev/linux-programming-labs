package main

import (
	"context"
	"fmt"
	"net"
	"os"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Println("should be one argument")
		os.Exit(1)
	}

	// All address
	// ips, err := net.LookupHost(os.Args[1])
	ips, err := net.DefaultResolver.LookupIP(context.Background(), "ip4", os.Args[1])
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	for _, ip := range ips {
		fmt.Println(ip)
	}
}
