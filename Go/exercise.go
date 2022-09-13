/**
go get -u github.com/rs/zerolog/log
go mod tidy
go fmt ./...
go run . or go build .
**/

package main

import (
	"github.com/rs/zerolog"
	"github.com/rs/zerolog/log"
)

func main() {
	zerolog.TimeFieldFormat = zerolog.TimeFormatUnix

	log.Print("Start...")
}
