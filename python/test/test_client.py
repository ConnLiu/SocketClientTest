#!/usr/bin/python
# -*- coding: UTF-8 -*-

import socket, struct# 客户端 发送一个数据，再接收一个数据

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM) #声明socket类型，同时生成链接对象
client.connect(('localhost',8890)) #建立一个链接，连接到本地的6969端口
while True:
    # addr = client.accept()
    # print '连接地址：', addr
    msg = '欢迎访问菜鸟教程！'  #strip默认取出字符串的头尾空格
    client.send(msg.encode('utf-8'))  #发送一条信息 python3 只接收btye流
    data = client.recv(1024) #接收一个信息，并指定接收的大小 为1024字节
    print(data)
    # this is for test
    # > important  
    # list_w = struct.unpack(">dddddddd",data[0:64])    #a,b,c即需要对数据进行
    
    # print('list_w:',list_w) #输出我接收的信息
    # print('list_w1:',float(list_w[0])) #输出我接收的信息

    dataStr = data.decode()
    print('recv:',dataStr) #输出我接收的信息
    if "exit" in dataStr:
        print("exit....")
        break
client.close() #关闭这个链接