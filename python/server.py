# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import socket

import time

 

if __name__ == '__main__':

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server.bind(("localhost", 8890))

    server.listen(0)

    connection, address = server.accept()

    print(connection, address)
    recv_str=connection.recv(1024)[0:5]
    recv_str=recv_str.decode("ascii")
    
    num=0
    rnd = 0
    while True:

        # connection, address = server.accept()

        # print(connection, address)

        rnd += 1
        print("----------------Round:", rnd)
        

        if not recv_str:

            break

        num=num+1


        print("Input anything to send:")

        recv_str = input()
        
        connection.send( bytes("%s" % recv_str,encoding="ascii"))

        time.sleep( 0.5 )


    connection.close()

    input("enter end")
