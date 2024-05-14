import os

ini = open(os.path.dirname(__file__)+"\Config\DefaultEngine.ini", "r")
content = ini.read()
content = content.replace("DefaultPlatformService=NULL", "DefaultPlatformService=Steam")
content = content.replace("bEnabled=false", "bEnabled=true")
ini = open(os.path.dirname(__file__)+"\Config\DefaultEngine.ini", "w")
ini.write(content)

batch = os.path.dirname(__file__)+"\launch_online.bat"
os.startfile(batch)