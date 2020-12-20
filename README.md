# Issue of WioTerminal WiFi

I found the difference WioTerminal WiFi from M5Stack(ESP32).

## for WioTerminal

```
$ platformio run -e seeed_wio_terminal --target upload
```

## for M5Stack

```
$ platformio run -e m5stack --target upload
```


## start test

```
$ platformio device monitor -b 115200
```

## test

- works on M5Stack.
- works on WioTerminal.

```
$ curl -v http://[IP address]/hello
```

- works on M5Stack.
- doesn't work on WioTerminal.
  - too slow
  - don't close socket

```
$ curl -v http://[IP address]/hello-many
```

## log ( WioTerminal )

```
$ curl -v http://192.168.1.1/hello
*   Trying 192.168.1.1:80...
* Connected to 192.168.1.1 (192.168.1.1) port 80 (#0)
> GET /hello HTTP/1.1
> Host: 192.168.1.1
> User-Agent: curl/7.73.0
> Accept: */*
>
* Mark bundle as not supporting multiuse
< HTTP/1.1 200 OK
< Content-Type: text/json
< Content-Length: 12
< Connection: close
<
Hello World!* Closing connection 0
$
```

```
$ curl -v http://192.168.1.1/hello-many
*   Trying 192.168.1.1:80...
* Connected to 192.168.1.1 (192.168.1.1) port 80 (#0)
> GET /hello-many HTTP/1.1
> Host: 192.168.1.1
> User-Agent: curl/7.73.0
> Accept: */*
>
* Mark bundle as not supporting multiuse
< HTTP/1.1 200 OK
< Content-Type: text/json
< Accept-Ranges: none
< Transfer-Encoding: chunked
< Connection: close
<
Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello
World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!
Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello
World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!
Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello
World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!
Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!
```

Don't close connection...

## log ( M5Stack )

```
$ curl -v http://192.168.4.1/hello
*   Trying 192.168.4.1:80...
* Connected to 192.168.4.1 (192.168.4.1) port 80 (#0)
> GET /hello HTTP/1.1
> Host: 192.168.4.1
> User-Agent: curl/7.73.0
> Accept: */*
>
* Mark bundle as not supporting multiuse
< HTTP/1.1 200 OK
< Content-Type: text/json
< Content-Length: 12
< Connection: close
<
Hello World!* Closing connection 0
$
```

```
$ curl -v http://192.168.4.1/hello-many
*   Trying 192.168.4.1:80...
* Connected to 192.168.4.1 (192.168.4.1) port 80 (#0)
> GET /hello-many HTTP/1.1
> Host: 192.168.4.1
> User-Agent: curl/7.73.0
> Accept: */*
>
* Mark bundle as not supporting multiuse
< HTTP/1.1 200 OK
< Content-Type: text/json
< Accept-Ranges: none
< Transfer-Encoding: chunked
< Connection: close
<
Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello
World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!
Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello
World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!
Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello
World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!
Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!* Closing connecti
on 0
$
```

