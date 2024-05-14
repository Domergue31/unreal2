import os

ini = open(os.path.dirname(__file__)+"\Config\DefaultEngine.ini", "r")
content = ini.read()
content = content.replace("DefaultPlatformService=Steam", "DefaultPlatformService=NULL")
content = content.replace("bEnabled=true", "bEnabled=false")
ini = open(os.path.dirname(__file__)+"\Config\DefaultEngine.ini", "w")
ini.write(content)

batch = os.path.dirname(__file__)+"\launch_online.bat"
os.startfile(batch)