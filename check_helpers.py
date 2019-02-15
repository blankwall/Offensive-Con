import subprocess

with open("targets.txt") as f:
	data = f.readlines()[1:]


known = []
for d in data:
	f = d.split("--")
	if len(f) < 2:
		continue
	known += [f[1].strip()]

stdoutdata = subprocess.getoutput("ls /Library/PrivilegedHelperTools").split()
for i in stdoutdata:
	if i not in known:
		print("New helper found: ", i) 
	
