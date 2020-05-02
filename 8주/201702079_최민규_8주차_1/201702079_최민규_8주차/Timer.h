#pragma once

typedef struct _Timer Timer;

Timer*	Timer_new();

void	Timer_delete(Timer* _this);
void	Timer_start(Timer* _this);
void	Timer_stop(Timer* _this);
double	Timer_duration(Timer* _this);