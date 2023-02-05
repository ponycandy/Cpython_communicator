import threading
class callbackObj:
    def __init__(self):
        pass
    def set_target_data(self,targetdata): #this function must be reimplemented by other callback
        self.evt = threading.Event()
        self.targetdata=targetdata
        self.targetdata.set_evn(self.evt)
        self.evt.clear()