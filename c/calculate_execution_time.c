/*
 * Copyright (c) 2017, Sohrab Monfared <sohrab.monfared@gmail.com>
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the <organization> nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
  struct timeval start_tv, end_tv;
  struct timeval *start_tv_ptr, *end_tv_ptr;

  start_tv_ptr = &start_tv;
  end_tv_ptr = &end_tv;


  if (argc < 2){
    printf("usage: %s </path/to/binary>\n", argv[0]);
    return -2;
  }


  if (gettimeofday(start_tv_ptr, NULL) != 0){
    perror("gettimeofday");
    return -1;
  }

  system(argv[1]);

  if (gettimeofday(end_tv_ptr, NULL) != 0){
    perror("gettimeofday");
    return -1;
  }

  printf("%f\n", ((end_tv_ptr->tv_sec *1e6 + end_tv_ptr->tv_usec) - (start_tv_ptr->tv_sec *1e6 + start_tv_ptr->tv_usec)) / 1000000 );

  return 0;
}
