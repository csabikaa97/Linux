import os
import sys
Channel="NULL"
Interface="NULL"
Essid="NULL"
Precharacters="NULL"
Bssid="NULL"
Times=10
Essidbase="NULL"
Filepath="NULL"
i=0
while i<len(sys.argv):
	print("argv["+str(i)+"]: "+sys.argv[i])
	if sys.argv[i]=="c":
		Channel=sys.argv[i+1]
		print("Found channel :"+Channel)
		i=i+1
	if sys.argv[i]=="i":
		Interface=sys.argv[i+1]
		print("Found interface: "+Interface)
		i=i+1
	if sys.argv[i]=="":
		
		i=i+1
	i=i+1
