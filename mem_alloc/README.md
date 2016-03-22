# mem_alloc

Allocate and fill memory at `rate` (MB/s) for `last` seconds, call new `calls_per_sec` times per second.

### Usage
```
Usage: ./mem_alloc rate (MB/s) [last=10] [calls_per_sec=1000]
```

### Example
```
time ./mem_alloc 100 8 200
```
#### output
```
allocate mem at 100MB/s for 8 s
524288 bytes/call  @ 200 calls/s
1 s total allocated = 100 MB
2 s total allocated = 200 MB
3 s total allocated = 300 MB
4 s total allocated = 400 MB
5 s total allocated = 500 MB
6 s total allocated = 600 MB
7 s total allocated = 700 MB
8 s total allocated = 800 MB

real	0m9.656s
user	0m0.324s
sys	0m0.679s
```
