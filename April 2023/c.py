def fun6(s):
    words = s.split()
    if len(words) == 0:
        return 0
    return len(words[-1])


print(fun6("Python Exercises"))
