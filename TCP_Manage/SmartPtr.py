from LockingProxy import  LockingProxy



class SmartPtr:
    def __init__(self):
        pass
    def setpointee(self,ion):
        self.pointee_=ion
    def __getattr__(self,name):
        var1 = 'LockingProxy(self.pointee_).'
        var1=var1+name
        return eval(var1)