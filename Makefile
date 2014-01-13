# Builds all the projects in the solution...
.PHONY: all_projects
all_projects: VonNeumannVM 

# Builds project 'VonNeumannVM'...
.PHONY: VonNeumannVM
VonNeumannVM: 
	make --directory="VonNeumannVM/" --file=VonNeumannVM.makefile

# Cleans all projects...
.PHONY: clean
clean:
	make --directory="VonNeumannVM/" --file=VonNeumannVM.makefile clean

