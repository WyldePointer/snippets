/*
 * Copyright (c) 2017, Sohrab Monfared <sohrab.monfared@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the <organization> nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


/* 
                   00
                   /\
                  /  \
                 /    \
                /      \
               /        \
              /          \
             /            \
            /              \
           /                \
          /                  \
         1                    2
        /\                    /\
       /  \                  /  \
      /    \                /    \
     /      \              /      \
    3        4            5        6
   / \      / \          / \      / \
  7   8    9   10      11   12  13   14

*/

/*
 * TODO: What if both left && right wipe fails?
 */

#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned int destroyed_units_count = 0;
unsigned int max_destroy_attempts = 3;
const struct timespec _DEMO_slowness = {0, 800000000};
time_t t;

typedef struct Unit{
  unsigned int _DEMO_id;
  struct Unit *left;
  struct Unit *right;
} Unit;

void callback_wipe_failed(unsigned int id){
  printf("**ALERT** ERROR WIPING ID %d. WILL TRY AGAIN.\n", id);
}

void callback_maximum_attempts(unsigned int id){
  printf("**ALERT** MAXIMUM ATTEMPTS HAS REACHED FOR ID %d. REPORTING;\n", id);
}

/* DoD 5220.22-M */
unsigned int wipe(Unit *unit){

  unsigned int pass = 0;

  printf("wipe(%d); ", unit->_DEMO_id); 

  /* Pass 1: Writing a zero and verify the write */

  /* Pass 2: Writing a one and verify the write */

  /* Pass 3: Writing a random character and verify the write */

  while (pass++ < 3){

    printf("Pass %d ", pass);

    fflush(stdout);

    if ((rand() % 3) == 0){
      printf("\n");
      return 0;
    }

    nanosleep(&_DEMO_slowness, NULL);
  }

  printf("\n");

  return 1;
}

void destroy(Unit *unit){

  unsigned int current_destroy_attempt = 1;

  srand(time(&t));

  printf("destroy(%d);\n", unit->_DEMO_id);

  while(unit != NULL){

    /* TODO: Parallel */

    if (unit->left != NULL){
      destroy(unit->left);
      unit->left = NULL;
    }

    if (unit->right != NULL){
      destroy(unit->right);
      unit->right = NULL;
    }

    if (unit->left == NULL && unit->right == NULL){

      while (unit != NULL){

        if (current_destroy_attempt++ > max_destroy_attempts){

          callback_maximum_attempts(unit->_DEMO_id);

          return;
        }

        if (wipe(unit)){

          printf("#%d HAS BEEN SUCCESSFULLY WIPED AND DESTROYED.\n",
            unit->_DEMO_id);

          unit = NULL;

          destroyed_units_count++;

        } else {

          callback_wipe_failed(unit->_DEMO_id);

        }

      }

    }

  }


}

int main(int argc, char *argv[]){

  Unit top = {0, NULL, NULL};

  Unit l0 = {1, NULL, NULL};
  Unit r0 = {2, NULL, NULL};

  Unit l0l = {3, NULL, NULL};
  Unit l0r = {4, NULL, NULL};

  Unit r0l = {5, NULL, NULL};
  Unit r0r = {6, NULL, NULL};


  top.left = &l0;
  top.right = &r0;

  l0.left = &l0l;
  l0.right = &l0r;

  r0.left = &r0l;
  r0.right = &r0r;

  destroy(&top);

  printf("\nDestroyed units: %d\n", destroyed_units_count);

  return 0;
}
