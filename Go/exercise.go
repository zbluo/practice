/**
go get -u github.com/rs/zerolog/log
go mod tidy
go fmt ./...
go run . or go build .
**/

package main

import (
	"fmt"
	//"practice/exercise/dpe"
	"practice/exercise/mycrypto"
)

func main() {
	mycrypto.AesTest()
	fmt.Print("The end....\n")
}
