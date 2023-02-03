from mutexobj import mutexobj

class MatData(mutexobj):
    def __init__(self):
        self.matrix='NULL'
        pass
    def getdata(self):
        return self.matrix
    def modifydata(self,data):
        self.flag=1 #说明发生一次更新
        self.matrix=data.copy()
    def setflag0(self):
        self.flag=0 #用来检验是否发生更新的门控
    def get_flag_state(self):
        return self.flag