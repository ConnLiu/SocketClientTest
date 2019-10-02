import time, socket

class MySocket:
    def __init__(self):
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            server.bind(("localhost", 8890))
            print("Connecting")
            server.listen(0)
            connection, address = server.accept()
            self.connection = connection


            recv_str = connection.recv(1024)
            recv_str = recv_str.decode("ascii")
            print("Connected:", connection, address)
            print("And recive:\n", recv_str)
            
        except socket.error as msg:
            print("Couldnt connect with the socket-server: %s\n terminating program" % msg)
            connection.close()


    def __del__(self):
        print("Deleting class and close socket connection.")
        self.connection.close()

    def send(self, msg):
        connection = self.connection
        connection.send(bytes("%s" % msg, encoding="ascii"))
        time.sleep(0.5)

if __name__=="__main__":
    obj = MySocket()
    print("this is", obj)
    while 1:
        s = input()
        obj.send(s if s!="end" else "")