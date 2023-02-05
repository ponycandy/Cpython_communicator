#已经学会了
#那就开始搭建我们的系统吧
#用来保存和加载神经网络参数的代码见下面
from TCP_Manage import *

Matdatapointer,Matadatamanager=Tcpcreator.create_proxy('127.0.0.1',8001)
while(1):
    if(Matdatapointer.is_pudated()):
        print(Matdatapointer.getdata())

#发送数据的例子

# matr1 = np.mat("1 2 3;4 5 6;7 8 9")
# Matadatamanager.sendMat(matr1)

#读取数据的例子
# numpymat=Matdatapointer.getdata()


#用来获取门控，判断是否发生更新