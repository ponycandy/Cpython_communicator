import numpy as np
import struct
class MatMaker:
    def __init__(self,TCPMassenger,DataMake):
        self.MTCP=TCPMassenger
        self.M_DATAM=DataMake
    def make_mat(self,numpydata):
        #允许tensor和array类型
        #np.mat(array)无比转为mat类型输入！！
        rows=np.size(numpydata,0)  #计算 X 的行数
        cols=np.size(numpydata,1)  #计算 X 的列数
        self.bytes_data = bytes()
        for rownum in range(0,rows):  # 迭代 10 到 20 之间的数字
            for colnum in range(0,cols): # 根据因子迭代
                self.bytes_data =self.bytes_data + struct.pack("d", (numpydata[rownum,colnum]))
        return self.bytes_data
    def sendMat(self,numpydata):
        self.make_mat(numpydata)

        self.M_DATAM.clear_iterative_pack()

        header=0xaadd
        self.M_DATAM.iterative_pack_2(header,'H')

        rows=np.size(numpydata,0)
        self.M_DATAM.iterative_pack_2(rows,'i')

        cols=np.size(numpydata,1)
        self.M_DATAM.iterative_pack_2(cols,'i')

        self.M_DATAM.append_data(self.bytes_data)

        self.MTCP.socket_send_hex(self.M_DATAM.get_iterative_hex_code())