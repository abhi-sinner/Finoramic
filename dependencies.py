


import sys, os,json
import pip
class Script: 

	def __init__(self):                                     #intialization for class Script
		self.cmd="sudo pip install "
		self.dicElem={}
		self.existingdict={}
		self.dictS={}


	def getData(self,name):                                 #this function gets the data from Dependencies.json
		f=open(name,'r')
		data=json.load(f);
		self.dicElem=data.get("Dependencies")
		f.close()

	def getExistingDependencies(self):                        #Existing dependencies into d_packages
		
		d_packages = pip.get_installed_distributions(local_only=True)
		d_packages_list = sorted(["%s==%s" % (i.key, i.version)
			for i in d_packages])

		for ele in d_packages_list:                               
			var=ele.split("==")
			self.existingdict[var[0]]=var[1]

	def DependenciesInstalling(self):                       
		for key,val in self.dicElem.items():
			os.system(self.cmd+str(key)+"=="+str(val))                #command for installing particular dependencies

	def checkUninstalled(self,):                                    #check for successfull installation
		for i,j in self.dicElem.items():
			if i in self.existingdict:
				if j==self.existingdict[i]:
					print(i+" is successfully installed\n")
				else:
					self.dictS[i]=j;
			else:
				self.dictS[i]=j;

		print("####")                                       #print the name of dependencies not installed
		print("*Dependencies which are not installed*\n")
		for k,v in self.dictS.items():
			print(k+" of version "+v+" is not installed")
		print("$end$")


if __name__ == '__main__':
	obj=Script()

	obj.getData("Dependencies.json")
	
	obj.DependenciesInstalling()

	obj.getExistingDependencies()

	obj.checkUninstalled()
