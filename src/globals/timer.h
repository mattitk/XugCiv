#include <chrono>
#include <thread>



class Timer
{

	public:	
	std::chrono::high_resolution_clock::time_point start_time, end_time;
	
	Timer()
	{
		start_time = std::chrono::high_resolution_clock::now();
	}

	unsigned long int Time()
	{
		end_time = std::chrono::high_resolution_clock::now();
		return std::chrono::duration_cast<std::chrono::microseconds>(end_time-start_time).count();
	}
};
