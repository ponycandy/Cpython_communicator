import socket
import time
import threading
import struct


class TCP_Messager():
    def __init__(self,IPaddr, port, callbackclass):
        self.sock = socket.socket()
        self.sock.bind((IPaddr, port))
        self.sock.listen()
        self.callback = callbackclass
        self.client_sock, self.client_addr = self.sock.accept()  #will stuck here until the incoming connect,so wait
        self.thread_read = threading.Thread(target=self.socket_recv_handle, args=(self.client_sock,)).start()
    def overallcallback(self,r):
        pass
    def socket_recv_handle(self, client_socket):
        while True:
            r = client_socket.recv(2048)
            self.callback.callbackfunc(r)
            # s=r[0:order+2]#short header
            # header = struct.unpack("h", s)
            # if(header=='aabb'):
            #     self.callback.callbackfunc(r) #解码器,可以使用一般解码器或者自定义解码器
    def socket_send_hex(self, hexcode):
        self.client_sock.send(hexcode)




# 接下来的空间留给具体编码，可以在下面继续添加，或者在代码中添加