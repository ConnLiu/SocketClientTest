# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import socket

import time

def listenPathPlanner():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        server.bind(("localhost", 8890))
        server.listen(0)
        connection, address = server.accept()
    
        print(connection, address)
        recv_str=connection.recv(1024)[0:5]
        recv_str=recv_str.decode("ascii")
        print("Recive:\n",recv_str)
        num=0
        rnd = 0
        while True:
            rnd += 1
            print("----------------Round:", rnd)
            if not recv_str:
    
                break
    
            num=num+1
    
            print("Input anything to send:")
    
            recv_str = input()
            
            connection.send( bytes("%s" % recv_str,encoding="ascii"))
            time.sleep( 0.5 )
    except socket.error as msg:
        print("Couldnt connect with the socket-server: %s\n terminating program" % msg)
        connection.close()
        
    input("enter end")

if __name__ == '__main__':
    listenPathPlanner()

