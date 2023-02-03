
import struct
import numpy

class Default_Callback:
    def set_target_data(self,mattarget):
        self.targetmatSmptr=mattarget
    def callbackfunc(self,code):
        order=0

        s=code[0:2]#short header
        header = struct.unpack("H", s)[0]
        if(header==0xaadd):
            print("yes")
        order=order+2


        s=code[order:order+4]#rows
        rows = struct.unpack("i", s)[0]
        order=order+4
        #
        s=code[order:order+4]#rows
        cols = struct.unpack("i", s)[0]
        order=order+4
        #
        total_element=rows*cols
        self.mat= numpy.zeros((rows, cols))
        for rownum in range(0,rows):
            for colnum in range(0,cols):
                index=rownum*cols+colnum

                s=code[order:order+8]
                self.mat[rownum,colnum] = struct.unpack("d", s)[0]
                print(self.mat[rownum,colnum])
                order=order+8
        self.targetmatSmptr.modifydata(self.mat)