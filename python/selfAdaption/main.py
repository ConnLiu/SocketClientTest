# -*- coding: utf-8 -*-
from communication.mysocket import MySocket
from utils.weights import Weights

import socket, struct, time






if __name__ == '__main__':
    print("this is main")
    obj = MySocket()
    print("this is", obj)

    w = float(5)
    weights = Weights(w)
    print(weights.getAll())
    print(type(weights.getAll()))
    data = struct.pack(">dddddddd",*(weights.getAll()))
    print(data)
    obj.sendStruct(data)

    while 1:
        #action = int(input("Choose: 1:input anything, 2:input struct..."))
        action = 2
        if action == 1:
            s = input()
            obj.send(s if s!="end" else "")
            if s == "exit":
                print("exit....")
        elif action == 2:
            w = float(input("input value:"))
            weights = Weights(w)
            print(weights.getAll())
            print(type(weights.getAll()))
            data = struct.pack(">dddddddd",*(weights.getAll()))
            print(data)
            obj.sendStruct(data)