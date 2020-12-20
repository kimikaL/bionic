/*
 * Copyright (C) 2013 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "private/libc_logging.h" 
#include <sys/system_properties.h>

int stat(const char* path, struct stat* sb) {
//  __libc_format_log(ANDROID_LOG_INFO, "stat", "%s", path);

  if(strcmp(path, "/sys/class/net/wlan0/address") == 0)
  {
    char *temp_pathname = const_cast<char*>(path);
    strcpy(temp_pathname, "/data/address");
    __libc_format_log(ANDROID_LOG_INFO, "stat changed1", "%s", path);
  }  

 // char buf[5];

 // if(__system_property_get("test.su.on", buf) == 0)
 // {
  	if(strcmp(path, "/system/bin/su") == 0 || strcmp(path, "/system/sbin/su") == 0 || strcmp(path, "/system/xbin/su") == 0 ||
	  	 strcmp(path, "/su/bin/su") == 0 || strcmp(path, "/sbin/su") == 0 || strcmp(path, "/system/sd/xbin/su") == 0 ||
	  	 strcmp(path, "/system/bin/failsafe/su") == 0 || strcmp(path, "/vendor/bin/su") == 0)
	  {
	    char *temp_pathname = const_cast<char*>(path);
	    strcpy(temp_pathname, "/sdcard/su");
	    __libc_format_log(ANDROID_LOG_INFO, "stat changed2", "%s", path);
	  }  
//	}


  return fstatat(AT_FDCWD, path, sb, 0);
}
__strong_alias(stat64, stat);
