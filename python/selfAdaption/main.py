# -*- coding: utf-8 -*-
from communication.mysocket import MySocket
from utils.weights import Weights

import socket, struct, time






if __name__ == '__main__':
    print("this is main")
    
    obj = MySocket()
    print("this is", obj)
    while 1:
        action = 2#int(input("Choose: 1:input anything, 2:transfer string..."))

        if action == 1:
            s = input()
            obj.send(s if s!="end" else "")
            if s == "exit":
                print("exit....")

        elif action == 2: # transfer use json
            w = 3#float(input("input value:"))
            weights = Weights(w)
            
            data = weights.getJson()
            print(data)
            obj.send("Change")
            obj.send(data)
            float(input("input to continue"))

