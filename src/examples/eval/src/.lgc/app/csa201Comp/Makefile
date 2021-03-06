
################################################################################
#
# This Makefile is auto-generated by OpenClovis IDE
#
# Makefile for csa201Comp
#
# This Makefile assumes the following:
#   - CLOVIS_ROOT environment variable is specified properly
#   - Entire source tree under $(CLOVIS_ROOT)/ASP is checked out
#
################################################################################
include $(CLOVIS_ROOT)/SAFplus/mk/preface.mk

# Component name (using all lowercase):

EXENAME := csa201Comp

# List local source files needed for the component server:

SRC_FILES := $(wildcard *.c)
CPP_FILES := $(wildcard *.C) $(wildcard *.cxx)

# List other ASP components of which client libraries your component
# depends on:

DEP_COMP_LIST := utils osal timer buffer ioc rmd eo amf event ckpt dbal debug cor prov mso pm alarm om hal name txn idl log cm fault
# FIXME: Indirect dependencies via client library needs need to be
# added by hand for now:
DEP_COMP_LIST += cnt



# List ASP libraries needed to get this server built (or None):

ASP_LIBS := libmw.a

# List any third party libs needed to get this server built (or None):
THIRD_PARTY_EZXML_PATH = $(CLOVIS_ROOT)/ASP/3rdparty/ezxml/stable

EXTRA_CPPFLAGS := -I$(THIRD_PARTY_EZXML_PATH)


# Executable name (when building server exectuable):
# Notice the '=' in the assignment.

EXE_NAME = $(EXENAME)

CPPFLAGS += -I$(ASP_CONFIG) 

ifeq ($(ASP_BUILD),0)
	LDFLAGS += -Wl,-rpath-link $(ASP_LIBDIR)
endif

BUILD_CPLUSPLUS = 0

# ---BEGIN_APPLICATION_CODE---
# Note if you make changes only within these existing APPLICATION_CODE blocks,
# then your changes will be preserved even if you make modifications in the
# IDE and regenerate the source.

# Important variables:
# OBJ_DIR  - Where all the object files are generated
# LIB_DIR  - Where all the libs are generated
# BIN_DIR  - Where the final product is generated

# To add libraries to the link line and to the dependencies append them to 
# EXTRA_LDLIBS.  For example, let's make a library named "libmystuff.a":
# EXTRA_LDLIBS    += $(LIB_DIR)/libmystuff.a

# To recursively make in dependent subdirectories, append them to SUB_DIRS
# SUB_DIRS += 

# ---END_APPLICATION_CODE---
 
include $(CLOVIS_ROOT)/ASP/mk/make-server.mk

# ---BEGIN_APPLICATION_CODE---
# Define additional targets BELOW, so that they are not used as the default 
# target.

# To make specific additional targets (other then C or c++ files in this
# directory -- these are automatically added), add them here.  For example,
# to add a script that needs to be copied:
# all: $(BIN_DIR)/myScript

# Add the rules to build the additional targets here:
# For example:
# $(BIN_DIR)/myScript: myScript.sh
#       $(MKDIR) $(BIN_DIR)
#       $(CP) $< $@

# Above I had an example of an external library "libmystuff.a".  Now I must 
# define the target to build it.  Let us imagine that the source for this 
# library exists in a subdirectory called "common" off of the parent.

# $(LIB_DIR)/libmystuff.a: ../common/mystuff.c
#   $(MAKE) -C ../common

# Note that the OpenClovis defined make variables will still be defined in the
# invocation of this sub-makefile.  They must be used to ensure that binaries
# and libraries are placed in the correct directories, and that the correct
# compiler is used (the compiler changes when doing cross-builds).

# For more information (and an example Makefile) see the OpenClovis SDK user 
# guide.

# ---END_APPLICATION_CODE---

