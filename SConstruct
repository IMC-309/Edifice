env = Environment()
env.Append(CCFLAGS = ['-std=c++0x'])
env.Append(CPPPATH = ["#"])

Export("env")
SConscript('external/SConscript')
SConscript("tutorial/SConscript")

