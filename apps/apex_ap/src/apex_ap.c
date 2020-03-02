/*******************************************************************
 **                                                               **
 **  Copyright(C) 2020 Cepton Technologies. All Rights Reserved.  **
 **  Contact: https://www.cepton.com                              **
 **                                                               **
 *******************************************************************/

#include "platform_init.h"
#include "sdk.h"

#include "core/cortex_a9.h"
#include "cpu_utility/cpu_utility.h"
#include "utility/spinlock.h"

/**
 * @brief Global mutex controlling access to the console
 */
spinlock_t console_lock;

/**
 * @brief Example function that runs on each core. In practice, we will have
 * different functions running on each core, but this shows how to concurrently
 * execute code on each core.
 */
void say_hello_forever()
{
  uint32_t cpu_id = cpu_get_current();

  while (1)
  {
    // Control access to the console
    spinlock_lock(&console_lock, kSpinlockWaitForever);
    printf("Apex while loop running on core %d.\n", cpu_id);
    spinlock_unlock(&console_lock);
  }
}

int main(void)
{
  platform_init();

  printf("Starting the infinite while loop.\n");

  // Determine how many CPUs we have access to
  int cpu_count = cpu_get_cores();

  // Initialize mutexes
  spinlock_init(&console_lock);

  // Start all cpus and have them run say_hello_forever
  for (int i = 1; i < cpu_count; i++)
  {
    cpu_start_secondary(i, &say_hello_forever, 0);
  }

  say_hello_forever();

  return 0;
}
