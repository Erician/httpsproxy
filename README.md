# httpsproxy
this is a proxy for http and https with the tunnel technology

Note: I did not follow the RFC(https://tools.ietf.org/html/rfc7231#section-4.3.6) about sending CONNECT method to proxy server before transport real data,
Which make the client easy to use the program but is not safe.

Note: This program is just for learning, and maybe it is not safe. So I suggest you do not use this program when refered to your important infomation like credit card, account, shopping info, etc. 

# todo list
(1)log files rotate

# how to run this proxy
(1)cd into src
```shell
$ cd httpsproxy/src
```
(2)compile
```shell
$ make clean
$ make 
```
(3)run hpptsproxy-server on a server 
```shell
$ make start-server    #use "make stop-server" to stop the server
```
(4)run httpsproxy-client on your own computer
```shell
$ make start-client    #use "make stop-client" to stop the client
```
(5)proxy for some web
If you want to proxy some web, just config the web domains'ip to localhost. For example:
to proxy example.com, we should add a line in the /etc/hosts:
```vim
127.0.0.1   example.com
```
# auto start httpsproxy when the computer starting
(1) modify the file path in src/httpsproxy.sh, should be your own path.
(2) put the src/httpsproxy.sh file to /etc/init.d
```shell
$ cd httpsproxy/src
$ sudo cp httpsproxy.sh /etc/init.d
```
(3) change the file mode with the following command:
```shell
$ sudo chmod 755 /etc/init.d/httpsproxy.sh
```
(4) make a soft link file in /etc/rc3.d
```shell
$ sudo ln -s /etc/init.d/httpsproxy.sh /etc/rc3.d/S03httpsproxy 
```
