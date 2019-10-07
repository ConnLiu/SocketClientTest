# -*- coding: utf-8 -*-
from communication.mysocket import MySocket
from utils.weights import Weights

import socket, struct, time






if __name__ == '__main__':
    print("this is main")
    
    obj = MySocket()
    print("this is", obj)
    while 1:
        #action = int(input("Choose: 1:input anything, 2:input struct, 3:transfer string..."))
        action = 3
        if action == 1:
            s = input()
            obj.send(s if s!="end" else "")
            if s == "exit":
                print("exit....")
        elif action == 2:
            w = float(input("input value:"))
            weights = Weights(w)
            print(weights.getAllStruct())
            print(type(weights.getAllStruct()))
            data = struct.pack(">dddddddd",*(weights.getAllStruct()))
            print(data)
            obj.sendStruct(data)
        elif action == 3: # transfer use json
            w = float(input("input value:"))
            weights = Weights(w)
            
            data = weights.getJson()
            print(data)
            obj.send(data)
            # print(weights.getAllStruct())
            # print(type(weights.getAllStruct()))
            # data = struct.pack(">dddddddd",*(weights.getAllStruct()))
            # print(data)
            # obj.sendStruct(data)
