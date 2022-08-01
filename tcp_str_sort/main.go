package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
	"os"
)

func main() {
	l, err := net.Listen("tcp", "127.0.0.1:"+os.Args[1])
	if err != nil {
		log.Fatalln(err)
	}

	defer l.Close()

	for {
		conn, _ := l.Accept()
		go handleIncomingRequest(conn)
	}
}

func handleIncomingRequest(conn net.Conn) {
	defer conn.Close()
	buf := bufio.NewReader(conn)

	const OFF = "OFF\n"
	for {
		line, _, err := buf.ReadLine()
		if err != nil {
			log.Fatalln(err)
		}

		strLine := string(line)

		if strLine == OFF {
			fmt.Println("finished with OFF command")
		}

	}

}

//
//func handleIncomingRequest(conn net.Conn) {
//	buf := bufio.NewReader(conn)
//
//	off := []rune("off")
//
//	for {
//		symbol, size, _ := buf.ReadRune()
//		if size == 0 {
//			break
//		}
//
//		switch symbol {
//		case rune(0):
//
//		}
//
//		off[0] = off[1]
//		off[1] = off[2]
//		off[2] = symbol
//
//		if string(off) == "OFF" {
//
//		}
//	}
//
//	conn.Close()
//}
