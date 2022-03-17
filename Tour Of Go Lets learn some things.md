# Tour Of Go Lets learn some things.



### List of important things I will probably forget

1. Exported Names. If you want to export a function or interface or whatever from a package, you make it available via Pascal Cased Name

   EX : func main() vs func Main() the second one could be imported outside its package but the lowercase one cannot

```go
package main

import "fmt"

func main() {
	fmt.Println("Hello, Whats poppin")
}

```

The classic hello world vibes. This is pretty common stuff.



## Packages

Every go program is made up of packages.

Programs start running in package main. 

This program is using the packages with import paths "fmt" and "math/rand"



The Convention is the package name is the same as the last element of the import path. For instance the "math/rand" package comprises a group of files that begin with the statement `package rand`

```go
package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println("My favorite number is", rand.Intn(10))
}

```

## Exported Names

In go, a name is exported if it begins with a capital letter. For example, Pizza is an exported name, as is Pi which is exported from the math package. 



When you import a package you can only refer to its exported namesj. This ensures that all capitial lettered names are public and lowercase are private.

```go
package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(math.Pi) // Note that this wouldnt work with math.pi because the pi function in math.pi isnt capitalized.We are importing packages here and every exported name in that package. 
}

```

## Named Return Values

Go's return values may be named. If so, they are treated as variables defined at the top of the  function. an empty return is dangerous in golang



## Primitive Types in GO

```go
bool
string
int int8 int16 int32 int64
uint uint8 uint16 uint32 uint64 uintptr
byte // alias for uint8
rune //  alias for int32
float32 float64
complex64 complex128
```

use general types if you can



#### Note

An int is signed by default meaning it can represent both positive and negative values. An unsigned is an integer that can never be negative. Use this for problems like first missing positve and shit.



## Default state

Empty declarations of a primitive type will result in a certain default state

numeric values : 0

bool : false

string : ""

```go
package main

import "fmt"

func main() {
	var i int // 0
	var f float64 // 0
	var b bool // false
	var s string // ""
	fmt.Printf("%v %v %v %q\n", i, f, b, s)
}

```





```yaml
version: '2.2'
services:
  elasticsearch:
    image: docker.elastic.co/elasticsearch/elasticsearch:6.2.4
    container_name: elasticsearch
    environment:
      - cluster.name=docker-cluster
      - bootstrap.memory_lock=true
      - "ES_JAVA_OPTS=-Xms512m -Xmx512m"
    ulimits:
      memlock:
        soft: -1
        hard: -1
    volumes:
      - esdata1:/usr/share/elasticsearch/data
    ports:
      - 9200:9200
    networks:
      - esnet
  elasticsearch2:
    image: docker.elastic.co/elasticsearch/elasticsearch:6.2.4
    container_name: elasticsearch2
    environment:
      - cluster.name=docker-cluster
      - bootstrap.memory_lock=true
      - "ES_JAVA_OPTS=-Xms512m -Xmx512m"
      - "discovery.zen.ping.unicast.hosts=elasticsearch"
    ulimits:
      memlock:
        soft: -1
        hard: -1
    volumes:
      - esdata2:/usr/share/elasticsearch/data
    networks:
      - esnet

volumes:
  esdata1:
    driver: local
  esdata2:
    driver: local

networks:
  grok-enetwork:
  
  
  
  
  
```

