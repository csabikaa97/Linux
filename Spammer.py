import os
import sys
from random import randint
Channel="NULL"
Interface="NULL"
Essid="NULL"
Precharacters="NULL"
Bssid="NULL"
Times=10
Essidbase="NULL"
Filepath="NULL"
Frequency=1;
Fixchannel=0;
i=0
print("Argument initialization start...")
while i<len(sys.argv):
	print("argv["+str(i)+"]: "+sys.argv[i])
	if sys.argv[i]=="c":
		Channel=sys.argv[i+1]
		print("Found channel: "+Channel)
		Fixchannel=1
		i=i+1
	if sys.argv[i]=="i":
		Interface=sys.argv[i+1]
		print("Found interface: "+Interface)
		i=i+1
	if sys.argv[i]=="e":
		Essid=sys.argv[i+1]
		print("Essid found: "+Essid)
		i=i+1
	if sys.argv[i]=="p":
		Precharacters=sys.argv[i+1]
		print("Prefix characters found: "+Precharacters)
		i=i+1
	if sys.argv[i]=="f":
		Filepath=sys.argv[i+1]
		print("List file found: "+Filepath)
		i=i+1
	if sys.argv[i]=="b":
		Bssid=sys.argv[i+1]
		print("Bssid found: "+Bssid)
		i=i+1
	if sys.argv[i]=="t":
		Times=int(sys.argv[i+1])
		print("Runs "+str(Times)+" times.")
		i=i+1
	if sys.argv[i]=="l":
		Essidbase=sys.argv[i+1]
		print("Essid base found: "+Essidbase)
		i=i+1
	if sys.argv[i]=="T":
		Frequency=int(sys.argv[i+1])
		print("Frequency found: "+str(Frequency))
		i=i+1
	i=i+1
print("Argument initialization done.")
print("Checking wireless devices...")
if not Interface == "NULL":
	try:
		InterfaceFile=open("/sys/class/net/"+str(Interface)+"/type","r")
	except IOError:
		print("Interface "+Interface+" is not available.")
		sys.exit()
	print("Interface "+Interface+" is up.")
	try:
		InterfaceFile=open("/sys/class/net/mon0/type","r")
	except IOError:
		print("mon0 interface is not up")
		print("Starting airmon-ng")
		os.system("airmon-ng check kill")
		os.system("airmon-ng start "+str(Interface))
	try:
		InterfaceFile=open("/sys/class/net/"+Interface+"/type","r")
		if InterfaceFile.read() == "803":
			print("Interface "+Interface+" is in monitor mode.")
		else:
			print("Interface "+Interface+" is not in monitor mode. Changing it...")
			os.system("iwconfig "+Interface+" mode monitor")
	except IOError:
		sys.exit()
else:
	print("Unknown interface. Exiting...")
	sys.exit()
print("Checking wireless devices done.")
print("Starting generation...")
Command=""
for i in range(0,Times):
	if Fixchannel == 0:
		Channel=str(randint(1,11))
	if not Filepath == "NULL":
		try:
			Essidlistfile=open(str(Filepath))
		except IOError:
			print("Can't open list file.")
			sys.exit()
		EssidlistfileString=Essidlistfile.read()
	if not Essidbase == "NULL":
		Essid=Essidbase+"-"+str(randint(1,9999999))
	if i == 0:
		Command="airbase-ng -c "+Channel+" -e "+Essid+" -a "+Bssid+" mon0"
	else:
		Command=Command+" && SleepnRun \"airbase-ng -c "+Channel+" -a "+ Bssid+" -e "+Essid+" mon0\" "+str(i+1)
print("Generation done.")
print("Command: \""+Command+"\"")
print("Running script(s)...")
os.system(str(Command))
os.system(str(Command))

print("Closing program...")
os.system("airmon-ng stop mon0")
os.system("killall SleepnRun")
os.system("killall airbase-ng")
os.system("iwconfig "+Interface+" mode managed")
print("Thanks for using Spammer :D")
