PROJ_NAME = main.c

BUILD_DIR = Build

#Source code files
SRC =
src/activity1.c\
src/activity2.c\
src/activity3.c\
src/activity4.c\

#header file paths
INC = -I inc

#To Find out OS
ifdef OS
   FixPath = $(subst /,\,$1)
#Name of the compiler used
   CC = avr-gcc.exe
#elf to hex file converter used
   AVR_OBJ_CPY = avr-objcopy.exe
else #configurations for Linux OS
   ifeq ($(shell uname), Linux)
#Correct the path based on OS
      FixPath = $1				
# Name of the compiler used
	  CC = avr-gcc
#elf to hex file converter used
	  AVR_OBJ_CPY = avr-objcopy 
   endif
endif

.PHONY:all analysis clean doc

all:$(BUILD_DIR)
# Compile the code and generate the ELF file
	$(CC) -g -Wall -Os -mmcu=atmega328  $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)

$(BUILD_DIR):
# Create directory to store the built files
	mkdir $(BUILD_DIR)

analysis: $(SRC)
# to Analyse the code using Cppcheck command line utility
	cppcheck --enable=all $^

clean:
# to Remove the build files
	rm -rf $(call FixPath,$(BUILD_DIR)/*)
