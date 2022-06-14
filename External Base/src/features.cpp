#include "features.hpp"
#include "pointers.hpp"
#include "script.hpp"


namespace ellohim::features
{
	void run_per_tick()
	{

	}

	void script_func()
	{
		while (true)
		{
			try 
			{
				features::run_per_tick();
			}
			catch (std::exception const& ex)
			{
				LOG(INFO) << ex.what();
			}
			script::get_current()->yield();
		}
	}
}
