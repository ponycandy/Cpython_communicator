from SmartPtr import SmartPtr
from MatData import MatData
from Default_Callback import Default_Callback
from TCP_Messager import TCP_Messager
from MatMaker import MatMaker
from DataMaker import DataMaker

def create_proxy():
    testptr=SmartPtr()
    testMiddata=MatData()
    testptr.setpointee(testMiddata)
    DFC=Default_Callback()
    DFC.set_target_data(testptr)
    TCPM=TCP_Messager('127.0.0.1',8001,DFC)

    #以上是回传数据的函数
    #一下是发送数据的函数
    m_datamaker=DataMaker()
    m_matmakr= MatMaker(TCPM,m_datamaker)


    return testptr,m_matmakr

    #说明：返回的值,m_matmakr具有方法 def sendMat(self,numpymat)
    #说明：返回的值,testptr具有方法
    # def getdata(self):
    #     return self.matrix
    # def modifydata(self,data):
    #     self.flag=1 #说明发生一次更新
    #     self.matrix=data.copy()
    # def setflag0(self):
    #     self.flag=0 #用来检验是否发生更新的门控
    # def get_flag_state(self):
    #     return self.flag
# 以上两个返回值以及其接口足以应对所有的socket操作了，更灵活的操作如重新定义数据结构和地址等，可以参考这里的结构进行更改