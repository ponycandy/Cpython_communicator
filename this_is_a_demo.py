from TCP_Messager.Tcpcreator import create_proxy
import numpy as np

Matdatapointer,Matadatamanager=create_proxy()

#发送数据的例子

        # matr1 = np.mat("1 2 3;4 5 6;7 8 9")
        # Matadatamanager.sendMat(matr1)

#读取数据的例子
        # numpymat=Matdatapointer.getdata()

#此外，Matdatapointer的其它APi为：
        # def getdata(self):
        #     return self.matrix
        # def setflag0(self):
        #     self.flag=0
        #用来检验是否发生更新的门控，每次更新数据的时候，这个门控会设置为1，这里提供手动设置门控的方法
        # def get_flag_state(self):
        #     return self.flag
        #用来获取门控，判断是否发生更新