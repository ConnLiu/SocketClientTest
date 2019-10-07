import socket, time

class MySocket:
    def __init__(self):
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            server.bind(("localhost", 8890))
            print("Connecting")
            server.listen(0)
            connection, address = server.accept()

            self.connection = connection
            self.address = address
            print("Connected:", connection, address)
            
        except socket.error as msg:
            print("Couldnt connect with the socket-server: %s\n terminating program" % msg)
            connection.close()

    def receive(self):
        connection = self.connection
        recv_str = connection.recv(1024)
        recv_str = recv_str.decode("ascii")
        print("And recive:\n", recv_str)

    def __del__(self):
        print("Deleting class and close socket connection.")
        self.connection.close()

    def sendStruct(self, data):
        connection = self.connection
        connection.send(data)

    def send(self, msg):
        connection = self.connection
        connection.send(bytes("%s" % msg, encoding="ascii"))
        time.sleep(0.5)


if __name__=="__main__":
    print("this is mysocket_main")            