from SmartPtr import SmartPtr
from MatData import MatData
from Default_Callback import Default_Callback
from TCP_Messager import TCP_Messager
from MatMaker import MatMaker
from DataMaker import DataMaker

#工厂模式
def create_proxy(Ip,port):
    testptr=SmartPtr()
    testMiddata=MatData()
    testptr.setpointee(testMiddata)
    DFC=Default_Callback()
    DFC.set_target_data(testptr)
    TCPM=TCP_Messager(Ip,port,DFC)

    #以上是回传数据的函数
    #一下是发送数据的函数
    m_datamaker=DataMaker()
    m_matmakr= MatMaker(TCPM,m_datamaker)


    return testptr,m_matmakr

