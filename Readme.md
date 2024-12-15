# Multithreading cpp HTTPS requests.

_Under development investigation..._

How works curl with threads to do requests in parallel.

## How to build example

Run bash file:

```
./buildmultithreadingExample.sh
```

## Output example

```
$ ./main
Size of urls vector: 29
URL 1: Response from https://jsonplaceholder.typicode.com/posts/41
        [Content length: 256][URL: https://jsonplaceholder.typicode.com/posts/41][HTTP Response status code: 200][TransferTotalTime: 0.98472][NumberOfSizeDownloaded: 0.256 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 2: Response from https://jsonplaceholder.typicode.com/posts/2
        [Content length: 278][URL: https://jsonplaceholder.typicode.com/posts/2][HTTP Response status code: 200][TransferTotalTime: 1.26713][NumberOfSizeDownloaded: 0.278 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 3: Response from https://jsonplaceholder.typicode.com/posts/12
        [Content length: 250][URL: https://jsonplaceholder.typicode.com/posts/12][HTTP Response status code: 200][TransferTotalTime: 1.04788][NumberOfSizeDownloaded: 0.25 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 4: Response from https://jsonplaceholder.typicode.com/posts/12
        [Content length: 250][URL: https://jsonplaceholder.typicode.com/posts/12][HTTP Response status code: 200][TransferTotalTime: 0.975533][NumberOfSizeDownloaded: 0.25 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 5: Response from https://jsonplaceholder.typicode.com/posts/22
        [Content length: 230][URL: https://jsonplaceholder.typicode.com/posts/22][HTTP Response status code: 200][TransferTotalTime: 1.22272][NumberOfSizeDownloaded: 0.23 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 6: Response from https://jsonplaceholder.typicode.com/posts/23
        [Content length: 253][URL: https://jsonplaceholder.typicode.com/posts/23][HTTP Response status code: 200][TransferTotalTime: 1.001][NumberOfSizeDownloaded: 0.253 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 7: Response from https://jsonplaceholder.typicode.com/posts/64
        [Content length: 225][URL: https://jsonplaceholder.typicode.com/posts/64][HTTP Response status code: 200][TransferTotalTime: 1.0292][NumberOfSizeDownloaded: 0.225 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 8: Response from https://jsonplaceholder.typicode.com/posts/7qweq2
        [Content length: 2][URL: https://jsonplaceholder.typicode.com/posts/7qweq2][HTTP Response status code: 404][TransferTotalTime: 1.04549][NumberOfSizeDownloaded: 0.002 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 9: Response from https://jsonplaceholder.typicode.com/posts/35
        [Content length: 283][URL: https://jsonplaceholder.typicode.com/posts/35][HTTP Response status code: 200][TransferTotalTime: 1.04848][NumberOfSizeDownloaded: 0.283 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 10: Response from https://jsonplaceholder.typicode.com/posts/5
        [Content length: 225][URL: https://jsonplaceholder.typicode.com/posts/5][HTTP Response status code: 200][TransferTotalTime: 0.843568][NumberOfSizeDownloaded: 0.225 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 11: Response from https://jsonplaceholder.typicode.com/posts/54
        [Content length: 234][URL: https://jsonplaceholder.typicode.com/posts/54][HTTP Response status code: 200][TransferTotalTime: 1.0446][NumberOfSizeDownloaded: 0.234 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 12: Response from https://jsonplaceholder.typicode.com/posts/23
        [Content length: 253][URL: https://jsonplaceholder.typicode.com/posts/23][HTTP Response status code: 200][TransferTotalTime: 0.935755][NumberOfSizeDownloaded: 0.253 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 13: Response from https://jsonplaceholder.typicode.com/posts/164
        [Content length: 2][URL: https://jsonplaceholder.typicode.com/posts/164][HTTP Response status code: 404][TransferTotalTime: 1.03924][NumberOfSizeDownloaded: 0.002 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 14: Response from https://jsonplaceholder.typicode.com/posts/72
        [Content length: 278][URL: https://jsonplaceholder.typicode.com/posts/72][HTTP Response status code: 200][TransferTotalTime: 1.01308][NumberOfSizeDownloaded: 0.278 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 15: Response from https://jsonplaceholder.typicode.com/posts/35
        [Content length: 283][URL: https://jsonplaceholder.typicode.com/posts/35][HTTP Response status code: 200][TransferTotalTime: 1.26885][NumberOfSizeDownloaded: 0.283 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 16: Response from https://jsonplaceholder.typicode.com/posts/58
        [Content length: 223][URL: https://jsonplaceholder.typicode.com/posts/58][HTTP Response status code: 200][TransferTotalTime: 1.04154][NumberOfSizeDownloaded: 0.223 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 17: Response from https://jsonplaceholder.typicode.com/posts/12
        [Content length: 250][URL: https://jsonplaceholder.typicode.com/posts/12][HTTP Response status code: 200][TransferTotalTime: 1.06369][NumberOfSizeDownloaded: 0.25 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 18: Response from https://jsonplaceholder.typicode.com/posts/2
        [Content length: 278][URL: https://jsonplaceholder.typicode.com/posts/2][HTTP Response status code: 200][TransferTotalTime: 1.04646][NumberOfSizeDownloaded: 0.278 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 19: Response from https://jsonplaceholder.typicode.com/posts/4
        [Content length: 270][URL: https://jsonplaceholder.typicode.com/posts/4][HTTP Response status code: 200][TransferTotalTime: 1.27385][NumberOfSizeDownloaded: 0.27 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 20: Response from https://jsonplaceholder.typicode.com/posts/52
        [Content length: 285][URL: https://jsonplaceholder.typicode.com/posts/52][HTTP Response status code: 200][TransferTotalTime: 1.32498][NumberOfSizeDownloaded: 0.285 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 21: Response from https://jsonplaceholder.typicode.com/posts/24
        [Content length: 243][URL: https://jsonplaceholder.typicode.com/posts/24][HTTP Response status code: 200][TransferTotalTime: 1.00204][NumberOfSizeDownloaded: 0.243 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 22: Response from https://jsonplaceholder.typicode.com/posts/24
        [Content length: 243][URL: https://jsonplaceholder.typicode.com/posts/24][HTTP Response status code: 200][TransferTotalTime: 1.03517][NumberOfSizeDownloaded: 0.243 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 23: Response from https://jsonplaceholder.typicode.com/posts/54
        [Content length: 234][URL: https://jsonplaceholder.typicode.com/posts/54][HTTP Response status code: 200][TransferTotalTime: 1.25732][NumberOfSizeDownloaded: 0.234 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 24: Response from https://jsonplaceholder.typicode.com/posts/54
        [Content length: 234][URL: https://jsonplaceholder.typicode.com/posts/54][HTTP Response status code: 200][TransferTotalTime: 0.843255][NumberOfSizeDownloaded: 0.234 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 25: Response from https://jsonplaceholder.typicode.com/posts/23
        [Content length: 253][URL: https://jsonplaceholder.typicode.com/posts/23][HTTP Response status code: 200][TransferTotalTime: 1.05304][NumberOfSizeDownloaded: 0.253 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 26: Response from https://jsonplaceholder.typicode.com/posts/64
        [Content length: 225][URL: https://jsonplaceholder.typicode.com/posts/64][HTTP Response status code: 200][TransferTotalTime: 1.0213][NumberOfSizeDownloaded: 0.225 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 27: Response from https://jsonplaceholder.typicode.com/posts/7qweq2
        [Content length: 2][URL: https://jsonplaceholder.typicode.com/posts/7qweq2][HTTP Response status code: 404][TransferTotalTime: 1.03671][NumberOfSizeDownloaded: 0.002 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 28: Response from https://jsonplaceholder.typicode.com/posts/35
        [Content length: 283][URL: https://jsonplaceholder.typicode.com/posts/35][HTTP Response status code: 200][TransferTotalTime: 1.04284][NumberOfSizeDownloaded: 0.283 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
URL 29: Response from https://jsonplaceholder.typicode.com/posts/5
        [Content length: 225][URL: https://jsonplaceholder.typicode.com/posts/5][HTTP Response status code: 200][TransferTotalTime: 0.928881][NumberOfSizeDownloaded: 0.225 (kbytes)][Schema: HTTPS][Content-Type Header: application/json; charset=utf-8]
Program execution duration time: 1336 (milliseconds)
javi@DESKTOP-2RMU1LD:/mnt/j/Repositories/cpp-multithreading-http-requests$
```