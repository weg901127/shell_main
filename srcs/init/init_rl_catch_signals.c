#include "../../micro_shell.h"

void	init_rl_catch_signals()
{
	extern int rl_catch_signals;

	rl_catch_signals = 0;
}
