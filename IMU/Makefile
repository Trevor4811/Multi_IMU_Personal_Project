
INCDIR := include
SRCDIR := src
BUILDDIR := build
BINDIR := bin
CXX := g++
CFLAGS :=	-c \
			-g \

ifeq ($(OS),Windows_NT)
	IS_WIN := 1
endif

.PHONY: all
all: 	dirs \
		LSM6DSOX\

force: 	clean \
		all\

test: 	dirs \
		TestFile


.PHONY: dirs
dirs:
ifeq ($(IS_WIN),1)
	if not exist $(BINDIR) mkdir $(BINDIR)
	if not exist $(BUILDDIR) mkdir $(BUILDDIR)
else
	mkdir -p $(BINDIR)
	mkdir -p $(BUILDDIR)
endif

LSM6DSOX: dirs LSM6DSOX.o I2CDevice.o I2CBus.o AccelData.o GyroData.o
	$(CXX) -o $(BINDIR)/LSM6DSOX $(BUILDDIR)/LSM6DSOX.o $(BUILDDIR)/I2CDevice.o $(BUILDDIR)/I2CBus.o -li2c

LSM6DSOX.o: dirs $(SRCDIR)/LSM6DSOX.cpp
	$(CXX) $(CFLAGS) -o $(BUILDDIR)/LSM6DSOX.o $(SRCDIR)/LSM6DSOX.cpp

I2CDevice: dirs I2CDevice.o I2CBus.o
	$(CXX) -o $(BINDIR)/I2CDevice $(BUILDDIR)/I2CDevice.o $(BUILDDIR)/I2CBus.o -li2c

I2CDevice.o: dirs $(SRCDIR)/I2CDevice.cpp
	$(CXX) $(CFLAGS) -o $(BUILDDIR)/I2CDevice.o $(SRCDIR)/I2CDevice.cpp

AccelData.o: dirs $(SRCDIR)/AccelData.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILDDIR)/AccelData.o $(SRCDIR)/AccelData.cpp

GyroData.o: dirs $(SRCDIR)/GyroData.cpp
	$(CXX) $(CXXFLAGS) -o $(BUILDDIR)/GyroData.o $(SRCDIR)/GyroData.cpp

I2CBus: dirs I2CBus.o
	$(CXX) -o $(BINDIR)/I2CBus $(BUILDDIR)/I2CBus.o

I2CBus.o: dirs $(SRCDIR)/I2CBus.cpp
	$(CXX) $(CFLAGS) -o $(BUILDDIR)/I2CBus.o $(SRCDIR)/I2CBus.cpp

TestFile: dirs TestFile.o
	$(CXX) -o $(BINDIR)/TestFile $(BUILDDIR)/TestFile.o

TestFile.o: dirs $(SRCDIR)/TestFile.cpp
	$(CXX) $(CFLAGS) -o $(BUILDDIR)/TestFile.o $(SRCDIR)/TestFile.cpp

.PHONY: clean
clean : 
	rm -fr $(BUILDDIR) $(BINDIR)

