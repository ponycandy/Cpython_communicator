class LockingProxy:
    def __init__(self,ion):
        self.pointee_=ion
        self.pointee_.Lock()
    def __getattr__(self,name):
        var1 = 'self.pointee_.'+name
        return eval(var1)
    def __del__(self):
        self.pointee_.Unlock()
        pass