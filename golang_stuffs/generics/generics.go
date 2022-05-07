package main

import "fmt"

type Number interface {
	float64 | int | int8 | int16 | int32 | int64
}

func Index[T comparable](s []T, x T) int {

	for i, v := range s {
		//v and x are type T which has the comparable constraint
		if v == x {
			return i
		}
	}
	return -1
}

func CreateNumber[T Number](num T){
return num

}

func main() {
  x := CreateNumber(3.3)
  y := CreateNumber(3)
  fmt.Println(x + y )
  exit(0)
}


