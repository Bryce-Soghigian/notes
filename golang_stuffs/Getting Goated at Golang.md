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

