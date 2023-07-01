package dpe

import (
	"fmt"
	"regexp"
	"strings"
)

func Test() {
	fmt.Print("Test regrexp...\n")
	text := `type=1400 audit(0.0:6285): avc: denied { execute_no_trans } for comm="Thread-3" path="/system/bin/ping" dev="vda" ino=2046 scontext=u:r:system_server:s0 tcontext=u:object_r:system_file:s0 tclass=file permissive=1`

	re := regexp.MustCompile(`path="([^"]+)"`)

	ma := re.FindStringSubmatch(text)
	if len(ma) > 1 {
		fmt.Println("Match found:\n", strings.TrimSpace(ma[1]))
	} else {
		fmt.Println("No match found.")
	}

	//line := "01-07 15:30:49.691000  7963  7963 I auditd  : type=1400 audit(0.0:6285): avc: denied { execute_no_trans } for comm=\"Thread-3\" path=\"/system/bin/ping\" dev=\"vda\" ino=2046 scontext=u:r:system_server:s0 tcontext=u:object_r:system_file:s0 tclass=file permissive=1"
	//line1 := "--------- switch to system"
	//line2 := "01-07 15:30:46.483877  1748  1771 I         : on_message: send subscribe package to 192.168.1.1"
	line3 := "00-07 15:30:00.0  1007  1145 I  : NAS_car.prop.srv.veh: onPropertyEvent, property=0x160927b, area=0x0, value={.int32Values = [], .floatValues = [11.3], .int64Values = [], .bytes = [], .stringValue = }"

	regex := regexp.MustCompile(`^(?P<date>\d{2}-\d{2})\s+(?P<time>\d{2}:\d{2}:\d{2}\.\d+)\s+(?P<pid>\d+)\s+(?P<tid>\d+)\s+(?P<level>[A-Z])\s+(?P<tag>[^:]+): (?P<message>.*)`)
	match := regex.FindStringSubmatch(line3)
	if match == nil {
		return
	}

	// Extract the fields from the regex match
	date := match[regex.SubexpIndex("date")]
	time := match[regex.SubexpIndex("time")]
	pid := match[regex.SubexpIndex("pid")]
	tid := match[regex.SubexpIndex("tid")]
	level := match[regex.SubexpIndex("level")]
	tag := strings.TrimSpace(match[regex.SubexpIndex("tag")])
	message := match[regex.SubexpIndex("message")]

	// Do something with the parsed log entry
	// For example, print it to the console
	fmt.Printf("\n\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n", date, time, pid, tid, level, tag, message)
	fmt.Printf("length of tag: %d\n\n", len(tag))
}
