import threading


class mutexobj:
    mutex = threading.Lock()

    def Lock(self):
        self.mutex.acquire()
    def Unlock(self):
        self.mutex.release()
