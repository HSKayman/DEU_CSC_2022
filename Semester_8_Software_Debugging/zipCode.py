# Zip Code practice program.
# Software debugging exercise.

class ZIPCode:
    # US Only
    
    def __init__(self, zip):
        self._zip = zip
        self.checkRep()

    def zip(self):
        return self._zip
    
    def checkRep(self):
        assert len(self.zip()) == 5
        # add in your asserts to ensure this is a valid ZIP code
        for c in self.zip():
            assert '0'<= c <='9'