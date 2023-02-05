from mutexobj import mutexobj

class MatData(mutexobj):
    def __init__(self):
        self.matrix='NULL'
        pass
    def getdata(self):
        return self.matrix
    def modifydata(self,data):
        self.matrix=data.copy()
        self.updatestate()

