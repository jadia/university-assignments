#!/bin/bash
# Q2: Write a shell script to find out the (a) largest and smallest process (b) oldest and youngest
# process presently running in the system.
# Hint: Create some processes to test your script.

printf 'Oldest Process:\n';
ls -ltr /proc/ | head -n 2 | tail -n 1 | cut -d " " -f 45-48,51
printf '\nYoungest Process\n';
ls -lt /proc/ | head -n 2 | tail -n 1 | cut -d " " -f 41-45
printf '\nSmallest process\n';
ps -eo pid,%mem --sort=%mem | head -n 2 | tail -n 1
printf '\nLargest process\n';
ps -eo pid,%mem --sort=%mem | tail -n 1
