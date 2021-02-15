#ifndef _CONTROLLER_H
#define _CONTROLLER_H

void *direction_controller(int direction, struct time duration);
void *cmd_controller();
void *function_controller(int behavior);

#endif