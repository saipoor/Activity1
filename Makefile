PROJ_NAME = controller

BUILD_DIR = Build

# Source code files
SRC = main.c\
src/activity1.c\
src/activity2.c\
src/activity3.c\
src/activity4.c\

# header file paths
INC = -I inc

# Find out the OS 
ifdef OS	# configurations for Windwos OS
# Correct the path based on OS
   FixPath = $(subst /,\,$1)
# Name of the compiler used
   CC = avr-gcc.exe
#  elf to hex file converter used
   AVR_OBJ_CPY = avr-objcopy.exe
else #configurations for Linux OS
   ifeq ($(shell uname), Linux)
# Correct the path based on OS
      FixPath = $1				
# the compiler used
	  CC = avr-gcc
# elf to hex file converter used
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
# Analyse the code using Cppcheck command line utility
	cppcheck --enable=all $^

doc:
# Build the code code documentation using Doxygen command line utility
	make -C documentation

clean:
# Remove all the build files and generated document files
	rm -rf $(call FixPath,$(BUILD_DIR)/*)
	make -C documentation clean
