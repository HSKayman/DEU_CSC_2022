class Time:
    def __init__(self,h=0,m=0,s=0):
        assert 0<=h<=23
        assert 0<=m<=59
        assert 0<=s<=60
        self._hours=int(h)
        self._minutes=int(m)
        self._seconds=int(s)

    def hours(self):
        return self._hours

    def minutes(self):
        return self._minutes

    def seconds(self):
        return self._seconds

    def __repr__(self):
        return "{:02d}:{:02d}:{:02d}".format(
            self.hours(),self.minutes(),self.seconds())

t=Time(13.4,0,0)
print(t) 
