# All variables and this file are optional, if they are not present the PG and the
# makefiles will try to parse the correct values from the file system.
#
# Variables that specify exclusions can use % as a wildcard to specify that anything in
# that position will match. A partial path can also be specified to, for example, exclude
# a whole folder from the parsed paths from the file system
#
# Variables can be specified using = or +=
# = will clear the contents of that variable both specified from the file or the ones parsed
# from the file system
# += will add the values to the previous ones in the file or the ones parsed from the file 
# system
# 
# The PG can be used to detect errors in this file, just create a new project with this addon 
# and the PG will write to the console the kind of error and in which line it is

meta:
	ADDON_NAME = ofxREST
	ADDON_DESCRIPTION = REST Client with C++ REST SDK (https://casablanca.codeplex.com/)
	ADDON_AUTHOR = sk-march
	ADDON_TAGS = "network"
	ADDON_URL = https://github.com/sk-march/ofxREST.git

common:
	# dependencies with other addons, a list of them separated by spaces 
	# or use += in several lines
	# ADDON_DEPENDENCIES =
	
	# include search paths, this will be usually parsed from the file system
	# but if the addon or addon libraries need special search paths they can be
	# specified here separated by spaces or one per line using +=
	# ADDON_INCLUDES =
	
	# any special flag that should be passed to the compiler when using this
	# addon
	# ADDON_CFLAGS =
	
	# any special flag that should be passed to the linker when using this
	# addon, also used for system libraries with -lname
	# ADDON_LDFLAGS =
	
	# linux only, any library that should be included in the project using
	# pkg-config
	# ADDON_PKG_CONFIG_LIBRARIES =
	
	# osx/iOS only, any framework that should be included in the project
	# ADDON_FRAMEWORKS =
	
	# source files, these will be usually parsed from the file system looking
	# in the src folders in libs and the root of the addon. if your addon needs
	# to include files in different places or a different set of files per platform
	# they can be specified here
	# ADDON_SOURCES =
	
	# some addons need resources to be copied to the bin/data folder of the project
	# specify here any files that need to be copied, you can use wildcards like * and ?
	# ADDON_DATA = 
	
	# when parsing the file system looking for libraries exclude this for all or
	# a specific platform
	# ADDON_LIBS_EXCLUDE =
	
	# when parsing the file system looking for sources exclude this for all or
	# a specific platform
	# ADDON_SOURCES_EXCLUDE = 
	
	# when parsing the file system looking for include paths exclude this for all or
	# a specific platform
	# ADDON_INCLUDES_EXCLUDE =
	
linux64:
	# ADDON_LDFLAGS =
	# ADDON_CFLAGS  = 
	# ADDON_SOURCES_EXCLUDE =
	
linux:
	# ADDON_LDFLAGS = 
	# ADDON_CFLAGS  = 
	# ADDON_SOURCES_EXCLUDE =
	
win_cb:
	# ADDON_CFLAGS =
	# ADDON_SOURCES_EXCLUDE =
	# ADDON_INCLUDES +=
	
vs:
	# ADDON_LIBS += cpprest110_2_5.lib;
	ADDON_LIBS_EXCLUDE += cpprest110_2_5.lib; cpprest110_xp_2_5.lib; cpprest110d_2_5.lib; cpprest110d_xp_2_5.lib;

linuxarmv6l:
	# ADDON_LDFLAGS = 
	# ADDON_CFLAGS  = 
	# ADDON_SOURCES_EXCLUDE =
	
linuxarmv7l:
	# ADDON_LDFLAGS = 
	# ADDON_CFLAGS  = 
	# ADDON_SOURCES_EXCLUDE =

android/armeabi:	
	# ADDON_LDFLAGS = 
	# ADDON_CFLAGS  = 
	# ADDON_SOURCES_EXCLUDE =
	
android/armeabi-v7a:	
	# ADDON_LDFLAGS = 
	# ADDON_CFLAGS  = 
	# ADDON_SOURCES_EXCLUDE =

osx:
	# ADDON_LDFLAGS = 
	# ADDON_CFLAGS  = 
	# ADDON_SOURCES_EXCLUDE =
    
ios:
	# ADDON_LDFLAGS = 
	# ADDON_CFLAGS  = 
	# ADDON_SOURCES_EXCLUDE =

