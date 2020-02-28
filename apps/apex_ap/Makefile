###################################################################
##                                                               ##
##  Copyright(C) 2020 Cepton Technologies. All Rights Reserved.  ##
##  Contact: https://www.cepton.com                              ##
##                                                               ##
###################################################################

#
# Apex main application
#

include $(SDK_ROOT)/mk/common.mk


# Set up to link application.
APP_NAME = apex_ap
LINK_APP = 1

# Local source files.
define SOURCES
    $(APPS_ROOT)/common/platform_init.c
    $(APPS_ROOT)/common/ivt.c
    src/apex_ap.c
endef

# Need to include the SDK library!
LIBRARIES = \
    $(LIBSDK) \
    $(LIBBOARD)

# Specify our linker script.
LD_FILE = $(APPS_ROOT)/common/basic_sdk_app.ld.S

# Add common to include paths.
INCLUDES += -I$(APPS_ROOT)/common


include $(SDK_ROOT)/mk/targets.mk
