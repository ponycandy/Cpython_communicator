import threading


class mutexobj:
    mutex = threading.Lock()
    flag=0
    def Lock(self):
        self.mutex.acquire()
    def Unlock(self):
        self.mutex.release()
    def set_evn(self,event):
        self.evn=event
    def setflag0(self):
        self.flag=0 #用来检验是否发生更新的门控
    def get_flag_state(self):
        return self.flag
    def is_pudated(self):#阻塞等待，只起效一次
        self.evn.wait()
        self.evn.clear()
        return 1
    def updatestate(self):
        self.flag=1 #说明发生一次更新
        self.evn.set()