import struct

class DataMaker:
    def getBytesPack(array_data):
        bytes_data = bytes()
        for i in range(len(array_data)):
            bytes_data += struct.pack('B', array_data[i])
        return bytes_data
    def iterative_pack(packet,data,packtype):

        return packet
    def iterative_pack_2(self,data,packtype):
        self.bytepack = self.bytepack+struct.pack(packtype, data)
    def append_data(self,data):
        self.bytepack = self.bytepack+data
    def clear_iterative_pack(self):
        self.bytepack = bytes() #重置
    def get_iterative_hex_code(self):
        return self.bytepack