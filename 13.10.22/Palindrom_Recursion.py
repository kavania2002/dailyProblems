# https://www.codechef.com/YTPP001/problems/NUMPLIN

def ispali(s):
    if (len(s)==1 or len(s)==0):
        return True
    elif (s[0]==s[-1]):
        s=s[1:-1]
        return ispali(s)
    else:
        return False
    
s = "abcba"
print(ispali(s))
