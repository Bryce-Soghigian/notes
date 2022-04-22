# Getting Goated at Golang

The purpose of this article is to learn more about golang and the comparative programming paridgm.

Im going to start by taking some notes on the basics of golang









### Defer Statement

The defer statement defers the execution of a function until the function scope its in returns a value. The deferred calls arguments are evaluated immediately, but the function call is not executed until the surrounding function returns.



#### Stacking defers

If you call defer multiple tiems the calls are pushed onto a callsrtack. When a function executes, its deferrred calls are executed in LIFO.



#### When to use defer?

Defer should be used to make sure some responsibity is properly addressed if your code fails. Like an open database or a file.





```go
func CopyFile(dstName, srcName string) (written int64, err error) {
    src, err := os.Open(srcName)
    if err != nil {
        return
    }

    dst, err := os.Create(dstName)
    if err != nil {
        return
    }

    written, err = io.Copy(dst, src)
    dst.Close()
    src.Close()
    return
}
```



Whats the bug? What happens if err != nil? What closes the file? We need some tool to execute an action regardless if we reach some error state.





```go
func CopyFile(dstName, srcName string) (written int64, err error){
    src, err := os.Open(srcName)
    if err != nil {
        return
    }
    defer src.Close()
    dst, err := os.Create(dstName)
    if err != nil{
        return 
    }
    defer dst.Close()
    return io.Copy(dst,src)
}
```

Using the defer keyword we can make sure we end up running the Close() regardless if the code is successful or not.



### Pointers



Go has pointers :o A pointer holds the memory address of a value.

The Type *T is a pointer to a T value. A pointers zero value is nil

```go
func main(){
	x := 7
	fmt.Println(&x) // Tell the memory address for x
    y := &x
    
    fmt.Println(*y)
	
}
```



# Structs

A struct is a collection of fields. 



Structs can be accessed using the dot syntax you see in many languages

```go
package main

import "fmt"

type Vertex struct {
	X int
	Y int
}
vertex := Vertex{1,2}

fmt.Println(vertex.X, vertex.Y)
```



### Pointers to structs

Struct fields can be acessed through a struct pointer 

To acces the field X of a struct when we have the struct pointer p we could write (*p).X./ However this syntax is shitty. So the langauge permits us instead to write just p.X, without the explicit dereference. 



### Struct Literals

A struct literal denotes a newly allocated struct value by listing the values of its fields. you can list just a subset of fields by using the Name: syntax.



Keep in mind if you use a struct literal to declare a blank struct its zero value will be the default value of the struct field. 





```
type Vertex struct {
x,y int
}

The default value of x and y will be 0

```



# Arrays

The type [n]T is an array of n values with a type of T



```go

type Vertex struct {
    X,Y int
}

var adjList [100]Vertex

```



# Slices the superior datatype

Unlike the bullshit that is arrays. Slices are dynamic. 







We can also slice sarrays to form slices





```go
package main

import "fmt"

func main() {
	primes := [6]int{2, 3, 5, 7, 11, 13}

	var s []int = primes[1:4]
	fmt.Println(s)
}


```



A slice does not store any data, it just decribes a section of an underlying array. Changing the elements of a slice modifys the corresponding elements of its underlying array. Other slices that share a the same underlying array will see those changes.
