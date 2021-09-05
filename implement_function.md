# 实现beacon功能



授人以鱼不如授人以渔，简单实现一个cmdshell的功能

![image-20210905105246685](imgs/implement_function/image-20210905105246685.png)

从这里到这里都是从ida里扒拉下来的，这里其实就是获取cmd命令

![image-20210905105330142](imgs/implement_function/image-20210905105330142.png)

获取完cmd命令后，这里是存储结果以及发送指令的

最后到beacon.cpp执行

![image-20210905105619927](imgs/implement_function/image-20210905105619927.png)

结果

![image-20210905110429573](imgs/implement_function/image-20210905110429573.png)
